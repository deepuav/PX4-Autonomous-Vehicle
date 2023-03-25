# Starting Guide

#### 1) Test the sdf models.

Adding airframe configurations
```
ln -fs ~/catkin_ws/src/px4_sim/airframes_sitl/* ~/PX4-Autopilot/build/px4_sitl_default/etc/init.d-posix/airframes/
```

Go to the catkin_ws first
```
cd ~/catkin_ws
```
In the terminal 1 run:
```
roscore
```
run the launch file with your defined vehicle
In the terminal 2 run:
```
roslaunch px4_sim 0launch_model_only.launch
```
You can change the vehicle type 
```
<arg name="vehicle" default="r1_rover"/>
```
Change world file if necessary
```
<arg name="world" default="$(find px4_sim)/worlds/empty.world"/>
```

#### 2) Run with PX4 SITL.
In the terminal 1 run:
```
roscore
```
In the terminal 2 run:
```
roslaunch px4_sim 1mavros_posix_sitl.launch
```

Remember that you can change the vehicle type.
```
<arg name="vehicle" default="frame450"/>
```
Now we can use Qground Control(QGC) or run ./QGroundControl.AppImage

#### 3) Run the predefined mission

In QGC you can add a predefined mission in the path ~/px4_sim/mission and run the mission as usual.

#### 4) Run in mission mode with mavros.
In the terminal 1 run:
```
roscore
```
In the terminal 2 run:
```
roslaunch px4_sim 1mavros_posix_sitl.launch
```
Now go to the path ../px4_sim/src you need to get the permision to all pythons files. I mean chmod +x to all python file in the /src path.

Example: chmod +x control_vel.py

In the terminal 3 run:
```
source devel/setup.bash
rosrun mavros mavsys mode -c OFFBOARD
rosrun mavros mavsafety arm
rosrun px4_sim wind.py
rosrun px4_sim control_vel.py
rosrun px4_sim mavros_offboard_posctl_test.py
```
``Note: others python scripts is experimental. If the OFFBOARD is running, you won't be able to run a QGC mission plan.``

The option is to run launch file instead of python node.
In the terminal 3 run: (Options)
```
roslaunch px4_sim 3mission_qgcaruco_sitl.launch
```
Now, If everything is fine close all and moving to the next step.

#### 5) Run the Avoidance Navigation
In the terminal 1 run:
```
roscore
```
For air vehicle run:
In the terminal 2 run:
```
roslaunch px4_sim 2obs_avoidance_air_local.launch
```

For ground vehicle run:
In the terminal 2 run: (Option)
```
roslaunch px4_sim 2obs_avoidance_car_lidar.launch
```
In the terminal 3 run:
```
rosrun mavros mavsys mode -c OFFBOARD
rosrun mavros mavsafety arm
```

#### 6) Run Avoidance Mission
In the terminal run:
```
roslaunch px4_sim 4mission_followme_sitl.launch
```
    
#### 7) Run multiple UAV with mavros.
In the terminal run:
```
roslaunch px4_sim 5multi_uav_auto_sitl.launch
```