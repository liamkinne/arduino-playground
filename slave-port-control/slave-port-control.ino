#include <Wire.h>

enum type_t {DIGITAL, ANALOG};

const bool DEBUG = true;
const uint8_t ADDRESS = 0x08;

uint8_t pin;
type_t type;
uint8_t value;

void setup() {
  Wire.begin(ADDRESS);
  Wire.onReceive(receive);
  if (DEBUG) Serial.begin(9600);
  debug("Setup Complete");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9, HIGH);
}

void receive(int byteCount) {
  pin = Wire.read();
  type = type_t(Wire.read());
  value = Wire.read();

  pinMode(pin, OUTPUT);

  switch (type) {
    case type_t::DIGITAL: digitalWrite(9, value); debug("Digital Write"); break;
    case type_t::ANALOG: analogWrite(9, value); debug("Ananog Write"); break;
  }
}

void debug(String input) {
  if (DEBUG) Serial.println(input);
}

