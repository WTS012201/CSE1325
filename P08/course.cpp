#include "course.h"

Course::Course(Subject _subject, int _grade) : subject{_subject}, grade{_grade} {}
Course::Course(std::istream& ist) {
    std::string s;
    ist >> s;
    if(s == "reading") subject = Subject::READING;
    else if(s == "writing") subject = Subject::WRITING;
    else if(s == "math") subject = Subject::MATH;
    else if(s == "science") subject = Subject::SCIENCE;
    else if(s == "history") subject = Subject::HISTORY;
    else if(s == "art") subject = Subject::ART;
    else if(s == "music") subject = Subject::MUSIC;
    else subject = Subject::SPORTS;
    ist >> grade;
    ist.ignore(32767, '\n');
}
void Course::save(std::ostream& ost){
    ost << subject << std::endl;
    ost << grade << std::endl;
}
std::ostream& operator<<(std::ostream& ost, const Course course){
    ost << course.subject << std::endl << course.grade;
    return ost;
}
std::string Course::to_string(){
    std::string s;
    if(subject == Subject::READING) s = "reading";
    else if(subject == Subject::WRITING) s = "writing";
    else if(subject == Subject::MATH) s = "math";
    else if(subject == Subject::SCIENCE) s = "science";
    else if(subject == Subject::HISTORY) s = "history";
    else if(subject == Subject::ART) s = "art";
    else if(subject == Subject::MUSIC) s = "music"; 
    else s = "sports";
    return s;
}
std::string Course::full_info(){
    return to_string() + " (grade " + std::to_string(grade) + ")";
}