# [ICCV23_Challenge_LiI](https://superodometry.com/iccv23_challenge_LiI)

* File structure:
```
rosbag
├── TartanAir_lidar_{places ...}_noise0.bag
└── SubT_MRS_{trajectory names ...}_{robot types ...}.zip
    └── (zipped) raw_data_{...}yyyy-mm-dd-hh-mm-ss{...}.bag

folder
├── TartanAir_lidar_{places ...}.zip
│   ├── (zipped) imu
│   │   └── [acc/gyro/imu/imu_time].[npy/txt]
│   └── (zipped) lidar
│       ├── {...}_lcam_front_lidar.ply
│       └── timestamps.txt
└── SubT_MRS_{trajectory names ...}_{robot types ...}.zip
    ├── (zipped) imu
    │   └── imu_data.csv
    ├── (zipped) lidar
    │   ├── {...}.las
    │   └── timestamps.txt
    └── (zipped) tf
        └── tf_data.csv
```