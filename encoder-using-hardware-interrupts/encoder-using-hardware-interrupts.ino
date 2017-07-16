#define Serial SerialUSB // Needed for certain boards (e.g. Arduino Zero)

// Pin assignments
const uint8_t PIN_A = 8;
const uint8_t PIN_B = 9;

int32_t pos = 0; // Encoder Position

void setup() {
  // Setup serial
  Serial.begin(9600);
  
  // Set Pinmodes w/ internal pullup
  pinMode(PIN_A, INPUT_PULLUP);
  pinMode(PIN_B, INPUT_PULLUP);
  
  // Attach Interrupts
  attachInterrupt(digitalPinToInterrupt(8), pinA, RISING);
  attachInterrupt(digitalPinToInterrupt(9), pinB, RISING);
}

void loop() {
  // Print pos
  Serial.print("Position: ");
  Serial.println(pos);
  delay(100);
}

void pinA() {
  pos += !digitalRead(PIN_B); // Check if pin A is leading and increment position by 1
}

void pinB() {
  pos -= !digitalRead(PIN_A); // Check if pin B is leading and deduct position by 1
}

