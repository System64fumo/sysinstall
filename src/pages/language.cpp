#include "language.hpp"

page_language::page_language() : Gtk::Box(Gtk::Orientation::VERTICAL) {
	setup_language_list();
	setup_ui();
}

void page_language::setup_language_list() {
	// TODO: I REALLY don't want to do this but it might be the only way..
	language_list["en_US.UTF-8"] = "English United States";
}

void page_language::setup_ui() {
	append(label_text);
	append(scrolledwindow_language);
	scrolledwindow_language.set_child(listbox_language);

	label_text.set_text("Language");
	label_text.set_margin(20);
	label_text.get_style_context()->add_class("title-1");

	scrolledwindow_language.set_size_request(400, 400);
	scrolledwindow_language.set_halign(Gtk::Align::CENTER);

	listbox_language.get_style_context()->add_class("rich-list");
	listbox_language.get_style_context()->add_class("content");

	const char *filename = "/etc/locale.gen";
	FILE *file = fopen(filename, "r");
	if (!file) {
		perror("Failed to open /etc/locale.gen");
		return;
	}

	char line[256];
	bool skip_first = true;

	while (fgets(line, sizeof(line), file)) {
		if (strstr(line, "UTF-8")) {
			if (skip_first) {
				skip_first = false;
				continue;
			}

			char *start = line;
			while (*start == '#' || *start == ' ' || *start == '\t')
				start++;

			char *end = start;
			while (*end != ' ' && *end != '\t' && *end != '\n' && *end != '\0')
				end++;
			*end = '\0';

			if (*start) {
				// TODO: Use language map instead of locales
				listbox_language.append(*Gtk::make_managed<Gtk::Label>(start));
			}
		}
	}
}
