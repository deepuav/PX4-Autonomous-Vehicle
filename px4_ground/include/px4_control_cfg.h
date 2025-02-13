/*
 * px4_control_cfg.h
 *
 *  Created on: 2018-5-4
 *      Author: zipout
 *///Email		  : 1554459957@qq.com

#ifndef PX4_CONTROL_CFG_H_
#define PX4_CONTROL_CFG_H_
#include <ros/ros.h>
#include <iostream>
using namespace std;
 typedef struct
	{
		float vel_x;
		float vel_y;
		float vel_z;
	} S_SETPOINT_VEL;
	typedef struct
	{
		float difference;      //Proportional term
		float differential;    //Differential term
		float tempDiffer;			 //Proportional item at last moment
		float intergral;       //Integral item
	} S_PID_ITEM;
	typedef struct
	{
		float p;       //coefficient of proportionality
		float d;       //Differential term coefficient
		float i;       //Integral term coefficient
	} S_PID;
#endif /* PX4_CONTROL_CFG_H_ */
#include <ros/ros.h>
#include <iostream>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <geometry_msgs/Twist.h>
#include <mavros_msgs/PositionTarget.h>
#include <Eigen/Dense>
#include "offboard_control.h"
using namespace std;
using namespace Eigen;
class PX4RosNav {
 public:
    /**
     * default constructor
     */
    PX4RosNav(const ros::NodeHandle& nh, const ros::NodeHandle& nh_private);
    /**
     * destructor
     */
    ~PX4RosNav();
    void initialize();

  /**
  * @brief      check healthiness of the avoidance system to trigger failsafe in
  *             the FCU
  * @param[in]  since_last_cloud, time elapsed since the last waypoint was
  *             published to the FCU
  * @param[in]  since_start, time elapsed since staring the node
  * @param[out] planner_is_healthy, true if the planner is running without
  *errors
  * @param[out] hover, true if the vehicle is hovering
  **/
  OffboardControl OffboardControl_;
 private:
  ros::NodeHandle nh_;
  ros::NodeHandle nh_private_;
  ros::Timer cmdloop_timer_;
  void CmdLoopCallback(const ros::TimerEvent& event);
  void PublishVelControl();
  void CmdVelCallback(const geometry_msgs::Twist &msg);
  Eigen::Vector3d  px4_vel_;

  float desire_posz_;
  ros::Subscriber cmd_vel_sub_;
};