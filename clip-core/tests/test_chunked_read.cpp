// Unit tests for readInChunks (clip/ChunkedRead.h): a fake memory stands in for the ECU, so no CAN adapter is needed.
// Run: ctest in the clip-core build directory, or ./clip-core-tests.
#include "clip/ChunkedRead.h"

#include <cstdio>
#include <set>
#include <string>
#include <vector>

static int g_failures = 0;

#define CHECK(condition)                                                              \
    do {                                                                              \
        if (!(condition)) {                                                           \
            std::printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition);          \
            g_failures++;                                                             \
        }                                                                             \
    } while (0)

// The byte the fake ECU holds at an address.
static uint8_t memoryByte(uint32_t address)
{
    return static_cast<uint8_t>((address * 7u + 3u) & 0xFFu);
}

// A fake chunk reader over memoryByte with scripted faults.
struct FakeEcu
{
    std::set<uint32_t> failAlways;      // chunk start addresses that never read
    std::set<uint32_t> failOnce;        // chunk start addresses whose first attempt fails
    uint8_t shortReplyLimit = 0;        // when non-zero, a reply holds at most this many bytes
    bool emptyReplies = false;          // every reply succeeds with no bytes
    uint8_t extraBytes = 0;             // every reply holds this many bytes beyond the request
    int calls = 0;

    ChunkReader reader()
    {
        return [this](uint32_t address, uint8_t length, std::vector<uint8_t>& out) {
            calls++;
            if (failAlways.count(address)) {
                return false;
            }
            if (failOnce.count(address)) {
                failOnce.erase(address);
                return false;
            }
            if (emptyReplies) {
                return true;
            }
            uint32_t count = length + extraBytes;
            if (shortReplyLimit != 0 && count > shortReplyLimit) {
                count = shortReplyLimit;
            }
            for (uint32_t i = 0; i < count; i++) {
                out.push_back(memoryByte(address + i));
            }
            return true;
        };
    }
};

// data[n] must be the byte at base + n, except inside the gaps, which hold padByte.
static bool alignedWithMemory(const TChunkedReadResult& result, uint32_t base, uint8_t padByte)
{
    for (uint32_t n = 0; n < result.data.size(); n++) {
        bool inGap = false;
        for (const TReadGap& gap : result.gaps) {
            if (base + n >= gap.address && base + n < gap.address + gap.length) {
                inGap = true;
            }
        }
        if (result.data[n] != (inGap ? padByte : memoryByte(base + n))) {
            return false;
        }
    }
    return true;
}

static void testAllChunksRead()
{
    FakeEcu ecu;
    TChunkedReadResult result = readInChunks(0x809242, 1000, 128, ecu.reader());
    CHECK(result.completed);
    CHECK(result.data.size() == 1000);
    CHECK(result.gaps.empty());
    CHECK(alignedWithMemory(result, 0x809242, 0xFF));
    CHECK(ecu.calls == 8);  // 7 x 128 + 104
}

static void testFailedChunkIsPaddedAndLaterBytesKeepTheirOffsets()
{
    // The bug this replaces: a failed chunk was skipped without padding, so every later byte moved down 0x80.
    FakeEcu ecu;
    ecu.failAlways.insert(0x40c200);
    TChunkedReadResult result = readInChunks(0x40c000, 0x400, 0x80, ecu.reader());
    CHECK(result.completed);
    CHECK(result.data.size() == 0x400);
    CHECK(result.gaps.size() == 1);
    CHECK(result.gaps[0].address == 0x40c200);
    CHECK(result.gaps[0].length == 0x80);
    CHECK(result.data[0x200] == 0xFF);
    CHECK(result.data[0x27f] == 0xFF);
    CHECK(result.data[0x280] == memoryByte(0x40c280));
    CHECK(alignedWithMemory(result, 0x40c000, 0xFF));
    CHECK(ecu.calls == 8 - 1 + 3);  // 7 good chunks + 3 attempts at the failed one
}

static void testRetryRecoversAChunk()
{
    FakeEcu ecu;
    ecu.failOnce.insert(0x800080);
    TChunkedReadResult result = readInChunks(0x800000, 0x100, 0x80, ecu.reader());
    CHECK(result.completed);
    CHECK(result.gaps.empty());
    CHECK(alignedWithMemory(result, 0x800000, 0xFF));
}

static void testShortRepliesStayAligned()
{
    FakeEcu ecu;
    ecu.shortReplyLimit = 50;
    TChunkedReadResult result = readInChunks(0x800000, 300, 128, ecu.reader());
    CHECK(result.completed);
    CHECK(result.data.size() == 300);
    CHECK(result.gaps.empty());
    CHECK(alignedWithMemory(result, 0x800000, 0xFF));
}

static void testEmptyReplyIsAFailureNotALoop()
{
    FakeEcu ecu;
    ecu.emptyReplies = true;
    TChunkedReadResult result = readInChunks(0x800000, 0x80 * 3, 0x80, ecu.reader(), 2, 5);
    CHECK(result.completed);  // 3 failed chunks < 5
    CHECK(result.data.size() == 0x180);
    CHECK(result.gaps.size() == 1);  // adjacent gaps merge
    CHECK(result.gaps[0].length == 0x180);
    CHECK(ecu.calls == 9);
}

static void testExtraBytesAreDropped()
{
    FakeEcu ecu;
    ecu.extraBytes = 4;
    TChunkedReadResult result = readInChunks(0x800000, 0x100, 0x80, ecu.reader());
    CHECK(result.completed);
    CHECK(result.data.size() == 0x100);
    CHECK(alignedWithMemory(result, 0x800000, 0xFF));
}

static void testTooManyFailedChunksStops()
{
    FakeEcu ecu;
    for (uint32_t a = 0x800100; a < 0x800400; a += 0x80) {
        ecu.failAlways.insert(a);
    }
    TChunkedReadResult result = readInChunks(0x800000, 0x800, 0x80, ecu.reader(), 0, 5);
    CHECK(!result.completed);
    CHECK(result.data.size() == 0x100 + 5 * 0x80);
    CHECK(result.gaps.size() == 1);
    CHECK(result.gaps[0].address == 0x800100);
    CHECK(alignedWithMemory(result, 0x800000, 0xFF));
}

static void testPadByteAndProgress()
{
    FakeEcu ecu;
    ecu.failAlways.insert(0x1000);
    std::vector<uint32_t> reported;
    TChunkedReadResult result = readInChunks(0x1000, 0x100, 0x80, ecu.reader(), 1, 5, 0x00,
                                             [&](uint32_t done, uint32_t, uint32_t) { reported.push_back(done); });
    CHECK(result.completed);
    CHECK(result.data[0] == 0x00);
    CHECK(alignedWithMemory(result, 0x1000, 0x00));
    CHECK(reported == std::vector<uint32_t>({0, 0x80}));
}

int main()
{
    testAllChunksRead();
    testFailedChunkIsPaddedAndLaterBytesKeepTheirOffsets();
    testRetryRecoversAChunk();
    testShortRepliesStayAligned();
    testEmptyReplyIsAFailureNotALoop();
    testExtraBytesAreDropped();
    testTooManyFailedChunksStops();
    testPadByteAndProgress();
    if (g_failures == 0) {
        std::printf("readInChunks: all tests passed\n");
        return 0;
    }
    std::printf("readInChunks: %d check(s) failed\n", g_failures);
    return 1;
}
