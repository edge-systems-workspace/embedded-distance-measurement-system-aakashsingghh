/**
* @file ultrasonic_sensor.ino
 * @brief Ultrasonic distance measurement using HC-SR04.
 *
 * @details
 * Measures distance using trigger and echo pins.
 * Distance formula:
 *      distance = (duration × speed_of_sound) / 2
 *
 * Speed of sound ≈ 0.034 cm/µs
 * Division by 2 because sound travels to object and back.
 *
 * Prints distance in centimeters every 1 second.
 *
 * @author Akash Singh
 * @date 2026
 */

#include <Arduino.h>

/// @brief Trigger pin connected to HC-SR04
#define trigPin 9

/// @brief Echo pin connected to HC-SR04
#define echoPin 10

/**
 * @brief Setup function
 * Initializes serial communication and pin modes.
 */
void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

/**
 * @brief Main loop
 * Sends ultrasonic pulse and calculates distance.
 */
void loop() {

    /// Ensure trigger is LOW initially
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    /// Send 10µs HIGH pulse to trigger ultrasonic burst
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    /// Measure time for echo to return (in microseconds)
    long duration = pulseIn(echoPin, HIGH);

    /**
     * Distance calculation:
     * duration × 0.034 (cm/µs) gives total travel distance
     * Divide by 2 for one-way distance
     */
    long distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(1000);
}