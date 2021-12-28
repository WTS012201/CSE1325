#include "mainwin.h"
#include <iostream>

Mainwin::Mainwin() : display{new Gtk::Label()} {

    set_default_size(960, 540);
    set_title("SMART");

    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    //  menu
    
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //  file

    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);

    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);
    
    //  insert

    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    Gtk::MenuItem *menuitem_new_student = Gtk::manage(new Gtk::MenuItem("_New Student", true));
    menuitem_new_student->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_new_student);

    Gtk::MenuItem *menuitem_new_parent = Gtk::manage(new Gtk::MenuItem("_New Parent", true));
    menuitem_new_parent->signal_activate().connect([this] {this->on_new_parent_click();});
    insertmenu->append(*menuitem_new_parent);

    //  relate

    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);

    Gtk::MenuItem *menuitem_student_parent = Gtk::manage(new Gtk::MenuItem("Student to Parent", true));
    menuitem_student_parent->signal_activate().connect([this] {this->on_student_parent_click();});
    relatemenu->append(*menuitem_student_parent);

    //  display

    show_data();
    vbox->pack_start(*display, Gtk::PACK_SHRINK, 0);

    vbox->show_all();
}

Mainwin::~Mainwin() {}
void Mainwin::show_data(){
    Glib::ustring s{"<span size='12000' weight='bold'>Students\n\n"};
    for(int i = 0; i < students.size(); i++)
        s += students.at(i).full_info() + "\n";
    s += "\nParents\n\n";
    for(int i = 0; i < parents.size(); i++)
        s += parents.at(i).full_info() + "\n";
    s += "</span>";
    display->set_markup(s);
}
void Mainwin::on_new_school_click(){
    students.clear();
    parents.clear();
    show_data();
}
void Mainwin::on_new_student_click(){   
    EntryDialog edialog_name{*this, "<big>Student name?</big>", true};
    edialog_name.run();
    EntryDialog edialog_email{*this, "<big>Student email?</big>", true};
    edialog_email.run();
    EntryDialog edialog_grade{*this, "<big>Student grade?</big>", true};
    edialog_grade.run();
    Student s{std::string(edialog_name.get_text()), std::string(edialog_email.get_text()), 
    std::stoi(std::string(edialog_grade.get_text()))};
    students.push_back(s);
    show_data();
    //Gtk::MessageDialog mdialog{*this, edialog.get_text()};
    //mdialog.run();
}
void Mainwin::on_new_parent_click(){
    EntryDialog edialog_name{*this, "<big>Parent name?</big>", true};
    edialog_name.run();
    EntryDialog edialog_email{*this, "<big>Parent email?</big>", true};
    edialog_email.run();
    Parent p{std::string(edialog_name.get_text()), std::string(edialog_email.get_text())};
    parents.push_back(p);
    show_data();
}
void Mainwin::on_student_parent_click(){
    Glib::ustring s{"<span size='12000' weight='bold'>"};
    for(int i = 0; i < students.size(); i++)
        s += std::to_string(i) + ") " + students.at(i).to_string() + "\n";
    s += "</span>";
    EntryDialog edialog_student{*this, "<big>Select student</big>", true};
    edialog_student.set_secondary_text(s, true);
    edialog_student.run();
    int s_num = std::stoi(std::string(edialog_student.get_text()));

    s = "<span size='12000' weight='bold'>";
    for(int i = 0; i < parents.size(); i++)
        s += std::to_string(i) + ") " + parents.at(i).to_string() + "\n";
    s += "</span>";
    EntryDialog edialog_parent{*this, "<big>Select parent</big>", true};
    edialog_parent.set_secondary_text(s, true);
    edialog_parent.run();
    int p_num = std::stoi(std::string(edialog_parent.get_text()));

    students.at(s_num).add_parent(parents.at(p_num));
    parents.at(p_num).add_student(students.at(s_num));
    show_data();
}
void Mainwin::on_quit_click(){
    close();
}