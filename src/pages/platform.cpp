#include "platform.hpp"
#include "../window.hpp"

page_platform::page_platform(sysinstall* win) : Gtk::Box(Gtk::Orientation::VERTICAL), window(win) {
	setup_ui();
	load_platforms();
}

void page_platform::setup_ui() {
	append(label_text);
	append(scrolledwindow_platform);
	scrolledwindow_platform.set_child(listbox_platform);

	label_text.set_text("Platform");
	label_text.set_margin(20);
	label_text.get_style_context()->add_class("title-1");

	scrolledwindow_platform.set_size_request(400, -1);
	scrolledwindow_platform.set_halign(Gtk::Align::CENTER);
	//scrolledwindow_platform.set_vexpand();
	scrolledwindow_platform.set_policy(Gtk::PolicyType::NEVER, Gtk::PolicyType::NEVER);
	scrolledwindow_platform.set_margin_bottom(20);

	listbox_platform.get_style_context()->add_class("rich-list");
	listbox_platform.get_style_context()->add_class("content");
}

void page_platform::load_platforms() {
	listbox_platform.append(*Gtk::make_managed<Gtk::Label>("Orange Pi 5 Plus"));
	listbox_platform.append(*Gtk::make_managed<Gtk::Label>("Orange Pi 3 B"));
	listbox_platform.get_row_at_index(1)->set_sensitive(false);
}
