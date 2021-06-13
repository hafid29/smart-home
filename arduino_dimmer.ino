#include <RBDdimmer.h>

// ===============================
// Define your pin here
#define zcrossPin 2
#define dimmerOutput 7
// ===============================

String inData;

dimmerLamp dimmer(dimmerOutput);

void setup() {
  //Serial Begin at 9600 Baud 
  Serial.begin(115200);
  dimmer.begin(NORMAL_MODE,ON);
  dimmer.setState(OFF);
}

void loop() {
  if (Serial.available() > 0) {
    
    inData = Serial.readStringUntil('\n');
    Serial.println(inData);
    
    // Logika relay
    if (inData == "nyala") {
      dimmer.setState(ON);
    }
    if (inData == "mati") {
      dimmer.setState(OFF);
    }
    dimmingLamp(inData.toInt());
  }
}

void dimmingLamp(int value) {
  if (dimmer.getState() != OFF) {
    dimmer.setState(ON);
    dimmer.setPower(value);
  }
}
