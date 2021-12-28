#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include <fstream>
#include "parent.h"
#include "entrydialog.h"
#include "comboboxcontainer.h"
#include "transcript.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    private:
        std::string filename;
        int display_status;
        Gtk::Label* display;
        std::vector<Student*> students;
        std::vector<Parent*> parents;
        std::vector<Course*> courses;
        std::vector<Section*> sections;
        std::vector<Teacher*> teachers;
        std::vector<Transcript*> transcripts;
        void show_data();
    protected:
        void on_save_click();
        void on_save_as_click();
        void on_open_click();
        void on_new_school_click();
        void on_new_student_click();
        void on_new_parent_click();
        void on_student_parent_click();
        void on_quit_click();
        void on_about_click();
        void on_new_course_click();
        void on_new_section_click();
        void on_new_teacher_click();
        void on_new_transcript_click();
        void on_set_grade_click();
};

#endif
