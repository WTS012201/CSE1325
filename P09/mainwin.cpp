#include "mainwin.h"
#include <iostream>

Mainwin::Mainwin() : filename{"untitled.smart"}, display_status{0} {

    set_default_size(950, 200);
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

    Gtk::MenuItem *menuitem_new_teacher = Gtk::manage(new Gtk::MenuItem("_New Teacher", true));
    menuitem_new_teacher->signal_activate().connect([this] {this->on_new_teacher_click();});
    insertmenu->append(*menuitem_new_teacher);

    Gtk::MenuItem *menuitem_new_course = Gtk::manage(new Gtk::MenuItem("_New Course", true));
    menuitem_new_course->signal_activate().connect([this] {this->on_new_course_click();});
    insertmenu->append(*menuitem_new_course);

    Gtk::MenuItem *menuitem_new_section = Gtk::manage(new Gtk::MenuItem("_New Section", true));
    menuitem_new_section->signal_activate().connect([this] {this->on_new_section_click();});
    insertmenu->append(*menuitem_new_section);

    Gtk::MenuItem *menuitem_new_transcript = Gtk::manage(new Gtk::MenuItem("_New Transcript", true));
    menuitem_new_transcript->signal_activate().connect([this] {this->on_new_transcript_click();});
    insertmenu->append(*menuitem_new_transcript);

    //  relate

    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);

    Gtk::MenuItem *menuitem_student_parent = Gtk::manage(new Gtk::MenuItem("Student to Parent", true));
    menuitem_student_parent->signal_activate().connect([this] {this->on_student_parent_click();});
    relatemenu->append(*menuitem_student_parent);

    Gtk::MenuItem *menuitem_grade = Gtk::manage(new Gtk::MenuItem("Set a grade", true));
    menuitem_grade->signal_activate().connect([this] {this->on_set_grade_click();});
    relatemenu->append(*menuitem_grade);

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

    Gtk::MenuItem *menuitem_teachers = Gtk::manage(new Gtk::MenuItem("_Teachers", true));
    menuitem_teachers->signal_activate().connect([this] {this->display_status = 5; this->show_data();});
    viewmenu->append(*menuitem_teachers);

    Gtk::MenuItem *menuitem_transcripts = Gtk::manage(new Gtk::MenuItem("_Transcripts", true));
    menuitem_transcripts->signal_activate().connect([this] {this->display_status = 6; this->show_data();});
    viewmenu->append(*menuitem_transcripts);
    
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

    Gtk::Image* button6_image = Gtk::manage(new Gtk::Image{"button6_on.png"});
    Gtk::ToolButton *button6 = Gtk::manage(new Gtk::ToolButton(*button6_image));
    button6->set_tooltip_markup("New teacher");
    button6->signal_clicked().connect([this] {this->on_new_teacher_click();});
    toolbar->append(*button6);

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

    Gtk::Image* button7_image = Gtk::manage(new Gtk::Image{"button7_on.png"});
    Gtk::ToolButton *button7 = Gtk::manage(new Gtk::ToolButton(*button7_image));
    button7->set_tooltip_markup("New transcript");
    button7->signal_clicked().connect([this] {this->on_new_transcript_click();});
    toolbar->append(*button7);
    
    Gtk::Image* button8_image = Gtk::manage(new Gtk::Image{"button8_on.png"});
    Gtk::ToolButton *button8 = Gtk::manage(new Gtk::ToolButton(*button8_image));
    button8->set_tooltip_markup("Set grade");
    button8->signal_clicked().connect([this] {this->on_set_grade_click();});
    toolbar->append(*button8);

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
        case 5:
            s += "\nTeachers\n\n";
            for(int i = 0; i < teachers.size(); i++)
                s += teachers.at(i)->full_info() + "\n";
            break;
        case 6:
            s += "\nTranscripts\n\n";
            for(int i = 0; i < transcripts.size(); i++)
                s += transcripts.at(i)->full_info() + "\n";
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
    teachers.clear();
    transcripts.clear();
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
void Mainwin::on_new_teacher_click(){
    EntryDialog edialog_name{*this, "<big>Teacher name?</big>", true};
    if(edialog_name.run() == Gtk::RESPONSE_OK)
        edialog_name.hide();
    else return;
    EntryDialog edialog_email{*this, "<big>Teacher email?</big>", true};
    if(edialog_email.run() == Gtk::RESPONSE_OK)
        edialog_email.hide();
    else return;
    teachers.push_back(new Teacher{edialog_name.get_text(), edialog_email.get_text()});
    show_data();
}

void Mainwin::on_student_parent_click(){
    
    Gtk::MessageDialog dialog_student{*this, "Select student"};
    ComboBoxContainer<std::vector<Student*>> cbt_students(students);
    dialog_student.get_vbox()->pack_start(cbt_students);
    dialog_student.get_vbox()->show_all();
    if(dialog_student.run() == Gtk::RESPONSE_OK)
        dialog_student.hide();
    else return;
    
    Gtk::MessageDialog dialog_parent{*this, "Select parent"};
    ComboBoxContainer<std::vector<Parent*>> cbt_parents(parents);
    dialog_parent.get_vbox()->pack_start(cbt_parents);
    dialog_parent.get_vbox()->show_all();
    if(dialog_parent.run() == Gtk::RESPONSE_OK)
        dialog_parent.hide();
    else return;
    
    students.at(int{cbt_students.get_active_row_number()})->add_parent(*parents.at(int{cbt_parents.get_active_row_number()}));
    parents.at(int{cbt_parents.get_active_row_number()})->add_student(*students.at(int{cbt_students.get_active_row_number()}));
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
        ofs << teachers.size() << std::endl;
        for(auto t : teachers)
            t->save(ofs);
        ofs << courses.size() << std::endl;
        for(auto c : courses)
            c->save(ofs);
        ofs << sections.size() << std::endl;
        for(auto s : sections)
            s->save(ofs);
        ofs << transcripts.size() << std::endl;
        for(auto t : transcripts)
            t->save(ofs);
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
                teachers.push_back(new Teacher{ifs});
            }
            ifs >> size;
            for(int i = 0; i < size; i++){
                courses.push_back(new Course{ifs});
            }
            ifs >> size;
            for(int i = 0; i < size; i++){
                sections.push_back(new Section{ifs});
            }
            ifs >> size;
            for(int i = 0; i < size; i++){
                transcripts.push_back(new Transcript{ifs});
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

    Gtk::MessageDialog dialog_teacher{*this, "Select teacher"};
    ComboBoxContainer<std::vector<Teacher*>> cbt_teachers(teachers);
    dialog_teacher.get_vbox()->pack_start(cbt_teachers);
    dialog_teacher.get_vbox()->show_all();
    if(dialog_teacher.run() == Gtk::RESPONSE_OK)
        dialog_teacher.hide();
    else return;

    Teacher teacher = *teachers.at(cbt_teachers.get_active_row_number());
    Course course = *courses.at(std::stoi(std::string(edialog_course.get_text())));
    int year = std::stoi(std::string(edialog_year.get_text()));
    sections.push_back(new Section{course, semester, year, teacher});
    edialog_year.hide();
    show_data();
}
void Mainwin::on_new_transcript_click() {
    Gtk::MessageDialog dialog_student{*this, "Select student"};
    ComboBoxContainer<std::vector<Student*>> cbt_students(students);
    dialog_student.get_vbox()->pack_start(cbt_students);
    dialog_student.get_vbox()->show_all();
    if(dialog_student.run() == Gtk::RESPONSE_OK)
        dialog_student.hide();
    else return;
    
    Gtk::MessageDialog dialog_section{*this, "Select section"};
    ComboBoxContainer<std::vector<Section*>> cbt_sections(sections);
    dialog_section.get_vbox()->pack_start(cbt_sections);
    dialog_section.get_vbox()->show_all();
    if(dialog_section.run() == Gtk::RESPONSE_OK)
        dialog_section.hide();
    else return;

    transcripts.push_back(new Transcript{*students.at(cbt_students.get_active_row_number()), *sections.at(cbt_sections.get_active_row_number())});
    show_data();
}
void Mainwin::on_set_grade_click(){
    Gtk::MessageDialog dialog_transcript{*this, "Select transcript"};
    ComboBoxContainer<std::vector<Transcript*>> cbt_transcripts(transcripts);
    dialog_transcript.get_vbox()->pack_start(cbt_transcripts);
    dialog_transcript.get_vbox()->show_all();
    dialog_transcript.add_button("A", -1);
    dialog_transcript.add_button("B", 1);
    dialog_transcript.add_button("C", 2);
    dialog_transcript.add_button("D", 3);
    dialog_transcript.add_button("F", 4);
    dialog_transcript.add_button("I", 5);
    dialog_transcript.add_button("X", 6);
    int result = dialog_transcript.run();
    if(result == Gtk::RESPONSE_OK)
        dialog_transcript.hide();

    Grade grade;
    if(result == 0) grade = Grade::A;
    else if(result == 1) grade = Grade::B;
    else if(result == 2) grade = Grade::C;
    else if(result == 3) grade = Grade::D;
    else if(result == 4) grade = Grade::F;
    else if(result == 5) grade = Grade::I;
    else if(result == 6) grade = Grade::X;
    else return;

    transcripts.at(cbt_transcripts.get_active_row_number())->assign_grade(grade);
    show_data();
}