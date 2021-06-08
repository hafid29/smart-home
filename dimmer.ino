#define ZCROSS 13
#define PWAPIN 14

int input;

void setup() {
pinMode(ZCROSS, INPUT_PULLUP);
pinMode(PWAPIN, OUTPUT);
Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
        input = Serial.read();
//        analogWrite(ZCROSS,input);
        analogWrite(PWAPIN,input);
        Serial.print(input);
    }
}
