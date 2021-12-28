#ifndef __TRANSCRIPT_H
#define __TRANSCRIPT_H

#include "student.h"
#include "section.h"
#include "grade.h"

class Transcript {
    private:
        Section section;
        Student student;
        Grade grade;
    public:
        Transcript(Student _student, Section _section);
        Transcript(std::istream& ist);
        std::string full_info();
        std::string to_string();
        void assign_grade(Grade grade);
        virtual void save(std::ostream& ost);
        friend std::ostream& operator<<(std::ostream& ost, Transcript transcript);

};

#endif