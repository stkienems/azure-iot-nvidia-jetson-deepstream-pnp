﻿/*******************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.2.
 *
 * You need to add your implementation here to:
 *    - get telemetry data from device/sensor
 *    - set read-only property data
 *    - handle read-write property callback
 *    - process device command
 *
 * Generated Date: Tuesday, October 8, 2019
 *******************************************************************************************/

#include "jetson_impl.h"
#include "utilities/digitaltwin_serializer.h"
#include "utilities/deviceinfo_interface.h"
#include "utilities/deepstream_interface.h"
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>

#define Payload_Buffer_Size 256

char* exec_shell(const char *cmd) {
    FILE *fd;
    fd = popen(cmd, "r");
    if (!fd) return "ERROR";
 
    char   buffer[256];
    size_t chread;
    /* String to store entire command contents in */
    size_t comalloc = 256;
    size_t comlen   = 0;
    char  *comout   = malloc(comalloc);
 
    /* Use fread so binary data is dealt with correctly */
    while ((chread = fread(buffer, 1, sizeof(buffer), fd)) != 0) {
        if (comlen + chread >= comalloc) {
            comalloc *= 2;
            comout = realloc(comout, comalloc);
        }
        memmove(comout + comlen, buffer, chread);
        comlen += chread;
    }
 
    /* make output conform to cstring */
    comout[comlen] = '\0';

    /* We can now work with the output as we please */
    pclose(fd);
    return comout;
}


static int exec_prog(const char **argv)
{
    pid_t   pid;
    int     status;

    if (0 == (pid = vfork())) {
            if (-1 == execve(argv[0], (char **)argv , NULL)) {
                    perror("child process execve failed [%m]");
                    return -1;
            }
        _exit(0);
    }

    return 0;
}

void SendTelemetry_Succeeded_Callback(const char* interfaceName, const char* telemetryName)
{
    // If needed, put your business logic here to handle the confirmation of the delivery for device telemetry on success.

    LogInfo("DigitalTwin successfully delivered telemetry message for %s::%s", interfaceName, telemetryName);
}

void SendTelemetry_Error_Callback(const char* interfaceName, const char* telemetryName)
{
    // If needed, put your business logic here to handle the confirmation of the delivery for device telemetry on failure.

    LogInfo("DigitalTwin failed to deliver telemetry message for %s::%s", interfaceName, telemetryName);
}

void ReportProperty_Succeeded_Callback(const char* interfaceName, const char* propertyName)
{
    // If needed, put your business logic here to handle the result callback reporting property on success.

    LogInfo("DigitalTwin successfully report writable property for %s::%s", interfaceName, propertyName);
}

void ReportProperty_Error_Callback(const char* interfaceName, const char* propertyName)
{
    // If needed, put your business logic here to handle the result callback of reporting property on failure.

    LogInfo("DigitalTwin failed to report writable property for %s::%s", interfaceName, propertyName);
}

char* Deviceinfo_Property_GetManufacturer()
{
    return "Nvidia";
}

char* Deviceinfo_Property_GetModel()
{
    return "Jetson Nano";
}

char* Deviceinfo_Property_GetSwVersion()
{
    // TODO: provide implementation here
    return "1.0";
}

char* Deviceinfo_Property_GetOsName()
{
    return exec_shell("uname -a 2>&1");
}

char* Deviceinfo_Property_GetProcessorArchitecture()
{
    return exec_shell("lscpu | grep Architecture | awk '{print $2}' 2>&1");
}

char* Deviceinfo_Property_GetProcessorManufacturer()
{
    return "ARM";
}

long Deviceinfo_Property_GetTotalStorage()
{
    return atol(exec_shell("df | grep /dev/mmcblk0p1 | awk '{print $2}' 2>&1"));
}

long Deviceinfo_Property_GetTotalMemory()
{
    return atol(exec_shell("free | grep Mem: | awk '{print $2}' 2>&1"));
}

double Thermalzones_Telemetry_ReadThermal_zone_0()
{
    return atof(exec_shell("cat /sys/devices/virtual/thermal/thermal_zone0/temp"))/1000.0;
}

double Thermalzones_Telemetry_ReadThermal_zone_1()
{
    return atof(exec_shell("cat /sys/devices/virtual/thermal/thermal_zone1/temp"))/1000.0;
}

double Thermalzones_Telemetry_ReadThermal_zone_2()
{
    return atof(exec_shell("cat /sys/devices/virtual/thermal/thermal_zone2/temp"))/1000.0;
}

double Thermalzones_Telemetry_ReadThermal_zone_3()
{
    return atof(exec_shell("cat /sys/devices/virtual/thermal/thermal_zone3/temp"))/1000.0;
}

double Thermalzones_Telemetry_ReadThermal_zone_4()
{
    return atof(exec_shell("cat /sys/devices/virtual/thermal/thermal_zone4/temp"))/1000.0;
}

double Thermalzones_Telemetry_ReadThermal_zone_5()
{
    return atof(exec_shell("cat /sys/devices/virtual/thermal/thermal_zone5/temp"))/1000.0;
}


bool Deepstream_Telemetry_ReadDeepstream_status()
{
    int pid = atoi(exec_shell("pidof deepstream-app"));

    if(pid)
        return true;

    return false;
}

int Deepstream_Telemetry_ReadDeepstream_detections()
{

    // Create workspace directories
    exec_shell("mkdir -p /tmp/deepstream-detections-output-dir");
    exec_shell("mkdir -p /tmp/deepstream-detections-processing-dir");

    // Remove all output with filesize of 0 as these contain no detections
    exec_shell("find /tmp/deepstream-detections-output-dir/ -size 0 -type f -delete");

    // Move all deepstream-detections to processing directory
    exec_shell("mv /tmp/deepstream-detections-output-dir/*  /tmp/deepstream-detections-processing-dir/ 2>/dev/null");

    // Objects detected is equal to Number of lines in output file, return highest count since last telemetry interval
    int detections = atoi(exec_shell("wc -l /tmp/deepstream-detections-processing-dir/* 2>/dev/null | grep \"/\" | sort -n | tail -n 1 | awk '{print $1}'"));

    //Clean the processing directory for the next telemetry interval
    exec_shell("rm /tmp/deepstream-detections-processing-dir/* 2> /dev/null");

    return detections;
}

DIGITALTWIN_COMMAND_RESULT Deepstream_Command_SetDeepStreamConfig(char* deepStreamConfigPath, DEEPSTREAM_SETDEEPSTREAMCONFIG_setDeepStreamConfigResponse* response, unsigned int* statusCode)
{

    // You need to process the device command, and set the command response and statusCode correspondingly.
    // Finally, return DIGITALTWIN_COMMAND_OK if the command execution succeeded, or 'DIGITALTWIN_COMMAND_ERROR' on failure.

    LogInfo("Parameter: deepStreamConfigPath = %s", deepStreamConfigPath);

    int pid = atoi(exec_shell("pidof deepstream-app"));

    if(pid)
        kill(pid, SIGTERM);

    const char *deepstream_command[256] = {"/usr/bin/deepstream-app" , "-c" , deepStreamConfigPath};

    exec_prog(deepstream_command);

    // Set command response and status code
    response->description = "Deepstream configuration applied";

    *statusCode = 200;
    LogInfo("Device executed 'setDeepStreamConfig' command successfully");
    return DIGITALTWIN_COMMAND_OK;
}