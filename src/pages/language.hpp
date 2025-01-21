#include <map>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/listbox.h>
#include <gtkmm/scrolledwindow.h>

class page_language : public Gtk::Box {
	public:
		page_language();

	private:
		std::map<std::string, std::string> language_list;

		Gtk::Label label_text;
		Gtk::ListBox listbox_language;
		Gtk::ScrolledWindow scrolledwindow_language;

		void setup_language_list();
		void setup_ui();
};
