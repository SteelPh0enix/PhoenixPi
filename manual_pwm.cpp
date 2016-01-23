#include <iostream>
#include <unistd.h>
#include <wiringPi.h>
#define PWM_RANGE 1000
#define PWM_CLOCK 19.2 * PWM_RANGE / 50

//SERVO RANGE = 25 - 124 for 1000 range

int main()
{
	wiringPiSetupGpio();
	pinMode(18, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(PWM_RANGE);
	pwmSetClock(PWM_CLOCK); // pwmFrequency in Hz = 19.2e6 Hz / pwmClock / pwmRange
	
	int f;
	while(true)
	{
		//std::cin >> f;
		//pwmWrite(18, f);
		for(f = 25; f < 124; f++) { pwmWrite(18, f); usleep(10000); }
		for(f = 124; f > 25; f--) { pwmWrite(18, f); usleep(10000); }
	}
	return 0;
}