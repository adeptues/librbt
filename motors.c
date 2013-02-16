#include <stdlib.h>

#include "motors.h"

void lightOn()
{
    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,lighton);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 3) {
        printf("wrote %d bytes\n",trans);

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}

void closeClaw()
{
    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,m1Close);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 3) {
        printf("wrote %d bytes\n",trans);

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}

void moveM2Down()
{
    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,m2Down);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 3) {
        printf("wrote %d bytes\n",trans);

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}

void moveM2Up()
{
    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,m2Up);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 3) {
        printf("wrote %d bytes\n",trans);

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}

void moveM3Down()
{
    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,m3Down);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 3) {
        printf("wrote %d bytes\n",trans);

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}

void moveM3Up()
{

    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,m3Up);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 3) {
        printf("wrote %d bytes\n",trans);

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}

void moveM4Down()
{

    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,m4Down);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 3) {
        printf("wrote %d bytes\n",trans);

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}

void moveM4Up()
{

    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,m4Up);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 3) {
        printf("wrote %d bytes\n",trans);

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}

void moveM5AntiClock()
{
    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,m5Anti);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 3) {
        printf("wrote %d bytes\n",trans);

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}

void moveM5Clockwise()
{
    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,m5Clock);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 3) {
        printf("wrote %d bytes\n",trans);

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}







void openClaw()
{
    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,m1Open);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 3) {
        printf("wrote %d bytes\n",trans);

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}

void stop()
{
    unsigned char * data = malloc(sizeof(Message));

    msgToData(data,stopCmd);

    int trans = libusb_control_transfer(devh,0x40,6,0x100,0,data,3,2000);

    if(trans == 3) {
        printf("wrote %d bytes\n",trans);

    } else {
        printf("Failed to write to device trans %s\n",libusb_error_name(trans));

    }

    free(data);

}



