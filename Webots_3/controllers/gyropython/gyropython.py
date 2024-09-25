from controller import Robot

# Time step for the simulation (ms)
TIME_STEP = 64

# Create the Robot instance
robot = Robot()

# Get the Gyroscope sensor and enable it
gyro = robot.getDevice("gyro")  # Use the name of the Gyroscope node in Webots
gyro.enable(TIME_STEP)

# Main loop: perform simulation steps and read gyroscope values
while robot.step(TIME_STEP) != -1:
    # Get the gyroscope values (angular velocity in rad/s for X, Y, Z)
    gyro_values = gyro.getValues()

    # Extract the angular velocity around the x, y, and z axes
    angular_velocity_x = gyro_values[0]
    angular_velocity_y = gyro_values[1]
    angular_velocity_z = gyro_values[2]

    # Display the gyroscope readings
    print(f"Angular Velocity (rad/s) -> X: {angular_velocity_x:.3f}, Y: {angular_velocity_y:.3f}, Z: {angular_velocity_z:.3f}")

# Cleanup is done automatically when the program exits
