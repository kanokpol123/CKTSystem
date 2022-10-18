#ifndef ORDERDETAIL_H
#define ORDERDETAIL_H

#include "Food.h"
#include <string>
#include <list>

using namespace std;

class OrderDetail
{
private:
    //แอตทริบิวต์ Pointer เพื่อจองหน่วยความจำไปเก็บไว้ใน itemList
    Food *OrderItem;

    //แอตทริบิวต์จำนวนอาหารในการสั่ง
    int foodQty;

    //แอตทริบิวต์ลิสของรายการอาหาร
    list<Food*> itemList;
public:

    //เมธอดคืนค่าลิส itemList
    list<Food*> getFoodList();

    //เมธอดเพิ่ม Food เข้าไปใน itemList
    void addFood(Food inputFood);
    
    //เมธอดลบ Food ใน itemList
    void removeFood(int index);
};

#endif
