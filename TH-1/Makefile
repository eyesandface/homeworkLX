CC = g++
CXXFLAGS = -c

TARGET = array-summary
SRC = summaryArray.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(SRC)

sumarryArray.o : summaryArray.cpp
	$(CC) $(CXXFLAGS) summaryArray.cpp

clean:
	rm -f $(TARGET)

