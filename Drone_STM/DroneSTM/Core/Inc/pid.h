#ifndef INC_PID_H_
#define INC_PID_H_

#include "main.h"

/*
 * 	Definition of the parameters of a PID
 */

typedef struct{
	double Kp;
	double Ki;
	double Kd;
	double setpoint;
	double integral;
	double previous_error;
}PID;

double Compute_PID(PID &pid, double measure, double dt);

#endif /* INC_PID_H_ */
