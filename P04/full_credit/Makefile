CXXFLAGS = --std=c++17

Main: Main.o Deck.o Card.o *.h
	$(CXX) $(CXXFLAGS) Main.o Deck.o Card.o -o Main

Main.o: Main.cpp *.h
	$(CXX) $(CXXFLAGS) -c Main.cpp -o Main.o

Deck.o: Deck.cpp *.h
	-$(CXX) $(CXXFLAGS) -c Deck.cpp -o Deck.o

Card.o: Card.cpp *.h
	-$(CXX) $(CXXFLAGS) -c Card.cpp -o Card.o

clean:
	rm -f *.o *.gch *~ a.out Main