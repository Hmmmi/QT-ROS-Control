/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/qtros/main_window.hpp"
#include "../include/qtros/myviz.h"
#include "../include/qtros/mapp.h"
#include "../include/qtros/romap.h"
/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qtros {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{

	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
  QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    ReadSettings();
	setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

	/*********************
	** Logging
	**********************/
	ui.view_logging->setModel(qnode.loggingModel());
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    //使用connect()函数将信号与槽进行连接
    ui.view_logging_sub->setModel(qnode.loggingModel_sub());
    QObject::connect(&qnode, SIGNAL(loggingUpdated_sub()), this, SLOT(updateLoggingView_sub()));
    QObject::connect(ui.sent_cmd, SIGNAL(clicked()), this, SLOT(pub_cmd()));
    QObject::connect(ui.dialog_button, SIGNAL(clicked()), this, SLOT(on_dialog_button_clicked()));

    /*********************
    ** Auto Start
    **********************/
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
  msgBox.critical(NULL, "A Ou :(", "<h2>Couldn't find the ros master.</h2>");
  //msgBox.information(NULL, "A Ou :(", "Couldn't find the ros master.");
  //QMessageBox::information(NULL, "A Ou :(", "Couldn't find the ros master.");
  //msgBox.setText("Couldn't find the ros master.");
  //msgBox.exec();
    //close();
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked(bool check ) {
	if ( ui.checkbox_use_environment->isChecked() ) {
		if ( !qnode.init() ) {
      showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
		}
	} else {
		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
				   ui.line_edit_host->text().toStdString()) ) {
      showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
			ui.line_edit_topic->setReadOnly(true);
		}
	}
}


void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
	//ui.line_edit_topic->setEnabled(enabled);
}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
        ui.view_logging->scrollToBottom();
}

//定义updateLoggingView_sub()函数，将QListView组件自动滑到最底部
void MainWindow::updateLoggingView_sub() {
    ui.view_logging_sub->scrollToBottom();
}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>QT-ROS Test Program 1.1</h2> "
                                                "<p>@Copyright JingMi</p> "
                                                "<p>Getting stared with ROS. "
                                                "I use QT for GUI development. "
                                                "I implement the Raspberry Pi robot controlled "
                                                "by buttons and display the map by librviz library.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "qtros");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    //ui.line_edit_topic->setText(topic_name);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }
}

void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "qtros");
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}

//MainWindow与QNode的连接，调用qnode的sent_cmd()函数
void MainWindow::pub_cmd()
{
    qnode.sent_cmd();
}

//弹出框显示
void MainWindow::on_dialog_button_clicked()
{
  system("gnome-terminal -x bash -c 'source ~/JingMi_ROS_ws/catkin_ws/devel/setup.bash; rosrun rviz rviz'&");
  system("gnome-terminal -x bash -c 'source ~/JingMi_ROS_ws/catkin_ws/devel/setup.bash; rqt'&");
  system("gnome-terminal -x bash -c 'source ~/JingMi_ROS_ws/catkin_ws/devel/setup.bash; export TURTLEBOT3_MODEL=burger; roslaunch turtlebot3_slam turtlebot3_slam.launch slam_methods:=gmapping'&");
  exit(0);
}

void MainWindow::on_up_clicked()
{
  qnode.up();
}

void MainWindow::on_down_clicked()
{
  qnode.down();
}

void MainWindow::on_left_clicked()
{
  qnode.left();
}

void MainWindow::on_right_clicked()
{
  qnode.right();
}

void MainWindow::on_lib_rviz_button_clicked()
{
  MyViz* myviz = new MyViz();
  myviz->show();
  myviz->resize(600, 400);
  myviz->setWindowTitle("Mapping Show");
}

void MainWindow::on_romap_button_clicked()
{
  RoMap* romap = new RoMap();
  romap->show();
}

void MainWindow::on_mapping_button_clicked()
{
  MAPP* mapp = new MAPP();
  mapp->show();
}

}  // namespace qtros







