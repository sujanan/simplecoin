CC=gcc
CFLAG=-g

PROG=blockchain
LIBS= -lm -lssl -lcrypto

all: $(PROG)

blockchain: blockchain.o hash.o
	$(CC) $(CFLAGS) -o blockchain blockchain.o hash.o $(LIBS)

blockchain.o: blockchain.h hash.h

clean:
	rm -f *.o $(PROG)
