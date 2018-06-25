#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

struct block {
    unsigned int index;      // block height in chain
    char *hash;              // block hash (sha256)
    char *prev_hash;         // previous block hash
    char *data;              // block data
    unsigned long timestamp; // block timestamp
};

int main() 
{
    return 0;
}
