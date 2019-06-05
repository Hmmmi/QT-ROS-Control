/**
 * @file /include/qtros/main_window.hpp
 *
 * @brief Qt based gui for qtros.
 *
 * @date November 2010
 **/
#ifndef qtros_MAIN_WINDOW_H
#define qtros_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

//#include <QtWidgets/QMainWindow>
//#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "manual_dialog.h"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace qtros {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();
  int ssh_login();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_button_connect_clicked(bool check );
	void on_checkbox_use_environment_stateChanged(int state);

  void on_up_clicked();
  void on_down_clicked();
  void on_left_clicked();
  void on_right_clicked();

    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically
    //声明日志更新函数
    void updateLoggingView_sub();
    //声明发布消息函数
    void pub_cmd();
    //声明弹出框按钮点击后需要处理的函数
    void on_dialog_button_clicked();
    void on_lib_rviz_button_clicked();

private slots:
    void on_romap_button_clicked();

    void on_mapping_button_clicked();

    void on_button_connect_clicked();

private:
	Ui::MainWindowDesign ui;
    //声明QNode对象
	QNode qnode;
};

}  // namespace qtros

#endif // qtros_MAIN_WINDOW_H
