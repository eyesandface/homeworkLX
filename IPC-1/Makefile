CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall

TARGET = signal-echo

$(TARGET): signalEcho.cpp
	$(CXX) -o $(TARGET) signalEcho.cpp $(CXXFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
