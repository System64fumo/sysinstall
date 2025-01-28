#include <gtkmm/application.h>
#include "window.hpp"

int main(int argc, char* argv[]) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("funky.sys64.sysinstall");

	while (true) {
		switch(getopt(argc, argv, "oh")) {
			case 'o':
				setup = true;
				continue;

			case 'h':
			default :
				std::printf("usage:\n");
				std::printf("  sysinstall [argument...]:\n\n");
				std::printf("arguments:\n");
				std::printf("  -o	Start out of box setup\n");
				std::printf("  -h	Show this help message\n");
				return 0;

			case -1:
				break;
			}

			break;
	}

	return app->make_window_and_run<sysinstall>(0, nullptr);
}
