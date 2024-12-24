CC = g++
CFLAGS = -std=c++17 -O2 -Wall
TARGETS = first second

all: $(TARGETS)

first: first.cpp sharedArray.h
	$(CC) $(CFLAGS) -o first first.cpp -lpthread

second: second.cpp sharedArray.h
	$(CC) $(CFLAGS) -o second second.cpp -lpthread

clean:
	rm -f $(TARGETS)
