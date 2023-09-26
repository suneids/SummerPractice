#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <vector>
#include <locale>
#include <QString>

using namespace std;
struct Item {
    int id;
    QString name;
    int price;
};

class Model{
public:
    Model();
    static const int goodsCount = 12;
    int discountPercent = 10;
    bool isDiscounded = false;
    int balance = 0;
    Item goodsNames[goodsCount] = {
        {11, "Энергетик", 70},
        {12,"Кириешки", 20},
        {13,"Кыр Сосичка", 50},
        {21,"Тандырная лепешка", 220},
        {22,"Сок 0.5л", 60},
         {23,"Чупа-чупс",30},
         {31,"Вода газ",50},
         {32,"Вода без газа",50},
         {33,"Круасан",60},
         {41,"Шоколадный батончик",70},
         {42,"Ролтон",300},
         {43,"Французские вафли",250}
    };
    QString imgPaths[12] = {
        ":/img/img/11.png",
        ":/img/img/12.png",
        ":/img/img/13.png",
        ":/img/img/21.png",
        ":/img/img/22.png",
        ":/img/img/23.png",
        ":/img/img/31.png",
        ":/img/img/32.png",
        ":/img/img/33.png",
        ":/img/img/41.png",
        ":/img/img/42.png",
        ":/img/img/43.png",
    };
    QString paymentTooltips[9]{
        "Внести монеты",
        "Внести купюры",
        "Использовать Дисконтную карту",
        "Вернуть средства",
        "Номер выбранного товара",
        "Выбор товара",
        "Оплатить",
        "К оплате",
        "Внесенные средства"
    };
};

#endif // MODEL_H
