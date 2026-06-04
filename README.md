# Traffic Light & Pedestrian Crossing System 🚦

An Arduino-based traffic control system that simulates a real-world traffic light with pedestrian crossing functionality. The system ensures safe pedestrian movement by synchronizing crossing requests with the vehicle traffic cycle and providing visual and audio alerts.

##  Overview
The traffic lights follow a standard **Red → Yellow → Green** sequence for vehicles. When a pedestrian pushes the crossing button, the system waits until the vehicle light turns red, activates the pedestrian green light accompanied by a countdown and a buzzer, and then safely resumes the normal traffic cycle.

A 7-segment display provides a crossing countdown, while a buzzer and pedestrian signals guide users during the crossing period.

## Key Features
* **Automated Traffic Cycle:** Vehicle lights cycle seamlessly through Red, Yellow, and Green.
* **On-Demand Pedestrian Crossing:** A push-button safely triggers the crossing sequence without abruptly interrupting the vehicle cycle.
* **Visual & Audio Indicators:** * The pedestrian green light blinks during the last 3 seconds of the crossing window.
    * A buzzer sounds at the start and the end of the pedestrian crossing phase to aid visually impaired pedestrians.
* **Countdown Timer:** A 7-segment display shows the remaining time for pedestrians to cross safely.

## Components Used

* Arduino Uno
* Breadboard & Jumper Wires
* 5x LEDs (2 Red, 1 Yellow, 2 Green)
* 1x 7-Segment Display
* 1x Push Button
* 1x Piezo Buzzer
* Resistors

## Working

1. Vehicle traffic lights continuously cycle through Red, Yellow, and Green.
2. A pedestrian can request a crossing using the push button.
3. The system waits until the vehicle signal turns red before activating the pedestrian phase.
4. The countdown timer displays the remaining crossing time.
5. During the final 3 seconds, the pedestrian green signal blinks as a warning.
6. Once the crossing phase ends, normal traffic operation resumes.

##  Challenges Overcome
* **Timing & Sequencing:** Ensuring the pedestrian phase aligns exactly with the vehicle Red light without causing disruptive delays or skipping states in the main cycle.
* **Component Synchronization:** Synchronizing the blinking LED effect with the buzzer and the 7-segment countdown during the final 3 seconds required precise `delay()` management and logic structuring.

## Technologies Used

* Arduino IDE
* Embedded C
* TinkerCAD

## Circuit Diagram

![Circuit Diagram](https://github.com/user-attachments/assets/43ef173a-315f-4173-be63-aa8270aee9e2)

## Simulation

[TinkerCAD: Traffic Light & Pedestrian Crossing System](https://www.tinkercad.com/things/8LeFOERb2vr-tremendous-hillargaaris/editel?sharecode=unEpk_knD3gUx9Gwqjeru2khIioJmQgETXTaiUh1PoE)

## Author

**Akanksha**
B.Tech, Electronics and Communication Engineering
Indian Institute of Technology Guwahati

