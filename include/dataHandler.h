#include "utility.h"



class dataHandler : public Param
{

public:
    dataHandler();
    void Run();

private:

    void VelodynePacketHandler(const velodyne_msgs::VelodyneScanConstPtr& msgIn);
    void imuHandler(const sensor_msgs::ImuConstPtr& msgIn);
    void tfHandler(const tf2_msgs::TFMessageConstPtr& msgIn);


public:
    ros::Subscriber lidarSub_;
    ros::Subscriber imuSub_;
    ros::Subscriber tfSub_;


};

