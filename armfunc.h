#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include <libusb.h>

//defines
#define vid  4711
#define pid  0000

//globals
libusb_device **devs;
libusb_device_handle * devh;

//must be called first befor library use
int libraryInit();

//must be called when finished executing 
int libraryDispose();

int isRobotArm(libusb_device * device);

static void printRobotInfo(libusb_device **devs);

static void print_devs(libusb_device **devs);

void lightOn();

void moveMotor();

void closeClaw();

void openClaw();