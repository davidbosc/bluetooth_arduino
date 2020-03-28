#ifndef SERVO_H_INCLUDED
#define SERVO_H_INCLUDED
#include "state.h"

class ServoWheels {
  public:
    ServoWheels();
    void setServoState(state state);
    void setServoSpeed(int right, int left);
  private:
    void stop();
    void forward();
    void backward();
    void spinRight();
    void spinLeft();
    void turnRight();
    void turnLeft();
};

#endif