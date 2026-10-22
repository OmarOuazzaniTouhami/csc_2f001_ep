CXX      = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

TARGET = bilbao
OBJS   = main.o location.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp location.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

location.o: location.cpp location.h
	$(CXX) $(CXXFLAGS) -c location.cpp -o location.o

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
