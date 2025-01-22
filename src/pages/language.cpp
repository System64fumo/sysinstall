#include "language.hpp"

page_language::page_language() : Gtk::Box(Gtk::Orientation::VERTICAL) {
	setup_language_list();
	setup_ui();
}

void page_language::setup_language_list() {
	// TODO: I REALLY don't want to do this but it might be the only way..
	language_list["ar_SA.UTF-8"] = "Arabic";
	language_list["bn_IN.UTF-8"] = "Bangla";
	language_list["eu_ES.UTF-8"] = "Basque";
	language_list["bg_BG.UTF-8"] = "Bulgarian";
	language_list["zh_HK.UTF-8"] = "Cantonese";
	language_list["ca_ES.UTF-8"] = "Catalan";
	language_list["hr_HR.UTF-8"] = "Croatian";
	language_list["cs_CZ.UTF-8"] = "Czech";
	language_list["da_DK.UTF-8"] = "Danish";
	language_list["nl_NL.UTF-8"] = "Dutch";
	language_list["en_US.UTF-8"] = "English";
	language_list["fi_FI.UTF-8"] = "Finnish";
	language_list["fr_FR.UTF-8"] = "French";
	language_list["gl_ES.UTF-8"] = "Galician";
	language_list["de_DE.UTF-8"] = "German";
	language_list["el_GR.UTF-8"] = "Greek";
	language_list["he_IL.UTF-8"] = "Hebrew";
	language_list["hi_IN.UTF-8"] = "Hindi";
	language_list["hu_HU.UTF-8"] = "Hungarian";
	language_list["id_ID.UTF-8"] = "Indonesian";
	language_list["it_IT.UTF-8"] = "Italian";
	language_list["ja_JP.UTF-8"] = "Japanese";
	language_list["kn_IN.UTF-8"] = "Kannada";
	language_list["kk_KZ.UTF-8"] = "Kazakh";
	language_list["ko_KR.UTF-8"] = "Korean";
	language_list["lt_LT.UTF-8"] = "Lithuanian";
	language_list["ms_MY.UTF-8"] = "Malay";
	language_list["zh_CN.UTF-8"] = "Mandarin";
	language_list["mr_IN.UTF-8"] = "Marathi";
	language_list["nb_NO.UTF-8"] = "Norwegian Bokmal";
	language_list["fa_IR.UTF-8"] = "Persian";
	language_list["pl_PL.UTF-8"] = "Polish";
	language_list["pt_PT.UTF-8"] = "Portuguese";
	language_list["ro_RO.UTF-8"] = "Romanian";
	language_list["ru_RU.UTF-8"] = "Russian";
	language_list["sk_SK.UTF-8"] = "Slovak";
	language_list["sl_SI.UTF-8"] = "Slovenian";
	language_list["es_ES.UTF-8"] = "Spanish";
	language_list["sv_SE.UTF-8"] = "Swedish";
	language_list["ta_IN.UTF-8"] = "Tamil";
	language_list["te_IN.UTF-8"] = "Telugu";
	language_list["th_TH.UTF-8"] = "Thai";
	language_list["tr_TR.UTF-8"] = "Turkish";
	language_list["uk_UA.UTF-8"] = "Ukrainian";
	language_list["vi_VN.UTF-8"] = "Vietnamese";
}

void page_language::setup_ui() {
	append(label_text);
	append(scrolledwindow_language);
	scrolledwindow_language.set_child(listbox_language);

	label_text.set_text("Language");
	label_text.set_margin(20);
	label_text.get_style_context()->add_class("title-1");

	scrolledwindow_language.set_size_request(400, -1);
	scrolledwindow_language.set_halign(Gtk::Align::CENTER);
	scrolledwindow_language.set_vexpand();
	scrolledwindow_language.set_margin_bottom(20);

	listbox_language.get_style_context()->add_class("rich-list");
	listbox_language.get_style_context()->add_class("content");

	// Sort stuff
	listbox_language.set_sort_func([this](Gtk::ListBoxRow* row1, Gtk::ListBoxRow* row2) {
		auto label1 = dynamic_cast<Gtk::Label*>(row1->get_child());
		auto label2 = dynamic_cast<Gtk::Label*>(row2->get_child());
		if (label1 && label2) {
			return label1->get_text().compare(label2->get_text());
		}
		return 0;
	});

	// Populate the list
	for (const auto& [key, value] : language_list) {
		listbox_language.append(*Gtk::make_managed<Gtk::Label>(value));
	}
	return;

	// TODO: Reconsider this at some point
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
				listbox_language.append(*Gtk::make_managed<Gtk::Label>(start));
			}
		}
	}
}
