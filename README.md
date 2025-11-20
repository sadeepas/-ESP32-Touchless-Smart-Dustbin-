# -ESP32-Touchless-Smart-Dustbin-
This project converts a standard trash can into a **Touchless Smart Dustbin** using an ESP32 microcontroller. It utilizes an HC-SR04 ultrasonic sensor to detect proximity and a servo motor to automatically open the lid, providing a hygienic, hands-free experience.


# ESP32 Touchless Smart Dustbin 🗑️✨

## Description
This project converts a standard trash can into a **Touchless Smart Dustbin** using an ESP32 microcontroller. It utilizes an HC-SR04 ultrasonic sensor to detect proximity and a servo motor to automatically open the lid, providing a hygienic, hands-free experience.

When an object (like a hand or trash) is detected within **20 cm**, the servo opens the lid. The lid remains open for **5 seconds** before closing automatically. An onboard LED provides visual feedback during the activation state.

## Features
*   **Touchless Operation:** Opens automatically when motion is detected.
*   **Auto-Close:** Automatically closes after a set delay (default 5 seconds).
*   **Status Indicator:** Onboard LED lights up when the lid is open.
*   **Range Safety:** Includes timeout logic to prevent false readings from far distances.
*   **ESP32 Optimized:** Uses hardware timers via the `ESP32Servo` library for smooth motor movement.

## Hardware Requirements
*   **Microcontroller:** ESP32 Development Board (e.g., ESP32 DOIT DEVKIT V1)
*   **Sensor:** HC-SR04 Ultrasonic Distance Sensor
*   **Actuator:** Servo Motor (SG90 for small bins, MG995 for larger/heavier lids)
*   **Power Supply:** 5V (USB or External Battery)
*   **Jumper Wires & Breadboard**

## Pin Configuration

| Component | Pin Name | ESP32 GPIO Pin |
|-----------|----------|----------------|
| **HC-SR04** | TRIG | GPIO 5 |
| **HC-SR04** | ECHO | GPIO 18 |
| **HC-SR04** | VCC | 5V / VIN |
| **HC-SR04** | GND | GND |
| **Servo** | Signal (Orange/Yellow) | GPIO 15 |
| **Servo** | VCC (Red) | 5V / VIN |
| **Servo** | GND (Brown/Black) | GND |
| **LED** | Built-in LED | GPIO 2 |

> **Note:** If you are using a heavy servo (like MG995), it is recommended to power the servo from an external 5V power source, sharing the ground with the ESP32, rather than drawing power directly from the ESP32 5V pin.

## Dependencies & Libraries
This project requires the **ESP32Servo** library to function correctly on the ESP32 architecture.

1.  Open Arduino IDE.
2.  Go to **Sketch** -> **Include Library** -> **Manage Libraries...**
3.  Search for **ESP32Servo**.
4.  Install the version by *Kevin Harrington*.

## Installation & Usage
1.  **Connect the Hardware** according to the Pin Configuration table above.
2.  **Open the Code** in the Arduino IDE.
3.  **Select your Board:** Go to Tools -> Board -> ESP32 Arduino -> DOIT ESP32 DEVKIT V1 (or your specific board).
4.  **Select Port:** Choose the COM port your ESP32 is connected to.
5.  **Upload** the sketch.
6.  **Open Serial Monitor** (Baud rate: 115200) to view the distance readings for debugging.

## Configuration
You can easily tweak the behavior by changing the definitions at the top of the `.ino` file:

*   **Detection Range:** Modify `if (dist > 0 && dist < 20)` to change how close you need to be to trigger the lid.
*   **Open Time:** Modify `delay(5000);` to change how long the lid stays open.
*   **Servo Angles:** Change `myServo.write(90)` (Open) or `myServo.write(0)` (Closed) to calibrate the lid angle.

## License
This project is open-source and free to use.
