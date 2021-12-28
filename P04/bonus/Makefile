CXXFLAGS = --std=c++17

Main: Main.o Deck.o Card.o Hintcard.o *.h
	$(CXX) $(CXXFLAGS) Main.o Hintcard.o Deck.o Card.o -o Main

Main.o: Main.cpp *.h
	$(CXX) $(CXXFLAGS) -c Main.cpp -o Main.o

Deck.o: Deck.cpp *.h
	-$(CXX) $(CXXFLAGS) -c Deck.cpp -o Deck.o

Card.o: Card.cpp *.h
	-$(CXX) $(CXXFLAGS) -c Card.cpp -o Card.o
	
Hintcard.o: Hintcard.cpp *.h
	-$(CXX) $(CXXFLAGS) -c Hintcard.cpp -o Hintcard.o
clean:
	rm -f *.o *.gch *~ a.out Main