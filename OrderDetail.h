#ifndef ORDERDETAIL_H 
#define ORDERDETAIL_H

#include "Food.h"
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

class OrderDetail
{
private:

    Food *orderItem;

    //แอตทริบิวต์จำนวนอาหารในการสั่ง
    int foodQty;
    Food* foodOrder;
    //แอตทริบิวต์ลิสของรายการอาหาร
    vector <Food*> itemList;
public:
    OrderDetail();
    map<Food*, unsigned int> myOrder;
    


    //constructor
    //เมธอดคืนค่าลิส itemList
    vector <Food*> getFoodList();
    map<Food*, unsigned> getFoodList();
    int getFoodQty();

    //เมธอดเพิ่ม Food เข้าไปใน itemList
    void addFood(Food inputFood);
    
    //เมธอดลบ Food ใน itemList
    void removeFood(int index);

    int getFoodQty();
    void setFoodOrder(Food* food);
    Food* getFoodOrder();
    void showOrderDetail();
};

#endif
