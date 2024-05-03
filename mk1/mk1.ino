
const int firingIndicator = 2;
const int mosfetGate = 3;
const int firingBuzzer = 4;
const int firingInput = 5;

//Timing (ms)
const int delayMosfetToggle = 100;
const int delayIndicatorToggle = 100;
const int firingCooldown = 1000;

void setup() {
  pinMode(firingIndicator, OUTPUT);
  pinMode(mosfetGate, OUTPUT);
  pinMode(firingBuzzer, OUTPUT);
  pinMode(firingInput, INPUT);

  digitalWrite(firingIndicator, LOW);
  digitalWrite(mosfetGate, LOW);
  digitalWrite(firingBuzzer, LOW);
}

void loop() {
  if (digitalRead(firingInput) == HIGH){
    Fire();
    delay(firingCooldown);
  }
}

void Fire(){
  digitalWrite(firingIndicator, HIGH);
  digitalWrite(mosfetGate, HIGH);
  digitalWrite(firingBuzzer, HIGH);
  delay(delayMosfetToggle);
  digitalWrite(mosfetGate, LOW);
  digitalWrite(firingBuzzer, LOW);
  delay(delayIndicatorToggle);
  digitalWrite(firingIndicator, LOW);

}