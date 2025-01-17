#pragma once
#include "IUSBEndpoint.h"
#include "switch.h"
#include <memory>

class SwitchUSBEndpoint : public IUSBEndpoint
{
private:
    UsbHsClientEpSession m_epSession{};
    UsbHsClientIfSession *m_ifSession;
    usb_endpoint_descriptor *m_descriptor;

    void *m_buffer;

public:
    //Pass the necessary information to be able to open the endpoint
    SwitchUSBEndpoint(UsbHsClientIfSession &if_session, usb_endpoint_descriptor &desc);
    ~SwitchUSBEndpoint();

    //Open and close the endpoint
    virtual Result Open();
    virtual void Close();

    //buffer should point to the data array, and only the specified size will be read.
    virtual Result Write(void *inBuffer, size_t bufferSize);

    //The data received will be put in the outBuffer array for the length of the specified size.
    virtual Result Read(void *outBuffer, size_t bufferSize);

    //Gets the direction of this endpoint (IN or OUT)
    virtual IUSBEndpoint::Direction GetDirection();

    //get the endpoint descriptor
    virtual IUSBEndpoint::EndpointDescriptor *GetDescriptor();

    // Get the current EpSession (after it was opened)
    inline UsbHsClientEpSession &GetSession() { return m_epSession; }
};