﻿/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.2.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: Thursday, October 10, 2019
 ***********************************************************************************************/

#include "thermalzones_interface.h"

#define MAX_MASSAGE_SIZE 256

//
// Application state associated with this interface.
// It contains the DIGITALTWIN_INTERFACE_CLIENT_HANDLE used for responses in callbacks along with properties set
// and representations of the property update and command callbacks invoked on given interface
//
typedef struct THERMALZONES_INTERFACE_STATE_TAG
{
    DIGITALTWIN_INTERFACE_CLIENT_HANDLE interfaceClientHandle;

} THERMALZONES_INTERFACE_STATE;

static THERMALZONES_INTERFACE_STATE appState;

// ThermalzonesInterface_TelemetryCallback is invoked when a DigitalTwin telemetry message is either successfully delivered to the service or else fails.
static void ThermalzonesInterface_TelemetryCallback(DIGITALTWIN_CLIENT_RESULT digitalTwinTelemetryStatus, void* userContextCallback)
{
    if (digitalTwinTelemetryStatus == DIGITALTWIN_CLIENT_OK)
    {
        SendTelemetry_Succeeded_Callback("Thermalzones", (const char*)userContextCallback);
        LogInfo("THERMALZONES_INTERFACE: DigitalTwin successfully delivered telemetry message for <%s>", (const char*)userContextCallback);
    }
    else
    {
        SendTelemetry_Error_Callback("Thermalzones", (const char*)userContextCallback);
        LogError("THERMALZONES_INTERFACE: DigitalTwin failed to deliver telemetry message for <%s>, error=<%s> ", (const char*)userContextCallback, MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, digitalTwinTelemetryStatus));
    }
}

// SendTelemetry is a helper function which is periodically invoked by the caller to send telemetry
DIGITALTWIN_CLIENT_RESULT ThermalzonesInterface_SendTelemetry_Internal(DIGITALTWIN_INTERFACE_CLIENT_HANDLE interfaceHandle, const char* telemetryName, const char* telemetryData)
{
    DIGITALTWIN_CLIENT_RESULT result;

    result = DigitalTwin_InterfaceClient_SendTelemetryAsync(interfaceHandle, telemetryName, telemetryData,
        ThermalzonesInterface_TelemetryCallback, (void*)telemetryName);

    if (result != DIGITALTWIN_CLIENT_OK)
    {
        LogError("THERMALZONES_INTERFACE:: DigitalTwin_InterfaceClient_SendTelemetryAsync failed for sending %s", telemetryName);
    }
    else
    {
        LogInfo("THERMALZONES_INTERFACE:: DigitalTwin_InterfaceClient_SendTelemetryAsync successfully sent %s", telemetryName);
    }

    DigitalTwinClientHelper_Check();
    return result;
}

DIGITALTWIN_CLIENT_RESULT ThermalzonesInterface_Telemetry_SendAll()
{
    DIGITALTWIN_CLIENT_RESULT result;

    // NOTE: Future versions of SDK will support ability to send multiple telemetries in a single
    // send.  For now, one at a time is sufficient albeit less efficient.
    if (((result = ThermalzonesInterface_Telemetry_SendThermal_zone_0()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = ThermalzonesInterface_Telemetry_SendThermal_zone_1()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = ThermalzonesInterface_Telemetry_SendThermal_zone_2()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = ThermalzonesInterface_Telemetry_SendThermal_zone_3()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = ThermalzonesInterface_Telemetry_SendThermal_zone_4()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = ThermalzonesInterface_Telemetry_SendThermal_zone_5()) != DIGITALTWIN_CLIENT_OK) )

    {
        LogError("THERMALZONES_INTERFACE: failed to send telemetries");
    }
    else
    {
        LogInfo("THERMALZONES_INTERFACE: Queuing of all telemetries to be sent has succeeded");
    }

    return result;
}

DIGITALTWIN_CLIENT_RESULT ThermalzonesInterface_Telemetry_SendThermal_zone_0()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("THERMALZONES_INTERFACE: interfaceClientHandle is required to be initialized before sending telemetries");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Thermalzones_SerializeThermal_zone_0Telemetry(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return ThermalzonesInterface_SendTelemetry_Internal(appState.interfaceClientHandle, ThermalzonesInterface_Thermal_zone_0Telemetry, payloadBuffer);
    }
    else
    {
        LogError("THERMALZONES_INTERFACE: serialize telemetry message thermal_zone_0 failed.");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT ThermalzonesInterface_Telemetry_SendThermal_zone_1()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("THERMALZONES_INTERFACE: interfaceClientHandle is required to be initialized before sending telemetries");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Thermalzones_SerializeThermal_zone_1Telemetry(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return ThermalzonesInterface_SendTelemetry_Internal(appState.interfaceClientHandle, ThermalzonesInterface_Thermal_zone_1Telemetry, payloadBuffer);
    }
    else
    {
        LogError("THERMALZONES_INTERFACE: serialize telemetry message thermal_zone_1 failed.");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT ThermalzonesInterface_Telemetry_SendThermal_zone_2()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("THERMALZONES_INTERFACE: interfaceClientHandle is required to be initialized before sending telemetries");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Thermalzones_SerializeThermal_zone_2Telemetry(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return ThermalzonesInterface_SendTelemetry_Internal(appState.interfaceClientHandle, ThermalzonesInterface_Thermal_zone_2Telemetry, payloadBuffer);
    }
    else
    {
        LogError("THERMALZONES_INTERFACE: serialize telemetry message thermal_zone_2 failed.");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT ThermalzonesInterface_Telemetry_SendThermal_zone_3()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("THERMALZONES_INTERFACE: interfaceClientHandle is required to be initialized before sending telemetries");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Thermalzones_SerializeThermal_zone_3Telemetry(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return ThermalzonesInterface_SendTelemetry_Internal(appState.interfaceClientHandle, ThermalzonesInterface_Thermal_zone_3Telemetry, payloadBuffer);
    }
    else
    {
        LogError("THERMALZONES_INTERFACE: serialize telemetry message thermal_zone_3 failed.");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT ThermalzonesInterface_Telemetry_SendThermal_zone_4()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("THERMALZONES_INTERFACE: interfaceClientHandle is required to be initialized before sending telemetries");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Thermalzones_SerializeThermal_zone_4Telemetry(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return ThermalzonesInterface_SendTelemetry_Internal(appState.interfaceClientHandle, ThermalzonesInterface_Thermal_zone_4Telemetry, payloadBuffer);
    }
    else
    {
        LogError("THERMALZONES_INTERFACE: serialize telemetry message thermal_zone_4 failed.");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT ThermalzonesInterface_Telemetry_SendThermal_zone_5()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("THERMALZONES_INTERFACE: interfaceClientHandle is required to be initialized before sending telemetries");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Thermalzones_SerializeThermal_zone_5Telemetry(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return ThermalzonesInterface_SendTelemetry_Internal(appState.interfaceClientHandle, ThermalzonesInterface_Thermal_zone_5Telemetry, payloadBuffer);
    }
    else
    {
        LogError("THERMALZONES_INTERFACE: serialize telemetry message thermal_zone_5 failed.");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

// ThermalzonesInterface_InterfaceRegisteredCallback is invoked when this interface
// is successfully or unsuccessfully registered with the service, and also when the interface is deleted.
static void ThermalzonesInterface_InterfaceRegisteredCallback(DIGITALTWIN_CLIENT_RESULT dtInterfaceStatus, void* userInterfaceContext)
{
    LogInfo("ThermalzonesInterface_InterfaceRegisteredCallback with status=<%s>, userContext=<%p>", MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, dtInterfaceStatus), userInterfaceContext);
    if (dtInterfaceStatus == DIGITALTWIN_CLIENT_OK)
    {
        // Once the interface is registered, send our reported properties to the service.  
        // It *IS* safe to invoke most DigitalTwin API calls from a callback thread like this, though it 
        // is NOT safe to create/destroy/register interfaces now.
        LogInfo("THERMALZONES_INTERFACE: Interface successfully registered.");
    }
    else if (dtInterfaceStatus == DIGITALTWIN_CLIENT_ERROR_INTERFACE_UNREGISTERING)
    {
        // Once an interface is marked as unregistered, it cannot be used for any DigitalTwin SDK calls.
        LogInfo("THERMALZONES_INTERFACE: Interface received unregistering callback.");
    }
    else
    {
        LogError("THERMALZONES_INTERFACE: Interface received failed, status=<%s>.", MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, dtInterfaceStatus));
    }
}

//
// Create DigitalTwin interface client handle
//
DIGITALTWIN_INTERFACE_CLIENT_HANDLE ThermalzonesInterface_Create()
{
    DIGITALTWIN_INTERFACE_CLIENT_HANDLE interfaceHandle;
    DIGITALTWIN_CLIENT_RESULT result;

    memset(&appState, 0, sizeof(THERMALZONES_INTERFACE_STATE));

    if ((result = DigitalTwin_InterfaceClient_Create(ThermalzonesInterfaceId,  ThermalzonesInterfaceInstanceName, ThermalzonesInterface_InterfaceRegisteredCallback, (void*)&appState, &interfaceHandle)) != DIGITALTWIN_CLIENT_OK)
    {
        LogError("THERMALZONES_INTERFACE: Unable to allocate interface client handle for interfaceId=<%s>, interfaceInstanceName=<%s>, error=<%s>", ThermalzonesInterfaceId, ThermalzonesInterfaceInstanceName, MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, result));
        interfaceHandle = NULL;
    }

    else
    {
        LogInfo("THERMALZONES_INTERFACE: Created DIGITALTWIN_INTERFACE_CLIENT_HANDLE successfully for interfaceId=<%s>, interfaceInstanceName=<%s>, handle=<%p>", ThermalzonesInterfaceId, ThermalzonesInterfaceInstanceName, interfaceHandle);
        appState.interfaceClientHandle = interfaceHandle;
    }

    return interfaceHandle;
}

void ThermalzonesInterface_Close(DIGITALTWIN_INTERFACE_CLIENT_HANDLE digitalTwinInterfaceClientHandle)
{
    // On shutdown, in general the first call made should be to DigitalTwin_InterfaceClient_Destroy.
    // This will block if there are any active callbacks in this interface, and then
    // mark the underlying handle such that no future callbacks shall come to it.
    DigitalTwin_InterfaceClient_Destroy(digitalTwinInterfaceClientHandle);

    // After DigitalTwin_InterfaceClient_Destroy returns, it is safe to assume
    // no more callbacks shall arrive for this interface and it is OK to free
    // resources callbacks otherwise may have needed.

}