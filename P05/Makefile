CXXFLAGS += --std=c++17

smart: parent.o person.o student.o main.o
	$(CXX) $(CXXFLAGS) parent.o person.o student.o main.o -o smart
parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp
person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) -c person.cpp
student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.gch *.o smart a.out

debug: parent.o person.o student.o main.o
	$(CXX) $(CXXFLAGS) -g parent.o person.o student.o main.o -o smart