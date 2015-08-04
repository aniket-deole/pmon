/***
Copyright (C) 2013 Aniket Deole <aniket.deole@gmail.com>
This program is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License version 2.1, as published
by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranties of
MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program.  If not, see <http://www.gnu.org/licenses/>.
***/

#ifndef _WINDOWBODY_HH_
#define _WINDOWBODY_HH_

#include <gtkmm.h>

#include <pmon.hh>
#include <maintoolbar.hh>

class PMon;
class MainToolbar;

void addCss (Gtk::Widget* widget, std::string cssClass, std::string css);

class WindowBody : public Gtk::Box {
private:
    int a;

    PMon* app;
public:
    WindowBody (bool homogeneous, int spacing, Gtk::PackOptions options, int padding = 0, PMon* a = NULL);
    ~WindowBody ();

    void setApp (PMon* a);
};

#endif
