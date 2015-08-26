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

class Process {

};

class CellRenderer : public Gtk::CellRenderer {
  public:
    Glib::PropertyProxy< int > property_id()
    {
      return property_id_.get_proxy();
    }

    Glib::PropertyProxy<Process> property_process()
    {
      return property_process_.get_proxy();
    }

    CellRenderer () :
      Glib::ObjectBase( typeid (CellRenderer) ),
      Gtk::CellRenderer(), 
      property_id_(*this, "id"),
      property_process_(*this, "process") {
        set_fixed_size (1, 30);
      }

    Pango::Rectangle* renderProcess (const ::Cairo::RefPtr< ::Cairo::Context >& cr, Gtk::Widget& widget, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, Pango::Rectangle* pr, int id) {
      Pango::FontDescription font_from;
      font_from.set_size (10 * Pango::SCALE);

      font_from.set_weight (Pango::WEIGHT_NORMAL);
      cr->move_to (10, cell_area.get_y () + 5);

      Glib::RefPtr <Pango::Layout> layout_from = widget.create_pango_layout ("");
      layout_from->set_font_description (font_from);
      layout_from->set_markup ("<span foreground='#444'>asd</span>");
      layout_from->set_width(210 * Pango::SCALE);
      layout_from->show_in_cairo_context (cr);
      return pr;
    }

    Glib::Property< int > property_id_;
    Glib::Property< Process > property_process_;

  protected:
    virtual void render_vfunc (const ::Cairo::RefPtr< ::Cairo::Context >& cr, Gtk::Widget& widget, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, Gtk::CellRendererState flags) {
      Pango::Rectangle* pr = new Pango::Rectangle ();
      renderProcess (cr, widget, background_area, cell_area, pr, property_id_);
    }
};

static Gtk::TreeViewColumn* create_column (Gtk::TreeModelColumn<int> tmc, int n) {
  CellRenderer* ncr = new CellRenderer ();
  Gtk::TreeViewColumn* c = Gtk::manage (new Gtk::TreeViewColumn ("Process", *ncr));
  c->add_attribute(*ncr, "id", tmc);
  c->add_attribute(*ncr, "process", 23);
  return c;
}



WindowBody::WindowBody (bool homogeneous, int spacing, Gtk::PackOptions options, int padding, PMon* a) 
  : Gtk::Box (Gtk::ORIENTATION_VERTICAL, padding) {
    app = a;
    set_orientation (Gtk::ORIENTATION_VERTICAL);

    Gtk::Box* body = Gtk::manage (new Gtk::Box (Gtk::ORIENTATION_HORIZONTAL, 0));

    //Create the Tree model:
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);

    Gtk::TreeModel::Row  row = *(m_refTreeModel->append());
    m_TreeView.append_column(*create_column (m_Columns.m_col_id, 1));

    row = *(m_refTreeModel->append());
    //Add the TreeView, inside a ScrolledWindow, with the button underneath:
    m_ScrolledWindow.add(m_TreeView);

    //Only show the scrollbars when they are necessary:
    m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    body->pack_start(m_ScrolledWindow);


    pack_start (*body, Gtk::PACK_EXPAND_WIDGET, 0);

    show_all_children ();
    show_all ();

  }

WindowBody::~WindowBody () {

}
