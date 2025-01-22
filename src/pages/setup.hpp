#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/spinner.h>

class sysinstall;

class page_setup : public Gtk::Box {
	public:
		page_setup(sysinstall*);

		void start_setup();

	private:
		sysinstall* window;

		Gtk::Label label_text;
		Gtk::Entry entry_setup_output;
		Gtk::Spinner spinner_progress;

		void setup_ui();
};
