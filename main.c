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

// first hash in chain
const char genesis_hash[] = "816534932c2b7154836da6afc367695e6337db8a921823784c14378abed4f7d7";

// calculate hash length from genesis hash
#define HASH_LEN (sizeof(genesis_hash)/sizeof(genesis_hash[0]))

int main() 
{
    return 0;
}
