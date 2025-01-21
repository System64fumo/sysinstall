#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/image.h>
#include <gtkmm/listbox.h>
#include <gtkmm/flowbox.h>

class sysinstall;

class page_user : public Gtk::Box {
	public:
		page_user(sysinstall*);

	private:
		sysinstall* window;

		Gtk::Label label_text;
		Gtk::ListBox listbox_main;
		Gtk::Box box_profile_picture;
		Gtk::Image profile_picture;
		Gtk::FlowBox flowbox_account_pictures;

		Gtk::Box box_full_name;
		Gtk::Label label_full_name;
		Gtk::Entry entry_full_name;

		Gtk::Box box_account_name;
		Gtk::Label label_account_name;
		Gtk::Entry entry_account_name;

		Gtk::Box box_password;
		Gtk::Label label_password;
		Gtk::Entry entry_password;

		Gtk::Box box_password_verification;
		Gtk::Label label_password_verification;
		Gtk::Entry entry_password_verification;

		void setup_ui();
		void setup_actions();
};
