#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#ifndef SHA256_DIGEST_LENGTH
#define SHA256_DIGEST_LENGTH 32
#endif

#define NONCE_LENGTH 1024

#define ARRAY_EMPTY(a) ((a == NULL || a[0] == 0) ? 1 : 0)

struct block {
	int index;
	int timestamp;
	unsigned char root_hash[SHA256_DIGEST_LENGTH];
	unsigned char prev_hash[SHA256_DIGEST_LENGTH];
	char nonce[NONCE_LENGTH];
};

#define GENESIS_BLOCK(name) \
	struct block name = { \
		0, 0, {	\
		0X09, 0XCA, 0X7E, 0X4E, 0XAA, 0X6E, 0X8A, 0XE9, \
		0XC7, 0XD2, 0X61, 0X16, 0X71, 0X29, 0X18, 0X48, \
		0X83, 0X64, 0X4D, 0X07, 0XDF, 0XBA, 0X7C, 0XBF, \
		0XBC, 0X4C, 0X8A, 0X2E, 0X08, 0X36, 0X0D, 0X5B, }, \
		{0}, { 'n', 'o', 'n', 'c', 'e', 0 } \
	}

static inline void extract(char src[2], unsigned char dest)
{
	unsigned char b1 = 0B00001111;		
	unsigned char b2 = 0B11110000;
	char a = (char) ((b2 & dest) >> 4);
	char b = (char) (b1 & dest);

	a = (a < 10) ? a + '0' : (a - 10) + 'A';
	b = (b < 10) ? b + '0' : (b - 10) + 'A';
	src[0] = a;
	src[1] = b;
}

extern int block_strlen(struct block *block);
extern void block_tostring(char *buffer, struct block *block);

#endif
