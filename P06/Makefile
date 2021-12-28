CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: smart

debug: CXXFLAGS += -g
debug: smart

smart: main.o mainwin.o parent.o person.o student.o entrydialog.o
	$(CXX) $(CXXFLAGS) parent.o person.o student.o main.o mainwin.o entrydialog.o $(GTKFLAGS) -o smart

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o

parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp

person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) -c person.cpp

student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp

clean:
	rm -f *.o *.gch smart

