public class PMon.App : Granite.Application {

    /**
     * Translatable launcher (.desktop) strings to be added to template (.pot) file.
     * These strings should reflect any changes in these launcher keys in .desktop file
     */
    public const string PROGRAM_NAME = "PMon";
    public const string COMMENT = N_("Process Monitor");
    public const string GENERIC = N_("Process Monitor");
    public const string KEYWORDS = N_("PMon;Process;Monitor;");
    public const string ABOUT_PMon = N_("About PMon");
    
    public static MainWindow mainWindow { get; private set;}

    construct {
        // This allows opening files. See the open() method below.
        flags |= ApplicationFlags.HANDLES_OPEN;

        // App info
/*        build_data_dir = Build.DATADIR;
        build_pkg_data_dir = Build.PKG_DATADIR;
        build_release_name = Build.RELEASE_NAME;
        build_version = Build.VERSION;
        build_version_info = Build.VERSION_INFO;
*/
        program_name = PROGRAM_NAME;
        exec_name = "pmon";

        app_copyright = "2015";
        application_id = "org.aniket.pmon";
        app_icon = "application-default-icon";
        app_launcher = "pmon.desktop";
        app_years = "2015";

        main_url = "https://github.com/aniket-deole/pmon";
        bug_url = "https://github.com/aniket-deole/pmon";
        help_url = "https://github.com/aniket-deole/pmon";
        translate_url = "https://github.com/aniket-deole/pmon";

        about_authors = {"Aniket Deole <aniket.deole@gmail.com>", null};

        about_artists = {"Aniket Deole <aniket.deole@gmail.com>", null};
    }


    protected override void activate () {
        
        if (mainWindow == null) {
            if (DEBUG)
                Granite.Services.Logger.DisplayLevel = Granite.Services.LogLevel.DEBUG;
            else
                Granite.Services.Logger.DisplayLevel = Granite.Services.LogLevel.INFO;

            mainWindow = new MainWindow ();
            mainWindow.build_ui ();
            mainWindow.set_application (this);
        }

        mainWindow.present ();
    }

    /**
     * We use this identifier to init everything inside the application.
     * For instance: libnotify, etc.
     */
    public string get_id () {
        return application_id;
    }

    /**
     * @return the application's brand name. Should be used for anything that requires
     * branding. For instance: Ubuntu's sound menu, dialog titles, etc.
     */
    public string get_name () {
        return program_name;
    }

    /**
     * @return the application's desktop file name.
     */
    public string get_desktop_file_name () {
        return app_launcher;
    }
}
