#include <stdlib.h>

#include "motors.h"

void lightOn()
{
    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,lighton);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 0) {
        printf("wrote %s\n",libusb_error_name(trans));

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}

void closeClaw()
{

}

void moveMotor()
{

}

void openClaw()
{

}

void stop()
{

}



