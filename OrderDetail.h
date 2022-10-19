#ifndef ORDERDETAIL_H 
#define ORDERDETAIL_H

#include "Food.h"
#include <string>
#include <map>

using namespace std;

class OrderDetail
{
private:

    Food *orderItem;

    //แอตทริบิวต์จำนวนอาหารในการสั่ง
    int foodQty;

    //แอตทริบิวต์ลิสของรายการอาหาร
    map<Food*, unsigned int> myOrder;
    
public:


    //constructor
    OrderDetail();

    //เมธอดคืนค่าลิส itemList
    map<Food*, unsigned> getFoodList();

    int getFoodQty();

    //เมธอดเพิ่ม Food เข้าไปใน itemList
    void addFood(Food inputFood);
    
    //เมธอดลบ Food ใน itemList
    void removeFood(int index);

    //เมธอดรายการอาหารใน Order
    void showOrderDetail();
};

#endif
