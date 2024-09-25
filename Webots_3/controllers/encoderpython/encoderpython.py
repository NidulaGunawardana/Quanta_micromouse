from controller import Robot

# Time step of the simulation in milliseconds
TIME_STEP = 64

# Create the Robot instance
robot = Robot()

# Get the motors (left and right wheels)
left_motor = robot.getDevice('left wheel motor')
right_motor = robot.getDevice('right wheel motor')

# Enable position feedback (encoders) from the motors
left_motor.setPosition(float('inf'))  # Set motor to velocity control mode
right_motor.setPosition(float('inf'))
left_motor.setVelocity(1.0)           # Set an initial velocity
right_motor.setVelocity(1.0)

# Enable encoders
left_encoder = robot.getDevice('left wheel sensor')
right_encoder = robot.getDevice('right wheel sensor')
left_encoder.enable(TIME_STEP)
right_encoder.enable(TIME_STEP)

# Main loop
while robot.step(TIME_STEP) != -1:
    # Get the encoder values (position of the left and right motors)
    left_encoder_value = left_encoder.getValue()
    right_encoder_value = right_encoder.getValue()
    
    # Print the encoder values
    print(f"Left Encoder: {left_encoder_value} | Right Encoder: {right_encoder_value}")
