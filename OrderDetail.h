#ifndef ORDERDETAIL_H
#define ORDERDETAIL_H

#include "Food.h"
#include <string>
#include <list>

using namespace std;

class OrderDetail
{
private:
    //แอตทริบิวต์จำนวนอาหารในการสั่ง
    int foodQty;

    //แอตทริบิวต์ลิสของรายการอาหาร
    list<Food*> itemList;
public:

    OrderDetail();
    //เมธอดคืนค่าลิส itemList
    list<Food*> getFoodList();

    int getFoodQty();
    //เมธอดเพิ่ม Food เข้าไปใน itemList
    void addFood(Food inputFood);
    
    //เมธอดลบ Food ใน itemList
    void removeFood(int index);
};

#endif
