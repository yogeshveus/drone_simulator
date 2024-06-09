# Arduino - Drone Simulator

## Problem Statement

This simulator simulates the programming environment for what would be the drone's onboard computer. The drone is flying over a city with buildings. It has with it, an ultrasound sensor, facing the ground. The ultrasound sensor can be invoked at any time to know the echo time from the ground right below the drone. Using some basic physics and maths, this can be used to gain information on the topology (buildings) over which the drone is flying. There are also sensors on the drone that allow it to find its position. The flight path is determined by a piece of software that has already been written and is not under our control. Our task is to use the data available to us, to calculate these in real-time:
1) The number of buildings in the path taken
2) The height of each of those buildings
3) Estimate on the length of the building
4) Positions of those buildings on the map

And all of these should be done, while making as few invocations to the ultrasound sensor as possible, to preserve the drone's battery.

![image](https://github.com/JustTheCoolest/Atom_Arduino_Drone_Simulator/assets/74148176/823cde4c-d41f-40ee-930f-4040c953c876)

## Who is this for?

This simulator serves as an introductory challenge to those who want to get into robot programming. The challenge incorporates aspects of robotics such as being unable to run instantaneous tests in the real world, having to deal with imperfect sensor data, etc.

## Instructions to attempt solving

You can download the latest release (right pane on the GitHub page) (you don't have to download the entire code).

The objective is to fill the drone.ino with your code. The simulator has been designed such that you can focus on the programming aspects of Arduino robots, rather than the details of integrating the electronic components. The functions available for use, are mentioned as comments in the file itself. To run the code, you have to compile and run the driver.cpp file. The calculated value for the number of buildings should be continually updated to the NUMBER_OF_BUILDINGS variable.

If interested, you can test your code by generating data for more flight path drawings using the OpenCV-based data generator.

## Contribution guidelines

1) Clone (via vscode)
2) Navigate to branch
3) Run Prep/calls.cpp
It should be running without setup errors (nothing other than index error)
4) Make changes to simulator.cpp
5) Stage changes
6) Write commit message
7) Commit
8) make sure you are in the correct branch 
9) Push
10) Call (at least a missed call) and inform me, I'll explain your next work
