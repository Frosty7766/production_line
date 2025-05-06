// Pin definitions for Motor 1
#define STEP_PIN1 2
#define DIR_PIN1 3

// Pin definitions for Motor 2
#define STEP_PIN2 4
#define DIR_PIN2 5

// IR sensor pins
#define IR_SENSOR1 6 // Start sensor
#define IR_SENSOR2 7 // Stop sensor

// Steps per revolution
const int stepsPerRevolution = 200;

// Delay between steps (smaller = faster)
int stepDelay = 1000; // Microseconds

void setup()
{
    // Motor pins
    pinMode(STEP_PIN1, OUTPUT);
    pinMode(DIR_PIN1, OUTPUT);
    pinMode(STEP_PIN2, OUTPUT);
    pinMode(DIR_PIN2, OUTPUT);

    // IR sensor pins
    pinMode(IR_SENSOR1, INPUT);
    pinMode(IR_SENSOR2, INPUT);

    // Set initial direction
    digitalWrite(DIR_PIN1, HIGH);
    digitalWrite(DIR_PIN2, HIGH);
}

void loop()
{
    // Wait for product to arrive at start
    if (digitalRead(IR_SENSOR1) == LOW)
    { // Assuming LOW = object detected
        // Start moving motors
        while (digitalRead(IR_SENSOR2) == HIGH)
        { // While no product at end
            // Move both motors
            digitalWrite(STEP_PIN1, HIGH);
            digitalWrite(STEP_PIN2, HIGH);
            delayMicroseconds(stepDelay);
            digitalWrite(STEP_PIN1, LOW);
            digitalWrite(STEP_PIN2, LOW);
            delayMicroseconds(stepDelay);
        }
    }
}