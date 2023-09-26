#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
bool NameLess(QObject *obj1, QObject *obj2){
    return obj1->objectName() <obj2->objectName();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->purchasedGood->setText("");
    qDebug() << ui->purchasedGood->text().length();
    ui->depositCoins->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->depositPapers->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(ui->add1, SIGNAL(clicked()), this, SLOT(AddNumber()));
    QObject::connect(ui->add2, SIGNAL(clicked()), this, SLOT(AddNumber()));
    QObject::connect(ui->add3, SIGNAL(clicked()), this, SLOT(AddNumber()));
    QObject::connect(ui->add4, SIGNAL(clicked()), this, SLOT(AddNumber()));

    QObject::connect(ui->depositCoins, SIGNAL(pressed()), this, SLOT(ShowCoinsMenuPrepare()));
    QObject::connect(ui->depositCoins, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ShowCoinsMenu(QPoint)));
    QObject::connect(coin1Action, SIGNAL(triggered()), this, SLOT(AddCoin1()));
    QObject::connect(coin2Action, SIGNAL(triggered()), this, SLOT(AddCoin2()));
    QObject::connect(coin5Action, SIGNAL(triggered()), this, SLOT(AddCoin5()));
    QObject::connect(coin10Action, SIGNAL(triggered()), this, SLOT(AddCoin10()));

    QObject::connect(ui->depositPapers, SIGNAL(pressed()), this, SLOT(ShowPapersMenuPrepare()));
    QObject::connect(ui->depositPapers, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ShowPapersMenu(QPoint)));
    QObject::connect(paper50Action, SIGNAL(triggered()), this, SLOT(AddPaper50()));
    QObject::connect(paper100Action, SIGNAL(triggered()), this, SLOT(AddPaper100()));

    QObject::connect(ui->discountCard, SIGNAL(clicked()), this, SLOT(AddDiscout()));
    QObject::connect(ui->getChange, SIGNAL(clicked()), this, SLOT(GetChange()));
    QObject::connect(ui->select, SIGNAL(clicked()), this, SLOT(SelectGood()));
    QObject::connect(ui->takeGood, SIGNAL(clicked()), this, SLOT(TakeGood()));
    AddTooltips();
    AddImgs();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddTooltips(){
    QList<QObject*> objects = ui->goods->children();
    std::sort(objects.begin(), objects.end(), NameLess);
    int i = 0;
    foreach(auto good, objects){
        QWidget *currentGood = dynamic_cast<QWidget*>(good);
        if(i < 12)
            currentGood->setToolTip(data.goodsNames[i++].name);
    }
    objects = ui->payment->children();
    std::sort(objects.begin(), objects.end(), NameLess);
    i = 0;
    foreach(auto paymentObject, objects){
        QWidget *currentObject = dynamic_cast<QWidget*>(paymentObject);
        if(i < 9)
            currentObject->setToolTip(data.paymentTooltips[i++]);
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

void MainWindow::AddNumber(){
    QPushButton *pButton = qobject_cast<QPushButton*>(sender());
    if(ui->goodNumber->text().length() < 2)
        ui->goodNumber->setText(ui->goodNumber->text()+pButton->text());
    else
        ui->goodNumber->setText(pButton->text());
    for(int i = 0; i < data.goodsCount; i++){
        if(QString::number(data.goodsNames[i].id) == ui->goodNumber->text()){
            ui->toBePaid->setText(QString::number(data.goodsNames[i].price));
            if(data.isDiscounded){
                int price = ui->toBePaid->text().toInt();
                price -= price*(data.discountPercent/100.0);
                ui->toBePaid->setText(QString::number(price));
            }
            ui->goodNumber->setText(ui->goodNumber->text() + ", " + data.goodsNames[i].name);
            break;
        }
        else{
            ui->toBePaid->setText("");
        }
    }

}

void MainWindow:: ShowCoinsMenuPrepare(){
    emit ui->depositCoins->customContextMenuRequested(ui->depositCoins->pos());
}

void MainWindow::ShowCoinsMenu(QPoint point){
    QPoint globalPos= ui->depositCoins->parentWidget()->mapToGlobal(ui->depositCoins->pos());
    QMenu menu;
    globalPos.setY(globalPos.y()+30);
    menu.addAction(coin1Action);
    menu.addSeparator();
    menu.addAction(coin2Action);
    menu.addSeparator();
    menu.addAction(coin5Action);
    menu.addSeparator();
    menu.addAction(coin10Action);
    menu.exec(globalPos);
}

void MainWindow::AddCoin1(){
    data.balance+=1;
    ui->yourMoney->setText(QString::number(data.balance));
}

void MainWindow::AddCoin2(){
    data.balance+=2;
    ui->yourMoney->setText(QString::number(data.balance));
}

void MainWindow::AddCoin5(){
    data.balance+=5;
    ui->yourMoney->setText(QString::number(data.balance));
}

void MainWindow::AddCoin10(){
    data.balance+=10;
    ui->yourMoney->setText(QString::number(data.balance));
}

void MainWindow::ShowPapersMenuPrepare(){
    emit ui->depositPapers->customContextMenuRequested(ui->depositPapers->pos());
}

void MainWindow::ShowPapersMenu(QPoint point){
    QPoint globalPos= ui->depositPapers->parentWidget()->mapToGlobal(ui->depositPapers->pos());
    QMenu menu1;
    globalPos.setY(globalPos.y() + 10);
    menu1.addAction(paper50Action);
    menu1.addSeparator();
    menu1.addAction(paper100Action);
    menu1.exec(globalPos);
}

void MainWindow::AddPaper50(){
    data.balance+=50;
    ui->yourMoney->setText(QString::number(data.balance));
}

void MainWindow::AddPaper100(){
    data.balance+=100;
    ui->yourMoney->setText(QString::number(data.balance));
}

void MainWindow::AddDiscout(){
    if(!data.isDiscounded){
        int price = ui->toBePaid->text().toInt();
        price -= price*(data.discountPercent/100.0);
        ui->toBePaid->setText(QString::number(price));
        data.isDiscounded = true;
    }
}

void MainWindow::GetChange(){
    ui->toBePaid->setText("");
    ui->goodNumber->setText("");
    data.isDiscounded = false;
    data.balance = 0;
    ui->yourMoney->setText("");
}

void MainWindow::SelectGood(){
    int toPay = (ui->toBePaid->text()).toInt();
    if(data.balance < toPay){
        ui->yourMoney->setText("Недостаточно средств");
        QTimer::singleShot(2000, this, SLOT(NotEnoughMoneyOrTakeYourGood()));
    }
    else{
        if(ui->purchasedGood->text()==""){
            data.balance -= toPay;
            ui->yourMoney->setText(QString::number(data.balance));
            QString goodName = ui->goodNumber->text();
            goodName.remove(0, 4);
            ui->purchasedGood->setText(goodName);
        }
        else{
            ui->yourMoney->setText("Дла начала заберите товар");
            QTimer::singleShot(2000, this, SLOT(NotEnoughMoneyOrTakeYourGood()));
        }
    }
}

void MainWindow::NotEnoughMoneyOrTakeYourGood(){
    ui->yourMoney->setText(QString::number(data.balance));
}

void MainWindow::TakeGood(){
    ui->purchasedGood->setText("");
}
