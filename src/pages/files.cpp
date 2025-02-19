#include "files.hpp"
#include "../window.hpp"

page_files::page_files(sysinstall* win) : Gtk::Box(Gtk::Orientation::VERTICAL), window(win), box_main(Gtk::Orientation::VERTICAL) {
	setup_ui();
}

void page_files::setup_ui() {
	append(label_text);
	append(box_main);

	box_main.append(label_files);
	box_main.append(listbox_files);
	box_main.append(label_extras);
	box_main.append(listbox_extras);

	box_main.set_halign(Gtk::Align::CENTER);
	box_main.set_size_request(500, -1);

	label_text.set_text("Files");
	label_text.set_margin(20);
	label_text.get_style_context()->add_class("title-1");

	label_files.set_text("Main");
	label_files.set_xalign(0);
	label_files.set_margin(5);
	label_files.get_style_context()->add_class("title-4");

	label_extras.set_text("Extras");
	label_extras.set_xalign(0);
	label_extras.set_margin(5);
	label_extras.get_style_context()->add_class("title-4");

	listbox_files.get_style_context()->add_class("boxed-list");
	listbox_files.set_selection_mode(Gtk::SelectionMode::NONE);
	listbox_files.set_margin_bottom(20);

	listbox_extras.get_style_context()->add_class("boxed-list");
	listbox_extras.set_selection_mode(Gtk::SelectionMode::NONE);
	listbox_extras.set_margin_bottom(20);

	// TODO: Add GUI file picker next to the entries
	// TODO: Add rootfs downloader? (That may be difficult to do)

	listbox_files.append(box_package);
	box_package.get_style_context()->add_class("header");
	box_package.append(label_package);
	label_package.set_text("Device Package");
	label_package.set_hexpand();
	label_package.set_xalign(0);
	box_package.append(entry_package);
	entry_package.set_size_request(300, -1);
	entry_package.set_valign(Gtk::Align::CENTER);
	entry_package.set_placeholder_text("/path/to/device_package.tar");

	listbox_files.append(box_rootfs);
	box_rootfs.get_style_context()->add_class("header");
	box_rootfs.append(label_rootfs);
	label_rootfs.set_text("Rootfs");
	label_rootfs.set_hexpand();
	label_rootfs.set_xalign(0);
	box_rootfs.append(entry_rootfs);
	entry_rootfs.set_size_request(300, -1);
	entry_rootfs.set_valign(Gtk::Align::CENTER);
	entry_rootfs.set_placeholder_text("/path/to/rootfs.img");

	listbox_extras.append(box_firmware);
	box_firmware.get_style_context()->add_class("header");
	box_firmware.append(label_firmware);
	label_firmware.set_text("Firmware");
	label_firmware.set_hexpand();
	label_firmware.set_xalign(0);
	box_firmware.append(entry_firmware);
	entry_firmware.set_size_request(300, -1);
	entry_firmware.set_valign(Gtk::Align::CENTER);
	entry_firmware.set_placeholder_text("/path/to/usr/lib/firmware");
}
