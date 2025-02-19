#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/image.h>
#include <gtkmm/flowbox.h>
#include <gtkmm/scrolledwindow.h>

class sysinstall;

class device : public Gtk::Box {
	public:
		device(const std::string&, const std::string&);

		Gtk::Image image_device;
		Gtk::Label label_device;
		Gtk::Label label_size;

		std::string path;
		uint64_t size;
};

class page_device : public Gtk::Box {
	public:
		page_device(sysinstall*);

	private:
		sysinstall* window;

		Gtk::Label label_text;
		Gtk::Box box_devices;
		Gtk::FlowBox flowbox_devices;
		Gtk::ScrolledWindow scrolledwindow_devices;

		void setup_ui();
		void get_disks();
};
