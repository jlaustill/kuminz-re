#ifndef SECURITYAUTH_H
#define SECURITYAUTH_H

#include <cstdint>
#include <vector>
#include <string>

/**
 * @brief CM550 ECU Security Authentication Module.
 *
 * This module implements the bit-packing algorithm used by CM550 ECUs
 * for security authentication. The ECU uses a challenge-response mechanism
 * based on the security key ("ABCDEF") and the ECU's hour meter value.
 *
 * Authentication Flow:
 *   1. Tool reads hour_meter value from ECU (address 0x803B9A, 4 bytes)
 *   2. Tool generates 10-byte auth payload using generateAuthPayload()
 *   3. Tool sends auth payload to ECU with protected write service
 *   4. ECU runs bitPackingAlgorithm on payload
 *   5. ECU verifies result[0:6] == "ABCDEF" and result[6:10] == hour_meter (within 26 ticks)
 *   6. If valid, ECU grants write access
 *
 * Algorithm Details (from firmware @ 0x2fbd8):
 *   - Uses mask table to separate bits into two streams
 *   - Mask bit 0: output bits forward (bytes 0-9)
 *   - Mask bit 1: output bits backward (bytes 9-0)
 *   - XORs each byte with another based on XOR table
 *   - Reorders bytes according to reorder table (XOR table reversed)
 */
class SecurityAuth
{
public:
    /**
     * @brief The fixed security key used by CM550 ECUs.
     */
    static constexpr const char* SECURITY_KEY = "ABCDEF";
    static constexpr size_t SECURITY_KEY_LEN = 6;

    /**
     * @brief Generate auth payload from security key and hour meter.
     * @param hourMeter Current ECU hour meter value (4 bytes, big-endian)
     * @param payload Output: 10-byte authentication payload
     * @return true if generation successful
     *
     * This is the REVERSE of bitPackingAlgorithm.
     * Given the desired output (security key + hour meter),
     * it computes the 10-byte input that produces that output.
     */
    static bool generateAuthPayload(uint32_t hourMeter, std::vector<uint8_t>& payload);

    /**
     * @brief Generate auth payload from security key and hour meter bytes.
     * @param hourMeterBytes 4 bytes from ECU address 0x803B9A
     * @param payload Output: 10-byte authentication payload
     * @return true if generation successful
     */
    static bool generateAuthPayload(const std::vector<uint8_t>& hourMeterBytes,
                                    std::vector<uint8_t>& payload);

    /**
     * @brief Forward bit-packing algorithm (for testing/verification).
     * @param input 10-byte input payload
     * @param output Output: 10-byte result
     *
     * This is the forward direction of the ECU's bitPackingAlgorithm.
     * Used to verify that generateAuthPayload produces correct results.
     */
    static void bitPackingForward(const std::vector<uint8_t>& input,
                                  std::vector<uint8_t>& output);

    /**
     * @brief Verify an auth payload produces correct output.
     * @param payload 10-byte auth payload
     * @param hourMeter Expected hour meter value
     * @return true if payload is valid
     */
    static bool verifyPayload(const std::vector<uint8_t>& payload, uint32_t hourMeter);

    /**
     * @brief Print algorithm tables for debugging.
     */
    static void printTables();

private:
    // Lookup tables from firmware @ 0x2fbc4, 0x2fbce
    static const uint8_t MASK_TABLE[10];
    static const uint8_t XOR_TABLE[10];

    // Reorder table is XOR_TABLE read backwards
    static uint8_t getReorderIndex(int i);

    // Helper: reverse the bit manipulation
    static void bitPackingReverse(const std::vector<uint8_t>& output,
                                  std::vector<uint8_t>& input);
};

#endif // SECURITYAUTH_H
