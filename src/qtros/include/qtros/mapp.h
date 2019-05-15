#ifndef MAPP_H
#define MAPP_H

#include <QWidget>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include<rviz/tool_manager.h>

//add
#include <ros/ros.h>
#include <signal.h>
#include <geometry_msgs/Twist.h>

#include <QAbstractButton>
#include <QtCore>

namespace Ui {
class MAPP;
}

class MAPP : public QWidget
{
  Q_OBJECT

public:
  explicit MAPP(QWidget *parent = 0);
  ~MAPP();
  void ros_init(int argc,char **argv);
  void shutdown(int sig);

  void setAutoRepeat(bool);

private slots:

  void on_back_button_pressed();

  void on_back_button_released();

  void on_left_button_pressed();

  void on_right_button_pressed();

  void on_forward_button_pressed();

  void on_stop_button_clicked();

  void on_map_button_clicked();

  void on_quit_button_clicked();

private:
  Ui::MAPP *ui;
  //声明可视化管理类VisualizationManager，并初始化，就可以不断更新
  rviz::VisualizationManager *manager_;
  //声明rviz的RenderPanel，这个面板类最终继承QWidget
  rviz::RenderPanel *render_panel_;
  rviz::Display *map_;
  QTimer *m_timer_;
};

#endif // MAPP_H
