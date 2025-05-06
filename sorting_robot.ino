#include <Servo.h>

#define IR_PIN1 7
#define IR_PIN2 8

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup()
{
    servo1.attach(3);
    servo2.attach(5);
    servo3.attach(6);
    servo4.attach(9);
    servo5.attach(10);

    pinMode(IR_PIN1, INPUT);
    pinMode(IR_PIN2, INPUT);

    Serial.begin(9600);
}

void loop()
{
    // Read IR sensor states
    int ir1State = digitalRead(IR_PIN1);
    int ir2State = digitalRead(IR_PIN2);

    if (ir1State == LOW)
    {
        // Move the robot arm to a lower position
        servo1.write(30); // Example angles
        servo2.write(45);
        servo3.write(60);
        servo4.write(90);
        servo5.write(120);
        Serial.println("Moving to lower position");
    }
    else if (ir2State == LOW)
    {
        // Move the robot arm to an upper position
        servo1.write(120); // Example angles
        servo2.write(90);
        servo3.write(60);
        servo4.write(45);
        servo5.write(30);
        Serial.println("Moving to upper position");
    }
    else
    {
        // Move the robot arm to the original position
        servo1.write(90); // Default position
        servo2.write(90);
        servo3.write(90);
        servo4.write(90);
        servo5.write(90);
        Serial.println("Returning to original position");
    }

    delay(500); // Delay for stability
}