#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/listbox.h>
#include <gtkmm/scrolledwindow.h>

class page_region : public Gtk::Box {
	public:
		page_region();

	private:
		Gtk::Label label_text;
		Gtk::ListBox listbox_language;
		Gtk::ScrolledWindow scrolledwindow_language;
};
