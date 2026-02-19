#include <Arduino.h>
/**
 * @file main.cpp
 * @brief Embedded RGB LED Control (Digital + PWM)
 * @author Mayank
 * @date 2026-01-22
 *
 * @details
 * Controls RGB LED using digital ON/OFF
 * and analog PWM brightness control.
 */

// Define RGB pins (PWM-capable pins on typical Arduino Uno)
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

void setup() {

    // Initialize Serial communication (9600 baud)
    Serial.begin(9600); // TODO 4

    // Configure RGB pins as OUTPUT
    pinMode(RED_PIN, OUTPUT);   // TODO 5
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    // Print initialization message
    Serial.println("RGB PWM control initialized."); // TODO 6
}

void loop() {

    // -------- DIGITAL MODE --------

    // Turn ON red (digital HIGH)
    digitalWrite(RED_PIN, HIGH); // TODO 7
    Serial.println("Digital: RED ON");
    delay(500);

    // Turn OFF red
    digitalWrite(RED_PIN, LOW); // TODO 8
    Serial.println("Digital: RED OFF");
    delay(500);

    // -------- ANALOG (PWM) MODE --------

    // Fade RGB using PWM to demonstrate analog brightness control
    // This will smoothly transition colors by varying duty cycle
    for (int brightness = 0; brightness <= 255; brightness += 5) {
        // Set RED brightness using analogWrite()
        analogWrite(RED_PIN, brightness);
        // Set GREEN brightness using analogWrite()
        analogWrite(GREEN_PIN, 255 - brightness);
        // Set BLUE brightness using analogWrite()
        analogWrite(BLUE_PIN, (brightness / 2));

        // Add delay for visible transition
        delay(20);
    }

    // Reverse fade back to start for a smooth loop
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
        analogWrite(RED_PIN, brightness);
        analogWrite(GREEN_PIN, 255 - brightness);
        analogWrite(BLUE_PIN, (brightness / 2));
        delay(20);
    }
}
