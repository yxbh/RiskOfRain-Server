#include "ServerGuiMainWindow.hpp"
#include "ui_ServerGuiMainWindow.h"

ServerGuiMainWindow::ServerGuiMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerGuiMainWindow)
{
    ui->setupUi(this);
}

ServerGuiMainWindow::~ServerGuiMainWindow()
{
    delete ui;
}
