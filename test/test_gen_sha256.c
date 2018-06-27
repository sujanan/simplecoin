#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../simplecoin.h"
#include "test.h"

int main()
{
    char hash_to_check[HASH_LEN];
    gen_sha256(hash_to_check, "hello, world");

    assert( strlen(hash_to_check) == HASH_LEN - 1 );
    assert( strcmp(TEST_HASH, hash_to_check) == 0 );

    return 0;
}
