//#pragma once
#ifndef _MOTORS_H

#define _MOTORS_H

#include <stdlib.h>
#include "armfunc.h"
#include "data.h"

//#include "data.h"

extern void lightOn();
extern void stop();

extern void moveMotor();

extern void closeClaw();

extern void openClaw();

#endif /* _MOTORS_H */