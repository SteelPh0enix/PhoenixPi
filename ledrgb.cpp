#include <iostream>
#include <cstdlib>
#include <ctime>
#include <wiringPi.h>
#include <unistd.h>

int main()
{
	wiringPiSetupGpio();
	int pins[3] = {18, 15, 14};
	bool pin_states[3] = {0, 0, 0};
	for (int i = 0; i < 3; i++) { pinMode(pins[i], OUTPUT); digitalWrite(pins[i], pin_states[i]); }
        srand(time(NULL));
	
	while (true) {
                digitalWrite(pins[rand()%3], rand()%2);
                sleep(1);
	}
	return 0;
}
