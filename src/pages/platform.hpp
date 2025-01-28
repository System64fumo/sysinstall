#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/listbox.h>
#include <gtkmm/scrolledwindow.h>

class sysinstall;

class page_platform : public Gtk::Box {
	public:
		page_platform(sysinstall*);

	private:
		sysinstall* window;

		Gtk::Label label_text;
		Gtk::ListBox listbox_platform;
		Gtk::ScrolledWindow scrolledwindow_platform;

		void setup_ui();
		void load_platforms();
};
