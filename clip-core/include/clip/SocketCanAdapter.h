#ifndef SOCKETCANADAPTER_H
#define SOCKETCANADAPTER_H

#include "ICanAdapter.h"

/**
 * @brief Linux SocketCAN implementation of ICanAdapter.
 *
 * Uses the SocketCAN interface for CAN bus communication on Linux.
 * Requires the 'can-utils' package and appropriate kernel modules.
 *
 * Setup commands:
 *   sudo modprobe can
 *   sudo modprobe can_raw
 *   sudo modprobe vcan  (for virtual CAN)
 *
 * For physical CAN:
 *   sudo ip link set can0 type can bitrate 250000
 *   sudo ip link set can0 up
 *
 * For virtual CAN (testing):
 *   sudo ip link add dev vcan0 type vcan
 *   sudo ip link set vcan0 up
 */
class SocketCanAdapter : public ICanAdapter
{
public:
    SocketCanAdapter();
    ~SocketCanAdapter() override;

    // Prevent copying
    SocketCanAdapter(const SocketCanAdapter&) = delete;
    SocketCanAdapter& operator=(const SocketCanAdapter&) = delete;

    /**
     * @brief Open a connection to the CAN device.
     * @param device Device name (e.g., "can0", "vcan0")
     * @return true if connection successful
     */
    bool open(const std::string& device) override;

    /**
     * @brief Close the CAN device connection.
     */
    void close() override;

    /**
     * @brief Check if the adapter is currently connected.
     */
    bool isOpen() const override;

    /**
     * @brief Send a CAN frame.
     * @param arbId 29-bit arbitration ID (extended frame)
     * @param data Pointer to data bytes (max 8 bytes)
     * @param len Number of data bytes (0-8)
     * @return true if sent successfully
     */
    bool send(uint32_t arbId, const uint8_t* data, uint8_t len) override;

    /**
     * @brief Receive a CAN frame with timeout.
     * @param arbId Output: arbitration ID of received frame
     * @param data Output: buffer for received data (must be at least 8 bytes)
     * @param len Output: number of data bytes received
     * @param timeoutMs Timeout in milliseconds (0 = non-blocking, -1 = infinite)
     * @return true if frame received, false on timeout or error
     */
    bool recv(uint32_t& arbId, uint8_t* data, uint8_t& len, int timeoutMs) override;

    /**
     * @brief Set CAN bus bitrate.
     *
     * Note: On SocketCAN, bitrate is set via 'ip link' command, not through
     * the socket. This method is provided for interface compatibility but
     * may not work on already-up interfaces.
     *
     * @param bitrate Bitrate in bits/second (e.g., 250000 for J1939)
     * @return true if bitrate set successfully
     */
    bool setBitrate(uint32_t bitrate) override;

    /**
     * @brief Get the device name.
     */
    const std::string& getDeviceName() const;

    /**
     * @brief Set receive filter for specific arbitration ID.
     * @param arbId Arbitration ID to filter (0 = accept all)
     * @param mask Mask for filtering (0 = accept all)
     * @return true if filter set successfully
     */
    bool setFilter(uint32_t arbId, uint32_t mask);

private:
    int m_socket;
    std::string m_deviceName;
    bool m_isOpen;
};

#endif // SOCKETCANADAPTER_H
