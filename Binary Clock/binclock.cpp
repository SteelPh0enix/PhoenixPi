#include <unistd.h>
#include <cstdint>
#include <wiringPi.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <ctime>
#include "adv_io.hpp"

int main()
{
	//init GPIO (example pins)
	std::vector<uint8_t> pins[3] = {
		{ 18, 15, 14, 13, 3, 2 }, //hours
		{ 8, 25, 24, 23, 22, 27 }, //mins
		{ 12, 6, 5, 7, 11, 9 } //secs
	};
	wiringPiSetupGpio();
	
	//init time/time struct
	boost::posix_time::ptime now;
	tm actTime;
	
	//main loop
	while(true)
	{
		now = boost::posix_time::second_clock::local_time(); //get actual time
		actTime = boost::posix_time::to_tm(now); //convert to tm
		
		advIO::pinsWrite(pins[0], static_cast<uint32_t>(actTime.tm_hour));
		advIO::pinsWrite(pins[1], static_cast<uint32_t>(actTime.tm_min));
		advIO::pinsWrite(pins[2], static_cast<uint32_t>(actTime.tm_sec));
		
		sleep(1);
	}
	return 0;
}