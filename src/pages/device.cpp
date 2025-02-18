#include "device.hpp"
#include "../window.hpp"

#include <filesystem>
#include <regex>
#include <fstream>

std::string format_size(uint64_t sizeInBytes) {
	const char* units[] = {"B", "KB", "MB", "GB", "TB"};
	int unitIndex = 0;
	double size = static_cast<double>(sizeInBytes);

	while (size >= 1024 && unitIndex < 4) {
		size /= 1024;
		unitIndex++;
	}

	char buffer[50];
	snprintf(buffer, sizeof(buffer), "%.2f %s", size, units[unitIndex]);
	return std::string(buffer);
}

std::string get_disk_name(const std::string& partitionName) {
	std::regex disk_regex("^(sd[a-z]+|nvme[0-9]+n[0-9]+|mmcblk[0-9]+)");
	std::smatch match;
	if (std::regex_search(partitionName, match, disk_regex)) {
		return match.str(0);
	}
	return "";
}

std::string get_rootfs_dev() {
	std::ifstream mountsFile("/proc/mounts");
	if (!mountsFile.is_open()) {
		return "";
	}

	std::string line;
	while (std::getline(mountsFile, line)) {
		std::istringstream iss(line);
		std::string device, mountPoint;
		iss >> device >> mountPoint;

		if (mountPoint == "/") {
			return device;
		}
	}

	return "";
}

void page_device::get_disks() {
	std::string rootDevice = get_rootfs_dev();
	if (rootDevice.empty())
		return;

	std::string rootDisk = get_disk_name(std::filesystem::path(rootDevice).filename());
	if (rootDisk.empty())
		return;

	std::filesystem::path sys_block_path = "/sys/block";

	std::regex disk_regex("^(sd[a-z]+|nvme[0-9]+n[0-9]+|mmcblk[0-9]+)$");

	for (const auto& entry : std::filesystem::directory_iterator(sys_block_path)) {
		std::string device_name = entry.path().filename();

		if (!std::regex_match(device_name, disk_regex))
			continue;
		if (device_name == rootDisk)
			continue;

		std::filesystem::path size_file_path = entry.path() / "size";

		std::ifstream size_file(size_file_path);
		if (!size_file.is_open())
			continue;

		uint64_t sector_count = 0;
		size_file >> sector_count;
		size_file.close();

		if (sector_count == 0)
			continue;

		uint64_t size_in_bytes = sector_count * 512;
		std::string formatted_size = format_size(size_in_bytes);
		std::printf("Disk: %s, Size: %s\n", device_name.c_str(), formatted_size.c_str());
		auto dev = Gtk::make_managed<device>(device_name, formatted_size);
		flowbox_devices.append(*dev);
	}
}

device::device(const std::string& name, const std::string& size) : Gtk::Box(Gtk::Orientation::VERTICAL) {
	set_size_request(128, 128);
	append(image_device);
	append(label_device);
	append(label_size);

	image_device.set_from_icon_name("drive-harddisk");
	image_device.set_valign(Gtk::Align::CENTER);
	image_device.set_pixel_size(64);
	image_device.set_vexpand(true);

	label_device.set_text(name);
	label_size.set_text(size);
	label_size.set_vexpand(true);
}


page_device::page_device(sysinstall* win) : Gtk::Box(Gtk::Orientation::VERTICAL), window(win), box_devices(Gtk::Orientation::VERTICAL) {
	setup_ui();

	get_disks();
}

void page_device::setup_ui() {
	append(label_text);
	append(scrolledwindow_devices);

	label_text.set_text("Device");
	label_text.set_margin(20);
	label_text.get_style_context()->add_class("title-1");

	scrolledwindow_devices.set_margin(20);
	scrolledwindow_devices.set_margin_top(0);
	scrolledwindow_devices.set_vexpand();
	scrolledwindow_devices.set_child(flowbox_devices);

	flowbox_devices.set_orientation(Gtk::Orientation::VERTICAL);
	flowbox_devices.set_halign(Gtk::Align::CENTER);
	flowbox_devices.set_valign(Gtk::Align::CENTER);
	flowbox_devices.set_max_children_per_line(5);
	flowbox_devices.set_row_spacing(10);
	flowbox_devices.set_column_spacing(10);
}
