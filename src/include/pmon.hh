/***
Copyright (C) 2015 Aniket Deole <aniket.deole@gmail.com>
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

#ifndef _PMON_HH_
#define _PMON_HH_

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <windowbody.hh>
#include <maintoolbar.hh>

class WindowBody;

class PMon : public Gtk::Window {
public:
	PMon ();
	virtual ~PMon ();

  MainToolbar* mainToolbar;
  WindowBody* windowBody;

protected:
	void on_button_clicked();
	Gtk::Button m_button;
};

#endif

