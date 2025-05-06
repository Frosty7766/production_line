// Define stepper motor pins
#define IR_PIN 6
#define STEP_PIN 8
#define DIR_PIN 9

// Define air pump pin
#define PUMP_PIN 5

// Function to move a stepper motor
void moveStepper(int stepPin, int dirPin, int steps, bool direction)
{
    digitalWrite(dirPin, direction); // Set direction
    for (int i = 0; i < steps; i++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000); // Adjust speed by changing delay
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
    }
}

void setup()
{
    // Initialize stepper motor pins
    pinMode(STEP_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);

    // Initialize air pump pin
    pinMode(PUMP_PIN, OUTPUT);

    // IR
    pinMode(IR_PIN, INPUT);

    // Initialize the air pump to be off
    digitalWrite(PUMP_PIN, LOW);
}

void loop()
{
    // Read IR sensor states
    int ir1State = digitalRead(IR_PIN);
    if (ir1State == LOW)
    {
        moveStepper(STEP_PIN, DIR_PIN, 1000, false);
        delay(1000);
        digitalWrite(PUMP_PIN, HIGH);
        moveStepper(STEP_PIN, DIR_PIN, 1000, true);
        delay(10000);
        moveStepper(STEP_PIN, DIR_PIN, 1000, false);
        delay(1000);
        digitalWrite(PUMP_PIN, LOW);
    }
}