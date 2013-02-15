#include <stdio.h>
#include <sys/types.h>

#include <libusb.h>

//defines
#define id  4711
#define part  0000

/**
 * This is designed to be a user mode library for controlling a robot arm
 * */
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
}


///Should find the robot arm device on the system and return a pointer to that device
libusb_device * findRobotArm(libusb_device **devs,libusb_device_handle ** devh){
  libusb_device * devPtr;
  
  int count = 0;
  while((devPtr = devs[count++]) != NULL){
    struct libusb_device_descriptor descr;
    int rtnCode = libusb_get_device_descriptor(devPtr,&descr);

    if(rtnCode < 0){
      printf("Failed to get device descriptor\n");
      return NULL;
    }

    if((descr.idVendor == id )&& (descr.idProduct == part)){
      printf("Found Robot Arm Device!\n");
      libusb_open(devPtr,);
      return devPtr;
    }

    
    
  }

  printf("could not find device robot arm with %d : %d ",id,part);
  return NULL;

  
  
  
}

int main(void)
{
	libusb_device **devs;
	//libusb_device_handle ** devh;
	int r;
	ssize_t cnt;

	
	r = libusb_init(NULL); // must be called fir st before any other libusb function 
	if (r < 0)
		return r;//failed to initialise

	cnt = libusb_get_device_list(NULL, &devs);//get a list of all usb devices on the system place it into the collection struct libusb_device
	if (cnt < 0)//cnt number of returned devices 
		return (int) cnt;

	//print_devs(devs);
	libusb_device * dev =  findRobotArm(devs);

	if(dev != NULL){
	  printf("find robot arm worksa\n");
	}

	//next step open device / claim interface and send data then free
	
	libusb_free_device_list(devs, 1);//free device list

	libusb_exit(NULL);//must be called when program quits
	return 0;
}