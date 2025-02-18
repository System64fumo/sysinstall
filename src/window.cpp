#include "window.hpp"
#include <gtkmm/singleselection.h>
#include "pages/language.hpp"
#include "pages/region.hpp"
#include "pages/user.hpp"
#include "pages/setup.hpp"
#include "pages/platform.hpp"
#include "pages/files.hpp"
#include "pages/device.hpp"

sysinstall::sysinstall() : box_main(Gtk::Orientation::VERTICAL) {
	set_title("Setup");
	set_default_size(1280, 720);
	set_child(box_main);

	// Out of Box Setup
	if (setup)
		load_setup_pages();
	else
		load_install_pages();

	setup_ui();

	button_previous.signal_clicked().connect([&]() {
		auto pages = stack_main.get_pages();
		auto selection = pages->get_selection();
		int current_page = selection->get_maximum();

		// First page
		if (current_page - 1 == 0)
			button_previous.set_sensitive(false);
		button_next.set_sensitive(true);

		pages->select_item(current_page - 1, false);
	});
	button_next.signal_clicked().connect([&]() {
		auto pages = stack_main.get_pages();
		auto selection = pages->get_selection();
		int current_page = selection->get_maximum();

		// Last page
		if (current_page + 1 == 3)
			button_next.set_sensitive(false);

		button_previous.set_sensitive(true);

		if (setup) {
			if (current_page == 1 && !password_set) {
				button_next.set_sensitive(false);
				pages->select_item(current_page + 1, false);
				return;
			}

			if (current_page == 2 && password_set) {
				revealer_nav.set_reveal_child(false);
				p_setup->start_setup();
			}
		}

		pages->select_item(current_page + 1, false);
	});
}

void sysinstall::setup_ui() {
	box_main.append(stack_main);
	box_main.append(revealer_nav);

	revealer_nav.set_child(centerbox_nav);
	revealer_nav.set_transition_type(Gtk::RevealerTransitionType::SLIDE_UP);
	revealer_nav.set_transition_duration(500);
	revealer_nav.set_reveal_child(true);

	if (setup) {
		box_main.get_style_context()->add_class("card");
		box_main.set_size_request(750, 600);
		box_main.set_halign(Gtk::Align::CENTER);
		box_main.set_valign(Gtk::Align::CENTER);
	}

	centerbox_nav.set_start_widget(button_previous);
	centerbox_nav.set_end_widget(button_next);
	centerbox_nav.set_margin(10);
	button_previous.set_image_from_icon_name("go-previous-symbolic");
	button_previous.set_size_request(100, -1);
	button_previous.set_sensitive(false);
	button_next.get_style_context()->add_class("suggested-action");
	button_next.set_image_from_icon_name("go-next-symbolic");
	button_next.set_size_request(100, -1);

	stack_main.set_transition_type(Gtk::StackTransitionType::SLIDE_LEFT_RIGHT);
	stack_main.set_hexpand(true);
	stack_main.set_vexpand(true);
}

void sysinstall::load_setup_pages() {
	auto p_language = Gtk::make_managed<page_language>(this);
	auto stack_language = stack_main.add(*p_language, "language");

	auto p_region = Gtk::make_managed<page_region>(this);
	auto stack_region = stack_main.add(*p_region, "region");

	auto p_user = Gtk::make_managed<page_user>(this);
	auto stack_user = stack_main.add(*p_user, "user");

	p_setup = Gtk::make_managed<page_setup>(this);
	auto stack_setup = stack_main.add(*p_setup, "setup");
}

void sysinstall::load_install_pages() {
	auto p_platform = Gtk::make_managed<page_platform>(this);
	auto stack_platform = stack_main.add(*p_platform, "platform");

	auto p_files = Gtk::make_managed<page_files>(this);
	auto stack_files = stack_main.add(*p_files, "files");

	auto p_device = Gtk::make_managed<page_device>(this);
	auto stack_device = stack_main.add(*p_device, "device");
}
