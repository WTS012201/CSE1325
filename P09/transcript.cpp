#include "transcript.h"

Transcript::Transcript(Student _student, Section _section) : student{_student}, section{_section}, grade{Grade::X}{}
Transcript::Transcript(std::istream& ist) : student{Student{ist}}, section{Section{ist}}{
    std::string s;
    ist >> s;
    if(s == "A") grade = Grade::A;
    else if(s == "B") grade = Grade::B;
    else if(s == "C") grade = Grade::C;
    else if(s == "D") grade = Grade::D;
    else if(s == "F") grade = Grade::F;
    else if(s == "I") grade = Grade::I;
    else grade = Grade::X;
    ist.ignore(32767, '\n');
}
void Transcript::assign_grade(Grade _grade){
    grade = _grade;
}
std::ostream& operator<<(std::ostream& ost, Transcript transcript){
    ost << transcript.full_info();
    return ost;
}
void Transcript::save(std::ostream& ost){
    student.save(ost);
    section.save(ost);
    ost << grade << std::endl;
}
std::string Transcript::to_string(){
    std::string s;
    if(grade == Grade::A) s = "A";
    else if(grade == Grade::B) s = "B";
    else if(grade == Grade::C) s = "C";
    else if(grade == Grade::D) s = "D";
    else if(grade == Grade::F) s = "F";
    else if(grade == Grade::I) s = "I";
    else s = "X";
    return s;
}
std::string Transcript::full_info(){
    return section.full_info() + ": " + student.to_string() + " earned a " + to_string();
}