#ifndef ORDERDETAIL_H
#define ORDERDETAIL_H

#include "Food.h"
#include <string>
#include <list>

using namespace std;

class OrderDetail
{
private:

    Food *orderItem;

    //แอตทริบิวต์จำนวนอาหารในการสั่ง
    int foodQty;

    //แอตทริบิวต์ลิสของรายการอาหาร
    list <Food*> itemList;
    
public:

    //constructor
    OrderDetail();

    //เมธอดคืนค่าลิส itemList
    list <Food*> getFoodList();

    int getFoodQty();

    //เมธอดเพิ่ม Food เข้าไปใน itemList
    void addFood(Food inputFood);
    
    //เมธอดลบ Food ใน itemList
    void removeFood(int index);

    //เมธอดรายการอาหารใน Order
    void showOrderDetail();
};

#endif
