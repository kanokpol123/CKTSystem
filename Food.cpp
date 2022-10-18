#include "Food.h"
Food::Food(string foodName, string size, string typeOfFood, string price)
{
    this->foodName = foodName;
    this->size = size;
    this->typeOfFood = typeOfFood;
    this->price = price;
}

string Food::getFoodName() {return foodName;}
string Food::getSize() {return size;}
string Food::getType() {return typeOfFood;}
string Food::getPrice() {return price;}