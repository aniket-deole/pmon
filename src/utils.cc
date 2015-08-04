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

#include <iostream>
#include <fstream>
#include <assert.h>
#include <openssl/md5.h>
#include <sstream>
#include <algorithm>

#include <gtkmm.h>

std::string replaceString(std::string subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
    return subject;
}

template <typename T>
std::string NumberToString(T pNumber)
{
 std::ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();
}

void addCss (Gtk::Widget* widget, std::string cssClass, std::string css) {
	Glib::RefPtr<Gtk::StyleContext> context;
	context = widget->get_style_context ();
	widget->set_name (cssClass);
	Glib::RefPtr<Gtk::CssProvider> provider = Gtk::CssProvider::create ();

	provider->load_from_data (css);
	context->add_provider (provider, GTK_STYLE_PROVIDER_PRIORITY_SETTINGS);
	context->add_class (cssClass);
}

