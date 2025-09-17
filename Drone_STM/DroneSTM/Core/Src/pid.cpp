#include "pid.h"
#include "utils.h"

double Compute_PID(PID &pid, double measure, double dt){
	double error = pid.setpoint - measure;
	double P = pid.Kp * error;
	pid.integral += error * dt;

	double I = pid.Ki * pid.integral;

    double D = pid.Kd * (error - pid.previous_error) / dt;
	pid.previous_error = error;

	return P + I + D;
}
