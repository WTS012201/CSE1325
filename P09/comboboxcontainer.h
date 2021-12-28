#ifndef __COMBOBOXCONTAINER_H
#define __COMBOBOXCONTAINER_H
#include <vector>
#include <cassert>
#include <gtkmm.h>

template<class T>
class ComboBoxContainer : public Gtk::ComboBoxText{
  public:
    ComboBoxContainer(T container) : ComboBoxText(true) {
        for(auto t : container){
            std::ostringstream oss; 
            oss << *t;
            append(oss.str());
        }
    }
};

#endif