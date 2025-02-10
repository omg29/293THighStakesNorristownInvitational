#include "lb.hpp"
#include "main.h"


//lb
pros::Motor lb(-20);
pros::Rotation rotationSensor(9);

const int numStates = 3;
int states[numStates] = {0, 39, 140};
int currState = 0;
int target = 0;

void nextState() {
    currState += 1;
    if (currState == numStates) {
        currState = 0;
    }
    target = states[currState];
}

void liftControl() {
    double kp = 1.4;
    double error = target - (rotationSensor.get_position()/100);
    double velocity = kp * error;
    lb.move(velocity);
}

void lbAsyncControl(void * param){
    while(true){
      liftControl();
      pros::delay(10);
    }
}