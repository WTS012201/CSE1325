#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "student.h"
#include "parent.h"
#include "entrydialog.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    private:
        Gtk::Label* display;
        std::vector<Student> students;
        std::vector<Parent> parents;
        void show_data();
    protected:
        void on_new_school_click();
        void on_new_student_click();
        void on_new_parent_click();
        void on_student_parent_click();
        void on_quit_click();
};

#endif
