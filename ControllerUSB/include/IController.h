#pragma once
#include "IUSBDevice.h"
#include "ControllerTypes.h"
#include "ControllerConfig.h"
#include <memory>

struct NormalizedButtonData
{
    bool buttons[NUM_CONTROLLERBUTTONS];
    float triggers[2];
    NormalizedStick sticks[2];
};

class IController
{
protected:
    std::unique_ptr<IUSBDevice> m_device;

public:
    IController(std::unique_ptr<IUSBDevice> &&interface) : m_device(std::move(interface)) {}
    virtual ~IController() = default;

    virtual Status Initialize() = 0;

    //Since Exit is used to clean up resources, no status report should be needed
    virtual void Exit() = 0;

    virtual Status GetInput() = 0;

    virtual NormalizedButtonData GetNormalizedButtonData() = 0;

    inline IUSBDevice *GetDevice() { return m_device.get(); }
    virtual ControllerType GetType() = 0;
    virtual Status SetRumble(uint8_t strong_magnitude, uint8_t weak_magnitude) = 0;
};