#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/listbox.h>
#include <gtkmm/scrolledwindow.h>

class sysinstall;

class page_region : public Gtk::Box {
	public:
		page_region(sysinstall*);

	private:
		sysinstall* window;

		Gtk::Label label_text;
		Gtk::ListBox listbox_region;
		Gtk::ScrolledWindow scrolledwindow_region;

		void setup_ui();
};
