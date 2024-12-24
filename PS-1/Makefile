TARGET = do-command

CC = g++
CXXFLAGS = -c

OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

doCommand.o: doCommand.cpp
	$(CC) $(CXXFLAGS) doCommand.cpp

clean:
	rm -f $(OBJ) $(TARGET)

all: $(TARGET)
