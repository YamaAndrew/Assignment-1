# motor_controller_pkg
This ROS package contains a motor_controller node that subscribes to motor control commands and performs basic functionalities such as starting, stopping, and setting velocity.

## Prerequisites
* ROS (Robot Operating System) installed. You can install ROS by following the instructions here.

## Building the Package
To build the motor_controller_pkg package, follow these steps:

1. Clone this repository into your catkin workspace's src directory:
```
git clone https://github.com/YamaAndrew/Assignment-1.git
```
2. Navigate to your catkin workspace:
```
cd /path/to/your/catkin_workspace
```
3. Build the package using catkin_make:
```
catkin_make
```
4. Start a rosmaster
```
roscore
```

## Running the motor_controller Node
Once the package is built, you can run the motor_controller node (in a new terminal) using the following steps:

1. Make sure your ROS environment is set up properly by sourcing your workspace:
```
source /path/to/your/catkin_workspace/devel/setup.bash
```
Replace /path/to/your/catkin_workspace with the actual path to your catkin workspace.
2. Launch the motor_controller node using rosrun:
```
rosrun motor_controller_pkg motor_controller
```

## Testing the Node
To test the motor_controller node, you can publish messages to the /motor_commands topic using the rostopic pub command (in a new terminal). For example:

To start the motor:
```
rostopic pub /motor_commands motor_controller_pkg/MotorCommand "command: 'start'"
```
To stop the motor:
```
rostopic pub /motor_commands motor_controller_pkg/MotorCommand "command: 'stop'"
```
To set the velocity to a specific value (e.g., 1.5):
```
rostopic pub /motor_commands motor_controller_pkg/MotorCommand "command: 'velocity', velocity: 1.5"
```

## Message Format
The motor_controller node expects messages of type MotorCommand on the /motor_commands topic. The MotorCommand message has the following format:
```
# Command: "start", "stop", "velocity"
string command
# Velocity value
float32 velocity
```

