#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/stack.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/listbox.h>
#include <gtkmm/revealer.h>
#include <gtkmm/centerbox.h>

class page_setup;

class sysinstall : public Gtk::Window {
	public:
		sysinstall();

		bool password_set;

		Gtk::Button button_previous;
		Gtk::Button button_next;

		std::string language;
		std::string time_zone;
		std::string full_username;
		std::string username;
		std::string password;

	private:
		page_setup* p_setup;

		Gtk::Box box_main;
		Gtk::Stack stack_main;
		Gtk::Revealer revealer_nav;
		Gtk::CenterBox centerbox_nav;

		void setup_ui();
		void load_pages();
};
