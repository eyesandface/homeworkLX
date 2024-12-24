CC = g++
CXXFLAGS = -std=c++11 -O2 -Wall

TARGET = prime-calculator

$(TARGET): primeCalculator.cpp
	$(CC) -o $(TARGET) primeCalculator.cpp $(CXXFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
