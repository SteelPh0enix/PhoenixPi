#include <iostream>
#include <wiringPi.h>
#include <unistd.h>

int main()
{
        wiringPiSetupGpio();
        pinMode(18, PWM_OUTPUT);
        int l;
        while(true)
{
        std::cin >> l;
        std::cout << "changing l to " << l << std::endl;
        pwmWrite(18, l);
}
}