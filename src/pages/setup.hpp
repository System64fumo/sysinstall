#include <gtkmm/box.h>
#include <gtkmm/label.h>

class page_setup : public Gtk::Box {
	public:
		page_setup();

	private:
		Gtk::Label label_text;

		void setup_ui();
};
