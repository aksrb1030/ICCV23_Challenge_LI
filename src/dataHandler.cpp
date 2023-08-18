#include "dataHandler.h"


dataHandler::dataHandler(/* args */)
{
    lidarSub_ = nh_.subscribe<velodyne_msgs::VelodyneScan>(lidarTopic_, 1, &dataHandler::VelodynePacketHandler, this, ros::TransportHints().tcpNoDelay());
    imuSub_ = nh_.subscribe<sensor_msgs::Imu>(imuTopic_, 200, &dataHandler::imuHandler, this, ros::TransportHints().tcpNoDelay());
    tfSub_ = nh_.subscribe<tf2_msgs::TFMessage>(tfTopic_, 200, &dataHandler::tfHandler, this, ros::TransportHints().tcpNoDelay());
}

void dataHandler::VelodynePacketHandler(const velodyne_msgs::VelodyneScanConstPtr& msgIn)
{
    std::cout << "msgIn->stamp : " << msgIn->header << "\n";
}

void dataHandler::imuHandler(const sensor_msgs::ImuConstPtr& msgIn)
{
    // std::cout << "msgIn->header : " <<msgIn->header << "\n";
}

void dataHandler::tfHandler(const tf2_msgs::TFMessageConstPtr& msgIn)
{
    // std::cout << "msgIn->transformcms.size() : " <<msgIn->transforms.size() << "\n";
}

void dataHandler::Run()
{
    
}





