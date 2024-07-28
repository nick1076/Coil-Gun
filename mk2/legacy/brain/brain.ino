
const int buzzerPin = 2;
const int blueLEDpin = 3;
const int redLEDpin = 4;
const int mosfetPin = 5;
const int fireInput = 6;

bool canFire = false;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(blueLEDpin, OUTPUT);
  pinMode(redLEDpin, OUTPUT);
  pinMode(mosfetPin, OUTPUT);
  pinMode(fireInput, INPUT_PULLUP);
  digitalWrite(blueLEDpin, LOW);
  digitalWrite(mosfetPin, LOW);
  beep(2, 1800, 65);
  beep(1, 2000, 65);
  digitalWrite(blueLEDpin, HIGH);
  canFire = true;
}

void loop() {
  if (digitalRead(fireInput) == LOW){
    fire();
  }
}

void beep(int amount, int freq, int del){
  for (int i = 0; i < amount; i++){
    tone(buzzerPin, freq);
    digitalWrite(redLEDpin, HIGH);
    delay(del);
    digitalWrite(redLEDpin, LOW);
    noTone(buzzerPin);
    delay(del);
  }
}

void fire(){
  if (!canFire){
    return;
  }
  canFire = false;
  digitalWrite(blueLEDpin, LOW);
  digitalWrite(redLEDpin, HIGH);
  
  beep(3, 2000, 65);
  
  digitalWrite(blueLEDpin, LOW);
  digitalWrite(redLEDpin, LOW);
  
  digitalWrite(mosfetPin, HIGH);
  
  delay(50);
  
  digitalWrite(mosfetPin, LOW);

  delay(1000);
  canFire = true;
  digitalWrite(blueLEDpin, HIGH);
}
