#include "utility.h"
#include "dataHandler.h"

int main(int argc, char **argv)
{

    ros::init(argc, argv, "iccv23_li");

    dataHandler dh;

    ros::spin();

    return 0;
}
