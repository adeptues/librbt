//#pragma once
#ifndef _ARMFUNC_H

#define _ARMFUNC_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include <libusb.h>

#include "data.h"

//defines
#define vid  4711
#define pid  0000

//globals

extern  libusb_device **devs;
extern libusb_device_handle * devh;

//must be called first befor library use
int libraryInit();

//must be called when finished executing
int libraryDispose();

int isRobotArm(libusb_device * device);

void printRobotInfo(libusb_device **devs);

void print_devs(libusb_device **devs);

void msgToData(unsigned char * data,Message msg);

#endif
