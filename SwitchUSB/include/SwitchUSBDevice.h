#pragma once
#include "IUSBDevice.h"
#include "switch.h"
#include "SwitchUSBInterface.h"
#include <vector>

class SwitchUSBDevice : public IUSBDevice
{
public:
    SwitchUSBDevice();
    ~SwitchUSBDevice();

    //Initialize the class with the SetInterfaces call.
    SwitchUSBDevice(UsbHsInterface *interfaces, int length);

    //There are no devices to open on the switch, so instead this returns success if there are any interfaces
    virtual Result Open();
    //Closes all the interfaces associated with the class
    virtual void Close();

    // Resets the device
    virtual void Reset();

    //Create interfaces from the given array of specified element length
    void SetInterfaces(UsbHsInterface *interfaces, int length);
};