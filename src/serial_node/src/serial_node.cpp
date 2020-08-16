#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "serial/serial.h"

#include "serial_node/serial_msg.h"
#include<nav_msgs/Odometry.h>  


#define sBUFFER_SIZE 1024
#define rBUFFER_SIZE 1024
unsigned char s_buffer[sBUFFER_SIZE];
unsigned char r_buffer[rBUFFER_SIZE];

serial::Serial ser;
typedef union
{
	float data;
	unsigned char data8[4];
} data_u;
data_u pitch;
data_u roll;
data_u yaw;

void cmd_callback(const geometry_msgs::Twist::ConstPtr& cmd_vel)
{
    uint8_t _cnt = 0;
    data_u _temp; // 声明一个联合体实例，使用它将待发送数据转换为字节数组
	uint8_t data_to_send[14]; // 待发送的字节数组
	
	data_to_send[_cnt++]=0xAA;
		
	// 将要发送的数据赋值给联合体的float成员
	// 相应的就能更改字节数组成员的值
	_temp.data = cmd_vel->linear.x;
	data_to_send[_cnt++]=_temp.data8[0];
	data_to_send[_cnt++]=_temp.data8[1];
	data_to_send[_cnt++]=_temp.data8[2];
	data_to_send[_cnt++]=_temp.data8[3]; // 最高位
	
	_temp.data = cmd_vel->linear.y;
	data_to_send[_cnt++]=_temp.data8[0];
	data_to_send[_cnt++]=_temp.data8[1];
	data_to_send[_cnt++]=_temp.data8[2];
	data_to_send[_cnt++]=_temp.data8[3]; // 最高位
	
	_temp.data = cmd_vel->angular.z;
	data_to_send[_cnt++]=_temp.data8[0];
	data_to_send[_cnt++]=_temp.data8[1];
	data_to_send[_cnt++]=_temp.data8[2];
	data_to_send[_cnt++]=_temp.data8[3]; // 最高位

    char checkout = 0;
    for(int i = 1; i < _cnt; i++)
    {
        checkout += data_to_send[i];
    }
	data_to_send[_cnt++] = checkout;

    // 串口发送
    ser.write(data_to_send, 14);
}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "serial_node");
	ros::NodeHandle nh;

	// 打开串口
	try
	{
		ser.setPort("/dev/ttyACM0");
		ser.setBaudrate(115200);
		serial::Timeout to = serial::Timeout::simpleTimeout(1000);
		ser.setTimeout(to);
		ser.open();
	}
	catch(serial::IOException &e)
	{
		ROS_INFO_STREAM("Failed to open port ");
		return -1;
	}
	ROS_INFO_STREAM("Succeed to open port" );

	int cnt = 0;
	ros::Rate loop_rate(500);
	ros::Publisher imu_pub = nh.advertise<serial_node::serial_msg>("imu", 1000);
	ros::Subscriber sub = nh.subscribe("/cmd_vel", 10, cmd_callback);

	int state = 0;
	unsigned char data_receive[12] = {0};
    while(ros::ok())
	{
		serial_node::serial_msg msg;
		if(ser.available())
		{
            uint8_t buffer = 0;
			size_t bytes_read = ser.read(&buffer, 1);

			if(state == 0 && buffer == 0xAA)
			{
				state++;
			}
			else if(state == 1 && buffer == 0xBB)
			{
				state++;
			}
			else if(state >= 2 && state < 15)
			{
				data_receive[state-2]=buffer;
				state ++;
				if(state == 15)
				{
					uint8_t checkout = 0;
					for(int k = 0; k < 12; k++)
					{
						checkout += data_receive[k];
					}
					if(checkout == data_receive[12])
					{
						for(int k = 0; k < 4; k++)
						{
							roll.data8[k] = data_receive[k];
							pitch.data8[k] = data_receive[4 + k];
							yaw.data8[k] = data_receive[8 + k];
						}	
					}					
					ROS_INFO("%f, %f, %f,", roll.data, pitch.data, yaw.data);

					// 发布接收到的imu数据
					msg.roll = roll.data;
					msg.pitch = pitch.data;
					msg.yaw = yaw.data;
					imu_pub.publish(msg); 
					state = 0;
				}
			}
			else state = 0;
		}

		ros::spinOnce();
		// loop_rate.sleep();
		cnt++;
	}
	ser.close();

	return 0;
}