#include <stdio.h>
#include <sys/types.h>

#include <libusb.h>
#include <stdlib.h>
#include <unistd.h>//not portable
//#include "data.h"
#include "armfunc.h"
#include "motors.h"


void clawTest(){
   lightOn();
  sleep(1);
  openClaw();
  sleep(1);
  stop();
  closeClaw();
  sleep(1);
  stop();


  stop();
}

void m2test(){
    //funcs here
  moveM2Up();
  sleep(1);
  stop();
  moveM2Down();
  sleep(1);
  stop();
}

void m3test(){
    moveM3Up();
  sleep(1);
  stop();
  moveM3Down();
  sleep(1);
  stop();
}

void m4test(){
    moveM4Up();
  sleep(1);
  stop();
  moveM4Down();
  sleep(1);
  stop();
}

void m5test(){
    moveM5Clockwise();
  sleep(1);
  stop();
  moveM5AntiClock();
  sleep(1);
  stop();
}

int main(void)
{
  printf("starting lib\n");
  int r = libraryInit();
  if(r < 0){
    printf("application execution failed\n");
    return -1;
  }
printf("starting device tests please look at the device!\n");
  clawTest();
  m2test();
  m3test();
  m4test();
  m5test();

  libraryDispose();
 

  return 0;
}