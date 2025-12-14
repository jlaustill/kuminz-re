#ifndef SOCKETCANADAPTER_H
#define SOCKETCANADAPTER_H

#include "ICanAdapter.h"
#include <functional>

/**
 * Linux SocketCAN implementation of ICanAdapter.
 * Provides direct access to CAN interfaces via the kernel's SocketCAN subsystem.
 */
class SocketCanAdapter : public ICanAdapter
{
public:
    using LogCallback = std::function<void(const std::string&)>;

    SocketCanAdapter();
    ~SocketCanAdapter() override;

    // ICanAdapter interface
    bool open(const std::string& interface) override;
    void close() override;
    bool isOpen() const override;
    bool send(uint32_t arbId, const uint8_t* data, uint8_t len) override;
    bool recv(uint32_t& arbId, uint8_t* data, uint8_t& len, int timeoutMs) override;

    /**
     * Set logging callback for verbose output
     */
    void setLogCallback(LogCallback callback);

private:
    void log(const std::string& msg);
    std::string formatFrame(const char* prefix, uint32_t arbId, const uint8_t* data, uint8_t len);

    int m_socket;
    std::string m_interface;
    LogCallback m_logCallback;
};

#endif // SOCKETCANADAPTER_H
