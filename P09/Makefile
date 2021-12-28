CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: smart

debug: CXXFLAGS += -g
debug: smart

smart: main.o mainwin.o parent.o person.o student.o entrydialog.o subject.o semester.o course.o section.o teacher.o transcript.o grade.o
	$(CXX) $(CXXFLAGS) parent.o person.o student.o main.o mainwin.o entrydialog.o subject.o semester.o course.o section.o teacher.o transcript.o grade.o $(GTKFLAGS) -o smart

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

subject.o: subject.cpp *.h
	$(CXX) $(CXXFLAGS) -c subject.cpp

semester.o: semester.cpp *.h
	$(CXX) $(CXXFLAGS) -c semester.cpp

course.o: course.cpp *.h
	$(CXX) $(CXXFLAGS) -c course.cpp

section.o: section.cpp *.h
	$(CXX) $(CXXFLAGS) -c section.cpp

teacher.o: teacher.cpp *.h
	$(CXX) $(CXXFLAGS) -c teacher.cpp

transcript.o: transcript.cpp *.h
	$(CXX) $(CXXFLAGS) -c transcript.cpp

grade.o: grade.cpp *.h
	$(CXX) $(CXXFLAGS) -c grade.cpp

clean:
	rm -f *.o *.gch smart

