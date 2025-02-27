#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/listbox.h>

class sysinstall;

class page_files : public Gtk::Box {
	public:
		page_files(sysinstall*);

	private:
		sysinstall* window;

		Gtk::Label label_text;


		Gtk::Box box_main;
		Gtk::Label label_files;
		Gtk::Label label_extras;
		Gtk::ListBox listbox_files;
		Gtk::ListBox listbox_extras;

		Gtk::Box box_package;
		Gtk::Label label_package;
		Gtk::Entry entry_package;

		Gtk::Box box_rootfs;
		Gtk::Label label_rootfs;
		Gtk::Entry entry_rootfs;

		Gtk::Box box_firmware;
		Gtk::Label label_firmware;
		Gtk::Entry entry_firmware;

		void setup_ui();
};
