#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../simplecoin.h"
#include "test.h"

#define BLOCK_STR_REGULAR "10" TEST_HASH TEST_HASH "some data" "1530114958"
#define BLOCK_STR_GENESIS "10" TEST_HASH "some data" "1530114958"

void regular_block()
{
    struct block b = {
        10,
        TEST_HASH,
        TEST_HASH,
        "some data",
        1530114958 // 10 digit unix timestamp
    };
    char str[block_strlen(&b)];
    block_tostr(&b, str);
    assert( strcmp(str, BLOCK_STR_REGULAR) == 0 );
}

void genesis_block()
{
    struct block b = {
        10,
        NULL,
        TEST_HASH,
        "some data",
        1530114958 // 10 digit unix timestamp
    };
    char str[block_strlen(&b)];
    block_tostr(&b, str);
    assert( strcmp(str, BLOCK_STR_GENESIS) == 0 );
}

int main()
{
    regular_block();
    return 0;
}
