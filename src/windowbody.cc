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

    //Create the Tree model:
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);

    //Fill the TreeView's model
    Gtk::TreeModel::Row row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 1;
    row[m_Columns.m_col_name] = "Billy Bob";
    row[m_Columns.m_col_number] = 10;
    row[m_Columns.m_col_percentage] = 15;

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 2;
    row[m_Columns.m_col_name] = "Joey Jojo";
    row[m_Columns.m_col_number] = 20;
    row[m_Columns.m_col_percentage] = 40;

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 3;
    row[m_Columns.m_col_name] = "Rob McRoberts";
    row[m_Columns.m_col_number] = 30;
    row[m_Columns.m_col_percentage] = 70;

    //Add the TreeView's view columns:
    //This number will be shown with the default numeric formatting.
    m_TreeView.append_column("ID", m_Columns.m_col_id);
    m_TreeView.append_column("Name", m_Columns.m_col_name);

    m_TreeView.append_column_numeric("Formatted number", m_Columns.m_col_number,
        "%010d" /* 10 digits, using leading zeroes. */);

    //Display a progress bar instead of a decimal number:
    Gtk::CellRendererProgress* cell = Gtk::manage(new Gtk::CellRendererProgress);
    int cols_count = m_TreeView.append_column("Some percentage", *cell);
    Gtk::TreeViewColumn* pColumn = m_TreeView.get_column(cols_count - 1);
    if(pColumn)
    {
      pColumn->add_attribute(cell->property_value(), m_Columns.m_col_percentage);
    }

    //Make all the columns reorderable:
    //This is not necessary, but it's nice to show the feature.
    //You can use TreeView::set_column_drag_function() to more
    //finely control column drag and drop.
    for(guint i = 0; i < 2; i++)
    {
      Gtk::TreeView::Column* pColumn = m_TreeView.get_column(i);
      pColumn->set_reorderable();
    }
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
