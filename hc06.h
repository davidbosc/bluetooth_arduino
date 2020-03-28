#ifndef HC06_H_INCLUDED
#define HC06_H_INCLUDED
#include "state.h"

class HC06 {
  public:
    HC06();
    char acceptBlueToothInput();
    state commandInterpreter(char command);
};

#endif
