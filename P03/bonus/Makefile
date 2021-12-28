CXXFLAGS = --std=c++17

main: main.o fraction.o *.h
	$(CXX) $(CXXFLAGS) main.o fraction.o -o main

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

fraction.o: fraction.cpp *.h
	-$(CXX) $(CXXFLAGS) -c fraction.cpp -o fraction.o

clean:
	rm -f *.o *.gch *~ a.out main