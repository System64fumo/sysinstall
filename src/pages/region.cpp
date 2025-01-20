#include "region.hpp"
#include <filesystem>

page_region::page_region() : Gtk::Box(Gtk::Orientation::VERTICAL) {
	append(label_text);
	append(scrolledwindow_region);
	scrolledwindow_region.set_child(listbox_region);

	label_text.set_text("Region");
	label_text.set_margin(20);
	label_text.get_style_context()->add_class("title-1");

	scrolledwindow_region.set_size_request(300, 400);
	scrolledwindow_region.set_halign(Gtk::Align::CENTER);


	const std::string prefix = "/usr/share/zoneinfo/";

	for (const auto& entry : std::filesystem::recursive_directory_iterator("/usr/share/zoneinfo")) {
		if (!entry.is_regular_file())
			continue;

		const std::string path = entry.path().string();

		if (path.find("/posix/") != std::string::npos ||
			path.find("/right/") != std::string::npos ||
			path.find("/Etc/") != std::string::npos ||
			path.find("/US/") != std::string::npos) {
			continue;
		}

		if (path.find(prefix) == 0) {
			std::string relative_path = path.substr(prefix.size());
			if (std::count(relative_path.begin(), relative_path.end(), '/') == 0)
				continue;

			listbox_region.append(*Gtk::make_managed<Gtk::Label>(relative_path));
		}
	}
}
