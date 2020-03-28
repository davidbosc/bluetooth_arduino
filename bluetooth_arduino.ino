#include "hc06.h"
#include "servoWheels.h"
#include "state.h"

state currentState = state::STOP_STATE;
HC06 bluetoothReceiver;
ServoWheels servos;

void setup() {
  Serial.begin(9600);
}

void loop() {
  char input = bluetoothReceiver.acceptBlueToothInput();
  currentState = static_cast<state>(bluetoothReceiver.commandInterpreter(input));
  servos.setServoState(currentState);
  delay(500);
}
