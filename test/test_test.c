#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../simplecoin.h"
#include "test.h"

int main()
{
    char hash[] = 
            "09ca7e4eaa6e8ae9c7d261167129184883644d07dfba7cbfbc4c8a2e08360d5b";
    char *hash_to_check = gen_sha256("hello, world");

    assert( strcmp(hash, hash_to_check) == 0 );
    return 0;
}
