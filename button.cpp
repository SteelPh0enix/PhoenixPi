#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
#define bInPin 21
#define bOutPin 20

int main()
{
        wiringPiSetupGpio();
        pinMode(bInPin, INPUT);
        pinMode(bOutPin, OUTPUT);
        digitalWrite(bOutPin, true);
        std::cout << "ready" << std::endl;
        while(true)
        {
                if (digitalRead(bInPin)) { std::cout << "kek" << std::endl; sleep(1);}
        }
}