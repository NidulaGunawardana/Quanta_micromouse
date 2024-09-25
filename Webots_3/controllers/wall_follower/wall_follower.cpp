// File:          wall_follower.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Motor.hpp>
#include <iostream>

#define TIME_STEP 64
#define MAX_SPEED 6.28

// All the webots classes are defined in the "webots" namespace
using namespace webots;
using namespace std;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();
  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  //  Motor *motor = robot->getMotor("motorname");
  //  DistanceSensor *ds = robot->getDistanceSensor("dsname");
  //  ds->enable(timeStep);
   Motor *left_motor = robot->getMotor("left wheel motor");
   Motor *right_motor = robot->getMotor("right wheel motor");
   
   left_motor->setPosition(INFINITY);
   right_motor->setPosition(INFINITY);
   
   left_motor->setVelocity(0.0);
   right_motor->setVelocity(0.0);
   
   DistanceSensor *ps[8];
   
   for (int i = 0; i < 8; i++) {
      std::string ps_name = "ps" + std::to_string(i);
      ps[i] = robot->getDistanceSensor(ps_name);
      ps[i]->enable(TIME_STEP);
}
    const float left_distance = ps[6];
    const float right_distance = ps[1];
    
   double left_speed = 0;
   double right_speed = 0;
   
   float Kp = 1;
   float Kd = 0.1;
   
   float prev_error = 0;
   
  Gyroscope *gyro = robot->getGyroscope("gyro");
  gyro->enable(TIME_STEP);
       
  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(TIME_STEP) != -1) {
    // Read the sensors:
    // Enter here functions to read sensor data, like:
    //  double val = ds->getValue();
    // bool left_wall = (ps[6]->getValue() > 90) && (ps[7]->getValue() > 90);
    // bool left_wall = ps[5]->getValue() > 90
    // bool front_wall = (ps[7]->getValue() > 90)
    // bool right_wall = (ps[0]->getValue() > 90) && (ps[1]->getValue() > 90);
    
    // bool front_wall = (ps[7]->getValue() > 90) && (ps[0]->getValue() > 90);
    const double *gyroValues = gyro->getValues();
    cout << "Gyroscope Z: " << gyroValues[2] << " rad/s" << endl;
    // Process sensor data here.
    
    if (front_wall == true){
      left_speed = MAX_SPEED;
      right_speed = -MAX_SPEED;
    }
    else{
      if (left_wall == true){
        left_speed = MAX_SPEED;
        right_speed = MAX_SPEED;
      }
      else{
        left_speed = MAX_SPEED/8;
        right_speed = MAX_SPEED;
      }
    }
    
    left_motor->setVelocity(left_speed);
    right_motor->setVelocity(right_speed);
    // Enter here functions to send actuator commands, like:
    //  motor->setPosition(10.0);
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
