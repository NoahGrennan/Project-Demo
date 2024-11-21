//Code by Noah Grennan
//This code is used for Arduino mega board and using a microphone can turn on and off and led to a noise or clap.  
int micPin = A0;          // pin that the mic is attached to
int gndPin = A1;  // pin that connects to ground for mic
int powerPin = A2; // power pin location for mic
int micValue1 = 0;  // mic value
int micValue2 = 0; // the Microphone value
int led1 = 13; // lead connected to analog 13 pin
boolean lightOn = false; // light starts turned off


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(powerPin, OUTPUT);
  pinMode(gndPin, OUTPUT);
  pinMode(micPin, INPUT);
  digitalWrite(gndPin,LOW);
  delay(500);
  digitalWrite(powerPin,HIGH);
  Serial.begin(9600);  //for test the input value initialize serial
}

void loop() {
  micValue1 = analogRead(micPin);  // read pin value
  Serial.println(micValue1);
  delay(1);
  micValue2 = analogRead(micPin);
  Serial.println(micValue2);
  
  if (micValue1-micValue2 > 2||micValue2-micValue1 > 2){
  lightOn = !lightOn;
  delay(100);
  digitalWrite(led1, lightOn);
  }
} 
