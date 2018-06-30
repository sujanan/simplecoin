#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>
#include "simplecoin.h"

// first hash in chain
const char genesis_hash[] = 
        "816534932c2b7154836da6afc367695e6337db8a921823784c14378abed4f7d7";

// calculate hash length from genesis hash
#define HASH_LEN (sizeof(genesis_hash)/sizeof(genesis_hash[0]))

// generate a sha256 hash
// note: buf length must be HASH_LEN + 1
void gen_sha256(char *buf, const char *str)
{
    memset(buf, 0, HASH_LEN);
    // [START hash generating]
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(hash, &sha256);
    // [END hash generating]
    int i;
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(buf + (i * 2), "%02x", hash[i]);
}

// calculate character length of block attibutes
size_t block_strlen(const struct block *b)
{
    size_t length = 0;
    length += snprintf(NULL, 0, "%u", b->index);
    // genesis block
    if (b->prev_hash != NULL)
        length += HASH_LEN - 1;
    length += HASH_LEN - 1;
    length += strlen(b->data);
    length += snprintf(NULL, 0, "%lu", b->timestamp);
    return length + 1;
}

// convert block to string
// note: str length must be generated using block_strlen
void block_tostr(const struct block *b, char *str)
{
    // index
    sprintf(str, "%u", b->index);
    str += strlen(str);
    // prev_hash
    // genesis block
    if (b->prev_hash != NULL) {
        strcpy(str, b->prev_hash);
        str += strlen(str);
    }
    // hash
    strcpy(str, b->hash);
    str += strlen(str);
    // data
    strcpy(str, b->data);
    str += strlen(str);
    // timestamp 
    sprintf(str, "%lu", b->timestamp);
    printf("%s\n", str);
}
