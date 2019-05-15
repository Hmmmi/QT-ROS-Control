#include "../include/qtros/manual_dialog.h"
#include "ui_manual_dialog.h"
#include <QDebug>

manualdialog::manualdialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::manualdialog)
{
  ui->setupUi(this);
}

manualdialog::~manualdialog()
{
  delete ui;
}

//add
void manualdialog::on_up_clicked()
{
  qDebug() << "up clicked" <<endl;
  qnode->up();
}

//add
void manualdialog::on_down_clicked()
{
  qnode->down();
}

//add
void manualdialog::on_left_clicked()
{
  qnode->left();
}

//add
void manualdialog::on_right_clicked()
{
  qnode->right();
}

//add
void manualdialog::on_back_clicked()
{
  this->close();
}
