const int greenLedPin = 10;  //assigning pins to comp.
const int yellowLedPin = 13;
 const int redLedPin = 7;
 const int echoPin = 4;
 const int trigPin = 9;
 long duration;
 int distance;

void setup() {  //assigning in/ou
  pinMode(greenLedPin, OUTPUT);
pinMode(yellowLedPin, OUTPUT);
pinMode(redLedPin, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
 Serial.begin(9600); //data transfer
}

void loop() {
  digitalWrite(trigPin, LOW); //this part triggers the trigger over and over.
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

 duration = pulseIn(echoPin, HIGH); //pulse of echo 

  distance = duration * 0.0343 / 2; //formula for distance

  if(distance > 20) { //lamps turn on and off 
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);

  }
  else if(distance >= 10 && distance <= 20) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW); 

}
else if(distance < 20){
  digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);

}
else if(distance > 0,01) {
  digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, HIGH);
}
delay(500); //delays the loop so its smoother
}