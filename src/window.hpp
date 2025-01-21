#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/stack.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/listbox.h>
#include <gtkmm/centerbox.h>

class sysinstall : public Gtk::Window {
	public:
		sysinstall();

		bool password_set;

		Gtk::Button button_previous;
		Gtk::Button button_next;

	private:

		Gtk::Box box_main;
		Gtk::Stack stack_main;
		Gtk::CenterBox centerbox_nav;

		void setup_ui();
		void load_pages();
};
