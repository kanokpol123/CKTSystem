#ifndef ORDERDETAIL_H
#define ORDERDETAIL_H

#include "Food.h"
#include <string>
#include <vector>
#include <list>

using namespace std;

class OrderDetail
{
private:
    //แอตทริบิวต์จำนวนอาหารในการสั่ง
    int foodQty;
    Food* foodOrder;
    //แอตทริบิวต์ลิสของรายการอาหาร
    vector <Food*> itemList;
public:
    OrderDetail();
    //เมธอดคืนค่าลิส itemList
    vector <Food*> getFoodList();

    int getFoodQty();
    //เมธอดเพิ่ม Food เข้าไปใน itemList
    void addFood(Food inputFood);
    
    //เมธอดลบ Food ใน itemList
    void removeFood(int index);

    int getFoodQty();
    void setFoodOrder(Food* food);
    Food* getFoodOrder();
};

#endif
