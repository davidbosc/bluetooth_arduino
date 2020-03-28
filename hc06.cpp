#include <Arduino.h>
#include "hc06.h"
#include "state.h"
#include <SoftwareSerial.h>

/***
 *  Pin configuration 
 */
#define RX_PIN             4
#define TX_PIN             2

/***
 * Global Variables
 */
SoftwareSerial blueToothReceiver(RX_PIN, TX_PIN);

/***
 * Initialize HC-06 Module
 */
HC06::HC06() {}

/***
 * Initialize HC-06 Module
 */
void HC06::init() {
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
  String input = "";
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
  switch(command) {
    case 'f':
      return state::FORWARD_STATE;
    case 'b':
      return state::BACKWARD_STATE;
    case 'l':
      return state::SPIN_LEFT_STATE;
    case 'r':
      return state::SPIN_RIGHT_STATE;
    default:
      return state::STOP_STATE;
  }
}
