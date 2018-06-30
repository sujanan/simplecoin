#ifndef SIMPLECOIN_H
#define SIMPLECOIN_H

struct block {
    unsigned int index;      // block height in chain
    char *prev_hash;         // previous block hash
    char *hash;              // block hash (sha256)
    char *data;              // block data
    unsigned long timestamp; // block timestamp
};

#endif
