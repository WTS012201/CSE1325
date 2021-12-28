#include "mainwin.h"
#include <iostream>

Mainwin::Mainwin() : filename{"untitled.smart"}, display_status{0} {

    set_default_size(725, 200);
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

    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("_Save As", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);
    
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);

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

    Gtk::MenuItem *menuitem_new_course = Gtk::manage(new Gtk::MenuItem("_New Course", true));
    menuitem_new_course->signal_activate().connect([this] {this->on_new_course_click();});
    insertmenu->append(*menuitem_new_course);

    Gtk::MenuItem *menuitem_new_section = Gtk::manage(new Gtk::MenuItem("_New Section", true));
    menuitem_new_section->signal_activate().connect([this] {this->on_new_section_click();});
    insertmenu->append(*menuitem_new_section);

    //  relate

    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);

    Gtk::MenuItem *menuitem_student_parent = Gtk::manage(new Gtk::MenuItem("Student to Parent", true));
    menuitem_student_parent->signal_activate().connect([this] {this->on_student_parent_click();});
    relatemenu->append(*menuitem_student_parent);

    //  about

    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

    //  view

    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    Gtk::MenuItem *menuitem_courses = Gtk::manage(new Gtk::MenuItem("_Courses", true));
    menuitem_courses->signal_activate().connect([this] {this->display_status = 1; this->show_data();});
    viewmenu->append(*menuitem_courses);

    Gtk::MenuItem *menuitem_sections = Gtk::manage(new Gtk::MenuItem("_Sections", true));
    menuitem_sections->signal_activate().connect([this] {this->display_status = 2; this->show_data();});
    viewmenu->append(*menuitem_sections);

    Gtk::MenuItem *menuitem_students = Gtk::manage(new Gtk::MenuItem("_Students", true));
    menuitem_students->signal_activate().connect([this] {this->display_status = 3; this->show_data();});
    viewmenu->append(*menuitem_students);

    Gtk::MenuItem *menuitem_parents = Gtk::manage(new Gtk::MenuItem("_Parents", true));
    menuitem_parents->signal_activate().connect([this] {this->display_status = 4; this->show_data();});
    viewmenu->append(*menuitem_parents);
    
    //  toolbar

    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    Gtk::ToolButton *new_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_school_button->set_tooltip_markup("New");
    new_school_button->signal_clicked().connect([this] {this->on_new_school_click();});
    toolbar->append(*new_school_button);
    
    Gtk::ToolButton *open_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    open_button->set_tooltip_markup("Open");
    open_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*open_button);

    Gtk::ToolButton *save_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    save_button->set_tooltip_markup("Save");
    save_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save_button);

    Gtk::ToolButton *save_as_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
    save_as_button->set_tooltip_markup("Save as");
    save_as_button->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*save_as_button);
    
    Gtk::SeparatorToolItem *sep0 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep0);

    Gtk::Image* button1_image = Gtk::manage(new Gtk::Image{"button1_on.png"});
    Gtk::ToolButton *button1 = Gtk::manage(new Gtk::ToolButton(*button1_image));
    button1->set_tooltip_markup("New student");
    button1->signal_clicked().connect([this] {this->on_new_student_click();});
    toolbar->append(*button1);

    Gtk::Image* button2_image = Gtk::manage(new Gtk::Image{"button2_on.png"});
    Gtk::ToolButton *button2 = Gtk::manage(new Gtk::ToolButton(*button2_image));
    button2->set_tooltip_markup("New parent");
    button2->signal_clicked().connect([this] {this->on_new_parent_click();});
    toolbar->append(*button2);

    Gtk::Image* button3_image = Gtk::manage(new Gtk::Image{"button3_on.png"});
    Gtk::ToolButton *button3 = Gtk::manage(new Gtk::ToolButton(*button3_image));
    button3->set_tooltip_markup("Relate a student to a parent");
    button3->signal_clicked().connect([this] {this->on_student_parent_click();});
    toolbar->append(*button3);

    Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep1);

    Gtk::Image* button4_image = Gtk::manage(new Gtk::Image{"button4_on.png"});
    Gtk::ToolButton *button4 = Gtk::manage(new Gtk::ToolButton(*button4_image));
    button4->set_tooltip_markup("New course");
    button4->signal_clicked().connect([this] {this->on_new_course_click();});
    toolbar->append(*button4);

    Gtk::Image* button5_image = Gtk::manage(new Gtk::Image{"button5_on.png"});
    Gtk::ToolButton *button5 = Gtk::manage(new Gtk::ToolButton(*button5_image));
    button5->set_tooltip_markup("New section");
    button5->signal_clicked().connect([this] {this->on_new_section_click();});
    toolbar->append(*button5);

    Gtk::SeparatorToolItem *sep2 = Gtk::manage(new Gtk::SeparatorToolItem());
    sep2->set_expand(true);  
    toolbar->append(*sep2);
    
    //  display
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);
    show_data();
    vbox->show_all();
}

Mainwin::~Mainwin() {}
void Mainwin::show_data(){  
    Glib::ustring s;
    s += "<span size='12000' weight='bold'>";
    switch(display_status){
        case 0:
            s += "Click view to show data";
            break;
        case 1:
            s += "Courses\n\n";
            for(int i = 0; i < courses.size(); i++)
                s += courses.at(i)->full_info() + "\n";
            break;
        case 2:
            s += "Sections\n\n";
            for(int i = 0; i < sections.size(); i++)
                s += sections.at(i)->full_info() + "\n";
            break;
        case 3:
            s += "Students\n\n";
            for(int i = 0; i < students.size(); i++)
                s += students.at(i)->full_info() + "\n";
            break;
        case 4:
            s += "\nParents\n\n";
            for(int i = 0; i < parents.size(); i++)
                s += parents.at(i)->full_info() + "\n";
            break;
    }
    s += "</span>";
    display->set_markup(s);
}
void Mainwin::on_new_school_click(){
    students.clear();
    parents.clear();
    courses.clear();
    sections.clear();
    show_data();
}
void Mainwin::on_new_student_click(){   
    EntryDialog edialog_name{*this, "<big>Student name?</big>", true};
    if(edialog_name.run() == Gtk::RESPONSE_OK)
        edialog_name.hide();
    else return;
    EntryDialog edialog_email{*this, "<big>Student email?</big>", true};
    if(edialog_email.run() == Gtk::RESPONSE_OK)
        edialog_email.hide();
    else return;
    EntryDialog edialog_grade{*this, "<big>Student grade?</big>", true};
    if(edialog_grade.run() == Gtk::RESPONSE_OK)
        edialog_grade.hide();
    else return;
    students.push_back(new Student{edialog_name.get_text(), edialog_email.get_text(),
    std::stoi(std::string(edialog_grade.get_text()))});
    show_data();
}
void Mainwin::on_new_parent_click(){
    EntryDialog edialog_name{*this, "<big>Parent name?</big>", true};
    if(edialog_name.run() == Gtk::RESPONSE_OK)
        edialog_name.hide();
    else return;
    EntryDialog edialog_email{*this, "<big>Parent email?</big>", true};
    if(edialog_email.run() == Gtk::RESPONSE_OK)
        edialog_email.hide();
    else return;
    parents.push_back(new Parent{edialog_name.get_text(), edialog_email.get_text()});
    show_data();
}
void Mainwin::on_student_parent_click(){
    Glib::ustring s{"<span size='12000' weight='bold'>"};
    for(int i = 0; i < students.size(); i++)
        s += std::to_string(i) + ") " + students.at(i)->to_string() + "\n";
    s += "</span>";
    EntryDialog edialog_student{*this, "<big>Select student</big>", true};
    edialog_student.set_secondary_text(s, true);
    if(edialog_student.run() == Gtk::RESPONSE_OK)
        edialog_student.hide();
    else return;
    int s_num = std::stoi(std::string(edialog_student.get_text()));

    s = "<span size='12000' weight='bold'>";
    for(int i = 0; i < parents.size(); i++)
        s += std::to_string(i) + ") " + parents.at(i)->to_string() + "\n";
    s += "</span>";
    EntryDialog edialog_parent{*this, "<big>Select parent</big>", true};
    edialog_parent.set_secondary_text(s, true);
    if(edialog_parent.run() == Gtk::RESPONSE_OK)
        edialog_parent.hide();
    else return;
    int p_num = std::stoi(std::string(edialog_parent.get_text()));

    students.at(s_num)->add_parent(*parents.at(p_num));
    parents.at(p_num)->add_student(*students.at(s_num));
    show_data();
}
void Mainwin::on_quit_click(){
    close();
}
void Mainwin::on_save_click(){
    try {
        std::ofstream ofs{filename};
        ofs << students.size() << std::endl;
        for(auto s : students)
            s->save(ofs);
        ofs << parents.size() << std::endl;
        for(auto p : parents)
            p->save(ofs);
        ofs << courses.size() << std::endl;
        for(auto c : courses)
            c->save(ofs);
        ofs << sections.size() << std::endl;
        for(auto s : sections)
            s->save(ofs);
        if(!ofs) throw std::runtime_error{"Error writing file"};
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, "Unable to save school"}.run();
    }
}
void Mainwin::on_save_as_click(){
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("smart files");
    filter_smart->add_pattern("*.smart");
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);
    
    if(dialog.run() == 1){
        Mainwin::filename = dialog.get_filename();
        on_save_click();
    }
}
void Mainwin::on_open_click(){
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("smart files");
    filter_smart->add_pattern("*.smart");
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            int size;
            on_new_school_click();
            filename = dialog.get_filename();
            std::ifstream ifs{filename};            
            if(!ifs) throw std::runtime_error{"File contents bad"};
            ifs >> size;
            for(int i = 0; i < size; i++){
                students.push_back(new Student{ifs});
            }
            ifs >> size;
            for(int i = 0; i < size; i++){
                parents.push_back(new Parent{ifs});
            }
            ifs >> size;
            for(int i = 0; i < size; i++){
                courses.push_back(new Course{ifs});
            }
            ifs >> size;
            for(int i = 0; i < size; i++){
                sections.push_back(new Section{ifs});
            }
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open school"}.run();
        }
    }
    show_data();
}
void Mainwin::on_about_click(){
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this);
    dialog.set_program_name("Smart");
    auto logo = Gdk::Pixbuf::create_from_file("logo.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 1.7.0+");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"William Sigala"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Logo by clipartmax, licensed for personal use https://www.clipartmax.com/middle/m2K9A0m2b1A0m2G6_school-house-clip-art-house-the-cliparts-school-house-cartoon-png/",
        "Icons done by William Sigala"};
    dialog.set_artists(artists);
    dialog.run();
}
void Mainwin::on_new_course_click() {
    Glib::ustring s{"<span size='12000' weight='bold'>"};
    s += "0) reading\n1) writing\n2) math\n3) science\n4) history\n5) art\n6) music\n7) sports\n</span>";
    EntryDialog edialog_subject{*this, "<big>Subject name?</big>", true};
    edialog_subject.set_secondary_text(s, true);
    if(edialog_subject.run() == Gtk::RESPONSE_OK)
        edialog_subject.hide();
    else return;
    EntryDialog edialog_grade{*this, "<big>Grade (1-12)?</big>", true};
    if(edialog_grade.run() == Gtk::RESPONSE_OK)
        edialog_grade.hide();
    else return;

    int sub_num = std::stoi(std::string(edialog_subject.get_text()));
    Subject subject;

    if(sub_num == 0) subject = Subject::READING;
    else if(sub_num == 1) subject = Subject::WRITING;
    else if(sub_num == 2) subject = Subject::MATH;
    else if(sub_num == 3) subject = Subject::SCIENCE;
    else if(sub_num == 4) subject = Subject::HISTORY;
    else if(sub_num == 5) subject = Subject::ART;
    else if(sub_num == 6) subject = Subject::MUSIC;
    else if(sub_num == 7) subject = Subject::SPORTS;
    else return;

    courses.push_back(new Course{subject, std::stoi(std::string(edialog_grade.get_text()))});
    show_data();
}
void Mainwin::on_new_section_click() {
    Glib::ustring s{"<span size='12000' weight='bold'>"};
    for(int i = 0; i < courses.size(); i++)
        s += std::to_string(i) + ") " + courses.at(i)->full_info() + "\n";
    s += "</span>";
    EntryDialog edialog_course{*this, "<big>Select courses</big>", true};
    edialog_course.set_secondary_text(s, true);
    if(edialog_course.run() == Gtk::RESPONSE_OK)
        edialog_course.hide();
    else return;

    EntryDialog edialog_year{*this, "<big>Select Semester and Year</big>", true};
    edialog_year.add_button("Cancel", 0);
    edialog_year.add_button("Fall", 1);
    edialog_year.add_button("Spring", 2);
    edialog_year.add_button("Summer", 3);

    int sem_num = edialog_year.run();
    if(sem_num)
        edialog_year.hide();
    else return;

    Semester semester; 
    if(sem_num == 0) semester = Semester::FALL;
    else if(sem_num == 1) semester = Semester::SPRING;
    else if(sem_num == 2) semester = Semester::SUMMER;
    else return;
    Course course = *courses.at(std::stoi(std::string(edialog_course.get_text())));
    int year = std::stoi(std::string(edialog_year.get_text()));
    sections.push_back(new Section{course, semester, year});
    edialog_year.hide();
}