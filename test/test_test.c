#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../simplecoin.h"
#include "test.h"

const char hash[] = 
        "09ca7e4eaa6e8ae9c7d261167129184883644d07dfba7cbfbc4c8a2e08360d5b";
#define HASH_LEN (sizeof(hash)/sizeof(hash[0]))

int main()
{
    char hash_to_check[HASH_LEN + 1];
    gen_sha256(hash_to_check, "hello, world");

    assert( strcmp(hash, hash_to_check) == 0 );

    return 0;
}
