# Project for BPY 1111: Physics for Computing Systems

## Group Members
- Ariel Boutcher -BSCCS/2025/40350
- Loise Wambui - BSCCS/2025/40219
- Grace Wanjiru -BSCCS/2025/39629
- Fridah Harawo -BSCCS/2025/35619
- Rose Mateta - BSCCS/2025/39761
- Finley Motari - BSCCS/2025/39262
- Joshua Samuel - BSCCS/2025/40065
- Benie Macharia - BSCCS/2025/39532
- Derrick Mburu - BSCCS/2025/40404
- Brillian Andalo - BSCCS/2025/41447

## Automated 2-Slot Parking System (Arduino + Tinkercad Simulation)

### Overview
This project simulates an **automated 2-slot parking system** using an **Arduino UNO** in **Tinkercad Circuits**.  
It demonstrates how parking systems can automatically detect vehicles, control a gate barrier, and indicate parking availability using simple electronic components.

The system uses **ultrasonic sensors** to detect approaching cars and monitor slot occupancy. A **servo motor** acts as a gate, while **LED indicators** show whether parking slots are free or occupied.

---

### Components Used
| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino UNO R3 | 1 | Main microcontroller |
| Ultrasonic Sensor (HC-SR04) | 3 | 1 for gate entry detection, 2 for parking slots |
| Servo Motor | 1 | Controls gate movement |
| LED (Green) | 2 | Indicates available slots |
| LED (Red) | 2 | Indicates occupied slots |
| 220Ω Resistors | 4 | Protect LEDs from excess current |
| Breadboard | 1 | For component connections |
| Jumper Wires | — | To make electrical connections |

---

### System Working Principle
1. **Vehicle Detection at Entry:**  
   When a car approaches the gate, the **entry ultrasonic sensor** measures a small distance (e.g., under 10 cm).  
   The system interprets this as a vehicle arrival and **opens the servo gate** automatically.

2. **Gate Control:**  
   The **servo motor** is programmed to rotate (usually 90°) to simulate a barrier lifting.  
   After a short delay, or when no vehicle is detected, the servo returns to its **original closed position (0°)**.

3. **Slot Monitoring:**  
   Each parking slot has its own **ultrasonic sensor** that continuously measures distance.  
   - If a car is parked (distance < threshold), the slot is marked **occupied**.  
   - If the car leaves (distance > threshold), the slot is marked **available**.

4. **LED Indication:**  
   Each slot has two LEDs:  
   - **Green LED ON** → Slot is free.  
   - **Red LED ON** → Slot is occupied.  
   When a slot becomes occupied, the program turns off the green LED and turns on the red one.

5. **Status Feedback:**  
   The Arduino continuously prints real-time sensor distances and slot statuses to the **Serial Monitor**, which helps verify system operation and debugging.

---

### Code Explanation

The Arduino sketch is divided into the following key sections:

#### 1. **Library Import & Variable Setup**
- The **Servo library** is included to control the servo motor easily.
- Variables are declared for all pin connections (trig, echo, LEDs, and servo).
- Boolean flags (`slot1Occupied`, `slot2Occupied`) track whether each slot is occupied.

#### 2. **Setup Function**
- Initializes the serial monitor for debugging.
- Attaches the servo motor to its control pin and sets the gate to a **closed position** initially.
- Defines all sensor pins as `INPUT` or `OUTPUT`.
- Sets LED pins as `OUTPUT` and turns both green LEDs on (since both slots are free at startup).

#### 3. **Distance Measurement Function**
- A helper function (`getDistance()`) is used to trigger the ultrasonic sensor and measure the **time for an echo pulse**.
- This time is converted into **distance in centimeters** using the formula:  
  `distance = (duration × 0.034) / 2`
- This function is called for each sensor in every loop cycle.

#### 4. **Main Loop**
- The loop continuously checks distances from:
  - The **entry sensor** (to control the gate).
  - **Slot sensors** (to monitor parking status).
- **Entry Logic:**  
  If the entry sensor detects a vehicle closer than 10 cm, the servo gate opens; otherwise, it remains closed.
- **Slot Logic:**  
  Each slot’s distance is compared to a threshold (e.g., 10 cm). If below it, the slot is marked occupied.
- **LED Update:**  
  The LEDs are updated based on the occupancy state:
  - Green ON and Red OFF = Free  
  - Red ON and Green OFF = Occupied
- **Serial Monitoring:**  
  Distances and slot states are printed to the serial monitor for testing.

#### 5. **Delays and Timing**
- A short delay (e.g., 500 ms) between sensor checks ensures stability and prevents false readings.
- A delay after opening the gate ensures it stays open long enough for a vehicle to pass.

---

### Circuit Connections

| Function | Arduino Pin | Component |
|-----------|--------------|------------|
| Entry Sensor Trig | 2 | HC-SR04 (Entry) |
| Entry Sensor Echo | 3 | HC-SR04 (Entry) |
| Slot 1 Sensor Trig | 4 | HC-SR04 (Slot 1) |
| Slot 1 Sensor Echo | 5 | HC-SR04 (Slot 1) |
| Slot 2 Sensor Trig | 6 | HC-SR04 (Slot 2) |
| Slot 2 Sensor Echo | 7 | HC-SR04 (Slot 2) |
| Slot 1 Green LED | 8 | LED (Green) |
| Slot 1 Red LED | 9 | LED (Red) |
| Slot 2 Green LED | 10 | LED (Green) |
| Slot 2 Red LED | 11 | LED (Red) |
| Servo Motor Signal | 12 | Servo Motor |

**Power:**
- All sensors and servo: **5V (VCC)**  
- All components share a **common GND**

---

### Simulation Instructions
1. Open [Tinkercad Circuits](https://www.tinkercad.com/circuits).  
2. Create a **New Circuit** and add the components listed above.  
3. Wire them according to the connection table.  
4. Paste the Arduino code into the editor.  
5. Start the simulation.  
6. Adjust the **object distance** for each ultrasonic sensor to simulate cars entering and leaving.

---

### Expected Behavior
| Scenario | Gate | Slot 1 LED | Slot 2 LED |
|-----------|------|-------------|-------------|
| No car | Closed | Green ON | Green ON |
| Car near entry | Opens | Green ON | Green ON |
| Car parked in Slot 1 | Closed | Red ON | Green ON |
| Car parked in Slot 2 | Closed | Green ON | Red ON |
| Both slots occupied | Closed | Red ON | Red ON |
| Car leaves slot | Closed | Green ON | (whichever is free) |

---

### Applications
- Smart parking systems  
- Garage automation demonstrations  
- IoT-based vehicle monitoring (with extensions)  
- Educational projects on sensors and automation

---

### Future Improvements
- Add an LCD display to show live slot status (e.g., “Slot 1: Occupied”).  
- Integrate RFID for secure access control.  
- Connect to IoT dashboards (Blynk, ThingSpeak) for real-time monitoring.  
- Add a buzzer alert when the gate opens or closes.  
- Implement a reservation system using cloud integration.

---


## Motion Activated Security Light Circuit (Tinkercad)

This project demonstrates how to create a basic motion-activated security light using an **Arduino Uno** and a **PIR Motion Sensor** in the Tinkercad Circuits simulator. The LED light will turn on when motion is detected and stay on for a set duration of 5 seconds.

-----

### 1\. Required Components

The following virtual components are needed from the Tinkercad Circuits library:

  * **1x Arduino Uno R3** (Microcontroller)
  * **1x Breadboard** (Small)
  * **1x PIR Motion Sensor** (Input)
  * **1x LED** (Output, any color)
  * **1x Resistor** ($220\Omega$) (Current Limiter for the LED)

-----

### 2\. Circuit Assembly Instructions

The circuit is built on the small breadboard and connected to the Arduino Uno.

#### Power Connections

| Arduino Pin | Breadboard Rail | Function |
| :--- | :--- | :--- |
| **5V** | Positive Rail (+) | Provides power to the breadboard. |
| **GND** | Negative Rail (-) | Provides ground reference. |

#### PIR Motion Sensor Connections

The PIR sensor has three pins: VCC (Power), OUT (Signal), and GND (Ground).

| PIR Pin | Connection Point | Function |
| :--- | :--- | :--- |
| **VCC** | Positive Rail (+) | Power supply. |
| **GND** | Negative Rail (-) | Ground connection. |
| **OUT** | **Arduino Digital Pin 2** | Sends the motion signal (HIGH or LOW) to the Arduino. |

#### LED and Resistor Connections

The resistor is essential and must be connected in **series** with the LED to prevent it from blowing out due to excessive current.

| Component Pin | Connection Point | Function |
| :--- | :--- | :--- |
| **LED Cathode** (Shorter Leg) | Negative Rail (-) | Connects the LED to ground. |
| **LED Anode** (Longer Leg) | One end of the Resistor | Connects the LED to the resistor. |
| **Resistor** (Other End) | **Arduino Digital Pin 13** | Receives the signal (power) from the Arduino. |

-----

### 3\. Arduino Code (C++)

Use the "Text" code editor in Tinkercad and upload the following code. This program checks the state of the PIR sensor and controls the LED accordingly.

```cpp
int pirPin = 2;    // Digital pin connected to PIR Sensor's OUT pin
int ledPin = 13;   // Digital pin connected to the LED

void setup() {
  pinMode(pirPin, INPUT);   // Configure the PIR pin to read data
  pinMode(ledPin, OUTPUT);  // Configure the LED pin to send data/power
  Serial.begin(9600);       // Initialize serial communication for monitoring
}

void loop() {
  int motionStatus = digitalRead(pirPin); // Read the state of Pin 2

  if (motionStatus == HIGH) {
    // Motion detected
    digitalWrite(ledPin, HIGH); // Turn the LED ON
    Serial.println("Motion detected! Light ON.");
    
    // IMPORTANT: This delay keeps the light on for 5 seconds.
    // The loop pauses here, then forces the LED OFF at the end of the block 
    // to ensure the light doesn't stay on indefinitely if motion persists.
    delay(5000); 
    digitalWrite(ledPin, LOW); // Force the LED OFF after the delay
  } 
  
  // Note: If the delay above is removed, the 'else' logic is often needed:
  /*
  else {
    // No motion detected, but the delay above handles turning it off 
    // even if motion stops instantly.
    digitalWrite(ledPin, LOW);  
  }
  */
}
```

-----

### 4\. Simulation and Testing

1.  Click the **"Start Simulation"** button.
2.  **Click on the PIR Motion Sensor** component. This displays the motion detection field.
3.  **Simulate Motion:** **Click and drag the small circle** that appears within the detection area.
4.  **Observation:**
      * The LED will immediately turn **ON**.
      * The **Serial Monitor** (open it during simulation) will print `"Motion detected! Light ON."`.
      * The LED will remain **ON** for **5 seconds** (due to the `delay(5000)` in the code), even if you immediately drag the circle out of the detection area.
      * After the delay, the LED will automatically turn **OFF**.

### Author
**Group 1 Members**  
Arduino and Embedded Systems Enthusiast  
Project simulated using [Tinkercad Circuits](https://www.tinkercad.com/circuits)

---

### License
This project is open-source under the **MIT License**.  
Feel free to modify and share with proper attribution.

