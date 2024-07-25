
const int firingIndicator = 4;
const int mosfetGate = 3;
const int firingInput = 2;

//Timing (ms)
const int delayMosfetToggle = 10;
const int delayIndicatorToggle = 100;
const int firingCooldown = 2000;

bool canFire = false;

void setup() {
  pinMode(firingIndicator, OUTPUT);
  pinMode(mosfetGate, OUTPUT);
  pinMode(firingInput, INPUT);

  digitalWrite(firingIndicator, LOW);
  digitalWrite(mosfetGate, LOW);

  digitalWrite(firingIndicator, HIGH);
  delay(500);
  digitalWrite(firingIndicator, LOW);
  canFire = true;
}

void loop() {
  if (digitalRead(firingInput) == HIGH && canFire){
    Fire();
    canFire = false;
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
