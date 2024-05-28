# Makefile

CXX = g++
CXXFLAGS = -std=c++11 -pthread
TARGET = calculator

all: $(TARGET)

$(TARGET): calculator.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) calculator.o

calculator.o: calculator.cpp
	$(CXX) $(CXXFLAGS) -c calculator.cpp

clean:
	rm -f *.o $(TARGET)
