#include "../include/qtros/mapp.h"
#include "ui_mapp.h"

//add
#include <ros/ros.h>
#include <signal.h>
#include <geometry_msgs/Twist.h>

ros::Publisher cmdVelPub;

MAPP::MAPP(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MAPP)
{
  ui->setupUi(this);

  int argc;
  char **argv;

  ros_init(argc, argv);

  render_panel_ = new rviz::RenderPanel;
  ui->verticalLayout_5->addWidget(render_panel_);
  manager_ = new rviz::VisualizationManager(render_panel_);
  render_panel_->initialize(manager_->getSceneManager(), manager_);
  manager_->initialize();
  manager_->startUpdate();

  ui->forward_button->setAutoRepeat(true);
  ui->forward_button->setAutoRepeatDelay(1000);
  ui->forward_button->setAutoRepeatInterval(100);

  ui->back_button->setAutoRepeat(true);
  ui->back_button->setAutoRepeatDelay(1000);
  ui->back_button->setAutoRepeatInterval(100);

  ui->left_button->setAutoRepeat(true);
  ui->left_button->setAutoRepeatDelay(1000);
  ui->left_button->setAutoRepeatInterval(100);

  ui->right_button->setAutoRepeat(true);
  ui->right_button->setAutoRepeatDelay(1000);
  ui->right_button->setAutoRepeatInterval(100);
}

MAPP::~MAPP()
{
  delete ui;
}

void MAPP::ros_init(int argc,char **argv)
{
  ros::init(argc,argv,"rosmap",ros::init_options::AnonymousName);
}


void MAPP::on_back_button_pressed()
{
  //为这个进程结点创建一个句柄
  ros::NodeHandle node;
  //在/mobile_base/commands/velocity topic上发布一个geometry_msgs/Twist的消息
  cmdVelPub = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
  ROS_INFO("move_turtle_goforward cpp start...");
  //控制信号载体 Twist message
  geometry_msgs::Twist speed;
  //设置线速度为0.1m/s，正为前进，负为后退(0)
  speed.linear.x = -1;
  //设置角速度为0rad/s，正为左转，负为右转 (0.5)
  speed.angular.z = 0;
  //将设置好的指令发送给机器人
  cmdVelPub.publish(speed);
}

void MAPP::on_back_button_released()
{

}

void MAPP::on_left_button_pressed()
{
  ros::NodeHandle node;
  cmdVelPub = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
  ROS_INFO("move_turtle_goforward cpp start...");
  geometry_msgs::Twist speed;
  speed.linear.x = 0;
  speed.angular.z = 1;
  cmdVelPub.publish(speed);
}

void MAPP::on_right_button_pressed()
{
  //为这个进程结点创建一个句柄
  ros::NodeHandle node;
  //在/mobile_base/commands/velocity topic上发布一个geometry_msgs/Twist的消息
  cmdVelPub = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
  ROS_INFO("move_turtle_goforward cpp start...");
  //控制信号载体 Twist message
  geometry_msgs::Twist speed;
  //设置线速度为0.1m/s，正为前进，负为后退(0)
  speed.linear.x = 0;
  //设置角速度为0rad/s，正为左转，负为右转 (0.5)
  speed.angular.z = -1;
  //将设置好的指令发送给机器人
  cmdVelPub.publish(speed);
}

void MAPP::on_forward_button_pressed()
{
  //为这个进程结点创建一个句柄
  ros::NodeHandle node;
  //在/mobile_base/commands/velocity topic上发布一个geometry_msgs/Twist的消息
  cmdVelPub = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
  ROS_INFO("move_turtle_goforward cpp start...");
  //控制信号载体 Twist message
  geometry_msgs::Twist speed;
  //设置线速度为0.1m/s，正为前进，负为后退(0)
  speed.linear.x = 1;
  //设置角速度为0rad/s，正为左转，负为右转 (0.5)
  speed.angular.z = 0;
  //将设置好的指令发送给机器人
  cmdVelPub.publish(speed);
}

void MAPP::on_stop_button_clicked()
{
  //为这个进程结点创建一个句柄
  ros::NodeHandle node;
  //在/mobile_base/commands/velocity topic上发布一个geometry_msgs/Twist的消息
  cmdVelPub = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
  ROS_INFO("move_turtle_goforward cpp start...");
  //控制信号载体 Twist message
  geometry_msgs::Twist speed;
  //设置线速度为0.1m/s，正为前进，负为后退(0)
  speed.linear.x = 0;
  //设置角速度为0rad/s，正为左转，负为右转 (0.5)
  speed.angular.z = 0;
  //将设置好的指令发送给机器人
  cmdVelPub.publish(speed);
}

//创建了显示createDisplay()，然后添加topic值，加载地图
void MAPP::on_map_button_clicked()
{
  manager_->removeAllDisplays();

  rviz::Display *map_ = manager_->createDisplay("rviz/Map","adjustable map",true);
  ROS_ASSERT(map_ != NULL);
  map_->subProp("Topic")->setValue("/map");
  map_->subProp("Size (m)")->setValue("0.05");

  rviz::Display *robot_ = manager_->createDisplay("rviz/RobotModel", "adjustable robot", true);
  ROS_ASSERT(robot_ != NULL);
  robot_->subProp("Robot Description")->setValue("robot_description");

  rviz::Display *laser_ = manager_->createDisplay("rviz/LaserScan", "adjustable scan", true);
  laser_->subProp("Topic")->setValue("/scan");
  laser_->subProp("Size (m)")->setValue("0.05");
}

void MAPP::on_quit_button_clicked()
{
  this->close();
}
