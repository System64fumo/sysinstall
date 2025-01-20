#include <gtkmm/application.h>
#include "window.hpp"

int main(int argc, char* argv[]) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("funky.sys64.sysinstall");

	return app->make_window_and_run<sysinstall>(0, nullptr);
}
