CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = main
OBJS = main.o GenericArray.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

GenericArray.o: GenericArray.cpp GenericArray.h
	$(CXX) $(CXXFLAGS) -c GenericArray.cpp

main.o: main.cpp GenericArray.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) $(TARGET)
