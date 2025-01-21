#include "setup.hpp"

page_setup::page_setup() : Gtk::Box(Gtk::Orientation::VERTICAL) {
	setup_ui();
}

void page_setup::setup_ui() {
	append(label_text);

	label_text.set_text("Setup");
	label_text.set_margin(20);
	label_text.get_style_context()->add_class("title-1");
}
