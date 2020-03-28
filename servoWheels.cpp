#include <Arduino.h>
#include "servoWheels.h"
#include "state.h"
#include <Servo.h>

/***
 * Pin Configuration
 */
#define RIGHT_SERVO_PIN             3
#define LEFT_SERVO_PIN              5

/***
 * Global Variables
 */
Servo rightServo;
Servo leftServo;
//CONSTANTS
#define RIGHT_OFFSET                4
#define LEFT_OFFSET                 5


/***
 * Initialize Servos
 */
ServoWheels::ServoWheels() {}

void ServoWheels::init() {
  rightServo.attach(RIGHT_SERVO_PIN);
  leftServo.attach(LEFT_SERVO_PIN);
  // waiting();
}

/***
 * Set the speed and direction of the
 * servos based on its current state
 */ 
void ServoWheels::setServoState(state s) {
  switch(s) {
    case state::FORWARD_STATE:
      forward();
      break;
    case state::BACKWARD_STATE:
      backward();
      break;
    case state::SPIN_LEFT_STATE:
      spinLeft();
      break;
    case state::SPIN_RIGHT_STATE:
      spinRight();
      break;
    default:
      waiting();
      break;
  }
}

/***
 * Set the speed of both servos
 */
void ServoWheels::setServoSpeed(int right, int left) {
  rightServo.write(right + RIGHT_OFFSET);
  leftServo.write(left + LEFT_OFFSET);
}

//TODO: Document all these functions, and clean up the constants
void ServoWheels::waiting() {
  setServoSpeed(90, 90);
}

void ServoWheels::forward() {
  setServoSpeed(0, 180);
}

void ServoWheels::backward() {
  setServoSpeed(180, 0);
}

void ServoWheels::spinRight() {
  setServoSpeed(93, 93);
}

void ServoWheels::spinLeft() {
  setServoSpeed(87, 87);
}

void ServoWheels::turnRight() {
  setServoSpeed(90, 180);
}

void ServoWheels::turnLeft() {
  setServoSpeed(0, 90);
}
