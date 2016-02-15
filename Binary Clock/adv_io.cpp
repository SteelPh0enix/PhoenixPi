#include "adv_io.hpp"

//vector-based
void advIO::pinsWrite(std::vector<uint8_t> &pins, uint32_t value) {
	for (std::size_t i = 0; i < pins.size(); i++)
		digitalWrite(pins[i], value & static_cast<uint32_t>(pow(2, i)));
}

uint32_t advIO::pinsRead(std::vector<uint8_t> &pins) {
	uint32_t buf = 0;
	for (std::size_t i = 0; i < pins.size(); i++)
		buf += digitalRead(pins[i]) * static_cast<uint32_t>(pow(2, i));
	return buf;
}

//array-based
void advIO::pinsWrite(uint8_t* pins, uint8_t pinsnum, uint32_t value) {
	for (uint8_t i = 0; i < pinsnum; i++)
		digitalWrite(pins[i], value & static_cast<uint32_t>(pow(2, i)));
}

uint32_t advIO::pinsRead(uint8_t* pins, uint8_t pinsnum) {
	uint32_t buf = 0;
	for (uint8_t i = 0; i < pinsnum; i++)
		buf += digitalRead(pins[i]) * static_cast<uint32_t>(pow(2, i));
	return buf;
}