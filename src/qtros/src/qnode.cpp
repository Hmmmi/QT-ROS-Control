/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include <geometry_msgs/Twist.h>
#include "../include/qtros/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qtros {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
    ros::init(init_argc,init_argv,"qtros");//ros节点初始化
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;//创建节点句
    // Add your ros communications here.
    //修改发布者订阅的话题，/turtle1/cmd_vel
    chatter_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    //chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);//创建一个Publisher，发布名为tter的topic，消息类型为td_msgs::String
    //在初始化函数init()中，创建一个Subscriber，订阅名为chatter的话题，接受1000信息队列，注册回调函数Callback
    //chatter_subscriber = n.subscribe("chatter", 1000, &QNode::Callback, this);//创建一个Subscribe，订阅名为chatter的topic，注册回调函数Callback
	start();
	return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"qtros");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
  //修改发布者订阅的话题，/turtle1/cmd_vel
  chatter_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
  //chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
    //在初始化函数init()中，创建一个Subscriber，订阅名为chatter的话题，接受1000信息队列，注册回调函数Callback
    //chatter_subscriber = n.subscribe("chatter", 1000, &QNode::Callback, this);
	start();
	return true;
}

//void QNode::run() {
//	ros::Rate loop_rate(1);
//	int count = 0;
//	while ( ros::ok() ) {

//		std_msgs::String msg;
//		std::stringstream ss;
//		ss << "hello world " << count;
//		msg.data = ss.str();
//		chatter_publisher.publish(msg);
//		log(Info,std::string("I sent: ")+msg.data);
//		ros::spinOnce();
//		loop_rate.sleep();
//		++count;
//	}
//	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
//	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
//}

void QNode::up() {
  ros::Rate loop_rate(1);

  if ( ros::ok() ) {
    geometry_msgs::Twist msg;
    msg.linear.x = 0.5;
    msg.angular.z = 0.0;

    chatter_publisher.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }
  log(Info,std::string("up"));
}

void QNode::down()
{
  ros::Rate loop_rate(1);

  if(ros::ok())
  {
    geometry_msgs::Twist msg;
    msg.linear.x = -0.5;
    msg.angular.z = 0.0;

    chatter_publisher.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }
  log(Info,std::string("down"));
}

void QNode::left()
{
  ros::Rate loop_rate(1);

  if(ros::ok())
  {
    geometry_msgs::Twist msg;
    msg.linear.x = 0.0;
    //弧度
    msg.angular.z = 0.78539;

    chatter_publisher.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }
  log(Info,std::string("left"));
}

void QNode::right()
{
  ros::Rate loop_rate(1);

  if(ros::ok())
  {
    geometry_msgs::Twist msg;
   msg.linear.x = 0.0;
    msg.angular.z = -0.78539;

    chatter_publisher.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }
  log(Info,std::string("right"));
}

void QNode::log( const LogLevel &level, const std::string &msg) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Fatal) : {
				ROS_FATAL_STREAM(msg);
				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
				break;
		}
	}
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
	Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}

//日志输出
void QNode::log_sub( const LogLevel &level, const std::string &msg ) {
    logging_model_sub.insertRows(logging_model_sub.rowCount(), 1);
    std::stringstream logging_model_msg;
    switch ( level ) {
        case(Debug) : {
                ROS_DEBUG_STREAM(msg);
                logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Info) : {
                ROS_INFO_STREAM(msg);
                logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Warn) : {
                ROS_WARN_STREAM(msg);
                logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Error) : {
                ROS_ERROR_STREAM(msg);
                logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Fatal) : {
                ROS_FATAL_STREAM(msg);
                logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
                break;
        }
    }
    QVariant new_row(QString(logging_model_msg.str().c_str()));
    logging_model_sub.setData(logging_model_sub.index(logging_model_sub.rowCount()-1),new_row);
    Q_EMIT loggingUpdated_sub(); // used to readjust the scrollbar
}

//回调函数Callback()，接受到话题消息后，将接受到的信息打印出来
void QNode::Callback( const std_msgs::StringConstPtr &submsg ) {
    log_sub(Info, std::string("Success sub: ")+submsg->data.c_str() );
}

//函数sent_cmd()，发布消息，以及循环等待回调函数
void QNode::sent_cmd(){
    if (ros::ok()) {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "clicked the btn";
        msg.data = ss.str();
        chatter_publisher.publish(msg);
        log(Info, std::string("I sent:" + msg.data) );
        ros::spinOnce();
    }
}

}  // namespace qtros
