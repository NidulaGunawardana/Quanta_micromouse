#include <webots/Robot.hpp>
#include <webots/Gyroscope.hpp>
#include <iostream>

#define TIME_STEP 64  // Define the time step for simulation

using namespace webots;
using namespace std;

int main(int argc, char **argv) {
  // Create a new robot instance
  Robot *robot = new Robot();

  // Get the Gyroscope sensor and enable it
  Gyroscope *gyro = robot->getDevice("gyro");
  gyro->enable(TIME_STEP);

  // Main loop: perform simulation steps and read the gyroscope values
  while (robot->step(TIME_STEP) != -1) {
    // Get the values from the gyroscope
    const double *gyroValues = gyro->getValues();

    // Display the gyroscope readings (angular velocity in x, y, z)
    cout << "Gyroscope X: " << gyroValues[0] << " rad/s" << endl;
    cout << "Gyroscope Y: " << gyroValues[1] << " rad/s" << endl;
    cout << "Gyroscope Z: " << gyroValues[2] << " rad/s" << endl;
  }

  // Clean up the robot instance
  delete robot;
  return 0;
}
