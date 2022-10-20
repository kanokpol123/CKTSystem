#ifndef FOOD_H
#define FOOD_H

#include <iostream>
using namespace std;

class Food {
    protected:
        string foodName;
        string size;
        string typeOfFood;
        string price;
    public:
        Food();
        Food(string foodName, string size, string typeOfFood, string price);
        void setFoodName(string foodName);
        string getFoodName();
        void setSize(string size);
        string getSize();
        void setType(string type);
        string getType();
        void setPrice(string price);
        string getPrice();
};

#endif