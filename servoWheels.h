#ifndef SERVO_H_INCLUDED
#define SERVO_H_INCLUDED
#include "state.h"
#include <Servo.h>

class ServoWheels {
  public:
    ServoWheels();
    void init();
    void setServoState(state s);
  private:
    void setServoSpeed(int right, int left);
    void waiting();
    void forward();
    void backward();
    void spinRight();
    void spinLeft();
    void turnRight();
    void turnLeft();
};

#endif
