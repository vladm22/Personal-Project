#ifndef INC_UTILS_H_
#define INC_UTILS_H_

#include "main.h"
#include <vector>

#define AVERAGE_SIZE 30

class MovingAverage{
public:
	MovingAverage(uint32_t windowSize);
	~MovingAverage();

	void addValue(uint32_t value) volatile;
	uint32_t getAverage() const volatile;
private:
	volatile uint32_t _windowSize;
	volatile uint32_t _sum;
	volatile uint32_t _count;
	volatile uint32_t _index;
	volatile uint32_t _data[AVERAGE_SIZE];
};

uint32_t map(uint32_t const &x, uint32_t const &in_min, uint32_t const &in_max, uint32_t const &out_min, uint32_t const &out_max);
double map(uint32_t const &x, double const &in_min, double const &in_max, double const &out_min, double const &out_max);

uint32_t Constrain(uint32_t min, uint32_t max, uint32_t value);
double Constrain(double min, double max, double value);
void BlinkLed(int seconds);


#endif /* INC_UTILS_H_ */
