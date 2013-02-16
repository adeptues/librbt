#include <stdio.h>
#include <sys/types.h>

#include <libusb.h>
#include <stdlib.h>
#include <unistd.h>//not portable
//#include "data.h"
#include "armfunc.h"
#include "motors.h"



/*
static void print_devs(libusb_device **devs)
{
	libusb_device *dev;
	int i = 0;

	while ((dev = devs[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			fprintf(stderr, "failed to get device descriptor");
			return;
		}

		printf("%04x:%04x (bus %d, device %d)\n",
			desc.idVendor, desc.idProduct,
			libusb_get_bus_number(dev), libusb_get_device_address(dev));
	}
}*/


int main(void)
{
  printf("starting lib\n");
  int r = libraryInit();
  if(r < 0){
    printf("application execution failed\n");
    return -1;
  }

  printf("turning light on\n");
  lightOn();
  printf("waiting 3 seconds\n");
  sleep(3);
  printf("turning light off\n");
  stop();

  libraryDispose();
 

  return 0;
}