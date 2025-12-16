#include "../can/SocketCanAdapter.h"
#include "../j1939/J1939.h"
#include "../j1939/J1939TP.h"
#include "../clip/Frame.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <csignal>
#include <fstream>

// Global flag for clean shutdown
volatile bool g_running = true;

void signalHandler(int)
{
    g_running = false;
}

void printUsage(const char* progname)
{
    std::cerr << "CLIP Protocol Test Tool\n\n";
    std::cerr << "Usage:\n";
    std::cerr << "  " << progname << " <interface> [ecu-address]\n";
    std::cerr << "  " << progname << " <interface> --monitor\n";
    std::cerr << "  " << progname << " <interface> --raw <hex-bytes>\n";
    std::cerr << "  " << progname << " <interface> --read <address> [length]\n";
    std::cerr << "  " << progname << " <interface> --j1939 <pgn> [ecu-address]\n";
    std::cerr << "  " << progname << " <interface> --cm550-param [cmd] [guard]\n";
    std::cerr << "  " << progname << " <interface> --cm550-status [type]\n";
    std::cerr << "  " << progname << " <interface> --cm550-raw <hex-bytes>\n\n";
    std::cerr << "Examples:\n";
    std::cerr << "  " << progname << " can0           # Connect to ECU at address 0x00\n";
    std::cerr << "  " << progname << " can0 0         # Same as above\n";
    std::cerr << "  " << progname << " can0 --monitor # Just monitor CAN traffic\n";
    std::cerr << "  " << progname << " can0 --raw 020100010000 # Send raw bytes\n";
    std::cerr << "  " << progname << " can0 --read 0x800000 16 # Read 16 bytes from RAM\n";
    std::cerr << "  " << progname << " can0 --j1939 0xFECA     # Request J1939 PGN with TP support\n";
    std::cerr << "  " << progname << " can0 --j1939 0xFEE5     # Request Engine Hours\n\n";
    std::cerr << "CM550-Specific Commands (dispatcher format - byte[0] routing):\n";
    std::cerr << "  " << progname << " can0 --cm550-param       # Send 0x11 ParamRequest\n";
    std::cerr << "  " << progname << " can0 --cm550-param 0x00  # ParamRequest with cmd=0x00\n";
    std::cerr << "  " << progname << " can0 --cm550-status      # Send 0x13 StatusRequest\n";
    std::cerr << "  " << progname << " can0 --cm550-raw 11000100000000 # Raw 8-byte frame\n\n";
    std::cerr << "DPA Frame Format Commands (from decompiled Insite dpas32_ghidra.c):\n";
    std::cerr << "  " << progname << " can0 --dpa-init          # Send DPA QueryInitialize (0x80 sync)\n";
    std::cerr << "  " << progname << " can0 --dpa-param [id]    # Send DPA GetParametersByID (0x10)\n";
    std::cerr << "  " << progname << " can0 --dpa-data [addr]   # Send DPA GetDataByAddress (0x13)\n";
    std::cerr << "  " << progname << " can0 --dpa-test          # Run all DPA frame format tests\n\n";
    std::cerr << "Direct Service ID Commands (PGN 0xEF00 - NO DPA wrapper):\n";
    std::cerr << "  " << progname << " can0 --svc-test          # Test all 23 registered service IDs\n";
    std::cerr << "  " << progname << " can0 --svc <id>          # Test specific service ID (hex)\n";
    std::cerr << "  " << progname << " can0 --svc 0x10          # Test GetParametersByID\n";
    std::cerr << "  " << progname << " can0 --svc 0x15          # Test GetAddressByParameterID\n";
    std::cerr << "  " << progname << " can0 --svc-4b            # Test 0x4B with TP flow control\n";
    std::cerr << "  " << progname << " can0 --svc-49            # Test 0x49 with TP flow control (triggers RTS!)\n";
    std::cerr << "  " << progname << " can0 --svc-49-ram [addr] [len]  # Test 0x49 with valid RAM addr (default: 0x800000, 16)\n";
    std::cerr << "  " << progname << " can0 --svc-4a [addr] [len]     # Test 0x4A (4-byte addr + 1-byte len) - fits 8 bytes!\n";
    std::cerr << "  " << progname << " can0 --dump-ram [file]         # Dump full RAM (0x800000-0x8091C2) to file\n";
}

void printFrame(uint32_t arbId, const uint8_t* data, uint8_t len)
{
    uint8_t pf = J1939::extractPF(arbId);
    uint8_t dest = J1939::extractDest(arbId);
    uint8_t source = J1939::extractSource(arbId);

    // Highlight frames addressed TO US
    bool toUs = (dest == J1939::TOOL_ADDRESS);

    // Check if it's a CLIP/Proprietary A frame (PF=0xEF)
    if (pf == J1939::CLIP_PF_DATA) {
        Clip::Frame frame;
        if (frame.decode(data, len)) {
            std::cout << "     ^ CLIP " << Clip::Frame::describeMsgType(frame.msgType);
            std::cout << " sess=" << static_cast<int>(frame.sessionId);
            std::cout << " conn=0x" << std::hex << static_cast<int>(frame.connectionId);
            std::cout << " ctrl=" << Clip::Frame::describeControl(frame.control);
            if (toUs) {
                std::cout << " [FROM ECU 0x" << std::hex << static_cast<int>(source) << "]";
            }
            std::cout << std::dec << "\n";

            // If it's a session open response (CM550 uses 0x0D, Insite expects 0x02)
            if (frame.getMsgType() == Clip::MsgType::SessionOpenResponse ||
                frame.getMsgType() == Clip::MsgType::TransportOpen) {

                // Check control byte for seed reply
                if (frame.control == static_cast<uint8_t>(Clip::ControlType::SeedReply)) {
                    std::cout << "     ^ *** SESSION ACCEPTED - SEED REPLY ***\n";
                    std::cout << "     ^ ECU Connection ID: 0x" << std::hex
                              << static_cast<int>(frame.connectionId) << std::dec << "\n";

                    if (frame.payloadLen >= 4) {
                        std::cout << "     ^ Seed: ";
                        for (int i = 0; i < 4 && i < frame.payloadLen; i++) {
                            std::cout << std::hex << std::setfill('0') << std::setw(2);
                            std::cout << static_cast<int>(frame.payload[i]);
                        }
                        std::cout << std::dec << "\n";

                        // Check if seed is all 0xFF (no security required?)
                        bool allFF = true;
                        for (int i = 0; i < 4 && i < frame.payloadLen; i++) {
                            if (frame.payload[i] != 0xFF) allFF = false;
                        }
                        if (allFF) {
                            std::cout << "     ^ NOTE: Seed is all 0xFF - may indicate no security required\n";
                        }
                    }
                }
            }
        }
    } else if (pf == J1939::J1939_PF_ACK && toUs) {
        // J1939 Acknowledgment TO US - this is important!
        std::cout << "     ^ *** J1939 ACK/NACK from ECU 0x" << std::hex << static_cast<int>(source) << " ***\n";
        std::cout << "     ^ Control: 0x" << std::hex << static_cast<int>(data[0]);
        switch (data[0]) {
            case 0x00: std::cout << " (Positive ACK)"; break;
            case 0x01: std::cout << " (Negative ACK - Not Supported)"; break;
            case 0x02: std::cout << " (Access Denied)"; break;
            case 0x03: std::cout << " (Cannot Respond)"; break;
            default: std::cout << " (Unknown)"; break;
        }
        std::cout << "\n";
        // Bytes 5-7 contain the PGN being acknowledged
        if (len >= 8) {
            uint32_t ackPgn = data[5] | (static_cast<uint32_t>(data[6]) << 8) | (static_cast<uint32_t>(data[7]) << 16);
            std::cout << "     ^ Acknowledged PGN: 0x" << std::hex << ackPgn << std::dec << "\n";
        }
    } else if (toUs) {
        // Any other frame addressed to us
        std::cout << "     ^ *** ADDRESSED TO US *** " << J1939::describeMessage(arbId) << "\n";
    } else {
        // Other J1939 traffic
        std::cout << "     ^ " << J1939::describeMessage(arbId) << "\n";
    }
}

int monitorMode(SocketCanAdapter& adapter)
{
    std::cout << "\n[INFO] Monitor mode - press Ctrl+C to exit\n\n";

    uint32_t arbId;
    uint8_t data[8];
    uint8_t len;

    while (g_running) {
        if (adapter.recv(arbId, data, len, 100)) {
            printFrame(arbId, data, len);
        }
    }

    return 0;
}

int connectMode(SocketCanAdapter& adapter, uint8_t ecuAddress)
{
    std::cout << "\n[INFO] Attempting CLIP session to ECU 0x"
              << std::hex << std::setfill('0') << std::setw(2)
              << static_cast<int>(ecuAddress) << "\n\n";

    // Build session open frame
    Clip::Frame openFrame = Clip::buildSessionOpen(0x01, 0x00);

    // Encode to CAN data
    uint8_t txData[8];
    uint8_t txLen = openFrame.encode(txData);

    // Build arbitration ID
    uint32_t txArbId = J1939::buildClipRequestId(ecuAddress);

    // Send the session open
    std::cout << "[INFO] Sending CLIP session open...\n";
    if (!adapter.send(txArbId, txData, txLen)) {
        std::cerr << "[ERROR] Failed to send frame\n";
        return 1;
    }

    std::cout << "     ^ " << Clip::Frame::describeMsgType(openFrame.msgType) << "\n";

    // Wait for response, showing all traffic
    std::cout << "\n[INFO] Waiting for response (showing all CAN traffic)...\n";
    std::cout << "[INFO] Looking for CLIP response on Proprietary A (PF=0xEF) from ECU 0x"
              << std::hex << static_cast<int>(ecuAddress) << "\n";
    std::cout << "[INFO] Expected response arbId: 0x" << std::hex
              << J1939::buildClipResponseId(ecuAddress) << "\n\n";

    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;

    int timeoutMs = 5000;  // 5 second total timeout
    int elapsed = 0;
    bool gotResponse = false;

    while (elapsed < timeoutMs && g_running) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            printFrame(arbId, rxData, rxLen);

            // Check if this is a CLIP response from our ECU (PF=0xEF, addressed to us)
            uint8_t rxPf = J1939::extractPF(arbId);
            uint8_t rxDest = J1939::extractDest(arbId);
            uint8_t rxSource = J1939::extractSource(arbId);

            if (rxPf == J1939::CLIP_PF_DATA && rxDest == J1939::TOOL_ADDRESS) {
                if (rxSource == ecuAddress) {
                    std::cout << "\n[SUCCESS] Got CLIP response from ECU!\n";
                    gotResponse = true;

                    // Decode and show details
                    Clip::Frame respFrame;
                    if (respFrame.decode(rxData, rxLen)) {
                        std::cout << "[INFO] " << respFrame.toString() << "\n";

                        // Check response type
                        if (respFrame.getMsgType() == Clip::MsgType::SessionOpenResponse ||
                            respFrame.getMsgType() == Clip::MsgType::TransportOpen) {

                            if (respFrame.control == static_cast<uint8_t>(Clip::ControlType::SeedReply)) {
                                std::cout << "\n[SUCCESS] Session established! ECU sent seed reply.\n";
                                std::cout << "[INFO] ECU assigned connection ID: 0x"
                                          << std::hex << static_cast<int>(respFrame.connectionId)
                                          << std::dec << "\n";
                                std::cout << "[INFO] Next step: Send key response to complete authentication\n";
                            }
                        } else if (respFrame.getMsgType() == Clip::MsgType::ConnectionRefused) {
                            std::cout << "\n[ERROR] ECU refused connection!\n";
                        }
                    }
                    break;
                } else {
                    std::cout << "     ^ (from different ECU, expected 0x"
                              << std::hex << static_cast<int>(ecuAddress)
                              << ", got 0x" << static_cast<int>(rxSource) << ")\n";
                }
            }
        }
        elapsed += 100;
    }

    if (!gotResponse && g_running) {
        std::cout << "\n[TIMEOUT] No CLIP response received after "
                  << std::dec << (timeoutMs / 1000) << " seconds\n";
        std::cout << "\n[DEBUG] Possible issues:\n";
        std::cout << "  - ECU might not support CLIP protocol on Proprietary A (PF=0xEF)\n";
        std::cout << "  - ECU might be at a different address (try --monitor to find it)\n";
        std::cout << "  - CLIP frame format might be incorrect for this ECU\n";
        std::cout << "  - ECU might need specific initialization sequence\n";
        return 1;
    }

    return 0;
}

int rawMode(SocketCanAdapter& adapter, uint8_t ecuAddress, const std::string& hexBytes)
{
    std::cout << "\n[INFO] Sending raw bytes to ECU 0x"
              << std::hex << std::setfill('0') << std::setw(2)
              << static_cast<int>(ecuAddress) << "\n\n";

    // Parse hex string into bytes
    std::vector<uint8_t> txData;
    for (size_t i = 0; i + 1 < hexBytes.size(); i += 2) {
        std::string byteStr = hexBytes.substr(i, 2);
        char* endptr;
        long val = std::strtol(byteStr.c_str(), &endptr, 16);
        if (*endptr != '\0') {
            std::cerr << "[ERROR] Invalid hex byte: " << byteStr << "\n";
            return 1;
        }
        txData.push_back(static_cast<uint8_t>(val));
    }

    if (txData.empty() || txData.size() > 8) {
        std::cerr << "[ERROR] Need 1-8 bytes, got " << txData.size() << "\n";
        return 1;
    }

    // Build arbitration ID (PF=0xEF Proprietary A)
    uint32_t txArbId = J1939::buildClipRequestId(ecuAddress);

    // Send the raw data
    std::cout << "[INFO] Sending raw message...\n";
    if (!adapter.send(txArbId, txData.data(), static_cast<uint8_t>(txData.size()))) {
        std::cerr << "[ERROR] Failed to send frame\n";
        return 1;
    }

    // Decode as CLIP frame for display
    if (txData.size() >= 3) {
        std::cout << "     ^ Decoded: sess=" << static_cast<int>((txData[0] >> 5) & 0x07);
        std::cout << " type=0x" << std::hex << static_cast<int>(txData[0] & 0x1F);
        std::cout << " conn=0x" << std::hex << static_cast<int>(txData[1]);
        std::cout << " ctrl=0x" << std::hex << static_cast<int>(txData[2]);
        std::cout << "\n";
    }

    // Wait for response
    std::cout << "\n[INFO] Waiting for response...\n\n";

    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;

    int timeoutMs = 3000;
    int elapsed = 0;

    while (elapsed < timeoutMs && g_running) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            printFrame(arbId, rxData, rxLen);

            // Check if addressed to us
            uint8_t rxPf = J1939::extractPF(arbId);
            uint8_t rxDest = J1939::extractDest(arbId);
            if (rxPf == J1939::CLIP_PF_DATA && rxDest == J1939::TOOL_ADDRESS) {
                std::cout << "\n[SUCCESS] Got response from ECU!\n";
                // Show raw hex for analysis
                std::cout << "[RAW] ";
                for (int i = 0; i < rxLen; i++) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(rxData[i]) << " ";
                }
                std::cout << "\n";
                break;
            }
        }
        elapsed += 100;
    }

    return 0;
}

int readMode(SocketCanAdapter& adapter, uint8_t ecuAddress, uint32_t address, uint16_t length)
{
    std::cout << "\n[INFO] Memory read from ECU 0x"
              << std::hex << std::setfill('0') << std::setw(2)
              << static_cast<int>(ecuAddress) << "\n";
    std::cout << "[INFO] Address: 0x" << std::hex << address
              << " Length: " << std::dec << length << " bytes\n\n";

    uint32_t txArbId = J1939::buildClipRequestId(ecuAddress);
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    uint8_t txData[8];

    // ============================================================
    // STEP 1: Open CLIP Session
    // ============================================================
    std::cout << "[STEP 1] Opening CLIP session...\n";

    Clip::Frame openFrame = Clip::buildSessionOpen(0x01, 0x00);
    uint8_t txLen = openFrame.encode(txData);

    if (!adapter.send(txArbId, txData, txLen)) {
        std::cerr << "[ERROR] Failed to send session open\n";
        return 1;
    }
    std::cout << "[TX] Session open: ";
    for (int i = 0; i < txLen; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(txData[i]) << " ";
    }
    std::cout << "\n";

    // Wait for session response
    // Two possible response formats:
    // 1. Old format (incorrect 0x02 request): 0x0D [connId] 0x02 [seed...] (SeedReply)
    // 2. New format (correct 0x01 request): 0x0C [connId] 0xFF ... (Success)
    uint8_t ecuConnectionId = 0x01;  // Default to our requested ID
    uint8_t encryptionLevel1 = 0;
    uint8_t encryptionLevel2 = 0;
    uint8_t seed[4] = {0};
    bool gotSessionResponse = false;

    int timeoutMs = 3000;
    int elapsed = 0;

    while (elapsed < timeoutMs && g_running && !gotSessionResponse) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t rxPf = J1939::extractPF(arbId);
            uint8_t rxDest = J1939::extractDest(arbId);
            uint8_t rxSource = J1939::extractSource(arbId);

            if (rxPf == J1939::CLIP_PF_DATA && rxDest == J1939::TOOL_ADDRESS && rxSource == ecuAddress) {
                std::cout << "[RX] ";
                for (int i = 0; i < rxLen; i++) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(rxData[i]) << " ";
                }
                std::cout << "\n";

                Clip::Frame respFrame;
                if (respFrame.decode(rxData, rxLen)) {
                    // Check for SUCCESS response (0x0C) - ECU accepts session
                    if (respFrame.msgType == 0x0C) {
                        ecuConnectionId = respFrame.connectionId;
                        gotSessionResponse = true;
                        std::cout << "[INFO] Got Session SUCCESS (0x0C)!\n";
                        std::cout << "       Connection ID: 0x" << std::hex
                                  << static_cast<int>(ecuConnectionId) << "\n";
                        std::cout << "       No seed required (session accepted)\n";
                    }
                    // Check for SeedReply (control byte = 0x02) - old format
                    else if (respFrame.control == static_cast<uint8_t>(Clip::ControlType::SeedReply)) {
                        ecuConnectionId = respFrame.connectionId;
                        // Parse seed data from payload
                        // Payload: [encLevel1][encLevel2][seed0][seed1][seed2] (5 bytes)
                        if (respFrame.payloadLen >= 2) {
                            encryptionLevel1 = respFrame.payload[0];
                            encryptionLevel2 = respFrame.payload[1];
                        }
                        if (respFrame.payloadLen >= 5) {
                            seed[0] = respFrame.payload[2];
                            seed[1] = respFrame.payload[3];
                            seed[2] = respFrame.payload[4];
                            seed[3] = 0xFF;
                        }
                        gotSessionResponse = true;
                        std::cout << "[INFO] Got SeedReply!\n";
                        std::cout << "       ECU Connection ID: 0x" << std::hex
                                  << static_cast<int>(ecuConnectionId) << "\n";
                        std::cout << "       Encryption Level 1: 0x" << std::hex
                                  << static_cast<int>(encryptionLevel1) << "\n";
                        std::cout << "       Encryption Level 2: 0x" << std::hex
                                  << static_cast<int>(encryptionLevel2) << "\n";
                        std::cout << "       Seed: " << std::hex;
                        for (int i = 0; i < 4; i++) {
                            std::cout << std::setfill('0') << std::setw(2)
                                      << static_cast<int>(seed[i]);
                        }
                        std::cout << std::dec << "\n";

                        if (encryptionLevel1 == 0xFF && encryptionLevel2 == 0xFF) {
                            std::cout << "       NOTE: 0xFF levels may indicate no encryption needed\n";
                        }
                    }
                    // Check for SessionOpenResponse (0x0D) - CM550 variant with SeedReply embedded
                    else if (respFrame.msgType == 0x0D) {
                        ecuConnectionId = respFrame.connectionId;
                        if (respFrame.control == 0x02) {  // Embedded SeedReply
                            if (respFrame.payloadLen >= 2) {
                                encryptionLevel1 = respFrame.payload[0];
                                encryptionLevel2 = respFrame.payload[1];
                            }
                        }
                        gotSessionResponse = true;
                        std::cout << "[INFO] Got SessionOpenResponse (0x0D)!\n";
                        std::cout << "       ECU Connection ID: 0x" << std::hex
                                  << static_cast<int>(ecuConnectionId) << "\n";
                    }
                }
            }
        }
        elapsed += 100;
    }

    if (!gotSessionResponse) {
        std::cerr << "[ERROR] Did not receive session response\n";
        return 1;
    }

    // ============================================================
    // STEP 2: Send Context Request
    // From Insite: After SeedReply, send DataTransfer with [0x01][0x03][context]
    // ============================================================
    std::cout << "\n[STEP 2] Sending context request (0x01 0x03)...\n";

    // Try multiple context request formats
    uint8_t localConnectionId = 0x01;  // Our local connection ID

    // Context request format A: Simple [0x01][0x03] with zeros
    uint8_t contextReq[8];
    contextReq[0] = (0 << 5) | 0x03;      // sequence 0, DataTransfer
    contextReq[1] = localConnectionId;     // OUR local connection ID
    contextReq[2] = 0x00;                  // Control = 0 (no special flags)
    contextReq[3] = 0x01;                  // Context header byte 0
    contextReq[4] = 0x03;                  // Context header byte 1
    contextReq[5] = 0x00;                  // Minimal context (no encryption)
    contextReq[6] = 0x00;
    contextReq[7] = 0x00;

    std::cout << "[TX] Context request A (ctrl=0x00): ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(contextReq[i]) << " ";
    }
    std::cout << "\n";

    adapter.send(txArbId, contextReq, 8);
    usleep(200000);

    // Collect any response
    bool gotContextReply = false;
    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }

            Clip::Frame respFrame;
            if (respFrame.decode(rxData, rxLen)) {
                if (respFrame.control == static_cast<uint8_t>(Clip::ControlType::ContextReply)) {
                    gotContextReply = true;
                    std::cout << " <- ContextReply! Session ESTABLISHED";
                }
            }
            std::cout << "\n";
        }
    }

    // Try context request format B: Using ECU connection ID
    contextReq[1] = ecuConnectionId;
    std::cout << "[TX] Context request B (conn=ECU): ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(contextReq[i]) << " ";
    }
    std::cout << "\n";

    adapter.send(txArbId, contextReq, 8);
    usleep(200000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }

            Clip::Frame respFrame;
            if (respFrame.decode(rxData, rxLen)) {
                if (respFrame.control == static_cast<uint8_t>(Clip::ControlType::ContextReply)) {
                    gotContextReply = true;
                    std::cout << " <- ContextReply!";
                }
            }
            std::cout << "\n";
        }
    }

    // Try just sending CTS to see if that establishes session
    std::cout << "\n[STEP 2b] Trying CTS as alternative...\n";
    uint8_t ctsCmd[8];
    ctsCmd[0] = (0 << 5) | 0x04;  // sequence 0, ClearToSend
    ctsCmd[1] = ecuConnectionId;  // ECU's assigned connection ID
    ctsCmd[2] = 0x01;             // Control: Ready
    ctsCmd[3] = 0x01;             // Number of packets we can receive
    ctsCmd[4] = 0x00;
    ctsCmd[5] = 0x00;
    ctsCmd[6] = 0x00;
    ctsCmd[7] = 0x00;

    std::cout << "[TX] CTS: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(ctsCmd[i]) << " ";
    }
    std::cout << "\n";

    adapter.send(txArbId, ctsCmd, 8);
    usleep(200000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            Clip::Frame respFrame;
            if (respFrame.decode(rxData, rxLen)) {
                if (respFrame.control == static_cast<uint8_t>(Clip::ControlType::ContextReply)) {
                    gotContextReply = true;
                    std::cout << " <- ContextReply! Session ESTABLISHED";
                }
            }
            std::cout << "\n";
        }
    }

    if (gotContextReply) {
        std::cout << "\n[SUCCESS] Session ESTABLISHED via context exchange!\n";
    } else {
        std::cout << "\n[INFO] No ContextReply received, session may not be fully established\n";
    }

    // ============================================================
    // STEP 3: Send Service 5 Memory Read Command
    // From CM550 firmware diagnosticCommandDispatcher @ 0x12484:
    //   - Byte 2 (control) = Service number (5)
    //   - Byte 3 (payload[0]) = Command code (0xC0 = MemoryRead2)
    //   - Bytes 4-6 (payload[1-3]) = 24-bit address (big-endian)
    //   - Byte 7 (payload[4]) = Length to read
    // ============================================================
    std::cout << "\n[STEP 3] Sending Service 5 Memory Read Command...\n";
    std::cout << "[INFO] Address: 0x" << std::hex << std::setfill('0') << std::setw(6) << address
              << " Length: " << std::dec << length << " bytes\n";

    // Test different Service 5 memory read command types
    Clip::Service5Cmd cmdTypes[] = {
        Clip::Service5Cmd::MemoryRead2,  // 0xC0 - Most common
        Clip::Service5Cmd::MemoryRead1,  // 0xE0
        Clip::Service5Cmd::MemoryRead3,  // 0x60
    };
    const char* cmdNames[] = {"MemoryRead2 (0xC0)", "MemoryRead1 (0xE0)", "MemoryRead3 (0x60)"};

    for (int testIdx = 0; testIdx < 3; testIdx++) {
        std::cout << "\n[TEST " << static_cast<char>('A' + testIdx) << "] " << cmdNames[testIdx] << "...\n";

        // Build the frame using our new helper function
        Clip::Frame memReadFrame = Clip::buildMemoryReadRequest(
            ecuConnectionId,        // Connection ID from session open (0x18)
            address,                // 24-bit memory address
            static_cast<uint8_t>(length),  // Bytes to read
            0,                      // Session ID
            cmdTypes[testIdx]       // Command type
        );

        // Encode to CAN frame
        uint8_t txData[8];
        uint8_t txLen = memReadFrame.encode(txData);

        std::cout << "[TX] " << memReadFrame.toString() << "\n";
        std::cout << "     Raw: ";
        for (int i = 0; i < txLen; i++) {
            std::cout << std::hex << std::setfill('0') << std::setw(2)
                      << static_cast<int>(txData[i]) << " ";
        }
        std::cout << "\n";
        std::cout << "     Decoded: type=0x" << std::hex << static_cast<int>(memReadFrame.msgType)
                  << " conn=0x" << static_cast<int>(memReadFrame.connectionId)
                  << " ctrl=0x" << static_cast<int>(memReadFrame.control)
                  << " cmd=" << Clip::describeService5Cmd(memReadFrame.payload[0])
                  << " addr=0x" << std::setw(2) << static_cast<int>(memReadFrame.payload[1])
                  << std::setw(2) << static_cast<int>(memReadFrame.payload[2])
                  << std::setw(2) << static_cast<int>(memReadFrame.payload[3])
                  << " len=" << std::dec << static_cast<int>(memReadFrame.payload[4]) << "\n";

        adapter.send(txArbId, txData, txLen);
        usleep(300000);  // 300ms wait for response

        // Collect responses
        bool gotResponse = false;
        while (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t rxPf = J1939::extractPF(arbId);
            uint8_t rxSource = J1939::extractSource(arbId);
            if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
                gotResponse = true;
                std::cout << "[RX] ";
                for (int i = 0; i < rxLen; i++) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(rxData[i]) << " ";
                }

                // Decode and analyze response
                Clip::Frame respFrame;
                if (respFrame.decode(rxData, rxLen)) {
                    std::cout << "\n     Decoded: " << Clip::Frame::describeMsgType(respFrame.msgType)
                              << " conn=0x" << std::hex << static_cast<int>(respFrame.connectionId)
                              << " ctrl=0x" << static_cast<int>(respFrame.control);

                    // Check if this is a data response (msgType 0x03 with matching service)
                    if (respFrame.msgType == 0x03 && respFrame.control == 0x05) {
                        std::cout << " <- Service 5 Response!";
                        std::cout << "\n     Payload data: ";
                        for (int i = 0; i < respFrame.payloadLen; i++) {
                            std::cout << std::hex << std::setfill('0') << std::setw(2)
                                      << static_cast<int>(respFrame.payload[i]) << " ";
                        }
                    }
                    // Check for error response (0x0C or other)
                    else if (respFrame.msgType == 0x0C || respFrame.msgType == 0x05) {
                        std::cout << " <- Error/Refused response";
                    }
                }
                std::cout << std::dec << "\n";
            }
        }

        if (!gotResponse) {
            std::cout << "[INFO] No response received for " << cmdNames[testIdx] << "\n";
        }
    }

    // ============================================================
    // TEST D: Multi-Packet Receive (0xB0) - For larger reads
    // From multiPacketReceiveHandler @ 0x12d76
    // ============================================================
    std::cout << "\n[TEST D] Multi-Packet Receive (0xB0) command...\n";
    Clip::Frame multiPktFrame = Clip::buildMultiPacketReceiveRequest(ecuConnectionId, 0);

    uint8_t mpTxData[8];
    uint8_t mpTxLen = multiPktFrame.encode(mpTxData);

    std::cout << "[TX] " << multiPktFrame.toString() << "\n";
    std::cout << "     Raw: ";
    for (int i = 0; i < mpTxLen; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(mpTxData[i]) << " ";
    }
    std::cout << "\n";

    adapter.send(txArbId, mpTxData, mpTxLen);
    usleep(500000);  // 500ms wait for multi-packet

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << std::dec << "\n";
        }
    }

    // ============================================================
    // TEST E: Try Service 4 init commands first (0x71, 0x73)
    // From firmware - Service 4 has init commands that might unlock Service 5
    // ============================================================
    std::cout << "\n[TEST E] Service 4 initialization commands...\n";

    // Service 4 command 0x71 (init)
    uint8_t svc4Init1[8] = {0x03, ecuConnectionId, 0x04, 0x71, 0x00, 0x00, 0x00, 0x00};
    std::cout << "[TX] Service 4 init (0x71): ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(svc4Init1[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, svc4Init1, 8);
    usleep(300000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << std::dec << "\n";
        }
    }

    // Service 4 command 0x73 (another init)
    uint8_t svc4Init2[8] = {0x03, ecuConnectionId, 0x04, 0x73, 0x00, 0x00, 0x00, 0x00};
    std::cout << "[TX] Service 4 init (0x73): ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(svc4Init2[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, svc4Init2, 8);
    usleep(300000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << std::dec << "\n";
        }
    }

    // Now retry Service 5 memory read
    std::cout << "\n[TEST E2] Service 5 after init...\n";
    Clip::Frame memReadAfterInit = Clip::buildMemoryReadRequest(
        ecuConnectionId, address, static_cast<uint8_t>(length), 0,
        Clip::Service5Cmd::MemoryRead2
    );
    uint8_t txDataInit[8];
    uint8_t txLenInit = memReadAfterInit.encode(txDataInit);
    std::cout << "[TX] " << memReadAfterInit.toString() << "\n";
    adapter.send(txArbId, txDataInit, txLenInit);
    usleep(300000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << std::dec << "\n";
        }
    }

    // ============================================================
    // TEST F: Try Service 5 with connection ID 0x18 (ECU's internal ID)
    // The error responses contain 0x18, which might be the required connId
    // ============================================================
    std::cout << "\n[TEST F] Service 5 with connection ID 0x18 (ECU internal ID)...\n";

    Clip::Frame memReadFrame18 = Clip::buildMemoryReadRequest(
        0x18,                       // Try ECU's internal connection ID
        address,
        static_cast<uint8_t>(length),
        0,
        Clip::Service5Cmd::MemoryRead2
    );

    uint8_t txData18[8];
    uint8_t txLen18 = memReadFrame18.encode(txData18);

    std::cout << "[TX] " << memReadFrame18.toString() << "\n";
    std::cout << "     Raw: ";
    for (int i = 0; i < txLen18; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(txData18[i]) << " ";
    }
    std::cout << "\n";

    adapter.send(txArbId, txData18, txLen18);
    usleep(500000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }

            Clip::Frame respFrame;
            if (respFrame.decode(rxData, rxLen)) {
                std::cout << "\n     Decoded: " << Clip::Frame::describeMsgType(respFrame.msgType)
                          << " conn=0x" << std::hex << static_cast<int>(respFrame.connectionId)
                          << " ctrl=0x" << static_cast<int>(respFrame.control);

                if (respFrame.msgType == 0x0C) {
                    std::cout << " <- SUCCESS!";
                    if (respFrame.payloadLen > 0) {
                        std::cout << "\n     Payload: ";
                        for (int i = 0; i < respFrame.payloadLen; i++) {
                            std::cout << std::hex << std::setfill('0') << std::setw(2)
                                      << static_cast<int>(respFrame.payload[i]) << " ";
                        }
                    }
                }
            }
            std::cout << std::dec << "\n";
        }
    }

    // ============================================================
    // TEST G: Try raw diagnostic format (no CLIP header) - like J1708 would send
    // Format: [len] [service] [cmd] [addr...] [length]
    // ============================================================
    std::cout << "\n[TEST G] Raw diagnostic format (J1708-style)...\n";

    uint8_t rawDiag[8] = {
        0x07,           // Message length
        0x05,           // Service 5
        0xC0,           // MemoryRead2 command
        static_cast<uint8_t>((address >> 16) & 0xFF),  // Addr high
        static_cast<uint8_t>((address >> 8) & 0xFF),   // Addr mid
        static_cast<uint8_t>(address & 0xFF),          // Addr low
        static_cast<uint8_t>(length),                  // Length
        0x00            // Padding
    };

    std::cout << "[TX] Raw diagnostic: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(rawDiag[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, rawDiag, 8);
    usleep(300000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << std::dec << "\n";
        }
    }

    // ============================================================
    // TEST H: Try broadcast destination (0xFF) instead of 0x00
    // ============================================================
    std::cout << "\n[TEST H] Broadcast destination (0xFF)...\n";

    // Build arb ID with destination 0xFF
    uint32_t broadcastArbId = (6 << 26) | (0xEF << 16) | (0xFF << 8) | J1939::TOOL_ADDRESS;

    Clip::Frame memReadBcast = Clip::buildMemoryReadRequest(
        ecuConnectionId, address, static_cast<uint8_t>(length), 0,
        Clip::Service5Cmd::MemoryRead2
    );
    uint8_t txDataBcast[8];
    uint8_t txLenBcast = memReadBcast.encode(txDataBcast);

    std::cout << "[TX] ArbId=0x" << std::hex << broadcastArbId << " Data: ";
    for (int i = 0; i < txLenBcast; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(txDataBcast[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(broadcastArbId, txDataBcast, txLenBcast);
    usleep(300000);

    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        // Accept from any source
        if (rxPf == J1939::CLIP_PF_DATA) {
            std::cout << "[RX] ArbId=0x" << std::hex << arbId << " Data: ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << std::dec << "\n";
        }
    }

    // ============================================================
    // Done with Service 5 tests - return here for --read mode
    // ============================================================
    std::cout << "\n[INFO] Service 5 memory read tests complete.\n";
    std::cout << "[INFO] Summary: Session established, but Service 5 commands return 0x0D status.\n";
    std::cout << "[INFO] \n";
    std::cout << "[INFO] NEXT STEP: Capture real Insite traffic to compare formats:\n";
    std::cout << "[INFO]   1. Run: candump can0 -L > insite_capture.log\n";
    std::cout << "[INFO]   2. Connect Insite to ECU and read a parameter\n";
    std::cout << "[INFO]   3. Compare captured traffic to our format\n";
    return 0;

    // TEST F: Try real J1939 engine PGNs via Request PGN (0xEA)
    // The ECU responds properly to J1939 Request - let's try actual engine PGNs
    std::cout << "\n[TEST F] Request REAL J1939 engine PGNs...\n";
    uint32_t requestPgn = J1939::buildRequestId(ecuAddress);

    // List of real J1939 engine PGNs to try (comprehensive list for CM550)
    struct PgnInfo {
        uint32_t pgn;
        const char* name;
    };
    PgnInfo testPgns[] = {
        // Electronic Engine Controllers
        {0x00F004, "EEC1 - Electronic Engine Controller 1 (RPM, Torque)"},
        {0x00F003, "EEC3 - Electronic Engine Controller 3"},
        {0x00FEC1, "EEC2 - Electronic Engine Controller 2"},
        {0x00FEDF, "EEC - Electronic Engine Controller (Composite)"},

        // Engine Temperature & Conditions
        {0x00FEEE, "ET1 - Engine Temperature 1"},
        {0x00FEF5, "AMB - Ambient Conditions"},
        {0x00FEEF, "Engine Fluid Level/Pressure 1"},

        // Engine Configuration & Hours
        {0x00FECA, "EC - Engine Configuration"},
        {0x00FEE5, "HOURS - Engine Hours, Revolutions"},

        // Fuel & Consumption
        {0x00FEE9, "Fuel Consumption (Liquid)"},
        {0x00FD09, "High Resolution Fuel Consumption"},

        // Vehicle & Transmission
        {0x00FEF1, "CCVS - Cruise Control/Vehicle Speed"},
        {0x00F005, "ETC1 - Electronic Transmission Controller 1"},

        // Diagnostics
        {0x00FECA, "DM1 - Active Diagnostic Trouble Codes"},
        {0x00FED3, "DM2 - Previously Active DTCs"},
        {0x00FECE, "DM6 - Pending DTCs"},
        {0x00FECF, "DM12 - Emissions DTCs"},

        // Software Identification
        {0x00FEDB, "Component Identification"},
        {0x00FEDA, "Software Identification"},
        {0x00FDC5, "ECU Identification Information"},

        // Additional engine data
        {0x00FEFC, "Dash Display"},
        {0x00FDD1, "Engine Fluid Level/Pressure 2"},
        {0x00F002, "Electronic Throttle Controller"},
        {0x00FEAE, "Air Supply Pressure"},
    };

    for (const auto& pgnInfo : testPgns) {
        // PGN request format: 3 bytes, little-endian
        uint8_t requestData[3];
        requestData[0] = pgnInfo.pgn & 0xFF;
        requestData[1] = (pgnInfo.pgn >> 8) & 0xFF;
        requestData[2] = (pgnInfo.pgn >> 16) & 0xFF;

        std::cout << "\n[TX] Request PGN 0x" << std::hex << std::setfill('0') << std::setw(6) << pgnInfo.pgn
                  << " (" << pgnInfo.name << ")\n";
        std::cout << "     Data: ";
        for (int i = 0; i < 3; i++) {
            std::cout << std::hex << std::setfill('0') << std::setw(2)
                      << static_cast<int>(requestData[i]) << " ";
        }
        std::cout << "\n";

        adapter.send(requestPgn, requestData, 3);
        usleep(200000);  // 200ms wait for response

        // Check for responses
        bool gotResponse = false;
        int rxCount = 0;
        while (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t rxSource = J1939::extractSource(arbId);
            uint8_t rxPf = J1939::extractPF(arbId);

            // Check if from our ECU
            if (rxSource == ecuAddress) {
                gotResponse = true;
                rxCount++;

                // Check if it's an ACK/NACK
                if (rxPf == J1939::J1939_PF_ACK) {
                    std::cout << "[RX] ACK/NACK: control=0x" << std::hex << static_cast<int>(rxData[0]);
                    switch (rxData[0]) {
                        case 0x00: std::cout << " (Positive ACK)"; break;
                        case 0x01: std::cout << " (Not Supported)"; break;
                        case 0x02: std::cout << " (Access Denied)"; break;
                        case 0x03: std::cout << " (Cannot Respond)"; break;
                    }
                    std::cout << "\n";
                } else {
                    // Potential data response!
                    uint32_t responsePgn = (static_cast<uint32_t>(rxPf) << 8);
                    if (rxPf < 0xF0) {
                        // PDU1 format - destination specific
                        responsePgn |= J1939::extractDest(arbId);
                    }

                    std::cout << "[RX] *** DATA RESPONSE! *** arbId=0x" << std::hex << arbId
                              << " PGN=0x" << std::setfill('0') << std::setw(6) << responsePgn << "\n";
                    std::cout << "     Data[" << std::dec << static_cast<int>(rxLen) << "]: ";
                    for (int i = 0; i < rxLen; i++) {
                        std::cout << std::hex << std::setfill('0') << std::setw(2)
                                  << static_cast<int>(rxData[i]) << " ";
                    }
                    std::cout << "\n";

                    // Decode specific PGNs
                    if (pgnInfo.pgn == 0x00F004 && rxLen >= 8) {  // EEC1
                        uint16_t rpm = (rxData[3] | (static_cast<uint16_t>(rxData[4]) << 8));
                        double actualRpm = rpm * 0.125;  // Resolution 0.125 RPM/bit
                        std::cout << "     Decoded EEC1: Engine RPM = " << std::dec << actualRpm << "\n";
                    } else if (pgnInfo.pgn == 0x00FEEE && rxLen >= 2) {  // Engine Temp 1
                        int coolantTemp = static_cast<int>(rxData[0]) - 40;  // Offset -40°C
                        std::cout << "     Decoded: Engine Coolant Temp = " << std::dec << coolantTemp << "°C\n";
                    } else if (pgnInfo.pgn == 0x00FEE5 && rxLen >= 4) {  // Engine Hours
                        uint32_t totalHours = rxData[0] | (static_cast<uint32_t>(rxData[1]) << 8) |
                                              (static_cast<uint32_t>(rxData[2]) << 16) |
                                              (static_cast<uint32_t>(rxData[3]) << 24);
                        double hours = totalHours * 0.05;  // Resolution 0.05 hr/bit
                        std::cout << "     Decoded: Engine Hours = " << std::dec << hours << " hours\n";
                    } else if (pgnInfo.pgn == 0x00F003 && rxLen >= 1) {  // EEC3
                        std::cout << "     Decoded EEC3: Nominal Friction Torque = "
                                  << std::dec << static_cast<int>(rxData[0]) << "%\n";
                    }
                }
            }
        }

        if (!gotResponse) {
            std::cout << "[RX] No response for PGN 0x" << std::hex << pgnInfo.pgn << "\n";
        }
    }

    std::cout << "\n[INFO] Finished testing J1939 PGN requests\n";

    // TEST G: Maybe the instruction needs to go in the 0x0301 context request format
    std::cout << "\n[TEST G] Embed instruction in context request format...\n";
    uint8_t testG[8];
    testG[0] = (0 << 5) | 0x03;
    testG[1] = localConnectionId;
    testG[2] = 0x00;
    testG[3] = 0x01;                   // Context header byte 0
    testG[4] = 0x03;                   // Context header byte 1
    testG[5] = 0x14;                   // Command: GetDataByAddress embedded in context
    testG[6] = 0x01;                   // Request ID
    testG[7] = (address >> 24) & 0xFF;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testG[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testG, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST H: Try CM550 diagnostic service 0x4A directly (4-byte addr + 1-byte len)
    // From firmware analysis: diagMemoryReadService4aHandler expects this format
    std::cout << "\n[TEST H] CM550 diagnostic service 0x4A (4-byte addr + 1-byte len)...\n";
    uint8_t testH[8];
    testH[0] = (0 << 5) | 0x03;        // DataTransfer
    testH[1] = ecuConnectionId;         // ECU's connection ID
    testH[2] = 0x06;                    // Control = 6 bytes of instruction data
    testH[3] = 0x4A;                    // Service 0x4A: memory read
    testH[4] = (address >> 24) & 0xFF;  // Address byte 0 (MSB)
    testH[5] = (address >> 16) & 0xFF;  // Address byte 1
    testH[6] = (address >> 8) & 0xFF;   // Address byte 2
    testH[7] = address & 0xFF;          // Address byte 3 (LSB)

    std::cout << "[TX] Frame 1: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testH[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testH, 8);
    usleep(100000);

    // Second frame with remaining length byte
    uint8_t testH2[8];
    testH2[0] = (1 << 5) | 0x03;       // sequence 1, DataTransfer
    testH2[1] = ecuConnectionId;
    testH2[2] = 0x00;
    testH2[3] = static_cast<uint8_t>(length); // Length (1 byte, max 255)
    testH2[4] = 0x00;
    testH2[5] = 0x00;
    testH2[6] = 0x00;
    testH2[7] = 0x00;

    std::cout << "[TX] Frame 2: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testH2[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testH2, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST I: Try single-frame 0x4A with all 6 bytes in control field style
    std::cout << "\n[TEST I] Single-frame 0x4A with instruction in payload...\n";
    uint8_t testI[8];
    testI[0] = (0 << 5) | 0x03;        // DataTransfer
    testI[1] = ecuConnectionId;
    testI[2] = 0x4A;                    // Service code as "control" byte
    testI[3] = (address >> 24) & 0xFF;
    testI[4] = (address >> 16) & 0xFF;
    testI[5] = (address >> 8) & 0xFF;
    testI[6] = address & 0xFF;
    testI[7] = static_cast<uint8_t>(length);

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testI[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testI, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 100)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST J: Try full CLIP transport sequence for data transfer
    // According to protocol doc, we may need:
    // 1. TransportOpen (0x02) with packet count
    // 2. Wait for CTS (0x04)
    // 3. Send Data frames (0x03)
    // 4. Wait for ACK
    std::cout << "\n[TEST J] Full CLIP transport sequence for memory read...\n";

    // Step 1: TransportOpen for data transfer (not session)
    // Format: [0x02][connId][ctrl][flags][pktCount]...
    uint8_t dataOpenFrame[8];
    dataOpenFrame[0] = 0x02;            // TransportOpen type
    dataOpenFrame[1] = ecuConnectionId; // Use ECU's connection ID
    dataOpenFrame[2] = 0x00;            // Control
    dataOpenFrame[3] = 0x02;            // Packet count = 2 (8 bytes of instruction)
    dataOpenFrame[4] = 0x00;
    dataOpenFrame[5] = 0x00;
    dataOpenFrame[6] = 0x00;
    dataOpenFrame[7] = 0x00;

    std::cout << "[TX] DataOpen: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(dataOpenFrame[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, dataOpenFrame, 8);
    usleep(200000);

    // Check for CTS response
    bool gotCts = false;
    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            // Check for CTS (byte 0 lower bits = 0x04)
            if ((rxData[0] & 0x1F) == 0x04) {
                gotCts = true;
                std::cout << " <- CTS!";
            }
            std::cout << "\n";
        }
    }

    if (gotCts) {
        std::cout << "[INFO] Got CTS, sending data frames...\n";
    } else {
        std::cout << "[WARN] No CTS received, trying data frames anyway...\n";
    }

    // Step 2: Send instruction as Data frames
    // Frame 1: [0x03][connId][ctrl][0x14][seqId][addr0][addr1][addr2]
    uint8_t dataFrame1[8];
    dataFrame1[0] = (0 << 5) | 0x03;   // seq=0, DataTransfer
    dataFrame1[1] = ecuConnectionId;
    dataFrame1[2] = 0x00;               // Control
    dataFrame1[3] = 0x14;               // GetDataByAddress command
    dataFrame1[4] = 0x01;               // Request sequence ID
    dataFrame1[5] = (address >> 24) & 0xFF;
    dataFrame1[6] = (address >> 16) & 0xFF;
    dataFrame1[7] = (address >> 8) & 0xFF;

    std::cout << "[TX] Data seq=0: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(dataFrame1[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, dataFrame1, 8);
    usleep(50000);

    // Frame 2: [0x23][connId][ctrl][addr3][len0][len1][pad][pad]
    uint8_t dataFrame2[8];
    dataFrame2[0] = (1 << 5) | 0x03;   // seq=1, DataTransfer
    dataFrame2[1] = ecuConnectionId;
    dataFrame2[2] = 0x00;               // Control
    dataFrame2[3] = address & 0xFF;     // Address LSB
    dataFrame2[4] = (length >> 8) & 0xFF;
    dataFrame2[5] = length & 0xFF;
    dataFrame2[6] = 0x00;
    dataFrame2[7] = 0x00;

    std::cout << "[TX] Data seq=1: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(dataFrame2[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, dataFrame2, 8);

    usleep(500000);
    std::cout << "[RX] Waiting for response...\n";
    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST K: CM550 Native Diagnostic Format (from firmware RE)
    // Based on diagnosticCommandDispatcher at 0x00012484:
    // - Service type 5 = memory read/write
    // - Command byte patterns: 0x60=3-byte addr with CRC, 0x61=3-byte addr no CRC
    //   0xC0/0xC1=2-byte addr, 0xE0/0xE1=1-byte addr
    // Low nibble 0 = CRC required, low nibble 1 = no CRC
    std::cout << "\n[TEST K] CM550 Native Diagnostic: Service 5 + cmd 0x61 (3-byte addr, no CRC)...\n";

    // Use 3-byte address from 24-bit address space
    uint32_t addr3byte = address & 0xFFFFFF;  // Truncate to 3 bytes
    uint8_t readCount = (length > 255) ? 255 : static_cast<uint8_t>(length);

    std::cout << "[INFO] 3-byte address: 0x" << std::hex << std::setfill('0') << std::setw(6) << addr3byte
              << " count: " << std::dec << static_cast<int>(readCount) << "\n";

    // Format: [svc=5][cmd=0x61][addr_hi][addr_mid][addr_lo][count]
    // Wrapped in CLIP DataTransfer frame
    uint8_t testK[8];
    testK[0] = (0 << 5) | 0x03;           // seq=0, DataTransfer
    testK[1] = ecuConnectionId;            // ECU's connection ID
    testK[2] = 0x06;                       // Control = 6 bytes of payload
    testK[3] = 0x05;                       // Service type 5 = memory access
    testK[4] = 0x61;                       // Command: 3-byte addr read, no CRC
    testK[5] = (addr3byte >> 16) & 0xFF;   // Address high byte
    testK[6] = (addr3byte >> 8) & 0xFF;    // Address mid byte
    testK[7] = addr3byte & 0xFF;           // Address low byte

    std::cout << "[TX] Frame 1: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testK[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testK, 8);
    usleep(100000);

    // Frame 2: count byte
    uint8_t testK2[8];
    testK2[0] = (1 << 5) | 0x03;          // seq=1, DataTransfer
    testK2[1] = ecuConnectionId;
    testK2[2] = 0x00;                      // Control
    testK2[3] = readCount;                 // Count of bytes to read
    testK2[4] = 0x00;
    testK2[5] = 0x00;
    testK2[6] = 0x00;
    testK2[7] = 0x00;

    std::cout << "[TX] Frame 2: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testK2[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testK2, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST L: CM550 format without CLIP wrapper (raw diagnostic message)
    // Maybe the CM550 doesn't use CLIP DataTransfer framing at all
    std::cout << "\n[TEST L] Raw CM550 Diagnostic (no CLIP framing, service 5)...\n";
    uint8_t testL[8];
    testL[0] = 0x05;                       // Service type 5 = memory access
    testL[1] = 0x61;                       // Command: 3-byte addr read, no CRC
    testL[2] = (addr3byte >> 16) & 0xFF;   // Address high byte
    testL[3] = (addr3byte >> 8) & 0xFF;    // Address mid byte
    testL[4] = addr3byte & 0xFF;           // Address low byte
    testL[5] = readCount;                  // Count
    testL[6] = 0x00;
    testL[7] = 0x00;

    std::cout << "[TX] Raw: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testL[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testL, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxSource == ecuAddress) {
            std::cout << "[RX] PF=0x" << std::hex << std::setfill('0') << std::setw(2)
                      << static_cast<int>(rxPf) << ": ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST M: Try with message length byte prefix (as seen in firmware)
    // The firmware reads messageLength from byte 0 of the buffer
    std::cout << "\n[TEST M] CM550 with length prefix (7 bytes total)...\n";
    uint8_t testM[8];
    testM[0] = 0x07;                       // Message length = 7 bytes
    testM[1] = 0x05;                       // Service type 5 = memory access
    testM[2] = 0x61;                       // Command: 3-byte addr read, no CRC
    testM[3] = (addr3byte >> 16) & 0xFF;   // Address high byte
    testM[4] = (addr3byte >> 8) & 0xFF;    // Address mid byte
    testM[5] = addr3byte & 0xFF;           // Address low byte
    testM[6] = readCount;                  // Count
    testM[7] = 0x00;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testM[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testM, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxPf = J1939::extractPF(arbId);
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxSource == ecuAddress) {
            std::cout << "[RX] PF=0x" << std::hex << std::setfill('0') << std::setw(2)
                      << static_cast<int>(rxPf) << ": ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST N: Service 4 system control commands to enable diagnostic mode
    // From firmware: Service 4 commands control diagnostic state
    // 0x66 = Clear diagnostic_command_state
    // 0x71 = Set bit 0 (enable secured services)
    // 0x73 = Set bit 1 (enable extended services)
    std::cout << "\n[TEST N] Service 4 initialization sequence...\n";

    // Send service 4, sub-code 0x71 to enable secured services
    uint8_t testN1[8];
    testN1[0] = (0 << 5) | 0x03;          // DataTransfer
    testN1[1] = ecuConnectionId;           // ECU's connection ID
    testN1[2] = 0x03;                      // Control = message length
    testN1[3] = 0x04;                      // Service type 4 = system control
    testN1[4] = 0x71;                      // Sub-code: Set bit 0 of command state
    testN1[5] = 0x00;
    testN1[6] = 0x00;
    testN1[7] = 0x00;

    std::cout << "[TX] Service 4, cmd 0x71 (enable secured): ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testN1[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testN1, 8);
    usleep(300000);

    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // Also try raw format: [len][service][subcode]
    uint8_t testN2[8];
    testN2[0] = 0x03;                      // Length = 3
    testN2[1] = 0x04;                      // Service 4
    testN2[2] = 0x71;                      // Sub-code 0x71
    testN2[3] = 0x00;
    testN2[4] = 0x00;
    testN2[5] = 0x00;
    testN2[6] = 0x00;
    testN2[7] = 0x00;

    std::cout << "[TX] Raw service 4: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testN2[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testN2, 8);
    usleep(300000);

    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // TEST O: After init, retry memory read with raw format
    std::cout << "\n[TEST O] Retry memory read after service 4 init...\n";
    uint8_t testO[8];
    testO[0] = 0x07;                       // Length
    testO[1] = 0x05;                       // Service 5
    testO[2] = 0x61;                       // 3-byte addr read
    testO[3] = (addr3byte >> 16) & 0xFF;
    testO[4] = (addr3byte >> 8) & 0xFF;
    testO[5] = addr3byte & 0xFF;
    testO[6] = readCount;
    testO[7] = 0x00;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testO[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testO, 8);

    usleep(500000);
    while (adapter.recv(arbId, rxData, rxLen, 200)) {
        uint8_t rxSource = J1939::extractSource(arbId);
        if (rxSource == ecuAddress) {
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]) << " ";
            }
            std::cout << "\n";
        }
    }

    // ============================================================
    // STEP 4: Wait for final responses
    // ============================================================
    usleep(500000);

    elapsed = 0;
    int responseCount = 0;
    int dataFrames = 0;

    while (elapsed < timeoutMs && g_running) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t rxPf = J1939::extractPF(arbId);
            uint8_t rxDest = J1939::extractDest(arbId);
            uint8_t rxSource = J1939::extractSource(arbId);

            // Show all CLIP frames from our ECU
            if (rxPf == J1939::CLIP_PF_DATA && rxSource == ecuAddress) {
                printFrame(arbId, rxData, rxLen);

                if (rxDest == J1939::TOOL_ADDRESS) {
                    responseCount++;
                    std::cout << "[RAW] ";
                    for (int i = 0; i < rxLen; i++) {
                        std::cout << std::hex << std::setfill('0') << std::setw(2)
                                  << static_cast<int>(rxData[i]) << " ";
                    }
                    std::cout << std::dec << "\n";

                    // Decode frame
                    Clip::Frame respFrame;
                    if (respFrame.decode(rxData, rxLen)) {
                        if (respFrame.getMsgType() == Clip::MsgType::ConnectionRefused) {
                            std::cout << "[ERROR] ECU refused request\n";
                            break;
                        }
                        // Check for DataTransfer (0x03) - this would be actual data
                        if (respFrame.getMsgType() == Clip::MsgType::DataTransfer) {
                            dataFrames++;
                            std::cout << "[DATA] Received data frame! seq="
                                      << static_cast<int>(respFrame.getSequence()) << "\n";
                        }
                        // Check for ClearToSend (0x04) - flow control
                        if (respFrame.getMsgType() == Clip::MsgType::ClearToSend) {
                            std::cout << "[CTS] ECU sent CTS, ready to continue\n";
                        }
                    }
                    std::cout << "\n";
                }
            }
        }
        elapsed += 100;
    }

    std::cout << "[INFO] Received " << responseCount << " response frame(s), "
              << dataFrames << " data frame(s)\n";
    return 0;
}

/**
 * J1939 PGN Request Mode with Transport Protocol Support
 *
 * Requests a specific PGN from the ECU and handles both single-frame
 * and multi-frame (via J1939 TP) responses.
 */
int j1939Mode(SocketCanAdapter& adapter, uint8_t ecuAddress, uint32_t pgn)
{
    std::cout << "\n[INFO] J1939 PGN Request Mode\n";
    std::cout << "[INFO] ECU address: 0x" << std::hex << std::setfill('0')
              << std::setw(2) << static_cast<int>(ecuAddress) << "\n";
    std::cout << "[INFO] Requesting PGN: 0x" << std::hex << std::setfill('0')
              << std::setw(6) << pgn << std::dec << "\n\n";

    // Build J1939 Request arbitration ID (PF=0xEA)
    uint32_t requestArbId = J1939::buildRequestId(ecuAddress);

    // Build PGN request data (3 bytes, little-endian)
    uint8_t requestData[3];
    requestData[0] = pgn & 0xFF;
    requestData[1] = (pgn >> 8) & 0xFF;
    requestData[2] = (pgn >> 16) & 0xFF;

    // Send the request
    std::cout << "[TX] " << std::hex << std::uppercase << std::setfill('0')
              << std::setw(8) << requestArbId << " [3] ";
    for (int i = 0; i < 3; i++) {
        std::cout << std::setw(2) << static_cast<int>(requestData[i]) << " ";
    }
    std::cout << std::dec << "\n";

    if (!adapter.send(requestArbId, requestData, 3)) {
        std::cerr << "[ERROR] Failed to send J1939 request\n";
        return 1;
    }

    // Wait for response with TP support
    J1939::TPSession tpSession;
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;

    int timeoutMs = 5000;  // 5 second timeout
    int elapsed = 0;
    bool gotResponse = false;
    bool gotNack = false;

    std::cout << "\n[INFO] Waiting for response...\n";

    while (elapsed < timeoutMs && g_running && !gotResponse && !gotNack) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t rxPf = J1939::extractPF(arbId);
            uint8_t rxSource = J1939::extractSource(arbId);

            // Only process frames from our target ECU
            if (rxSource != ecuAddress) {
                continue;
            }

            // Check for J1939 ACK/NACK
            if (rxPf == J1939::J1939_PF_ACK) {
                std::cout << "[RX] J1939 ACK/NACK: ";
                for (int i = 0; i < rxLen; i++) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(rxData[i]) << " ";
                }
                std::cout << "\n";

                if (rxData[0] == 0x01) {
                    std::cout << "[INFO] PGN 0x" << std::hex << pgn
                              << " is NOT SUPPORTED by this ECU\n";
                    gotNack = true;
                } else if (rxData[0] == 0x00) {
                    std::cout << "[INFO] Positive ACK received\n";
                }
                continue;
            }

            // Check for TP.CM (Connection Management)
            if (rxPf == J1939::J1939_PF_TP_CM) {
                J1939::TPConnectionMessage cm;
                if (cm.decode(rxData, rxLen)) {
                    std::cout << "[RX] " << cm.toString() << "\n";

                    if (cm.isBAM() && cm.pgn == pgn) {
                        // Start TP session
                        tpSession.startFromBAM(cm, rxSource);
                        std::cout << "[INFO] Starting multi-frame reassembly...\n";
                    }
                }
                continue;
            }

            // Check for TP.DT (Data Transfer)
            if (rxPf == J1939::J1939_PF_TP_DT && tpSession.active) {
                uint8_t seqNum = rxData[0];
                std::cout << "[RX] " << J1939::formatTPData(seqNum, tpSession.expectedPackets,
                                                            &rxData[1], rxLen - 1) << "\n";

                // Add frame to session
                if (tpSession.addFrame(seqNum, &rxData[1], rxLen - 1)) {
                    if (tpSession.isComplete()) {
                        std::cout << "\n[SUCCESS] Received " << std::dec
                                  << tpSession.data.size() << " bytes for PGN 0x"
                                  << std::hex << std::setfill('0') << std::setw(6) << tpSession.pgn << "\n\n";
                        std::cout << tpSession.hexDump() << "\n";

                        // Decode multi-frame PGNs
                        const std::vector<uint8_t>& tpData = tpSession.data;
                        switch (tpSession.pgn) {
                            case 0xFECA:  // DM1 Active Diagnostic Trouble Codes (65226)
                                if (tpData.size() >= 2) {
                                    std::cout << "\n     DM1 Active Faults:\n";
                                    std::cout << "     Lamp Status: MIL=" << ((tpData[0] >> 6) & 0x03)
                                              << " RSL=" << ((tpData[0] >> 4) & 0x03)
                                              << " AWL=" << ((tpData[0] >> 2) & 0x03)
                                              << " PL=" << (tpData[0] & 0x03) << "\n";
                                    // Parse DTCs (each is 4 bytes: SPN + FMI + OC)
                                    size_t numDtcs = (tpData.size() - 2) / 4;
                                    std::cout << "     Fault Count: " << numDtcs << "\n";
                                    for (size_t i = 0; i < numDtcs && (2 + i*4 + 3) < tpData.size(); i++) {
                                        size_t offset = 2 + i * 4;
                                        uint32_t spn = tpData[offset] |
                                                      (static_cast<uint32_t>(tpData[offset+1]) << 8) |
                                                      ((static_cast<uint32_t>(tpData[offset+2] & 0xE0) >> 5) << 16);
                                        uint8_t fmi = tpData[offset+2] & 0x1F;
                                        uint8_t oc = tpData[offset+3] & 0x7F;
                                        std::cout << "     DTC " << (i+1) << ": SPN=" << std::dec << spn
                                                  << " FMI=" << static_cast<int>(fmi)
                                                  << " OC=" << static_cast<int>(oc) << "\n";
                                    }
                                }
                                break;

                            case 0xFECB:  // DM2 Previously Active Faults (65227)
                                if (tpData.size() >= 2) {
                                    std::cout << "\n     DM2 Previously Active Faults:\n";
                                    size_t numDtcs = (tpData.size() - 2) / 4;
                                    std::cout << "     Fault Count: " << numDtcs << "\n";
                                    for (size_t i = 0; i < numDtcs && (2 + i*4 + 3) < tpData.size(); i++) {
                                        size_t offset = 2 + i * 4;
                                        uint32_t spn = tpData[offset] |
                                                      (static_cast<uint32_t>(tpData[offset+1]) << 8) |
                                                      ((static_cast<uint32_t>(tpData[offset+2] & 0xE0) >> 5) << 16);
                                        uint8_t fmi = tpData[offset+2] & 0x1F;
                                        uint8_t oc = tpData[offset+3] & 0x7F;
                                        std::cout << "     DTC " << (i+1) << ": SPN=" << std::dec << spn
                                                  << " FMI=" << static_cast<int>(fmi)
                                                  << " OC=" << static_cast<int>(oc) << "\n";
                                    }
                                }
                                break;

                            case 0xFEEB:  // Component Identification (65259)
                                {
                                    std::cout << "\n     Component Identification:\n";
                                    // Format: Make*Model*SerialNumber*UnitNumber*
                                    std::string compId(tpData.begin(), tpData.end());
                                    // Remove trailing 0xFF bytes
                                    size_t end = compId.find('\xFF');
                                    if (end != std::string::npos) {
                                        compId = compId.substr(0, end);
                                    }
                                    // Split by '*'
                                    size_t pos = 0, fieldNum = 0;
                                    const char* fieldNames[] = {"Make", "Model", "Serial Number", "Unit Number"};
                                    while ((pos = compId.find('*')) != std::string::npos && fieldNum < 4) {
                                        std::string field = compId.substr(0, pos);
                                        if (!field.empty()) {
                                            // Trim spaces
                                            size_t start = field.find_first_not_of(' ');
                                            size_t endPos = field.find_last_not_of(' ');
                                            if (start != std::string::npos) {
                                                field = field.substr(start, endPos - start + 1);
                                            }
                                            std::cout << "     " << fieldNames[fieldNum] << ": " << field << "\n";
                                        }
                                        compId.erase(0, pos + 1);
                                        fieldNum++;
                                    }
                                }
                                break;

                            default:
                                break;
                        }

                        gotResponse = true;
                    }
                } else {
                    std::cerr << "[ERROR] Failed to add TP.DT frame (sequence error?)\n";
                }
                continue;
            }

            // Check for single-frame data response
            // PDU2 format (PF >= 0xF0): PGN = PF * 256 + PS
            // PDU1 format (PF < 0xF0): PGN = PF * 256
            uint32_t responsePgn;
            if (rxPf >= 0xF0) {
                responsePgn = (static_cast<uint32_t>(rxPf) << 8) | J1939::extractDest(arbId);
            } else {
                responsePgn = static_cast<uint32_t>(rxPf) << 8;
            }

            // Check if this is the response to our requested PGN
            if (responsePgn == (pgn & 0xFFFF00) || responsePgn == pgn) {
                std::cout << "[RX] Single-frame response, PGN 0x" << std::hex
                          << std::setfill('0') << std::setw(6) << responsePgn << "\n";
                std::cout << "     Data[" << std::dec << static_cast<int>(rxLen) << "]: ";
                for (int i = 0; i < rxLen; i++) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(rxData[i]) << " ";
                }
                std::cout << "\n";

                // Decode common J1939 PGNs
                switch (pgn) {
                    case 0xFEE5:  // Engine Hours (65253)
                        if (rxLen >= 4) {
                            uint32_t totalHours = rxData[0] | (static_cast<uint32_t>(rxData[1]) << 8) |
                                                  (static_cast<uint32_t>(rxData[2]) << 16) |
                                                  (static_cast<uint32_t>(rxData[3]) << 24);
                            double hours = totalHours * 0.05;
                            std::cout << "     Decoded: Engine Hours = " << std::dec << std::fixed
                                      << std::setprecision(1) << hours << " hours\n";
                        }
                        break;

                    case 0xFEE7:  // Vehicle Hours (65255)
                        if (rxLen >= 8) {
                            // Bytes 0-3: Total PTO Hours, Bytes 4-7: Total Engine Hours
                            uint32_t engineHours = rxData[4] | (static_cast<uint32_t>(rxData[5]) << 8) |
                                                   (static_cast<uint32_t>(rxData[6]) << 16) |
                                                   (static_cast<uint32_t>(rxData[7]) << 24);
                            if (engineHours != 0xFFFFFFFF) {
                                double hours = engineHours * 0.05;
                                std::cout << "     Decoded: Vehicle Engine Hours = " << std::dec << std::fixed
                                          << std::setprecision(1) << hours << " hours\n";
                            }
                        }
                        break;

                    case 0xFEEE:  // Engine Temperature 1 (65262)
                        if (rxLen >= 2) {
                            if (rxData[0] != 0xFF) {
                                int coolantTemp = static_cast<int>(rxData[0]) - 40;
                                std::cout << "     Decoded: Engine Coolant Temp = " << std::dec << coolantTemp << "°C\n";
                            }
                            if (rxData[1] != 0xFF) {
                                int fuelTemp = static_cast<int>(rxData[1]) - 40;
                                std::cout << "     Decoded: Fuel Temp = " << std::dec << fuelTemp << "°C\n";
                            }
                        }
                        break;

                    case 0xFEEF:  // Engine Fluid Level/Pressure (65263)
                        if (rxLen >= 4) {
                            if (rxData[0] != 0xFF) {
                                int fuelLevel = static_cast<int>(rxData[0]) * 0.4;  // 0.4%/bit
                                std::cout << "     Decoded: Fuel Level = " << std::dec << fuelLevel << "%\n";
                            }
                            if (rxData[3] != 0xFF) {
                                int oilPressure = rxData[3] * 4;  // 4 kPa/bit
                                std::cout << "     Decoded: Oil Pressure = " << std::dec << oilPressure << " kPa ("
                                          << std::fixed << std::setprecision(1) << (oilPressure * 0.145) << " psi)\n";
                            }
                        }
                        break;

                    case 0xFEE0:  // Vehicle Distance (65248)
                        if (rxLen >= 8) {
                            uint32_t tripDist = rxData[0] | (static_cast<uint32_t>(rxData[1]) << 8) |
                                                (static_cast<uint32_t>(rxData[2]) << 16) |
                                                (static_cast<uint32_t>(rxData[3]) << 24);
                            uint32_t totalDist = rxData[4] | (static_cast<uint32_t>(rxData[5]) << 8) |
                                                 (static_cast<uint32_t>(rxData[6]) << 16) |
                                                 (static_cast<uint32_t>(rxData[7]) << 24);
                            double tripKm = tripDist * 0.125;  // 1/8 km resolution
                            double totalKm = totalDist * 0.125;
                            std::cout << "     Decoded: Trip Distance = " << std::dec << std::fixed
                                      << std::setprecision(1) << tripKm << " km ("
                                      << (tripKm * 0.621371) << " miles)\n";
                            std::cout << "     Decoded: Total Distance = " << totalKm << " km ("
                                      << (totalKm * 0.621371) << " miles)\n";
                        }
                        break;

                    case 0xFEE9:  // Intake/Exhaust Conditions 1 (65257)
                        if (rxLen >= 8) {
                            // Bytes 0-3: Fuel used (gaseous), Bytes 4-7: Fuel used (diesel)
                            uint32_t dieselUsed = rxData[4] | (static_cast<uint32_t>(rxData[5]) << 8) |
                                                  (static_cast<uint32_t>(rxData[6]) << 16) |
                                                  (static_cast<uint32_t>(rxData[7]) << 24);
                            if (dieselUsed != 0xFFFFFFFF) {
                                double liters = dieselUsed * 0.5;  // 0.5 L/bit
                                std::cout << "     Decoded: Total Fuel Used = " << std::dec << std::fixed
                                          << std::setprecision(1) << liters << " L ("
                                          << (liters * 0.264172) << " gal)\n";
                            }
                        }
                        break;

                    case 0xFEF5:  // Ambient Conditions (65269)
                        if (rxLen >= 1) {
                            if (rxData[0] != 0xFF) {
                                int pressure = rxData[0] * 0.5;  // 0.5 kPa/bit
                                std::cout << "     Decoded: Barometric Pressure = " << std::dec << pressure << " kPa\n";
                            }
                        }
                        break;

                    case 0xFEF0:  // Cruise Control/Vehicle Speed (65264)
                        if (rxLen >= 8) {
                            if (rxData[1] != 0xFF) {
                                double speed = rxData[1] / 256.0;  // 1/256 km/h per bit
                                // Combine with high byte if needed
                                if (rxData[2] != 0xFF) {
                                    speed = (rxData[1] | (static_cast<uint16_t>(rxData[2]) << 8)) / 256.0;
                                }
                                std::cout << "     Decoded: Vehicle Speed = " << std::dec << std::fixed
                                          << std::setprecision(1) << speed << " km/h ("
                                          << (speed * 0.621371) << " mph)\n";
                            }
                        }
                        break;

                    case 0xFEDC:  // I/O Control (65244)
                        if (rxLen >= 4) {
                            uint16_t batteryVolt = rxData[0] | (static_cast<uint16_t>(rxData[1]) << 8);
                            if (batteryVolt != 0xFFFF) {
                                double volts = batteryVolt * 0.05;  // 0.05 V/bit
                                std::cout << "     Decoded: Battery Voltage = " << std::dec << std::fixed
                                          << std::setprecision(1) << volts << " V\n";
                            }
                        }
                        break;

                    case 0xFECE:  // DM5 Readiness (65230)
                        if (rxLen >= 1) {
                            std::cout << "     Decoded: DM5 Readiness Status = 0x" << std::hex
                                      << static_cast<int>(rxData[0]) << std::dec << "\n";
                            std::cout << "     Active Fault Count = " << static_cast<int>(rxData[0] >> 4)
                                      << ", Previously Active = " << (rxData[0] & 0x0F) << "\n";
                        }
                        break;

                    case 0xF004:  // EEC1 - Electronic Engine Controller 1 (61444)
                        if (rxLen >= 5) {
                            uint16_t rpm = rxData[3] | (static_cast<uint16_t>(rxData[4]) << 8);
                            double actualRpm = rpm * 0.125;
                            std::cout << "     Decoded: Engine RPM = " << std::dec << std::fixed
                                      << std::setprecision(1) << actualRpm << " RPM\n";
                        }
                        break;

                    default:
                        // No decoder for this PGN
                        break;
                }

                gotResponse = true;
            }
        }
        elapsed += 100;
    }

    if (!gotResponse && !gotNack) {
        std::cout << "\n[TIMEOUT] No response received after "
                  << std::dec << (timeoutMs / 1000) << " seconds\n";
        return 1;
    }

    return 0;
}

// ============================================================================
// CM550-SPECIFIC DISPATCHER FORMAT TESTS
// Uses byte[0] = 0x11 (ParamRequest) or 0x13 (StatusRequest)
// NOT the standard CLIP DataTransfer (0x03) format!
// ============================================================================

int cm550ParamMode(SocketCanAdapter& adapter, uint8_t ecuAddress, uint8_t paramCmd, uint16_t guardWord)
{
    std::cout << "\n[CM550] Testing ParamRequest (0x11) format\n";
    std::cout << "[CM550] This uses vp44CanMessageDispatcher routing, NOT CLIP transport!\n";
    std::cout << "[CM550] Param cmd: 0x" << std::hex << static_cast<int>(paramCmd)
              << ", guard: 0x" << std::setfill('0') << std::setw(4) << guardWord << std::dec << "\n\n";

    // Build the CM550 ParamRequest frame
    Clip::RawFrame frame = Clip::buildCM550ParamRequest(
        0,           // sequence
        1,           // totalPackets
        paramCmd,    // paramCmd
        0x0000,      // paramData
        guardWord    // guardWord
    );

    std::cout << "[TX] " << frame.toString() << "\n";
    std::cout << "     ^ CM550 ParamRequest: seq=0 pkts=1 cmd=0x"
              << std::hex << static_cast<int>(paramCmd) << std::dec << "\n";

    // Build arbitration ID - use PGN 0xEC00 (TP.CM) for CM550 dispatcher!
    uint32_t txArbId = J1939::buildTPCMId(ecuAddress);

    // Send the frame
    if (!adapter.send(txArbId, frame.data, frame.len)) {
        std::cerr << "[ERROR] Failed to send CM550 ParamRequest\n";
        return 1;
    }

    // Wait for response
    std::cout << "\n[INFO] Waiting for response (look for 0x80 wrapper)...\n";
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    int elapsed = 0;
    int timeoutMs = 3000;

    while (g_running && elapsed < timeoutMs) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            // Print raw frame
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]);
                if (i < rxLen - 1) std::cout << " ";
            }
            std::cout << std::dec << "\n";

            // Check for CM550 response (0x80 wrapper)
            if (Clip::isCM550Response(rxData, rxLen)) {
                std::cout << "     ^ *** CM550 RESPONSE (0x80 wrapper) ***\n";
                std::cout << "     ^ Command echo: 0x" << std::hex
                          << static_cast<int>(Clip::getCM550ResponseCmd(rxData, rxLen))
                          << std::dec << "\n";
                if (rxLen >= 3) {
                    std::cout << "     ^ Response data: ";
                    for (int i = 2; i < rxLen; i++) {
                        std::cout << std::hex << std::setfill('0') << std::setw(2)
                                  << static_cast<int>(rxData[i]);
                        if (i < rxLen - 1) std::cout << " ";
                    }
                    std::cout << std::dec << "\n";
                }
                return 0;  // Success!
            }

            // Check source address
            uint8_t source = J1939::extractSource(arbId);
            if (source == ecuAddress) {
                std::cout << "     ^ Response from ECU 0x" << std::hex << static_cast<int>(ecuAddress)
                          << std::dec << "\n";
            }
        }
        elapsed += 100;
    }

    std::cout << "\n[TIMEOUT] No CM550 response received\n";
    return 1;
}

int cm550StatusMode(SocketCanAdapter& adapter, uint8_t ecuAddress, uint8_t statusType)
{
    std::cout << "\n[CM550] Testing StatusRequest (0x13) format\n";
    std::cout << "[CM550] Status type: 0x" << std::hex << static_cast<int>(statusType) << std::dec << "\n\n";

    // Build the CM550 StatusRequest frame
    Clip::RawFrame frame = Clip::buildCM550StatusRequest(statusType);

    std::cout << "[TX] " << frame.toString() << "\n";
    std::cout << "     ^ CM550 StatusRequest: type=0x"
              << std::hex << static_cast<int>(statusType) << std::dec << "\n";

    // Build arbitration ID - use PGN 0xEC00 (TP.CM) for CM550 dispatcher!
    uint32_t txArbId = J1939::buildTPCMId(ecuAddress);

    // Send the frame
    if (!adapter.send(txArbId, frame.data, frame.len)) {
        std::cerr << "[ERROR] Failed to send CM550 StatusRequest\n";
        return 1;
    }

    // Wait for response
    std::cout << "\n[INFO] Waiting for response...\n";
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    int elapsed = 0;
    int timeoutMs = 3000;

    while (g_running && elapsed < timeoutMs) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            // Print raw frame
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]);
                if (i < rxLen - 1) std::cout << " ";
            }
            std::cout << std::dec << "\n";

            // Check for CM550 response
            if (Clip::isCM550Response(rxData, rxLen)) {
                std::cout << "     ^ *** CM550 RESPONSE (0x80 wrapper) ***\n";
                return 0;
            }

            // Check source address
            uint8_t source = J1939::extractSource(arbId);
            if (source == ecuAddress) {
                std::cout << "     ^ Response from ECU 0x" << std::hex << static_cast<int>(ecuAddress)
                          << std::dec << "\n";
            }
        }
        elapsed += 100;
    }

    std::cout << "\n[TIMEOUT] No CM550 response received\n";
    return 1;
}

int cm550RawMode(SocketCanAdapter& adapter, uint8_t ecuAddress, const std::string& hexBytes)
{
    std::cout << "\n[CM550] Sending raw 8-byte frame\n";
    std::cout << "[CM550] Hex: " << hexBytes << "\n\n";

    // Parse hex string
    if (hexBytes.length() < 2 || hexBytes.length() > 16 || hexBytes.length() % 2 != 0) {
        std::cerr << "[ERROR] Hex string must be 2-16 characters (1-8 bytes)\n";
        return 1;
    }

    uint8_t bytes[8];
    size_t byteCount = hexBytes.length() / 2;
    for (size_t i = 0; i < byteCount; i++) {
        std::string byteStr = hexBytes.substr(i * 2, 2);
        bytes[i] = static_cast<uint8_t>(std::strtoul(byteStr.c_str(), nullptr, 16));
    }

    // Build raw frame
    Clip::RawFrame frame = Clip::buildRawFrame(bytes, static_cast<uint8_t>(byteCount));

    std::cout << "[TX] " << frame.toString() << "\n";
    std::cout << "     ^ CM550 Dispatch type: " << Clip::describeCM550MsgType(bytes[0]) << "\n";

    // Build arbitration ID - use PGN 0xEC00 (TP.CM) for CM550 dispatcher!
    uint32_t txArbId = J1939::buildTPCMId(ecuAddress);

    // Send the frame
    if (!adapter.send(txArbId, frame.data, frame.len)) {
        std::cerr << "[ERROR] Failed to send CM550 raw frame\n";
        return 1;
    }

    // Wait for response
    std::cout << "\n[INFO] Waiting for response...\n";
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    int elapsed = 0;
    int timeoutMs = 3000;

    while (g_running && elapsed < timeoutMs) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            // Print raw frame
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]);
                if (i < rxLen - 1) std::cout << " ";
            }
            std::cout << std::dec << "\n";

            // Check for CM550 response
            if (Clip::isCM550Response(rxData, rxLen)) {
                std::cout << "     ^ *** CM550 RESPONSE (0x80 wrapper) ***\n";
                return 0;
            }

            // Check source address
            uint8_t source = J1939::extractSource(arbId);
            if (source == ecuAddress) {
                std::cout << "     ^ Response from ECU 0x" << std::hex << static_cast<int>(ecuAddress)
                          << std::dec << "\n";
            }
        }
        elapsed += 100;
    }

    std::cout << "\n[TIMEOUT] No CM550 response received\n";
    return 1;
}

// ============================================================================
// DPA FRAME FORMAT TESTS (from decompiled Insite dpas32_ghidra.c)
// These wrap CLIP instructions in DPA frame format (0xC0/0x80 header, 0x49 TX)
// ============================================================================

/**
 * Send a DPA frame and wait for response
 * Only shows ECU responses, filters out broadcast traffic
 */
int sendDPAFrame(SocketCanAdapter& adapter, uint8_t ecuAddress, const Clip::RawFrame& frame, const std::string& desc)
{
    std::cout << "[TX] " << frame.toString() << "\n";
    std::cout << "     ^ DPA: " << Clip::describeDPAFrameType(frame.data[0])
              << " " << Clip::describeCLIPInstruction(frame.data[4]) << " " << desc << "\n";

    // Build arbitration ID - use PGN 0xEF00 (Proprietary A) for DPA frames
    // This is where diagnosticServiceDispatcher routes based on service ID
    uint32_t txArbId = J1939::buildClipRequestId(ecuAddress);

    // Send the frame
    if (!adapter.send(txArbId, frame.data, frame.len)) {
        std::cerr << "[ERROR] Failed to send DPA frame\n";
        return 1;
    }

    // Wait for response - only show ECU responses
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    int elapsed = 0;
    int timeoutMs = 2000;  // Reduced timeout for faster testing

    while (g_running && elapsed < timeoutMs) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t source = J1939::extractSource(arbId);
            uint8_t dest = J1939::extractDest(arbId);
            uint8_t pf = J1939::extractPF(arbId);

            // Only process frames FROM the ECU or addressed TO us
            bool fromEcu = (source == ecuAddress);
            bool toUs = (dest == J1939::TOOL_ADDRESS);
            bool isProprietaryA = (pf == J1939::CLIP_PF_DATA);  // 0xEF

            if (!fromEcu && !(toUs && isProprietaryA)) {
                // Skip broadcast traffic not relevant to us
                elapsed += 100;
                continue;
            }

            // Print ECU response
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]);
                if (i < rxLen - 1) std::cout << " ";
            }
            std::cout << std::dec << " (from 0x" << std::hex << static_cast<int>(source) << ")\n";

            // Check for DPA response (0xC0 or 0x80 header)
            if (Clip::isDPAFrame(rxData, rxLen)) {
                std::cout << "     ^ *** DPA RESPONSE ***\n";
                std::cout << "     ^ Frame type: " << Clip::describeDPAFrameType(rxData[0]) << "\n";
                if (rxLen >= 5) {
                    std::cout << "     ^ CLIP instruction: " << Clip::describeCLIPInstruction(rxData[4]) << "\n";
                }
                return 0;  // Success!
            }

            // Check for diagnostic error response (0x0D)
            if (rxLen >= 3 && rxData[0] == 0x0D) {
                std::cout << "     ^ *** DIAGNOSTIC ERROR RESPONSE ***\n";
                std::cout << "     ^ Error code: 0x" << std::hex << static_cast<int>(rxData[1])
                          << " Echo: 0x" << static_cast<int>(rxData[2]) << std::dec << "\n";
                return 0;  // Got a response (even if error)
            }

            // Check for CM550 response (0x80)
            if (Clip::isCM550Response(rxData, rxLen)) {
                std::cout << "     ^ *** RESPONSE (0x80) ***\n";
                return 0;
            }
        }
        elapsed += 100;
    }

    std::cout << "[TIMEOUT] No ECU response\n";
    return 1;
}

int dpaInitMode(SocketCanAdapter& adapter, uint8_t ecuAddress)
{
    std::cout << "\n[DPA] Testing QueryInitialize (0x00) with Sync frame (0x80)\n";
    std::cout << "[DPA] Frame format: [0x80] [00] [00] [0x49] [0x00] [param] [flags] [00]\n";
    std::cout << "[DPA] This sends to PGN 0xEF00 -> diagnosticServiceDispatcher\n\n";

    Clip::RawFrame frame = Clip::buildDPAQueryInit();
    return sendDPAFrame(adapter, ecuAddress, frame, "(session init)");
}

int dpaParamMode(SocketCanAdapter& adapter, uint8_t ecuAddress, uint8_t paramId)
{
    std::cout << "\n[DPA] Testing GetParametersByID (0x10) with Async frame (0xC0)\n";
    std::cout << "[DPA] Param ID: 0x" << std::hex << static_cast<int>(paramId) << std::dec << "\n";
    std::cout << "[DPA] Frame format: [0xC0] [00] [00] [0x49] [0x10] [param] [flags] [00]\n";
    std::cout << "[DPA] This sends to PGN 0xEF00 -> diagnosticServiceDispatcher\n\n";

    Clip::RawFrame frame = Clip::buildDPAGetParam(paramId, 0x00);
    return sendDPAFrame(adapter, ecuAddress, frame, "(get param by ID)");
}

int dpaDataMode(SocketCanAdapter& adapter, uint8_t ecuAddress, uint8_t addrByte)
{
    std::cout << "\n[DPA] Testing GetDataByAddress (0x13) with Async frame (0xC0)\n";
    std::cout << "[DPA] Address byte: 0x" << std::hex << static_cast<int>(addrByte) << std::dec << "\n";
    std::cout << "[DPA] Frame format: [0xC0] [00] [00] [0x49] [0x13] [addr] [flags] [00]\n";
    std::cout << "[DPA] This sends to PGN 0xEF00 -> diagnosticServiceDispatcher\n\n";

    Clip::RawFrame frame = Clip::buildDPAGetData(addrByte, 0x00);
    return sendDPAFrame(adapter, ecuAddress, frame, "(get data by address)");
}

int dpaTestMode(SocketCanAdapter& adapter, uint8_t ecuAddress)
{
    std::cout << "\n[DPA] Running comprehensive DPA frame format tests\n";
    std::cout << "[DPA] Testing all CLIP instructions (0x00-0x15) in DPA wrapper\n";
    std::cout << "[DPA] Sending to PGN 0xEF00 -> diagnosticServiceDispatcher\n";
    std::cout << "[DPA] ECU address: 0x" << std::hex << static_cast<int>(ecuAddress) << std::dec << "\n\n";

    // Test all CLIP instructions
    struct TestCase {
        Clip::CLIPInstruction instr;
        const char* name;
        uint8_t paramByte;
    };

    TestCase tests[] = {
        { Clip::CLIPInstruction::QueryInitialize, "QueryInitialize (0x00)", 0x00 },
        { Clip::CLIPInstruction::QueryTerminate, "QueryTerminate (0x01)", 0x00 },
        { Clip::CLIPInstruction::GetParametersByID, "GetParametersByID (0x10)", 0x01 },
        { Clip::CLIPInstruction::SetParametersByID, "SetParametersByID (0x11)", 0x01 },
        { Clip::CLIPInstruction::ExecuteOperation, "ExecuteOperation (0x12)", 0x00 },
        { Clip::CLIPInstruction::GetDataByAddress, "GetDataByAddress (0x13)", 0x00 },
        { Clip::CLIPInstruction::SetDataByAddress, "SetDataByAddress (0x14)", 0x00 },
        { Clip::CLIPInstruction::GetAddressByParameterID, "GetAddressByParamID (0x15)", 0x01 },
    };

    int successCount = 0;
    int testCount = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < testCount && g_running; i++) {
        std::cout << "\n=== Test " << (i+1) << "/" << testCount << ": " << tests[i].name << " ===\n";

        // Build frame - use Sync (0x80) for init/terminate, Async (0xC0) for others
        Clip::DPAFrameType frameType = (tests[i].instr == Clip::CLIPInstruction::QueryInitialize ||
                                         tests[i].instr == Clip::CLIPInstruction::QueryTerminate)
                                         ? Clip::DPAFrameType::Sync
                                         : Clip::DPAFrameType::Async;

        Clip::RawFrame frame = Clip::buildDPAFrame(frameType, tests[i].instr, tests[i].paramByte, 0x00);

        int result = sendDPAFrame(adapter, ecuAddress, frame, tests[i].name);
        if (result == 0) {
            successCount++;
            std::cout << "[PASS] Got response\n";
        } else {
            std::cout << "[FAIL] No response\n";
        }
    }

    std::cout << "\n========================================\n";
    std::cout << "DPA Test Summary: " << successCount << "/" << testCount << " responses\n";
    std::cout << "========================================\n";

    return 0;  // Always exit cleanly
}

// =========================================================================
// DIRECT SERVICE ID TEST FUNCTIONS
// For PGN 0xEF00 diagnosticServiceDispatcher - NO DPA wrapper!
// =========================================================================

int sendServiceFrame(SocketCanAdapter& adapter, uint8_t ecuAddress,
                      const Clip::RawFrame& frame, const char* description)
{
    // Build arbitration ID for PGN 0xEF00 (Proprietary A) to ECU
    uint32_t txArbId = J1939::buildClipRequestId(ecuAddress);

    std::cout << "[TX] ";
    for (int i = 0; i < frame.len; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(frame.data[i]);
        if (i < frame.len - 1) std::cout << " ";
    }
    std::cout << std::dec << " " << description << "\n";

    if (!adapter.send(txArbId, frame.data, frame.len)) {
        std::cerr << "[ERROR] Failed to send frame\n";
        return 1;
    }

    // Wait for response (2 second timeout)
    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    int timeoutMs = 2000;
    int elapsed = 0;

    while (elapsed < timeoutMs && g_running) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t source = J1939::extractSource(arbId);
            uint8_t dest = J1939::extractDest(arbId);
            uint8_t pf = J1939::extractPF(arbId);

            // Only process frames FROM the ECU or addressed TO us
            bool fromEcu = (source == ecuAddress);
            bool toUs = (dest == J1939::TOOL_ADDRESS);
            bool isProprietaryA = (pf == J1939::CLIP_PF_DATA);  // 0xEF

            if (!fromEcu && !(toUs && isProprietaryA)) {
                elapsed += 100;
                continue;
            }

            // Print ECU response
            std::cout << "[RX] ";
            for (int i = 0; i < rxLen; i++) {
                std::cout << std::hex << std::setfill('0') << std::setw(2)
                          << static_cast<int>(rxData[i]);
                if (i < rxLen - 1) std::cout << " ";
            }
            std::cout << std::dec << " (from 0x" << std::hex << static_cast<int>(source) << ")\n";

            // Check for diagnostic error response (0x0D)
            if (rxLen >= 3 && rxData[0] == 0x0D) {
                std::cout << "     ^ ERROR: code=0x" << std::hex << static_cast<int>(rxData[1])
                          << " echo=0x" << static_cast<int>(rxData[2]) << std::dec << "\n";
                return 0;  // Got a response (even if error)
            }

            // Check for success response (0x80)
            if (rxData[0] == 0x80) {
                std::cout << "     ^ *** SUCCESS RESPONSE (0x80) ***\n";
                return 0;
            }

            // Any other response from ECU
            std::cout << "     ^ Response byte[0]: " << Clip::describeEF00ServiceID(rxData[0]) << "\n";
            return 0;
        }
        elapsed += 100;
    }

    std::cout << "[TIMEOUT] No ECU response\n";
    return 1;
}

int svcMode(SocketCanAdapter& adapter, uint8_t ecuAddress, uint8_t serviceId)
{
    std::cout << "\n[SVC] Testing direct service ID: " << Clip::describeEF00ServiceID(serviceId) << "\n";
    std::cout << "[SVC] Sending to PGN 0xEF00 -> diagnosticServiceDispatcher\n";
    std::cout << "[SVC] Format: [svcId] [00] [00] [00] [00] [00] [00] [00]\n\n";

    bool registered = Clip::isRegisteredServiceID(serviceId);
    if (!registered) {
        std::cout << "[WARN] Service ID 0x" << std::hex << static_cast<int>(serviceId)
                  << std::dec << " is NOT in registered table - expect 0x18 error\n\n";
    }

    Clip::RawFrame frame = Clip::buildServiceProbe(serviceId);
    return sendServiceFrame(adapter, ecuAddress, frame, Clip::describeEF00ServiceID(serviceId).c_str());
}

int svcTestMode(SocketCanAdapter& adapter, uint8_t ecuAddress)
{
    std::cout << "\n[SVC] Testing all 23 registered EF00 service IDs\n";
    std::cout << "[SVC] Sending directly to PGN 0xEF00 -> diagnosticServiceDispatcher\n";
    std::cout << "[SVC] Format: [svcId] [00] [00] [00] [00] [00] [00] [00]\n";
    std::cout << "[SVC] ECU address: 0x" << std::hex << static_cast<int>(ecuAddress) << std::dec << "\n\n";

    // All registered service IDs
    struct TestCase {
        uint8_t svcId;
        const char* name;
    };

    TestCase tests[] = {
        // CLIP-compatible services (most likely to work)
        { 0x10, "GetParametersByID (0x10) - CLIP compatible" },
        { 0x15, "GetAddressByParameterID (0x15) - CLIP compatible" },
        { 0x01, "QueryTerminate (0x01) - CLIP compatible" },

        // System services (0x0x range)
        { 0x04, "SystemService04 (0x04)" },
        { 0x05, "SystemService05 (0x05)" },
        { 0x06, "SystemService06 (0x06)" },
        { 0x07, "SystemService07 (0x07)" },
        { 0x0A, "SystemService0A (0x0A)" },
        { 0x0B, "SystemService0B (0x0B)" },
        { 0x0F, "SystemService0F (0x0F) - same handler as 0x10" },
        { 0x16, "SystemService16 (0x16)" },
        { 0x18, "SystemService18 (0x18)" },

        // 0x4x range services
        { 0x41, "Service41 (0x41)" },
        { 0x43, "Service43 (0x43)" },
        { 0x44, "Service44 (0x44)" },
        { 0x45, "Service45 (0x45) - same handler as 0x44" },
        { 0x46, "Service46 (0x46)" },
        { 0x47, "Service47 (0x47)" },
        { 0x48, "Service48 (0x48)" },
        { 0x49, "Service49 (0x49)" },
        { 0x4A, "Service4A (0x4A)" },
        { 0x4B, "Service4B (0x4B)" },
        { 0x4C, "Service4C (0x4C)" },
        { 0x4D, "Service4D (0x4D)" },
    };

    int successCount = 0;
    int errorCount = 0;
    int timeoutCount = 0;
    int testCount = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < testCount && g_running; i++) {
        std::cout << "\n=== Test " << (i+1) << "/" << testCount << ": " << tests[i].name << " ===\n";

        Clip::RawFrame frame = Clip::buildServiceProbe(tests[i].svcId);
        int result = sendServiceFrame(adapter, ecuAddress, frame, tests[i].name);

        if (result == 0) {
            successCount++;
            std::cout << "[PASS] Got response\n";
        } else {
            timeoutCount++;
            std::cout << "[FAIL] No response\n";
        }
    }

    std::cout << "\n========================================\n";
    std::cout << "Service ID Test Summary:\n";
    std::cout << "  Responses: " << successCount << "/" << testCount << "\n";
    std::cout << "  Timeouts:  " << timeoutCount << "/" << testCount << "\n";
    std::cout << "========================================\n";

    return 0;  // Always exit cleanly
}

// =========================================================================
// SERVICE 0x4B WITH J1939 TRANSPORT PROTOCOL FLOW CONTROL
// This service triggers ECU to send multi-frame data via TP.CM/TP.DT
// =========================================================================

int svcTPMode(SocketCanAdapter& adapter, uint8_t ecuAddress, uint8_t serviceId,
              uint32_t ramAddr = 0, uint16_t readLen = 0)
{
    std::cout << "\n[SVC-TP] Testing Service 0x" << std::hex << static_cast<int>(serviceId)
              << std::dec << " with J1939 Transport Protocol\n";
    std::cout << "[SVC-TP] This service may trigger ECU to send multi-frame data\n";
    std::cout << "[SVC-TP] Protocol: Send service -> Wait RTS -> Send CTS -> Receive TP.DT\n";
    std::cout << "[SVC-TP] ECU address: 0x" << std::hex << static_cast<int>(ecuAddress) << std::dec << "\n";

    if (ramAddr != 0) {
        std::cout << "[SVC-TP] RAM Address: 0x" << std::hex << ramAddr << std::dec << "\n";
        std::cout << "[SVC-TP] Read Length: " << readLen << " bytes\n";
    }
    std::cout << "\n";

    // Step 1: Send service request
    std::cout << "=== Step 1: Send Service 0x" << std::hex << static_cast<int>(serviceId)
              << std::dec << " ===\n";

    Clip::RawFrame frame;
    if (ramAddr != 0 && serviceId == 0x49) {
        // Service 0x49 format based on j1939DataCopyWrapperExtended:
        // Byte 0: Service ID (0x49)
        // Bytes 1-2: Command/mode (2 bytes) - use 0x0000 for now
        // Bytes 3-6: Address (4 bytes, big-endian)
        // Byte 7: Length low byte
        // NOTE: Requires 11+ bytes total - this will fail with error 0x02!
        frame = Clip::buildServiceProbe(
            serviceId,
            0x00,                                    // Byte 1: cmd high
            0x00,                                    // Byte 2: cmd low
            static_cast<uint8_t>((ramAddr >> 24) & 0xFF),  // Byte 3: addr[31:24]
            static_cast<uint8_t>((ramAddr >> 16) & 0xFF),  // Byte 4: addr[23:16]
            static_cast<uint8_t>((ramAddr >> 8) & 0xFF),   // Byte 5: addr[15:8]
            static_cast<uint8_t>(ramAddr & 0xFF),          // Byte 6: addr[7:0]
            static_cast<uint8_t>(readLen & 0xFF)           // Byte 7: length low
        );
        std::cout << "[INFO] Sending with RAM address 0x" << std::hex << ramAddr
                  << " length " << std::dec << readLen << "\n";
    } else if (ramAddr != 0 && serviceId == 0x4A) {
        // Service 0x4A format: Memory read with 4-byte address + 1-byte length
        // Byte 0: Service ID (0x4A)
        // Bytes 1-4: Address (4 bytes, big-endian)
        // Byte 5: Length (1 byte)
        // Bytes 6-7: Padding (0x00)
        // Total: 6 bytes - fits in single CAN frame!
        frame = Clip::buildServiceProbe(
            serviceId,
            static_cast<uint8_t>((ramAddr >> 24) & 0xFF),  // Byte 1: addr[31:24]
            static_cast<uint8_t>((ramAddr >> 16) & 0xFF),  // Byte 2: addr[23:16]
            static_cast<uint8_t>((ramAddr >> 8) & 0xFF),   // Byte 3: addr[15:8]
            static_cast<uint8_t>(ramAddr & 0xFF),          // Byte 4: addr[7:0]
            static_cast<uint8_t>(readLen & 0xFF),          // Byte 5: length
            0x00,                                          // Byte 6: padding
            0x00                                           // Byte 7: padding
        );
        std::cout << "[INFO] Service 0x4A: 4-byte addr + 1-byte len (fits single frame)\n";
        std::cout << "[INFO] Sending addr=0x" << std::hex << ramAddr
                  << " len=" << std::dec << readLen << "\n";
    } else {
        frame = Clip::buildServiceProbe(serviceId);
    }

    uint32_t txArbId = J1939::buildClipRequestId(ecuAddress);
    std::cout << "[TX] ";
    for (int i = 0; i < frame.len; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(frame.data[i]);
        if (i < frame.len - 1) std::cout << " ";
    }
    std::cout << std::dec << " (Service 0x" << std::hex << static_cast<int>(serviceId)
              << std::dec << ")\n";

    if (!adapter.send(txArbId, frame.data, frame.len)) {
        std::cerr << "[ERROR] Failed to send frame\n";
        return 1;
    }

    // Step 2: Wait for RTS response on PGN 0xEC00 (TP.CM) or error on PGN 0xEF00
    std::cout << "\n=== Step 2: Wait for TP.CM RTS (or error response) ===\n";

    uint32_t arbId;
    uint8_t rxData[8];
    uint8_t rxLen;
    int timeoutMs = 3000;
    int elapsed = 0;
    bool gotRTS = false;
    bool gotError = false;
    J1939::TPConnectionMessage rts;

    while (elapsed < timeoutMs && g_running && !gotRTS && !gotError) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t source = J1939::extractSource(arbId);
            uint8_t dest = J1939::extractDest(arbId);
            uint8_t pf = J1939::extractPF(arbId);

            // Check for error response on PGN 0xEF00 addressed to us
            if (pf == J1939::CLIP_PF_DATA && dest == J1939::TOOL_ADDRESS && source == ecuAddress) {
                if (rxData[0] == 0x0D) {
                    std::cout << "[RX] ";
                    for (int i = 0; i < rxLen; i++) {
                        std::cout << std::hex << std::setfill('0') << std::setw(2)
                                  << static_cast<int>(rxData[i]);
                        if (i < rxLen - 1) std::cout << " ";
                    }
                    std::cout << std::dec << " (Error response from ECU)\n";
                    std::cout << "     ^ ERROR: code=0x" << std::hex << static_cast<int>(rxData[1])
                              << " echo=0x" << static_cast<int>(rxData[2]) << std::dec << "\n";

                    // Error code interpretation
                    switch (rxData[1]) {
                        case 0x02: std::cout << "     ^ Error 0x02: Invalid message length\n"; break;
                        case 0x03: std::cout << "     ^ Error 0x03: Security check failed\n"; break;
                        case 0x04: std::cout << "     ^ Error 0x04: Invalid parameters / buffer overflow\n"; break;
                        case 0x08: std::cout << "     ^ Error 0x08: Address lookup failed\n"; break;
                        case 0x09: std::cout << "     ^ Error 0x09: Address range invalid\n"; break;
                        case 0x0A: std::cout << "     ^ Error 0x0A: Address type rejected\n"; break;
                        case 0x18: std::cout << "     ^ Error 0x18: Unknown service\n"; break;
                        default: std::cout << "     ^ Unknown error code\n"; break;
                    }
                    gotError = true;
                    continue;
                }
            }

            // Look for TP.CM from ECU (PF=0xEC)
            if (pf == J1939::TP_PF_CM && source == ecuAddress) {
                std::cout << "[RX] ";
                for (int i = 0; i < rxLen; i++) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(rxData[i]);
                    if (i < rxLen - 1) std::cout << " ";
                }
                std::cout << std::dec << " (TP.CM from ECU)\n";

                if (rts.decode(rxData, rxLen) && rts.isRTS()) {
                    std::cout << "     ^ " << rts.toString() << "\n";
                    gotRTS = true;
                }
            }
        }
        elapsed += 100;
    }

    if (gotError) {
        std::cout << "\n[INFO] ECU returned error - service 0x4B may require specific conditions:\n";
        std::cout << "       - Engine running state\n";
        std::cout << "       - Prior session initialization\n";
        std::cout << "       - Specific parameter in request bytes\n";
        std::cout << "       Try running --svc-test again to see if response varies\n";
        return 1;
    }

    if (!gotRTS) {
        std::cout << "[TIMEOUT] No RTS received from ECU\n";
        return 1;
    }

    // Step 3: Send CTS response
    std::cout << "\n=== Step 3: Send TP.CM CTS ===\n";

    uint8_t ctsData[8];
    J1939::buildCTS(rts.numPackets, 1, rts.pgn, ctsData);

    uint32_t ctsArbId = J1939::buildTPCMArbId(ecuAddress);
    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(ctsData[i]);
        if (i < 7) std::cout << " ";
    }
    std::cout << std::dec << " (CTS: accept " << static_cast<int>(rts.numPackets)
              << " packets for PGN 0x" << std::hex << rts.pgn << std::dec << ")\n";

    if (!adapter.send(ctsArbId, ctsData, 8)) {
        std::cerr << "[ERROR] Failed to send CTS\n";
        return 1;
    }

    // Step 4: Receive TP.DT frames
    std::cout << "\n=== Step 4: Receive TP.DT Data ===\n";

    J1939::TPSession session;
    session.pgn = rts.pgn;
    session.sourceAddress = ecuAddress;
    session.expectedBytes = rts.totalBytes;
    session.expectedPackets = rts.numPackets;
    session.receivedPackets = 0;
    session.data.clear();
    session.data.reserve(rts.totalBytes);
    session.active = true;

    timeoutMs = 5000;
    elapsed = 0;

    while (elapsed < timeoutMs && g_running && !session.isComplete()) {
        if (adapter.recv(arbId, rxData, rxLen, 100)) {
            uint8_t source = J1939::extractSource(arbId);
            uint8_t dest = J1939::extractDest(arbId);
            uint8_t pf = J1939::extractPF(arbId);

            // Look for TP.DT from ECU addressed TO US (PF=0xEB, dest=0xF9)
            // Filter out broadcast TP.DT (dest=0xFF) which is unrelated traffic
            if (pf == J1939::TP_PF_DT && source == ecuAddress && dest == J1939::TOOL_ADDRESS) {
                uint8_t seqNum = rxData[0];

                std::cout << "[RX] ";
                for (int i = 0; i < rxLen; i++) {
                    std::cout << std::hex << std::setfill('0') << std::setw(2)
                              << static_cast<int>(rxData[i]);
                    if (i < rxLen - 1) std::cout << " ";
                }
                std::cout << std::dec << " (TP.DT #" << static_cast<int>(seqNum)
                          << "/" << static_cast<int>(rts.numPackets) << ")\n";

                // Check if this is actually an error response (0x0D prefix)
                if (seqNum == 1 && rxData[1] == 0x0D) {
                    std::cout << "     ^ ERROR response via TP: code=0x"
                              << std::hex << static_cast<int>(rxData[2])
                              << " svc=0x" << static_cast<int>(rxData[3]) << std::dec << "\n";
                    switch (rxData[2]) {
                        case 0x02: std::cout << "     ^ Error 0x02: Invalid message length (need multi-frame request?)\n"; break;
                        case 0x03: std::cout << "     ^ Error 0x03: Security check failed\n"; break;
                        case 0x09: std::cout << "     ^ Error 0x09: Address range invalid\n"; break;
                        default: break;
                    }
                }

                // Add frame payload (bytes 1-7) to session
                if (session.addFrame(seqNum, &rxData[1], rxLen - 1)) {
                    std::cout << "     ^ Added " << (rxLen - 1) << " bytes, total: "
                              << session.data.size() << "/" << rts.totalBytes << "\n";
                }
            }
        }
        elapsed += 100;
    }

    // Step 5: Display results
    std::cout << "\n=== Step 5: Results ===\n";

    if (session.isComplete()) {
        std::cout << "[SUCCESS] Received complete message (" << session.data.size() << " bytes)\n\n";
        std::cout << "Data hex dump:\n";
        std::cout << session.hexDump() << "\n\n";

        // Try to interpret as ASCII if printable
        std::cout << "ASCII interpretation:\n  ";
        for (size_t i = 0; i < session.data.size(); i++) {
            char c = static_cast<char>(session.data[i]);
            if (c >= 32 && c < 127) {
                std::cout << c;
            } else {
                std::cout << '.';
            }
        }
        std::cout << "\n";

        // Send EOM acknowledgment (optional but good practice)
        uint8_t eomData[8];
        J1939::buildEOM(session.data.size(), session.receivedPackets, rts.pgn, eomData);
        adapter.send(ctsArbId, eomData, 8);
        std::cout << "\n[TX] Sent EOM acknowledgment\n";

    } else {
        std::cout << "[INCOMPLETE] Only received " << session.data.size()
                  << "/" << rts.totalBytes << " bytes\n";
        if (session.data.size() > 0) {
            std::cout << "Partial data:\n";
            std::cout << session.hexDump() << "\n";
        }
    }

    return 0;
}

// =========================================================================
// DUMP RAM MODE - Read entire ECU RAM region to file using service 0x4A
// RAM range: 0x800000 - 0x8091C2 (37,315 bytes)
// =========================================================================

int dumpRamMode(SocketCanAdapter& adapter, uint8_t ecuAddress, const std::string& filename)
{
    constexpr uint32_t RAM_START = 0x800000;
    constexpr uint32_t RAM_END = 0x8091C2;
    constexpr uint32_t TOTAL_BYTES = RAM_END - RAM_START + 1;  // 37,315 bytes
    constexpr uint8_t CHUNK_SIZE = 128;  // bytes per read (max 255)

    std::cout << "\n[DUMP] CM550 RAM Dump via Service 0x4A\n";
    std::cout << "[DUMP] Range: 0x" << std::hex << RAM_START << " - 0x" << RAM_END << std::dec << "\n";
    std::cout << "[DUMP] Total: " << TOTAL_BYTES << " bytes\n";
    std::cout << "[DUMP] Output: " << filename << "\n\n";

    // Open output file
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "[ERROR] Failed to open output file: " << filename << "\n";
        return 1;
    }

    uint32_t addr = RAM_START;
    uint32_t bytesRead = 0;
    int errors = 0;

    while (addr <= RAM_END && g_running) {
        // Calculate chunk size (don't exceed end)
        uint32_t remaining = RAM_END - addr + 1;
        uint8_t chunkLen = (remaining < CHUNK_SIZE) ? static_cast<uint8_t>(remaining) : CHUNK_SIZE;

        // Progress bar
        int percent = (bytesRead * 100) / TOTAL_BYTES;
        std::cout << "\r[" << std::setw(3) << percent << "%] 0x" << std::hex << std::setfill('0')
                  << std::setw(6) << addr << std::dec << std::setfill(' ')
                  << " (" << bytesRead << "/" << TOTAL_BYTES << " bytes)" << std::flush;

        // Build service 0x4A request
        Clip::RawFrame frame = Clip::buildServiceProbe(
            0x4A,
            static_cast<uint8_t>((addr >> 24) & 0xFF),
            static_cast<uint8_t>((addr >> 16) & 0xFF),
            static_cast<uint8_t>((addr >> 8) & 0xFF),
            static_cast<uint8_t>(addr & 0xFF),
            chunkLen,
            0x00,
            0x00
        );

        // Send request
        uint32_t txArbId = J1939::buildClipRequestId(ecuAddress);
        if (!adapter.send(txArbId, frame.data, frame.len)) {
            std::cerr << "\n[ERROR] Failed to send request at 0x" << std::hex << addr << std::dec << "\n";
            errors++;
            if (errors > 5) break;
            continue;
        }

        // Wait for response (TP.CM RTS or error)
        uint32_t arbId;
        uint8_t rxData[8];
        uint8_t rxLen;
        int elapsed = 0;
        bool gotRTS = false;
        bool gotError = false;
        J1939::TPConnectionMessage rts;

        while (elapsed < 2000 && !gotRTS && !gotError) {
            if (adapter.recv(arbId, rxData, rxLen, 50)) {
                uint8_t source = J1939::extractSource(arbId);
                uint8_t dest = J1939::extractDest(arbId);
                uint8_t pf = J1939::extractPF(arbId);

                // Error response on EF00
                if (pf == J1939::CLIP_PF_DATA && dest == J1939::TOOL_ADDRESS && source == ecuAddress) {
                    if (rxData[0] == 0x0D) {
                        std::cerr << "\n[ERROR] at 0x" << std::hex << addr << ": code=0x"
                                  << static_cast<int>(rxData[1]) << std::dec << "\n";
                        gotError = true;
                    }
                }

                // TP.CM RTS
                if (pf == J1939::TP_PF_CM && source == ecuAddress) {
                    if (rts.decode(rxData, rxLen) && rts.isRTS()) {
                        gotRTS = true;
                    }
                }
            }
            elapsed += 50;
        }

        if (gotError) {
            errors++;
            if (errors > 5) {
                std::cerr << "[ERROR] Too many errors, aborting\n";
                break;
            }
            addr += chunkLen;
            continue;
        }

        if (!gotRTS) {
            std::cerr << "\n[TIMEOUT] No response at 0x" << std::hex << addr << std::dec << "\n";
            errors++;
            if (errors > 5) break;
            addr += chunkLen;
            continue;
        }

        // Send CTS
        uint8_t ctsData[8];
        J1939::buildCTS(rts.numPackets, 1, rts.pgn, ctsData);
        uint32_t ctsArbId = J1939::buildTPCMArbId(ecuAddress);
        adapter.send(ctsArbId, ctsData, 8);

        // Receive TP.DT frames
        J1939::TPSession session;
        session.pgn = rts.pgn;
        session.sourceAddress = ecuAddress;
        session.expectedBytes = rts.totalBytes;
        session.expectedPackets = rts.numPackets;
        session.receivedPackets = 0;
        session.data.clear();
        session.data.reserve(rts.totalBytes);
        session.active = true;

        elapsed = 0;
        while (elapsed < 3000 && !session.isComplete()) {
            if (adapter.recv(arbId, rxData, rxLen, 50)) {
                uint8_t source = J1939::extractSource(arbId);
                uint8_t dest = J1939::extractDest(arbId);
                uint8_t pf = J1939::extractPF(arbId);

                if (pf == J1939::TP_PF_DT && source == ecuAddress && dest == J1939::TOOL_ADDRESS) {
                    uint8_t seqNum = rxData[0];
                    session.addFrame(seqNum, &rxData[1], rxLen - 1);
                }
            }
            elapsed += 50;
        }

        // Send EOM
        uint8_t eomData[8];
        J1939::buildEOM(session.data.size(), session.receivedPackets, rts.pgn, eomData);
        adapter.send(ctsArbId, eomData, 8);

        if (session.isComplete() && session.data.size() >= 6) {
            // Response format: [4B][addr4][len][data...]
            // Skip 6 header bytes, write actual data
            size_t dataStart = 6;
            size_t dataLen = session.data.size() - dataStart;

            if (dataLen > 0 && dataLen <= chunkLen) {
                outFile.write(reinterpret_cast<const char*>(&session.data[dataStart]), dataLen);
                bytesRead += dataLen;
                addr += dataLen;
                errors = 0;  // Reset error count on success
            } else {
                std::cerr << "\n[WARNING] Unexpected data length at 0x" << std::hex << addr << std::dec << "\n";
                addr += chunkLen;
            }
        } else {
            std::cerr << "\n[WARNING] Incomplete response at 0x" << std::hex << addr << std::dec << "\n";
            addr += chunkLen;
            errors++;
        }

        // Small delay between requests
        usleep(10000);  // 10ms
    }

    std::cout << "\n\n[DONE] Wrote " << bytesRead << " bytes to " << filename << "\n";
    outFile.close();

    return (bytesRead == TOTAL_BYTES) ? 0 : 1;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }

    std::string interface = argv[1];
    bool monitorOnly = false;
    bool rawMode_flag = false;
    bool readMode_flag = false;
    bool j1939Mode_flag = false;
    bool cm550ParamMode_flag = false;
    bool cm550StatusMode_flag = false;
    bool cm550RawMode_flag = false;
    bool dpaInitMode_flag = false;
    bool dpaParamMode_flag = false;
    bool dpaDataMode_flag = false;
    bool dpaTestMode_flag = false;
    bool svcTestMode_flag = false;
    bool svcMode_flag = false;
    bool svcTPMode_flag = false;
    bool dumpRamMode_flag = false;
    uint8_t svcTPId = 0x4B;  // Default to 0x4B, can be set to 0x49 etc.
    std::string dumpRamFilename = "cm550_ram.bin";
    uint32_t svc49RamAddr = 0;  // RAM address for --svc-49-ram
    uint16_t svc49RamLen = 16;  // Length for --svc-49-ram
    std::string rawBytes;
    std::string cm550RawBytes;
    uint32_t readAddress = 0;
    uint16_t readLength = 16;
    uint32_t j1939Pgn = 0;
    uint8_t ecuAddress = 0x00;
    uint8_t cm550ParamCmd = 0x00;
    uint16_t cm550GuardWord = 0x0000;
    uint8_t cm550StatusType = 0x00;
    uint8_t dpaParamId = 0x00;
    uint8_t dpaAddrByte = 0x00;
    uint8_t svcId = 0x00;

    if (argc >= 3) {
        std::string arg2 = argv[2];
        if (arg2 == "--monitor" || arg2 == "-m") {
            monitorOnly = true;
        } else if (arg2 == "--raw" || arg2 == "-r") {
            rawMode_flag = true;
            if (argc >= 4) {
                rawBytes = argv[3];
            } else {
                std::cerr << "[ERROR] --raw requires hex bytes argument\n";
                return 1;
            }
        } else if (arg2 == "--read") {
            readMode_flag = true;
            if (argc >= 4) {
                char* endptr;
                readAddress = std::strtoul(argv[3], &endptr, 0);
                if (*endptr != '\0') {
                    std::cerr << "[ERROR] Invalid address: " << argv[3] << "\n";
                    return 1;
                }
                if (argc >= 5) {
                    readLength = static_cast<uint16_t>(std::strtoul(argv[4], &endptr, 0));
                    if (*endptr != '\0' || readLength == 0 || readLength > 256) {
                        std::cerr << "[ERROR] Invalid length (1-256): " << argv[4] << "\n";
                        return 1;
                    }
                }
            } else {
                std::cerr << "[ERROR] --read requires address argument\n";
                return 1;
            }
        } else if (arg2 == "--j1939") {
            j1939Mode_flag = true;
            if (argc >= 4) {
                char* endptr;
                j1939Pgn = std::strtoul(argv[3], &endptr, 0);
                if (*endptr != '\0') {
                    std::cerr << "[ERROR] Invalid PGN: " << argv[3] << "\n";
                    return 1;
                }
                // Optional ECU address as 4th argument
                if (argc >= 5) {
                    long val = std::strtol(argv[4], &endptr, 0);
                    if (*endptr == '\0' && val >= 0 && val <= 255) {
                        ecuAddress = static_cast<uint8_t>(val);
                    } else {
                        std::cerr << "[ERROR] Invalid ECU address: " << argv[4] << "\n";
                        return 1;
                    }
                }
            } else {
                std::cerr << "[ERROR] --j1939 requires PGN argument\n";
                return 1;
            }
        } else if (arg2 == "--cm550-param") {
            cm550ParamMode_flag = true;
            // Optional param cmd as 3rd argument
            if (argc >= 4) {
                char* endptr;
                long val = std::strtol(argv[3], &endptr, 0);
                if (*endptr == '\0' && val >= 0 && val <= 255) {
                    cm550ParamCmd = static_cast<uint8_t>(val);
                }
            }
            // Optional guard word as 4th argument
            if (argc >= 5) {
                char* endptr;
                long val = std::strtol(argv[4], &endptr, 0);
                if (*endptr == '\0' && val >= 0 && val <= 65535) {
                    cm550GuardWord = static_cast<uint16_t>(val);
                }
            }
        } else if (arg2 == "--cm550-status") {
            cm550StatusMode_flag = true;
            // Optional status type as 3rd argument
            if (argc >= 4) {
                char* endptr;
                long val = std::strtol(argv[3], &endptr, 0);
                if (*endptr == '\0' && val >= 0 && val <= 255) {
                    cm550StatusType = static_cast<uint8_t>(val);
                }
            }
        } else if (arg2 == "--cm550-raw") {
            cm550RawMode_flag = true;
            if (argc >= 4) {
                cm550RawBytes = argv[3];
            } else {
                std::cerr << "[ERROR] --cm550-raw requires hex bytes argument\n";
                return 1;
            }
        } else if (arg2 == "--dpa-init") {
            dpaInitMode_flag = true;
        } else if (arg2 == "--dpa-param") {
            dpaParamMode_flag = true;
            // Optional param ID as 3rd argument
            if (argc >= 4) {
                char* endptr;
                long val = std::strtol(argv[3], &endptr, 0);
                if (*endptr == '\0' && val >= 0 && val <= 255) {
                    dpaParamId = static_cast<uint8_t>(val);
                }
            }
        } else if (arg2 == "--dpa-data") {
            dpaDataMode_flag = true;
            // Optional address byte as 3rd argument
            if (argc >= 4) {
                char* endptr;
                long val = std::strtol(argv[3], &endptr, 0);
                if (*endptr == '\0' && val >= 0 && val <= 255) {
                    dpaAddrByte = static_cast<uint8_t>(val);
                }
            }
        } else if (arg2 == "--dpa-test") {
            dpaTestMode_flag = true;
        } else if (arg2 == "--svc-test") {
            svcTestMode_flag = true;
        } else if (arg2 == "--svc") {
            svcMode_flag = true;
            if (argc >= 4) {
                char* endptr;
                long val = std::strtol(argv[3], &endptr, 0);
                if (*endptr == '\0' && val >= 0 && val <= 255) {
                    svcId = static_cast<uint8_t>(val);
                } else {
                    std::cerr << "[ERROR] Invalid service ID: " << argv[3] << "\n";
                    return 1;
                }
            } else {
                std::cerr << "[ERROR] --svc requires service ID argument (e.g., --svc 0x10)\n";
                return 1;
            }
        } else if (arg2 == "--svc-4b") {
            svcTPMode_flag = true;
            svcTPId = 0x4B;
        } else if (arg2 == "--svc-49") {
            svcTPMode_flag = true;
            svcTPId = 0x49;
        } else if (arg2 == "--svc-49-ram") {
            svcTPMode_flag = true;
            svcTPId = 0x49;
            svc49RamAddr = 0x800000;  // Default: start of valid RAM region
            svc49RamLen = 16;
            // Optional: parse address from arg3
            if (argc >= 4) {
                char* endptr;
                svc49RamAddr = std::strtoul(argv[3], &endptr, 0);
                if (*endptr != '\0') {
                    std::cerr << "[ERROR] Invalid RAM address: " << argv[3] << "\n";
                    return 1;
                }
                // Validate address is in valid RAM range (0x800000 - 0x8091C2)
                if (svc49RamAddr < 0x800000 || svc49RamAddr > 0x8091C2) {
                    std::cerr << "[WARNING] Address 0x" << std::hex << svc49RamAddr
                              << " outside valid RAM range 0x800000-0x8091C2\n" << std::dec;
                }
            }
            // Optional: parse length from arg4
            if (argc >= 5) {
                char* endptr;
                svc49RamLen = static_cast<uint16_t>(std::strtoul(argv[4], &endptr, 0));
                if (*endptr != '\0' || svc49RamLen == 0 || svc49RamLen > 256) {
                    std::cerr << "[ERROR] Invalid length (1-256): " << argv[4] << "\n";
                    return 1;
                }
            }
            std::cout << "[INFO] Service 0x49 RAM read: addr=0x" << std::hex << svc49RamAddr
                      << " len=" << std::dec << svc49RamLen << "\n";
        } else if (arg2 == "--svc-4a") {
            // Service 0x4A: Memory read with 4-byte address + 1-byte length
            // This fits in single 8-byte CAN frame!
            svcTPMode_flag = true;
            svcTPId = 0x4A;
            svc49RamAddr = 0x800000;  // Default: start of valid RAM region
            svc49RamLen = 16;
            // Optional: parse address from arg3
            if (argc >= 4) {
                char* endptr;
                svc49RamAddr = std::strtoul(argv[3], &endptr, 0);
                if (*endptr != '\0') {
                    std::cerr << "[ERROR] Invalid RAM address: " << argv[3] << "\n";
                    return 1;
                }
            }
            // Optional: parse length from arg4 (max 255 for 1-byte length)
            if (argc >= 5) {
                char* endptr;
                svc49RamLen = static_cast<uint16_t>(std::strtoul(argv[4], &endptr, 0));
                if (*endptr != '\0' || svc49RamLen == 0 || svc49RamLen > 255) {
                    std::cerr << "[ERROR] Invalid length (1-255): " << argv[4] << "\n";
                    return 1;
                }
            }
            std::cout << "[INFO] Service 0x4A RAM read: addr=0x" << std::hex << svc49RamAddr
                      << " len=" << std::dec << svc49RamLen << "\n";
        } else if (arg2 == "--dump-ram") {
            // Dump full CM550 RAM region to file
            dumpRamMode_flag = true;
            // Optional: custom filename from arg3
            if (argc >= 4) {
                dumpRamFilename = argv[3];
            }
        } else {
            // Parse as hex or decimal
            char* endptr;
            long val = std::strtol(arg2.c_str(), &endptr, 0);
            if (*endptr == '\0' && val >= 0 && val <= 255) {
                ecuAddress = static_cast<uint8_t>(val);
            } else {
                std::cerr << "Invalid ECU address: " << arg2 << "\n";
                return 1;
            }
        }
    }

    // Set up signal handler
    signal(SIGINT, signalHandler);

    // Create adapter with logging
    // For --read mode, only log TX to reduce noise (RX is logged selectively by application)
    SocketCanAdapter adapter;
    if (readMode_flag) {
        adapter.setLogCallback([](const std::string& msg) {
            // Only log TX messages, skip RX (too noisy with J1939 broadcast traffic)
            if (msg.find("[TX]") != std::string::npos ||
                msg.find("[CAN]") != std::string::npos) {
                std::cout << msg << "\n";
            }
        });
    } else {
        adapter.setLogCallback([](const std::string& msg) {
            std::cout << msg << "\n";
        });
    }

    // Open interface
    std::cout << "[INFO] Opening CAN interface: " << interface << "\n";
    if (!adapter.open(interface)) {
        std::cerr << "[ERROR] Failed to open interface\n";
        return 1;
    }

    int result;
    if (monitorOnly) {
        result = monitorMode(adapter);
    } else if (rawMode_flag) {
        result = rawMode(adapter, ecuAddress, rawBytes);
    } else if (readMode_flag) {
        result = readMode(adapter, ecuAddress, readAddress, readLength);
    } else if (j1939Mode_flag) {
        result = j1939Mode(adapter, ecuAddress, j1939Pgn);
    } else if (cm550ParamMode_flag) {
        result = cm550ParamMode(adapter, ecuAddress, cm550ParamCmd, cm550GuardWord);
    } else if (cm550StatusMode_flag) {
        result = cm550StatusMode(adapter, ecuAddress, cm550StatusType);
    } else if (cm550RawMode_flag) {
        result = cm550RawMode(adapter, ecuAddress, cm550RawBytes);
    } else if (dpaInitMode_flag) {
        result = dpaInitMode(adapter, ecuAddress);
    } else if (dpaParamMode_flag) {
        result = dpaParamMode(adapter, ecuAddress, dpaParamId);
    } else if (dpaDataMode_flag) {
        result = dpaDataMode(adapter, ecuAddress, dpaAddrByte);
    } else if (dpaTestMode_flag) {
        result = dpaTestMode(adapter, ecuAddress);
    } else if (svcTestMode_flag) {
        result = svcTestMode(adapter, ecuAddress);
    } else if (svcMode_flag) {
        result = svcMode(adapter, ecuAddress, svcId);
    } else if (svcTPMode_flag) {
        result = svcTPMode(adapter, ecuAddress, svcTPId, svc49RamAddr, svc49RamLen);
    } else if (dumpRamMode_flag) {
        result = dumpRamMode(adapter, ecuAddress, dumpRamFilename);
    } else {
        result = connectMode(adapter, ecuAddress);
    }

    adapter.close();
    return result;
}
