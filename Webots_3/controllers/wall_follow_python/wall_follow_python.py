from controller import Robot

# Time step of the simulation in milliseconds
TIME_STEP = 64
WHEEL_RADIUS = 2.05
ROBOT_RADIUS = 2.9

# Create the Robot instance
robot = Robot()

# Get the motors (left and right wheels)
left_motor = robot.getDevice('left wheel motor')
right_motor = robot.getDevice('right wheel motor')

# Set motors to velocity control mode
left_motor.setPosition(float('inf'))
right_motor.setPosition(float('inf'))

# Set initial motor speeds
left_motor.setVelocity(1.0)
right_motor.setVelocity(1.0)

# Enable encoders
left_encoder = robot.getDevice('left wheel sensor')
right_encoder = robot.getDevice('right wheel sensor')
left_encoder.enable(TIME_STEP)
right_encoder.enable(TIME_STEP)

# Get the Gyroscope sensor and enable it
gyro = robot.getDevice("gyro")  # Use the name of the Gyroscope node in Webots
gyro.enable(TIME_STEP)

# Get the proximity sensors
ps = []

sensors = [
    robot.getDevice('ps0'),  # Front left
    robot.getDevice('ps1'),  # Front center
    # robot.getDevice('ps2'),  # Front right
    # robot.getDevice('ps3'),  # Right side
    # robot.getDevice('ps4'),  # Back right
    # robot.getDevice('ps5'),  # Back center
    robot.getDevice('ps6'),  # Back left
    robot.getDevice('ps7'),  # Left side
]

# Enable the proximity sensors
for sensor in sensors:
    sensor.enable(TIME_STEP)
    ps.append(sensor)
    
def get_distance():
   sensor_values = [sensor.getValue() for sensor in ps]
   print(sensor_values)

def moveDistance(target_distance):
     # Reset encoders
    INIT_LEFT_ENCODER = left_encoder.getValue()
    INIT_RIGHT_ENCODER = right_encoder.getValue()

    # Set motor speeds
    left_motor.setVelocity(2.0)  # m/s
    right_motor.setVelocity(2.0)  # m/s
    
    while robot.step(TIME_STEP) != -1:
        # Get the encoder values
        left_encoder_value = left_encoder.getValue() - INIT_LEFT_ENCODER
        right_encoder_value = right_encoder.getValue() - INIT_RIGHT_ENCODER
        
        # Calculate the distance traveled
        left_wheel_distance = WHEEL_RADIUS*left_encoder_value
        right_wheel_distance = WHEEL_RADIUS*right_encoder_value

        # Check if either wheel has traveled the target distance
        if abs(left_wheel_distance) >= target_distance or abs(right_wheel_distance) >= target_distance:
            break
            
        # print(f"Left Wheel Distance: {left_wheel_distance} | Right Wheel Distance: {right_wheel_distance}")

    # Stop the motors
    left_motor.setVelocity(0)
    right_motor.setVelocity(0)
    
def turnAngle(target_angle):
    # target_angle>0  turn clockwise
    # target_angle<0  turn anti-clockwise
     # Reset encoders
    INIT_LEFT_ENCODER = left_encoder.getValue()
    INIT_RIGHT_ENCODER = right_encoder.getValue()

    # Set motor speeds
    if (target_angle>0):
        left_motor.setVelocity(1.0)  # m/s
        right_motor.setVelocity(-1.0)  # m/s
    else:
        left_motor.setVelocity(-1.0)  # m/s
        right_motor.setVelocity(1.0)  # m/s
        
    
    while robot.step(TIME_STEP) != -1:
        # Get the encoder values
        left_encoder_value = left_encoder.getValue() - INIT_LEFT_ENCODER
        right_encoder_value = right_encoder.getValue() - INIT_RIGHT_ENCODER
        
        # Calculate the distance traveled
        left_wheel_travel_angle = (WHEEL_RADIUS*left_encoder_value)/ROBOT_RADIUS
        right_wheel_travel_angle = (WHEEL_RADIUS*right_encoder_value)/ROBOT_RADIUS

        # Check if either wheel has traveled the target distance
        if abs(left_wheel_travel_angle) >= abs(target_angle) or abs(right_wheel_travel_angle) >= abs(target_angle):
            break
            
        # print(f"Left Wheel Angle: {left_wheel_travel_angle} | Right Wheel Angle: {right_wheel_travel_angle}")

    # Stop the motors
    left_motor.setVelocity(0)
    right_motor.setVelocity(0)

def wall():
    dist0 = ps[0].getValue()
    dist1 = ps[7].getValue()
    
    dist2 = ps[1].getValue()
    dist3 = ps[6].getValue()
    
    if(dist0 < 70) and (dist1 <70) :
        F = True
     
    
    print(dist0)
    print(dist1)  

# Main loop
while robot.step(TIME_STEP) != -1:

    get_distance()
    moveDistance(72)
    turnAngle(1.57)
    get_distance()
    moveDistance(18)
    # moveDistance(18)
    # turnAngle(-1.57)
    # moveDistance(18)
    # turnAngle(-1.57)
    # moveDistance(18)
    # turnAngle(1.57)
    # break
    
   
    
    # Get the gyroscope values (angular velocity in rad/s for X, Y, Z)
    # gyro_values = gyro.getValues()
    
    # Extract the angular velocity around the x, y, and z axes
    # angular_velocity_z = gyro_values[2]/7450
    # angle += angular_velocity_z*(64/1000)

    # Display the gyroscope readings
    # print(f"Angle: {angle:.3f}, Angular Velocity: {angular_velocity_z:.3f}")


    # robot distance
    
    # total_time += TIME_STEP / 1000.0  # Convert milliseconds to seconds
    
    # distance_traveled = robot_velocity * total_time
    
   
    # Initial value recordings
    # if (const == 1):
        # INIT_LEFT_ENCODER = left_encoder.getValue()
        # INIT_RIGHT_ENCODER = right_encoder.getValue()
        # const = 0
        
    # Read the proximity sensors
    # values = [sensor.getValue() for sensor in sensors]
    
    # Get the encoder values (position of the left and right motors)
    # left_encoder_value = left_encoder.getValue() - INIT_LEFT_ENCODER
    # right_encoder_value = right_encoder.getValue() - INIT_RIGHT_ENCODER
    
    # left_wheel_distance = WHEEL_RADIUS*left_encoder_value
    # right_wheel_distance = WHEEL_RADIUS*right_encoder_value
    
    # Print the encoder values
    
     # Print the distance
    # print(f"Distance Traveled: {distance_traveled:.2f} m")

    
    # Optional: Print sensor values for debugging
    # print(f"Sensors: {values}")
