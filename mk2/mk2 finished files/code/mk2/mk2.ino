
const int firingIndicator = 4;
const int mosfetGate = 3;
const int firingInput = 5;

//Timing (ms)
const int delayMosfetToggle = 13;
const int delayIndicatorToggle = 100;
const int firingCooldown = 2000;

bool canFire = false;

void setup() {
  pinMode(firingIndicator, OUTPUT);
  pinMode(mosfetGate, OUTPUT);
  pinMode(firingInput, INPUT_PULLUP);

  digitalWrite(firingIndicator, LOW);
  digitalWrite(mosfetGate, LOW);

  digitalWrite(firingIndicator, HIGH);
  delay(500);
  digitalWrite(firingIndicator, LOW);
  canFire = true;
}

void loop() {
  if (digitalRead(firingInput) == LOW && canFire){
    canFire = false;
    Fire();
    delay(firingCooldown);
    canFire = true;
  }
}

void Fire(){
  digitalWrite(firingIndicator, HIGH);
  digitalWrite(mosfetGate, HIGH);
  delay(delayMosfetToggle);
  digitalWrite(mosfetGate, LOW);
  delay(delayIndicatorToggle);
  digitalWrite(firingIndicator, LOW);

}
