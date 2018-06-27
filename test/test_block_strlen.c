#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../simplecoin.h"
#include "test.h"

static void regular_block()
{
    size_t length = 0;
    char *data = "some data";
    struct block b = {
        10,
        TEST_HASH,
        TEST_HASH,
        data,
        1530114958 // 10 digit unix timestamp
    };
    length += 2;                    // index
    length += (HASH_LEN - 1) * 2;   // hashes
    length += 10;                   // timestamp
    length += strlen(data);         // data length
    length += 1;                    // null terminator

    assert( length == block_strlen(&b) );
}

int main()
{
    regular_block();
    return 0;
}
