#include "Food.h"

Food::Food(){}

Food::Food(string typeOfFood, string foodName, string size, string price)
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