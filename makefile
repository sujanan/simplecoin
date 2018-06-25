CC=gcc

CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=simplecoin.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *o simplecoin.out
