#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <iostream>

#define TIME_STEP 64

using namespace webots;

int main(int argc, char **argv) {
  // Create the robot instance
  Robot *robot = new Robot();
  
  // Get the motors (left and right wheels)
  Motor *left_motor = robot->getMotor("left wheel motor");
  Motor *right_motor = robot->getMotor("right wheel motor");
  
  // Enable position feedback from the motors (encoders)
  left_motor->enablePosition(TIME_STEP);
  right_motor->enablePosition(TIME_STEP);
  
  // Set motor velocity to make the robot move
  left_motor->setVelocity(1.0);
  right_motor->setVelocity(1.0);
  
  while (robot->step(TIME_STEP) != -1) {
    // Get the encoder values (position of the left and right motors)
    double left_encoder_value = left_motor->getPosition();
    double right_encoder_value = right_motor->getPosition();
    
    // Display the encoder readings
    std::cout << "Left Encoder: " << left_encoder_value << " | Right Encoder: " << right_encoder_value << std::endl;
  }
  
  // Clean up the robot
  delete robot;
  return 0;
}
