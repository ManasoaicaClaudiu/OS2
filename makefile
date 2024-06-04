# Makefile

CXX = g++
CXXFLAGS = -std=c++11 -pthread
TARGET = phonebook

all: $(TARGET)

$(TARGET): phonebook.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) phonebook.o

phonebook.o: phonebook.cpp
	$(CXX) $(CXXFLAGS) -c phonebook.cpp

clean:
	rm -f *.o $(TARGET)
