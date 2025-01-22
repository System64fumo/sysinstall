#include "setup.hpp"
#include "../window.hpp"

page_setup::page_setup(sysinstall* win) : Gtk::Box(Gtk::Orientation::VERTICAL), window(win) {
	setup_ui();
}

void page_setup::setup_ui() {
	append(label_text);
	append(entry_setup_output);
	append(spinner_progress);

	label_text.set_text("Setup");
	label_text.set_margin(20);
	label_text.get_style_context()->add_class("title-1");

	entry_setup_output.set_margin(20);
	entry_setup_output.set_margin_top(0);
	entry_setup_output.set_vexpand();
	entry_setup_output.set_sensitive(false);

	spinner_progress.set_margin_bottom(20);
}

void page_setup::start_setup() {
	spinner_progress.start();
	entry_setup_output.set_text(
		window->language + "\n" +
		window->time_zone + "\n" +
		window->full_username + "\n" +
		window->username + "\n" +
		window->password
	);
}
