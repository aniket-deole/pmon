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

#include <gtkmm/box.h>
#include <gtkmm/widget.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/styleprovider.h>

#include <windowbody.hh>

WindowBody::WindowBody (bool homogeneous, int spacing, Gtk::PackOptions options, int padding, PMon* a) 
    : Gtk::Box (Gtk::ORIENTATION_VERTICAL, padding) {
    app = a;
	  set_orientation (Gtk::ORIENTATION_VERTICAL);

    Gtk::Box* body = Gtk::manage (new Gtk::Box (Gtk::ORIENTATION_HORIZONTAL, 0));

    pack_end (*body, Gtk::PACK_EXPAND_WIDGET, 0);
  	show_all ();
}

WindowBody::~WindowBody () {

}
