#include "user.hpp"

page_user::page_user() : Gtk::Box(Gtk::Orientation::VERTICAL), box_profile_picture(Gtk::Orientation::VERTICAL) {
	append(label_text);
	append(box_profile_picture);
	append(listbox_main);

	label_text.set_text("User account");
	label_text.set_margin(20);
	label_text.get_style_context()->add_class("title-1");

	box_profile_picture.get_style_context()->add_class("card");
	box_profile_picture.set_halign(Gtk::Align::CENTER);
	box_profile_picture.set_size_request(500, -1);
	box_profile_picture.append(profile_picture);
	box_profile_picture.append(flowbox_account_pictures);
	box_profile_picture.set_margin_bottom(20);
	profile_picture.set_from_icon_name("user");
	profile_picture.set_pixel_size(128);
	profile_picture.set_vexpand(true);

	listbox_main.get_style_context()->add_class("boxed-list");
	listbox_main.set_selection_mode(Gtk::SelectionMode::NONE);
	listbox_main.set_halign(Gtk::Align::CENTER);
	listbox_main.set_size_request(500, -1);
	listbox_main.set_margin_bottom(20);

	listbox_main.append(box_full_name);
	box_full_name.append(label_full_name);
	box_full_name.get_style_context()->add_class("header");
	label_full_name.set_label("Full name");
	label_full_name.set_hexpand(true);
	label_full_name.set_halign(Gtk::Align::START);
	box_full_name.append(entry_full_name);
	entry_full_name.set_valign(Gtk::Align::CENTER);
	entry_full_name.set_placeholder_text("Full username");
	entry_full_name.set_size_request(342, -1);

	listbox_main.append(box_account_name);
	box_account_name.append(label_account_name);
	box_account_name.get_style_context()->add_class("header");
	label_account_name.set_label("Account name");
	label_account_name.set_hexpand(true);
	label_account_name.set_halign(Gtk::Align::START);
	box_account_name.append(entry_account_name);
	entry_account_name.set_valign(Gtk::Align::CENTER);
	entry_account_name.set_placeholder_text("Username");
	entry_account_name.set_size_request(342, -1);

	listbox_main.append(box_password);
	box_password.append(label_password);
	box_password.get_style_context()->add_class("header");
	label_password.set_label("Password");
	label_password.set_hexpand(true);
	label_password.set_halign(Gtk::Align::START);
	box_password.append(entry_password);
	entry_password.set_valign(Gtk::Align::CENTER);
	entry_password.set_placeholder_text("Password");
	entry_password.set_visibility(false);
	entry_password.set_input_purpose(Gtk::InputPurpose::PASSWORD);
	box_password.append(entry_password_verification);
	entry_password_verification.set_valign(Gtk::Align::CENTER);
	entry_password_verification.set_placeholder_text("Password verification");
	entry_password_verification.set_visibility(false);
	entry_password_verification.set_input_purpose(Gtk::InputPurpose::PASSWORD);
}
