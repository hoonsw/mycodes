# Makefile
TARGET=program
CXX=gcc
CXXFLAGS=-W
OBJECTS=main.o plus.o minus.o 

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
main.o: main.c
	$(CXX) $(CXXFLAGS) -c main.c
plus.o: plus.c
	$(CXX) $(CXXFLAGS) -c plus.c
minus.o: minus.c
	$(CXX) $(CXXFLAGS) -c minus.c
clean:
	rm -f *.o $(TARGET)
	
