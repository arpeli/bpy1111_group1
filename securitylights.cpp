/* code for motion activated street lights*/
int pirPin = 2;    // Digital pin connected to PIR Sensor's OUT pin
int ledPin = 13;   // Digital pin connected to the LED

void setup() {
  pinMode(pirPin, INPUT);   // Set PIR sensor pin as an input
  pinMode(ledPin, OUTPUT);  // Set LED pin as an output
  Serial.begin(9600);       // Initialize serial communication for debugging
}

void loop() {
  int motionStatus = digitalRead(pirPin); // Read the state of the PIR sensor

  if (motionStatus == HIGH) {
    // Motion detected
    digitalWrite(ledPin, HIGH); // Turn the LED ON
    Serial.println("Motion detected! Light ON.");
    delay(5000); // Keep the light on for 5 seconds
  } else {
    // No motion detected
    digitalWrite(ledPin, LOW);  // Turn the LED OFF
  }
}
