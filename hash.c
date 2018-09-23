#include <string.h>
#include <stdio.h>
#include <openssl/sha.h>
#include "blockchain.h"

static void print_sha256(unsigned char *hash)
{
	int i;
	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%0X", hash[i]);
}

void gen_sha256(unsigned char *hash, char *buffer)
{
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, buffer, strlen(buffer));
	SHA256_Final(hash, &sha256);
	print_sha256(hash);
}
