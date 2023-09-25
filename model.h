#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <vector>
#include <locale>
using namespace std;
struct Item {
    int id;
    string name;
    int price;
};

class Model{
public:
    Model();
    const Item mas[12] = {
        {11, "Энергетик", 70},
        {12,"Кириешки", 20},
        {13,"Кыр Сосичка", 50},
        {21,"Тандырная лепешка", 220},
        {22,"Сок 0.5л", 60},
         {23,"Чупа-чупс",25},
         {31,"Вода газ",50},
         {32,"Вода без газа",50},
         {33,"Круасан",60},
         {41,"Шоколадный батончик",70},
         {42,"Ролтон",300},
         {43,"Французские вафли",250}
    };
};

#endif // MODEL_H
