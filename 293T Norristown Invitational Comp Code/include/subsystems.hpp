#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

//clamp
inline pros::adi::Pneumatics clamp('A', false);

//doinkers
inline pros::adi::Pneumatics leftDoinker('B', false);
inline pros::adi::Pneumatics rightDoinker('C', false);
