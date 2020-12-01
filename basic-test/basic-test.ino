
#define NEN_PIN          7 // !Enable
#define STEP_PIN         8 // Step
#define DIR_PIN          9 // Direction

bool rotDir = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(NEN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(NEN_PIN, LOW);      // Enable driver in hardware
  digitalWrite(DIR_PIN, rotDir);      // Enable driver in hardware
}


void loop() {
  // put your main code here, to run repeatedly:
  // Run 100 steps and switch direction in software
  for (uint16_t i = 800; i>0; i--) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(2000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(2000);
  }
  rotDir = !rotDir;
  digitalWrite(DIR_PIN, rotDir);
  digitalWrite(LED_BUILTIN, rotDir);
}
