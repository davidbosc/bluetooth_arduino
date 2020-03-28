#include <Arduino.h>
#include "hc06.h"
#include "state.h"
#include <SoftwareSerial.h>

/***
 * Pin Configuration
 */
#define RX_PIN             4
#define TX_PIN             2

/***
 * Global Variables
 */
SoftwareSerial blueToothReceiver(RX_PIN, TX_PIN);
String input = "";

/***
 * Initialize HC-06 Module
 */
HC06::HC06() {
  blueToothReceiver.begin(9600);
}

/***
 * Convert input from a bluetooth device
 * and return it as a single character
 * 
 * Note: Right now, I have been using a
 * console window to test.
 */
char HC06::acceptBlueToothInput() {
  if(blueToothReceiver.available()) {
    while(blueToothReceiver.available()) {
      input += (char) blueToothReceiver.read();
    }
    return input.charAt(0);
  }
}

/***
 * Convert a character to a state
 */
state HC06::commandInterpreter(char command) {
  state nextState;
  switch(command) {
    case 'f':
      nextState = FORWARD_STATE;
      break;
    case 'b':
      nextState = BACKWARD_STATE;
      break;
    case 'l':
      nextState = SPIN_LEFT_STATE;
      break;
    case 'r':
      nextState = SPIN_RIGHT_STATE;
      break;
    default:
      nextState = STOP_STATE;
      break;
  }
  return nextState;
}
