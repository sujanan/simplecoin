#include <stdio.h>
#include <string.h>
#include <time.h>
#include "blockchain.h"
#include "hash.h"

static int count_digits(int n)
{
	if (n < 0)
		return 0;
	if (n < 10)
		return 1;
	if (n < 100)
		return 2;
	if (n < 1000)
		return 3;
	if (n < 10000)
		return 4;
	if (n < 100000)
		return 5;
	if (n < 1000000)
		return 6;
	if (n < 10000000)
		return 7;
	if (n < 100000000)
		return 8;
	if (n < 1000000000)
		return 9;
	return 10;
}

int block_strlen(struct block *block)
{
	int size = 0, i;

	if (!ARRAY_EMPTY(block->prev_hash))
		size += SHA256_DIGEST_LENGTH << 1; 

	size += SHA256_DIGEST_LENGTH << 1;	
	size += count_digits(block->index);
	size += count_digits(block->timestamp);
	for (i = 0; i < block->nonce[i]; i++)
		;
	size += i;

	return size;	
}

void block_tostring(char *buffer, struct block *block)
{
	char s[2];
	int size = 0, i, len;

	size += sprintf(buffer, "%d", block->index);
	size += sprintf(buffer + size, "%d", block->timestamp);

	for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
		extract(s, block->root_hash[i]);

		*(buffer + size) = s[0];
		size += 1;
		*(buffer + size) = s[1];
		size += 1;
	}
	if (!ARRAY_EMPTY(block->prev_hash)) {
		for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
			extract(s, block->prev_hash[i]);

			*(buffer + size) = s[0];
			size += 1;
			*(buffer + size) = s[1];
			size += 1;
		}
	}
	for (i = 0; block->nonce[i]; i++) {
		*(buffer + size) = block->nonce[i];
		size += 1;
	}
	buffer[size] = 0;
}

int main(int argc, char **argv)
{
	GENESIS_BLOCK(genesis_block);

	char buffer[block_strlen(&genesis_block)];
	block_tostring(buffer, &genesis_block);

	printf("%s\n", buffer);

	return 0;
}
