//#pragma once
#ifndef _DATA_H

#define _DATA_H

#include <stdlib.h>
//message struct for storing codes

 typedef struct{
  char b1;
  char b2;
  char b3;
  
}Message;

//valid messages
extern const Message lighton;

extern const Message stopCmd;

extern const Message m1Open;

extern const Message m1Close;

extern const Message m2Up;

extern const Message m2Down;

extern const Message m3Up;

extern const Message m3Down;

extern const Message m4Up;

extern const Message m4Down;

extern const Message m5Clock;

extern const Message m5Anti;

#endif /* _DATA_H */