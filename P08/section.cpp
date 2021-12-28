#include "section.h"

Section::Section(Course _course, Semester _semester, int _year) : course{_course}, semester{_semester}, year{_year} {}
Section::Section(std::istream& ist) : course{ist} {
    std::string s;
    ist >> s;
    if(s == "fall") semester = Semester::FALL;
    else if(s == "spring") semester = Semester::SPRING;
    else semester = Semester::SUMMER;
    ist >> year;
    ist.ignore(32767, '\n');
}
void Section::save(std::ostream& ost){
    ost << course << std::endl;
    ost << semester << std::endl;
    ost << year << std::endl;
}
std::ostream& operator<<(std::ostream& ost, const Section section){
    ost << section.course << section.semester << section.year;
    return ost;
}
std::string Section::to_string(){
    std::string s;
    if(semester == Semester::FALL) s = "fall";
    else if(semester == Semester::SPRING) s = "spring";
    else s = "summer";
    return s;
}
std::string Section::full_info(){
    return course.full_info() + " for " + to_string() + " " + std::to_string(year);
}