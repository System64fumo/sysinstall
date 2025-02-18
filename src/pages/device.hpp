#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/flowbox.h>
#include <gtkmm/scrolledwindow.h>

class sysinstall;

class page_device : public Gtk::Box {
	public:
		page_device(sysinstall*);

	private:
		sysinstall* window;

		Gtk::Label label_text;
		Gtk::Box box_devices;
		Gtk::FlowBox flowbox_devices;
		Gtk::ScrolledWindow scrolledwindow_devices;

		void setup_ui();
};
