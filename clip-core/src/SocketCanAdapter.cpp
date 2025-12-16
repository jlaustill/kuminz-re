#include "clip/SocketCanAdapter.h"

#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>

SocketCanAdapter::SocketCanAdapter()
    : m_socket(-1)
    , m_isOpen(false)
{
}

SocketCanAdapter::~SocketCanAdapter()
{
    close();
}

bool SocketCanAdapter::open(const std::string& device)
{
    if (m_isOpen) {
        close();
    }

    m_deviceName = device;

    // Create socket
    m_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (m_socket < 0) {
        return false;
    }

    // Get interface index
    struct ifreq ifr;
    std::memset(&ifr, 0, sizeof(ifr));
    std::strncpy(ifr.ifr_name, device.c_str(), IFNAMSIZ - 1);

    if (ioctl(m_socket, SIOCGIFINDEX, &ifr) < 0) {
        ::close(m_socket);
        m_socket = -1;
        return false;
    }

    // Bind socket to CAN interface
    struct sockaddr_can addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(m_socket, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr)) < 0) {
        ::close(m_socket);
        m_socket = -1;
        return false;
    }

    m_isOpen = true;
    return true;
}

void SocketCanAdapter::close()
{
    if (m_socket >= 0) {
        ::close(m_socket);
        m_socket = -1;
    }
    m_isOpen = false;
    m_deviceName.clear();
}

bool SocketCanAdapter::isOpen() const
{
    return m_isOpen;
}

bool SocketCanAdapter::send(uint32_t arbId, const uint8_t* data, uint8_t len)
{
    if (!m_isOpen || len > 8) {
        return false;
    }

    struct can_frame frame;
    std::memset(&frame, 0, sizeof(frame));

    // Set extended frame flag for 29-bit IDs
    frame.can_id = arbId | CAN_EFF_FLAG;
    frame.can_dlc = len;

    if (data && len > 0) {
        std::memcpy(frame.data, data, len);
    }

    ssize_t nbytes = write(m_socket, &frame, sizeof(frame));
    return nbytes == sizeof(frame);
}

bool SocketCanAdapter::recv(uint32_t& arbId, uint8_t* data, uint8_t& len, int timeoutMs)
{
    if (!m_isOpen) {
        return false;
    }

    // Set up timeout using select()
    if (timeoutMs >= 0) {
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(m_socket, &readfds);

        struct timeval tv;
        tv.tv_sec = timeoutMs / 1000;
        tv.tv_usec = (timeoutMs % 1000) * 1000;

        int ret = select(m_socket + 1, &readfds, nullptr, nullptr, &tv);
        if (ret <= 0) {
            // Timeout or error
            return false;
        }
    }

    struct can_frame frame;
    ssize_t nbytes = read(m_socket, &frame, sizeof(frame));

    if (nbytes != sizeof(frame)) {
        return false;
    }

    // Extract arbitration ID (remove flags)
    arbId = frame.can_id & CAN_EFF_MASK;
    len = frame.can_dlc;

    if (data && len > 0) {
        std::memcpy(data, frame.data, len);
    }

    return true;
}

bool SocketCanAdapter::setBitrate(uint32_t bitrate)
{
    // On Linux, bitrate is set via 'ip link' command before opening the socket
    // We can't change it while the interface is up
    // This would require:
    //   ip link set can0 down
    //   ip link set can0 type can bitrate 250000
    //   ip link set can0 up

    // For now, just return true if we're not open
    // Real implementation would use netlink or subprocess
    (void)bitrate;
    return !m_isOpen;
}

const std::string& SocketCanAdapter::getDeviceName() const
{
    return m_deviceName;
}

bool SocketCanAdapter::setFilter(uint32_t arbId, uint32_t mask)
{
    if (!m_isOpen) {
        return false;
    }

    struct can_filter filter;
    filter.can_id = arbId | CAN_EFF_FLAG;  // Extended frame
    filter.can_mask = mask | CAN_EFF_FLAG;

    if (setsockopt(m_socket, SOL_CAN_RAW, CAN_RAW_FILTER, &filter, sizeof(filter)) < 0) {
        return false;
    }

    return true;
}
