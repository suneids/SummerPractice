#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AddTooltips();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddTooltips(){
    QObjectList goods = ui->goods->children();
    int i = 0;
    foreach(auto good, goods){
        QLabel *currentGood = dynamic_cast<QLabel*>(good);
        currentGood->setToolTip(QString::fromStdString(data.mas[i++].name));
    }
}
