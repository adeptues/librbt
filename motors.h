//#pragma once
#ifndef _MOTORS_H

#define _MOTORS_H

#include <stdlib.h>
#include "armfunc.h"
#include "data.h"

//#include "data.h"

 void lightOn();
 void stop();

void moveM2Up();

void moveM2Down();

void moveM3Up();
void moveM3Down();

void moveM4Down();
void moveM4Up();

void moveM5Clockwise();
void moveM5AntiClock();

void closeClaw();

 void openClaw();

#endif /* _MOTORS_H */