public class PMon.MainWindow : Gtk.Window {
    /* Main layout widgets */
    private Gtk.Box       verticalBox;

    private Gtk.HeaderBar    headerbar;

    private bool window_maximized = false;
    private int window_width = 0;
    private int window_height = 0;

    public MainWindow () {
        headerbar = new Gtk.HeaderBar ();
        headerbar.show_close_button = true;
        set_titlebar (headerbar);

    }
 
    private inline void setup_window () {
        debug ("setting up main window");

        this.height_request = 350;
        this.width_request = 400;
        this.window_position = Gtk.WindowPosition.CENTER;

        // set the size based on saved settings
        this.set_default_size (1280,720);


        this.title = ((PMon.App) GLib.Application.get_default ()).get_name ();
        this.icon_name = "applicationd-default-icon";

        this.destroy.connect (on_quit);

        this.show ();
        debug ("done with main window");
    }

    private inline void build_main_widgets () {
        debug ("Building main widgets");

        /** App menu widgets **/

        headerbar.set_title (((PMon.App) GLib.Application.get_default ()).get_name ());
        headerbar.show_all ();

        debug ("Done with main widgets");
    }

    public void build_ui () {
        debug ("BUILDING USER INTERFACE");

        setup_window ();

        build_main_widgets ();

        debug ("DONE WITH USER INTERFACE");
    }

    private void on_quit () {
    }

}
