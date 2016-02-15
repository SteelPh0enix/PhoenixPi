#ifndef ADV_IO_HPP
#define ADV_IO_HPP
#include <wiringPi.h>
#include <cmath>
#include <vector>
#include <cstdint>

class advIO {
public:
	static void pinsWrite(std::vector<uint8_t> &pins, uint32_t value);
	static uint32_t pinsRead(std::vector<uint8_t> &pins);
	static void pinsWrite(uint8_t* pins, uint8_t pinsnum, uint32_t value);
	static uint32_t pinsRead(uint8_t* pins, uint8_t pinsnum);
};
#endif