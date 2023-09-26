#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void AddNumber();

    void AddCoin1();
    void AddCoin2();
    void AddCoin5();
    void AddCoin10();
    void ShowCoinsMenuPrepare();
    void ShowCoinsMenu(QPoint point);

    void AddPaper50();
    void AddPaper100();
    void ShowPapersMenuPrepare();
    void ShowPapersMenu(QPoint point);

    void AddDiscout();

    void GetChange();

    void SelectGood();
    void NotEnoughMoneyOrTakeYourGood();

    void TakeGood();
signals:

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Model data;
    QMenu *coinsMenu;


    QAction *coin1Action = new QAction(QString::fromUtf8("1 рубль"));
    QAction *coin2Action = new QAction(QString::fromUtf8("2 рубля"));
    QAction *coin5Action = new QAction(QString::fromUtf8("5 рублей"));
    QAction *coin10Action = new QAction(QString::fromUtf8("10 рублей"));


    QMenu *papersMenu;
    QAction *paper50Action = new QAction(QString::fromUtf8("50 рублей"));
    QAction *paper100Action = new QAction(QString::fromUtf8("100 рублей"));
private:
    Ui::MainWindow *ui;
    void AddTooltips();
    void AddImgs();
};
#endif // MAINWINDOW_H
