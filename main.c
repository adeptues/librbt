#include <stdio.h>
#include <sys/types.h>

#include <libusb.h>
#include <stdlib.h>
#include "data.h"
#include "armfunc.h"



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
/*
static void printRobotInfo(libusb_device **devs){
  	libusb_device *dev;
	int i = 0;

	while ((dev = devs[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			fprintf(stderr, "failed to get device descriptor");
			return;
		}

        if((desc.idVendor == vid )&& (desc.idProduct == pid)) {
	  struct libusb_config_descriptor * config;
	  libusb_get_config_descriptor(dev,0,&config);
	  struct libusb_interface  interface =  config->interface[0];
	  struct libusb_interface_descriptor idesc = *interface.altsetting;
	  
	  
            printf("Found Robot Arm Device!\n");
	    printf("Vendor id: %d\n",desc.idVendor);
	    printf("Product id: %d\n",desc.idProduct);
	    printf("Device Class: %d\n",desc.bDeviceClass);
	    printf("Number of Interfaces: %d\n",config->bNumInterfaces);
	    printf("Number of end points: %d\n",idesc.bNumEndpoints);
	    printf("End point address: %d\n",idesc.endpoint->bEndpointAddress);
	    printf("End point descriptor type %d\n",idesc.endpoint->bDescriptorType);
	    
	    libusb_free_config_descriptor(config);
        }

		printf("%04x:%04x (bus %d, device %d)\n",
			desc.idVendor, desc.idProduct,
			libusb_get_bus_number(dev), libusb_get_device_address(dev));
	}
}*/

/*
///Should find the robot arm device on the system and return a pointer to that device
libusb_device * findRobotArm(libusb_device **devs){
  libusb_device * devPtr;
  
  int count = 0;
  while((devPtr = devs[count++]) != NULL){
    struct libusb_device_descriptor descr;
    int rtnCode = libusb_get_device_descriptor(devPtr,&descr);

    if(rtnCode < 0){
      printf("Failed to get device descriptor\n");
      return NULL;
    }

    if((descr.idVendor == vid )&& (descr.idProduct == pid)){
      printf("Found Robot Arm Device!\n");


      return devPtr;
    }
    
  }

  printf("could not find device robot arm with %d : %d ",vid,pid);
  return NULL;
}*/
/*
int isRobotArm(libusb_device * device){
  struct libusb_device_descriptor desc;
  libusb_get_device_descriptor(device,&desc);
  if(desc.idProduct == pid && desc.idVendor == vid){
    return 1;
  }
  return 0;
  
}*/

int main(void)
{
 printf("hello world\n");
  /*
	libusb_device **devs;
	libusb_device_handle * devh;
	int r;
	ssize_t cnt;

	
	r = libusb_init(NULL); // must be called fir st before any other libusb function 
	if (r < 0)
		return r;//failed to initialise

	cnt = libusb_get_device_list(NULL, &devs);//get a list of all usb devices on the system place it into the collection struct libusb_device
	if (cnt < 0)//cnt number of returned devices 
		return (int) cnt;

	//open device directly with vid and pid
	//devh = libusb_open_device_with_vid_pid(NULL,vid,pid);
	int i;
	for(i = 0; i < cnt; i++){
	  libusb_device * device = devs[i];
	  if(isRobotArm(device)){
	    int er = libusb_open(device,&devh);
	    if(er < 0){
	      printf("Could Not Open Device: %s",libusb_error_name(er));
	      return -1;
	    }
	  }
	}

	if(devh == NULL){
	  printf("Could not open Device\n");
	  return -1;
	}
	
	libusb_free_device_list(devs, 1);//free device list

	//is there a kernel driver active
	if(libusb_kernel_driver_active(devh,0) == 1){
	  printf("Warning: kernel driver active attempting to detatch\n");
	  if(libusb_detach_kernel_driver(devh,0) == 0){
	    printf("kernel driver Detatched continueing ..\n");
	  }else{
	    printf("ERROR: Failed to detatch kernel driver!\n");
	    return -1;
	  }
	  
	}
	int rtnCode = libusb_claim_interface(devh,0);
	if(rtnCode < 0){
	  printf("Failure: Could Not claim interface\n");
	}
	printf("Interface claimed\n");

	unsigned char * data = (char *)malloc(3*sizeof(char));// 3bytes
	data[0] = 0x0;
	data[1] = 0x0;
	data[2] = 0x0;
	int actual = 0;
	//do io bulk transfer
	printf("Sending data\n");
	//int trans = libusb_bulk_transfer(devh, (129 | LIBUSB_ENDPOINT_OUT), data, 3, &actual, 1000);
	//int trans = libusb_interrupt_transfer(devh,(129 | LIBUSB_ENDPOINT_OUT),data,3,&actual,1000);
	int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

	if(trans == 0 && actual == 3){
	  printf("wrote %s\n",libusb_error_name(trans));
	}else{
	  printf("Failed to write to device trans %s actual %d\n",libusb_error_name(trans),actual);
	}
	
	//memory clean up
	printf("Cleaning up memory\n");
	int rd = libusb_release_interface(devh,0);

	if(rd < 0){
	  printf("Warning: Something horrible has happened ... cannot release interface\n");
	  return -1;
	}

	libusb_close(devh);
	

//printRobotInfo(devs);
	

	libusb_exit(NULL);//must be called when program quits
	free(data);
	return 0;*/
  return 0;
}