#ifndef TEST_H
#define TEST_H

#define TEST_HASH "09ca7e4eaa6e8ae9c7d261167129184883644d07dfba7cbfbc4c8a2e08360d5b"
#ifndef HASH_LEN
  // test hash is always char
  #define HASH_LEN (sizeof(TEST_HASH)/sizeof(char))
#endif

void gen_sha256(char *buf, const char *str);
size_t block_strlen(const struct block *b);

#endif
