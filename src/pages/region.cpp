#include "region.hpp"

page_region::page_region() : Gtk::Box(Gtk::Orientation::VERTICAL) {
	append(label_text);
	append(scrolledwindow_language);
	scrolledwindow_language.set_child(listbox_language);

	label_text.set_text("Region");
	label_text.set_margin(20);
	label_text.get_style_context()->add_class("title-1");

	scrolledwindow_language.set_size_request(300, 400);
	scrolledwindow_language.set_halign(Gtk::Align::CENTER);
}
