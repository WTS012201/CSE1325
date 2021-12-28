#include "mainwin.h"
#include <iostream>

Mainwin::Mainwin() : filename{"untitled.smart"} {

    set_default_size(550, 200);
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
    
    Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep1);

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

    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    
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
    s += "<span size='12000' weight='bold'>Students\n\n";
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
void Mainwin::on_save_click(){
    try {
        std::ofstream ofs{Mainwin::filename};
        ofs << students.size() << std::endl;
        for(auto s : students)
            s.save(ofs);
        ofs << parents.size() << std::endl;
        for(auto p : parents)
            p.save(ofs);
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

    dialog.set_filename("untitled.smart");

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

    dialog.set_filename("untitled.smart");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            int size;
            on_new_school_click();
            std::ifstream ifs{dialog.get_filename()};            
            if(!ifs) throw std::runtime_error{"File contents bad"};
            ifs >> size;
            for(int i = 0; i < size; i++){
                Student s{ifs};
                students.push_back(s);
            }
            ifs >> size;
            for(int i = 0; i < size; i++){
                Parent p{ifs};
                parents.push_back(p);
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