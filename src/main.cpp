/**
* @file touch_sensor.ino
 * @brief Touch sensor LED control example.
 *
 * @details
 * Reads digital signal from touch sensor.
 * If touched → LED ON and message printed.
 * If not touched → LED OFF.
 *
 * Logic:
 * HIGH (1) -> Touched
 * LOW  (0) -> Not Touched
 *
 * @author Akash Singh
 * @date 2026
 */

#include <Arduino.h>

/// @brief Digital pin connected to touch sensor
#define touchPin 7

/// @brief Built-in LED pin
#define ledPin 13

/**
 * @brief Setup function
 * Initializes pin modes and serial communication.
 */
void setup() {
    pinMode(touchPin, INPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

/**
 * @brief Main loop
 * Continuously checks touch sensor state.
 */
void loop() {

    /// Read touch sensor state
    int state = digitalRead(touchPin);

    /**
     * HIGH -> Touch detected
     * LOW  -> No touch detected
     */
    if (state == HIGH) {
        digitalWrite(ledPin, HIGH);
        Serial.println("Touched!!");
    } else {
        digitalWrite(ledPin, LOW);
        Serial.println("Not Touched!!");
    }

    delay(200);  // Small delay for stable reading
}