#pragma once


#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <deque>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cfloat>
#include <iterator>
#include <sstream>
#include <string>
#include <limits>
#include <iomanip>
#include <array>
#include <thread>
#include <mutex>
#include <sstream>

#include <Eigen/Dense>

#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <tf2_msgs/TFMessage.h>
#include <velodyne_msgs/VelodyneScan.h>



class Param
{
public:
    ros::NodeHandle nh_;

    std::string bagPath_;
    std::string lidarTopic_, imuTopic_, tfTopic_;
    bool bagReadBool_;

    std::vector<double> extrinsicVec;
    int rows, cols;
    Eigen::Matrix4d extrinsicMat_;

    Param()
    {
        nh_.getParam("/bag/path",bagPath_);
        nh_.getParam("/bag/bool",bagReadBool_);
        nh_.getParam("/laser_to_imu/data",extrinsicVec);
        nh_.getParam("/laser_to_imu/rows",rows);
        nh_.getParam("/laser_to_imu/cols",cols);
        nh_.getParam("/topic/lidar",lidarTopic_);
        nh_.getParam("/topic/imu",imuTopic_);
        nh_.getParam("/topic/tf",tfTopic_);

        int num = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                extrinsicMat_(i, j) = extrinsicVec[num];
                num++;
            }
            
        }
    }
};