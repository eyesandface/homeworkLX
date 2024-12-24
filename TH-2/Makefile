CXX = g++
CXXFLAGS = -std=c++17 -pthread

LIB_SRC = parallelScheduler.cpp
DEMO_SRC = demoApplication.cpp
LIB = libparallel_scheduler.so
DEMO = demo_application

all: $(DEMO)

$(LIB): $(LIB_SRC)
	$(CXX) $(CXXFLAGS) -shared -fPIC -o $(LIB) $(LIB_SRC)

$(DEMO): $(DEMO_SRC) $(LIB)
	$(CXX) $(CXXFLAGS) -o $(DEMO) $(DEMO_SRC) -L. -lparallel_scheduler

clean:
	rm -f $(LIB) $(DEMO)

.PHONY: all clean
