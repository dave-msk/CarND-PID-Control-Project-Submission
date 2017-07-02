#include "PID.h"
#include <math.h>

/*
* TODO: Complete the PID class.
*/

PID::PID() : p_error(0), i_error(0), d_error(0), t_error(0), num_updated(0){}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  i_error += cte;
  t_error += cte * cte;
  d_error = cte - p_error;
  p_error = cte;
  ++num_updated;
}

double PID::TotalError() {
  return sqrt(t_error/num_updated);
}

double PID::SteerAngle() {
  return -Kp*p_error - Ki*i_error - Kd*d_error;
}

