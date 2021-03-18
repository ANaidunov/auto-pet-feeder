#include <Servo.h>

const int servoPin = 13;
const int defaultInterval = 8;    // interval before next feeding (hours)
const int defaultFeedingTime = 3; // time of supply (seconds)

Servo Servo;

void setup()
{
    Servo.attach(servoPin);
    pinMode(servoPin, OUTPUT);

    StopFeeding();
}

void loop()
{
    Feed(defaultFeedingTime);

    int feedInterval = ConvertTimeToSeconds(timeInterval);
    delay(feedInterval);
}

void Feed(int feedingTime)
{
    delay(3000);
    StartFeeding();

    delay(feedingTime);
    StopFeeding();
}

void StartFeeding()
{
    Servo.write(0);
}

void StopFeeding()
{
    Servo.write(90);
}

int ConvertTimeToSeconds(int hours)
{
    return hours * 3600;
}