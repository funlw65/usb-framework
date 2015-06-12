#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#include <libusb.h>

#include "log.h"
#include "../common/constants.h"

libusb_context *usb;
libusb_device_handle *usb_handle;

/* Example:
void usb_push_status(void) {
        int ret = libusb_control_transfer(usb_handle, LIBUSB_REQUEST_TYPE_VENDOR,
                        USB_REQ_STATUS, club_open ? 1 : 0, 0, NULL, 0, 500);

        if(ret < 0)
                die("usb_push_status failed: %s", libusb_error_name(ret));
}
*/

int usb_init(void) {
	int ret = libusb_init(&usb);
	if(ret) {
		error("libusb_init failed: %s", libusb_error_name(ret));
		return -1;
	}

	usb_handle = libusb_open_device_with_vid_pid(usb, USB_VID, USB_PID);
	if(!usb_handle) {
		error("couldn't find USB device");
		return -1;
	}

	return 0;
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	setbuf(stdout, NULL);
	setbuf(stderr, NULL);

	printf("%s rev " GIT_REV " starting up\n", argv[0]);

	if(usb_init() < 0)
		die("USB initialization failed");
}
