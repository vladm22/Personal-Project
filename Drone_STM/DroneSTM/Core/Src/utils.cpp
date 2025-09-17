#include "utils.h"

MovingAverage::MovingAverage(uint32_t windowSize) :
	_windowSize(windowSize), _sum(0), _count(0), _index(0){
	for(int i{0}; i < AVERAGE_SIZE; ++i){
		_data[i] = 1500;
	}
}

MovingAverage::~MovingAverage(){

}

void MovingAverage::addValue(uint32_t value) volatile{
	if(_count < _windowSize){
		_sum += value;
		_count++;
	}
	else{
		_sum = _sum - _data[_index] + value;
	}

	_data[_index] = value;
	_index = (_index + 1) % _windowSize;
}

uint32_t MovingAverage::getAverage() const volatile{
	if(_count == 0){
		return 0;
	}
	return _sum / _count;
}

uint32_t map(uint32_t const &x, uint32_t const &in_min, uint32_t const &in_max, uint32_t const &out_min, uint32_t const &out_max){
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

double map(uint32_t const &x, double const &in_min, double const &in_max, double const &out_min, double const &out_max){
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint32_t Constrain(uint32_t min, uint32_t max, uint32_t value){
	if(value > max){
		return max;
	}
	else if(value < min){
		return min;
	}
	return value;
}

double Constrain(double min, double max, double value){
	if(value > max){
		return max;
	}
	else if(value < min){
		return min;
	}
	return value;
}

void BlinkLed(int seconds){
	for(int i{0}; i < seconds; ++i){
		HAL_GPIO_TogglePin(LED_13_GPIO_Port, LED_13_Pin);
		HAL_Delay(seconds);
	}
}
