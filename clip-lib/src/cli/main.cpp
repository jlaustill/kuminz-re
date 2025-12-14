#include "../can/SocketCanAdapter.h"
#include "../j1939/J1939.h"
#include "../clip/Frame.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <csignal>

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
    std::cerr << "  " << progname << " <interface> --read <address> [length]\n\n";
    std::cerr << "Examples:\n";
    std::cerr << "  " << progname << " can0           # Connect to ECU at address 0x00\n";
    std::cerr << "  " << progname << " can0 0         # Same as above\n";
    std::cerr << "  " << progname << " can0 --monitor # Just monitor CAN traffic\n";
    std::cerr << "  " << progname << " can0 --raw 020100010000 # Send raw bytes\n";
    std::cerr << "  " << progname << " can0 --read 0x800000 16 # Read 16 bytes from RAM\n";
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

    // Wait for SeedReply
    uint8_t ecuConnectionId = 0;
    uint8_t encryptionLevel1 = 0;
    uint8_t encryptionLevel2 = 0;
    uint8_t seed[4] = {0};
    bool gotSeedReply = false;

    int timeoutMs = 3000;
    int elapsed = 0;

    while (elapsed < timeoutMs && g_running && !gotSeedReply) {
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
                    // Check for SeedReply (control byte = 0x02)
                    if (respFrame.control == static_cast<uint8_t>(Clip::ControlType::SeedReply)) {
                        ecuConnectionId = respFrame.connectionId;
                        // Parse seed data from payload
                        // Payload: [encLevel1][encLevel2][seed0][seed1][seed2] (5 bytes)
                        if (respFrame.payloadLen >= 2) {
                            encryptionLevel1 = respFrame.payload[0];
                            encryptionLevel2 = respFrame.payload[1];
                        }
                        if (respFrame.payloadLen >= 5) {
                            // Only 3 more bytes in 8-byte frame, seed continues in next frame?
                            seed[0] = respFrame.payload[2];
                            seed[1] = respFrame.payload[3];
                            seed[2] = respFrame.payload[4];
                            // Note: 4th byte of seed may be in next frame or padding
                            seed[3] = 0xFF;  // Assume 0xFF for now
                        }
                        gotSeedReply = true;
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
                }
            }
        }
        elapsed += 100;
    }

    if (!gotSeedReply) {
        std::cerr << "[ERROR] Did not receive SeedReply\n";
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
    // STEP 3: Send CLIP instruction (getDataByAddress = 0x13)
    // From Insite analysis: instruction is 8 bytes
    // [cmd(1)] [reqId(1)] [addr(4, big-endian)] [len(2, big-endian)]
    // ============================================================
    std::cout << "\n[STEP 3] Sending getDataByAddress instruction (0x13)...\n";

    // Build the instruction (8 bytes)
    uint8_t instruction[8];
    instruction[0] = 0x13;  // Command: getDataByAddress
    instruction[1] = 0x01;  // Request ID
    // Address in big-endian
    instruction[2] = (address >> 24) & 0xFF;
    instruction[3] = (address >> 16) & 0xFF;
    instruction[4] = (address >> 8) & 0xFF;
    instruction[5] = address & 0xFF;
    // Length in big-endian
    instruction[6] = (length >> 8) & 0xFF;
    instruction[7] = length & 0xFF;

    std::cout << "[INFO] Instruction: cmd=0x13 reqId=0x01 addr=0x"
              << std::hex << std::setfill('0') << std::setw(8) << address
              << " len=" << std::dec << length << "\n";

    // ============================================================
    // TEST SERIES: Try different DataTransfer formats
    // The ECU echoes our byte 0 in control - something is wrong with format
    // ============================================================

    // TEST A: Maybe control byte should contain total message length
    std::cout << "\n[TEST A] Control = total message length (8 bytes)...\n";
    uint8_t testA[8];
    testA[0] = (0 << 5) | 0x03;       // sequence 0, DataTransfer
    testA[1] = ecuConnectionId;        // ECU's connection ID
    testA[2] = 0x08;                   // Control = total instruction length
    testA[3] = 0x13;                   // Command: getDataByAddress
    testA[4] = 0x01;                   // Request ID
    testA[5] = (address >> 24) & 0xFF;
    testA[6] = (address >> 16) & 0xFF;
    testA[7] = (address >> 8) & 0xFF;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testA[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testA, 8);
    usleep(200000);

    // Collect response
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

    // TEST B: Maybe we should use msgType 0x02 instead of 0x03 for data?
    // Some protocols use TransportOpen-like format for data
    std::cout << "\n[TEST B] Using msgType 0x02 for data (like TransportOpen)...\n";
    uint8_t testB[8];
    testB[0] = (0 << 5) | 0x02;       // sequence 0, TransportOpen-like
    testB[1] = ecuConnectionId;
    testB[2] = 0x08;                   // Control = length
    testB[3] = 0x13;                   // Command
    testB[4] = 0x01;                   // Request ID
    testB[5] = (address >> 24) & 0xFF;
    testB[6] = (address >> 16) & 0xFF;
    testB[7] = (address >> 8) & 0xFF;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testB[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testB, 8);
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
            std::cout << "\n";
        }
    }

    // TEST C: Try without the sequence bits - pure msgType in byte 0
    std::cout << "\n[TEST C] Pure msgType 0x03 without sequence bits...\n";
    uint8_t testC[8];
    testC[0] = 0x03;                   // Just DataTransfer, no sequence
    testC[1] = ecuConnectionId;
    testC[2] = 0x00;
    testC[3] = 0x13;
    testC[4] = 0x01;
    testC[5] = (address >> 24) & 0xFF;
    testC[6] = (address >> 16) & 0xFF;
    testC[7] = (address >> 8) & 0xFF;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testC[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testC, 8);
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
            std::cout << "\n";
        }
    }

    // TEST D: Try different command - maybe getAddressByParameterID (0x15)
    // with a known parameter ID instead of raw address
    std::cout << "\n[TEST D] Try getAddressByParameterID (0x15) with param ID 0x0001...\n";
    uint8_t testD[8];
    testD[0] = (0 << 5) | 0x03;
    testD[1] = ecuConnectionId;
    testD[2] = 0x00;
    testD[3] = 0x15;                   // getAddressByParameterID
    testD[4] = 0x01;                   // Request ID
    testD[5] = 0x00;                   // Parameter ID high byte
    testD[6] = 0x01;                   // Parameter ID low byte
    testD[7] = 0x00;

    std::cout << "[TX] ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testD[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testD, 8);
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
            std::cout << "\n";
        }
    }

    // TEST E: Use LOCAL connection ID (0x01) for all DataTransfer
    std::cout << "\n[TEST E] Using LOCAL connection ID (0x01) for DataTransfer...\n";
    uint8_t testE1[8];
    testE1[0] = (0 << 5) | 0x03;
    testE1[1] = localConnectionId;     // OUR connection ID
    testE1[2] = 0x00;
    testE1[3] = 0x13;
    testE1[4] = 0x01;
    testE1[5] = (address >> 24) & 0xFF;
    testE1[6] = (address >> 16) & 0xFF;
    testE1[7] = (address >> 8) & 0xFF;

    std::cout << "[TX] Frame 1: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testE1[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testE1, 8);
    usleep(100000);

    uint8_t testE2[8];
    testE2[0] = (1 << 5) | 0x03;       // sequence 1
    testE2[1] = localConnectionId;
    testE2[2] = 0x00;
    testE2[3] = address & 0xFF;
    testE2[4] = (length >> 8) & 0xFF;
    testE2[5] = length & 0xFF;
    testE2[6] = 0x00;
    testE2[7] = 0x00;

    std::cout << "[TX] Frame 2: ";
    for (int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(testE2[i]) << " ";
    }
    std::cout << "\n";
    adapter.send(txArbId, testE2, 8);

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
    testG[5] = 0x13;                   // Command embedded in context
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
    std::string rawBytes;
    uint32_t readAddress = 0;
    uint16_t readLength = 16;
    uint8_t ecuAddress = 0x00;

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
    SocketCanAdapter adapter;
    adapter.setLogCallback([](const std::string& msg) {
        std::cout << msg << "\n";
    });

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
    } else {
        result = connectMode(adapter, ecuAddress);
    }

    adapter.close();
    return result;
}
