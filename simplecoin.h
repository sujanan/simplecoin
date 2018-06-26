#ifndef SIMPLECOIN_H
#define SIMPLECOIN_H

struct block {
    unsigned int index;      // block height in chain
    char *hash;              // block hash (sha256)
    char *prev_hash;         // previous block hash
    char *data;              // block data
    unsigned long timestamp; // block timestamp
};

#endif
