cmake_minimum_required(VERSION 2.8.3)
project(iccv23_li)

set(CMAKE_BUILD_TYPE "Release")
add_compile_options(-std=c++14)
add_compile_options(-W)
add_compile_options(-Wall)
add_compile_options(-Wcast-qual)
add_compile_options(-Wshadow)
#SET(CMAKE_CXX_FLAGS "-O2 -g -Wall ${CMAKE_CXX_FLAGS}")

find_package(Boost REQUIRED)
find_package(Boost COMPONENTS filesystem thread REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  velodyne_msgs
  geometry_msgs
  nav_msgs
  sensor_msgs
  roscpp
  rospy
  std_msgs
  tf
)
find_package(libLAS REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(PCL 1.10 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/ThirdParty/include)
include_directories(/usr/include)

include_directories(
  ${Boost_INCLUDE_DIRS}
	${catkin_INCLUDE_DIRS} 
	${EIGEN3_INCLUDE_DIR}
	${PCL_INCLUDE_DIRS}
  include
)
MESSAGE(BOOST INCLUDE DIR: ${Boost_INCLUDE_DIRS})


catkin_package(
  CATKIN_DEPENDS geometry_msgs nav_msgs roscpp rospy std_msgs
  DEPENDS EIGEN3 PCL OpenCV libLAS
  INCLUDE_DIRS include
)

add_executable(iccv23_li src/main.cpp src/dataHandler.cpp)

target_include_directories(iccv23_li PRIVATE ${PCL_INCLUDE_DIRS})
target_link_libraries(iccv23_li ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${libLAS_LIBRARIES} ${Boost_LIBRARIES} /usr/lib/x86_64-linux-gnu/libjsoncpp.so.1.7.4)


install(DIRECTORY 
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})

install(TARGETS iccv23_li
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

  
