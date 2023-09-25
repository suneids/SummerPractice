#include "mainwindow.h"
#include "ui_mainwindow.h"

bool NameLess(QObject *obj1, QObject *obj2){
    return obj1->objectName() <obj2->objectName();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AddTooltips();
    AddImgs();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddTooltips(){
    QList<QObject*> goods = ui->goods->children();
    std::sort(goods.begin(), goods.end(), NameLess);
    int i = 0;
    qDebug() << goods;
    foreach(auto good, goods){
        QWidget *currentGood = dynamic_cast<QWidget*>(good);
        currentGood->setToolTip(data.mas[i++].name);
    }
}

void MainWindow::AddImgs(){
    QLabel *images[] = {
        ui->image11,
        ui->image12,
        ui->image13,
        ui->image21,
        ui->image22,
        ui->image23,
        ui->image31,
        ui->image32,
        ui->image33,
        ui->image41,
        ui->image42,
        ui->image43,
    };
    for(int i = 0; i < 12; i++){
        QPixmap pixmap(data.imgPaths[i]);
        images[i]->setPixmap(pixmap);
        images[i]->setMask(pixmap.mask());
        images[i]->show();
    }
}

