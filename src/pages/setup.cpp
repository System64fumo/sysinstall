#include "setup.hpp"
#include "../window.hpp"
#include <giomm/subprocess.h>
#include <giomm/subprocesslauncher.h>

page_setup::page_setup(sysinstall* win) : Gtk::Box(Gtk::Orientation::VERTICAL), window(win), box_setup_output(Gtk::Orientation::VERTICAL) {
	setup_ui();
}

void page_setup::setup_ui() {
	append(label_text);
	append(box_setup_output);
	append(spinner_progress);

	label_text.set_text("Setup");
	label_text.set_margin(20);
	label_text.get_style_context()->add_class("title-1");

	box_setup_output.append(label_setup_output);
	box_setup_output.get_style_context()->add_class("card");
	box_setup_output.set_margin(20);
	box_setup_output.set_margin_top(0);
	box_setup_output.set_vexpand();

	label_setup_output.set_vexpand();
	label_setup_output.set_margin(10);
	label_setup_output.set_xalign(0);
	label_setup_output.set_yalign(0);
	label_setup_output.set_sensitive(false);

	spinner_progress.set_margin_bottom(20);
}

void page_setup::start_setup() {
	spinner_progress.start();

	std::vector<std::string> arguments = {
		"/opt/setup/install.sh",
		window->language,
		window->time_zone,
		window->full_username,
		window->username,
		window->password
	};

	Gio::Subprocess::Flags flags =
		Gio::Subprocess::Flags::STDOUT_PIPE |
		Gio::Subprocess::Flags::STDERR_PIPE;

	auto launcher = Gio::SubprocessLauncher::create(flags);
	auto spawned_subprocess = launcher->spawn(arguments);
	constexpr gsize buffer_size = 4096;
	auto buffer = std::make_shared<std::vector<char>>(buffer_size);

	auto stdout_stream = spawned_subprocess->get_stdout_pipe();

	auto read_output = std::make_shared<std::function<void(Glib::RefPtr<Gio::AsyncResult>&)>>();

	*read_output = [&, stdout_stream, buffer, read_output](Glib::RefPtr<Gio::AsyncResult>& result) {
		gsize bytes_read = stdout_stream->read_finish(result);

		if (bytes_read > 0) {
			// Process the output
			std::string output(buffer->data(), bytes_read);
			label_setup_output.set_text(label_setup_output.get_text() + output);

			// Schedule another async read
			stdout_stream->read_async(
				buffer->data(), buffer->size(),
				[read_output](Glib::RefPtr<Gio::AsyncResult>& next_result) {
					(*read_output)(next_result);
				},
				Glib::PRIORITY_DEFAULT);
		}
	};

	// Start the first async read
	stdout_stream->read_async(
		buffer->data(), buffer->size(),
		[read_output](Glib::RefPtr<Gio::AsyncResult>& result) {
			(*read_output)(result);
		},
		Glib::PRIORITY_DEFAULT);
}
