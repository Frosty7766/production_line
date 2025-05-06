// Pin Definitions
const int irSensorPin = 3; // IR sensor to detect product
const int pumpPinEN = 10;
const int pumpPin2 = 9; // Water pump control (relay or transistor)
const int pumpPin1 = 8;
const int motorPin1 = 12;   // L293N Motor control input 1 (for valve)
const int motorPin2 = 11;   // L293N Motor control input 2 (for valve)
const int enablePin = 13;   // L293N Motor driver enable pin (optional for speed control)
const int flowMeterPin = 2; // Flow meter signal input

// Flowmeter Variables
volatile int flowCount = 0;
float flowRate = 0.0;
unsigned long lastFlowTime = 0;
unsigned long lastMillis = 0;
float volume = 0.0; // Volume dispensed in milliliters

// Calibration
const float targetVolume = 200.0;                // Target volume in ml
const float pulsePerLiter = 450.0;               // YF-S401 flowmeter pulses per liter
const float mlPerPulse = 1000.0 / pulsePerLiter; // ml per pulse

void setup()
{
    // Set up pins
    pinMode(irSensorPin, INPUT);
    pinMode(pumpPinEN, OUTPUT);
    pinMode(pumpPin1, OUTPUT);
    pinMode(pumpPin2, OUTPUT);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(enablePin, OUTPUT); // Optional: For speed control via PWM
    pinMode(flowMeterPin, INPUT);

    // Attach interrupt for flowmeter
    attachInterrupt(digitalPinToInterrupt(flowMeterPin), flowMeterISR, RISING);

    // Initialize the serial monitor
    Serial.begin(9600);
}

void loop()
{
    // Check for product presence
    if (digitalRead(irSensorPin) == HIGH)
    {
        // Product detected, open valve and start pump
        openValve();
        delay(100);
        startPump();

        // Reset the volume counter
        volume = 0.0;

        // Filling loop
        while (volume < targetVolume)
        {
            // Calculate the flow rate every second
            unsigned long currentMillis = millis();
            if (currentMillis - lastMillis >= 1000)
            {                         // Every second
                flowRate = flowCount; // Flow count per second
                flowCount = 0;        // Reset the count
                lastMillis = currentMillis;

                // Calculate the volume based on the flowmeter pulses
                volume += flowRate * mlPerPulse; // Each pulse corresponds to mlPerPulse milliliters

                Serial.print("Flow Rate: ");
                Serial.print(flowRate);
                Serial.print(" pulses/sec, Volume: ");
                Serial.print(volume);
                Serial.println(" ml");

                if (volume >= targetVolume)
                {
                    // Target volume reached, stop the pump and close the valve
                    stopPump();
                    delay(100);
                    closeValve();
                    break;
                }
            }
        }

        // Wait for the product to be removed
        while (digitalRead(irSensorPin) == HIGH)
        {
            delay(100); // Product is still present
        }

        // System is ready for the next product
        Serial.println("Waiting for next product...");
        delay(1000); // Wait for some time to avoid bouncing
    }
}

// Function to open the valve
void openValve()
{
    digitalWrite(motorPin1, HIGH); // Motor direction 1
    digitalWrite(motorPin2, LOW);  // Motor direction 2 (reverse)
    digitalWrite(enablePin, HIGH); // Enable motor driver (turn on)
    Serial.println("Valve Opened");
}

// Function to close the valve
void closeValve()
{
    digitalWrite(motorPin1, LOW);  // Motor direction 1
    digitalWrite(motorPin2, HIGH); // Motor direction 2 (reverse)
    digitalWrite(enablePin, HIGH); // Enable motor driver (turn on)
    Serial.println("Valve Closed");
}

// Function to start the water pump
void startPump()
{
    digitalWrite(pumpPin1, HIGH);  // Turn on pump
    digitalWrite(pumpPin2, LOW);   // Turn on pump
    digitalWrite(pumpPinEN, HIGH); // Turn on pump
    Serial.println("Pump Started");
}

// Function to stop the water pump
void stopPump()
{
    digitalWrite(pumpPin1, LOW);  // Turn off pump
    digitalWrite(pumpPin2, LOW);  // Turn on pump
    digitalWrite(pumpPinEN, LOW); // Turn on pump
    Serial.println("Pump Stopped");
}

// Interrupt Service Routine for flowmeter
void flowMeterISR()
{
    flowCount++;
}