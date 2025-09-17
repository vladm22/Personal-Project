#include "filter.h"

// Fonction de filtrage passe-bas
double applyLowPassFilter(double raw_gyro, double const &filtered_gyro) {
	double alpha = 0.1;
	return alpha * raw_gyro + (1.0 - alpha) * filtered_gyro;
}
