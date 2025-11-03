/*
Code for the Automatic Gate System and Parking notifier.
Written by GROUP 1 for BPY 1111: PHYSICS FOR COMPUTING SYSTEMS
*/

#include <Servo.h>

Servo gateServo;

// Ultrasonic pins
const int trigEntry = 2;
const int echoEntry = 3;
const int trigSlot1 = 4;
const int echoSlot1 = 5;
const int trigSlot2 = 6;
const int echoSlot2 = 7;

// LEDs
const int led1Green = 8;
const int led1Red = 9;
const int led2Green = 10;
const int led2Red = 11;

long duration;
int distance;

bool slot1Occupied = false;
bool slot2Occupied = false;

void setup() {
    Serial.begin(9600);
    gateServo.attach(12);
    gateServo.write(0); // gate closed

    pinMode(trigEntry, OUTPUT);
    pinMode(echoEntry, INPUT);
    pinMode(trigSlot1, OUTPUT);
    pinMode(echoSlot1, INPUT);
    pinMode(trigSlot2, OUTPUT);
    pinMode(echoSlot2, INPUT);

    pinMode(led1Green, OUTPUT);
    pinMode(led1Red, OUTPUT);
    pinMode(led2Green, OUTPUT);
    pinMode(led2Red, OUTPUT);

    digitalWrite(led1Green, HIGH);
    digitalWrite(led2Green, HIGH);
}

int getDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    return distance;
}

void loop() {
    int entryDist = getDistance(trigEntry, echoEntry);
    int slot1Dist = getDistance(trigSlot1, echoSlot1);
    int slot2Dist = getDistance(trigSlot2, echoSlot2);

    // Detect entry
    if (entryDist < 10) { // Car near gate
        gateServo.write(90); // open gate
        delay(2000);
    }
    else {
        gateServo.write(0); // close gate
    }

    // Slot 1 detection
    if (slot1Dist < 10) {
        slot1Occupied = true;
    }
    else {
        slot1Occupied = false;
    }

    // Slot 2 detection
    if (slot2Dist < 10) {
        slot2Occupied = true;
    }
    else {
        slot2Occupied = false;
    }

    // Update LEDs
    digitalWrite(led1Green, !slot1Occupied);
    digitalWrite(led1Red, slot1Occupied);
    digitalWrite(led2Green, !slot2Occupied);
    digitalWrite(led2Red, slot2Occupied);

    Serial.print("EntryDist: ");
    Serial.print(entryDist);
    Serial.print(" | Slot1: ");
    Serial.print(slot1Dist);
    Serial.print(" | Slot2: ");
    Serial.println(slot2Dist);

    delay(500);
}
