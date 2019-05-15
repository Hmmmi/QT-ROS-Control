#include "../include/qtros/romap.h"
#include "ui_romap.h"

RoMap::RoMap(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::RoMap)
{
  ui->setupUi(this);

  int argc;
  char** argv;
  ros_init(argc, argv);

  render_panel_ = new rviz::RenderPanel;
  ui->verticalLayout_2->addWidget(render_panel_);
  manager_ = new rviz::VisualizationManager(render_panel_);
  render_panel_->initialize(manager_->getSceneManager(), manager_);
  manager_->initialize();
  manager_->startUpdate();
}

RoMap::~RoMap()
{
  delete ui;
}

void RoMap::ros_init(int argc,char **argv)
{
  ros::init(argc,argv,"rosmap",ros::init_options::AnonymousName);
}

void RoMap::on_display_button_clicked()
{
  manager_->removeAllDisplays();
  rviz::Display* map = manager_->createDisplay("rviz/Map", "adjustable map", true);
  ROS_ASSERT( map != NULL );
  map->subProp("Topic")->setValue("/map");

  rviz::Display* robot = manager_->createDisplay("rviz/RobotModel", "adjustable robot", true);
  ROS_ASSERT( robot != NULL );
  robot->subProp("Robot Description")->setValue("robot_description");

  rviz::Display* laser = manager_->createDisplay("rviz/LaserScan", "adjustable scan", true);
  ROS_ASSERT( laser != NULL );
  laser->subProp("Topic")->setValue("/scan");
  laser->subProp("Size(m)")->setValue("0.1");
}

void RoMap::on_quit_button_clicked()
{
  this->close();
}
