#ifndef ORDERDETAIL_H 
#define ORDERDETAIL_H

#include "Food.h"
#include <string>
#include <iterator>
#include <map>

using namespace std;

class OrderDetail
{
private:
    
    //จำนวนเงินทั้งหมดที่ต้องจ่าย
    int totalPay;
    
    //เเอตทริบิวต์จำนวนอาหารทั้งหมดใน Order
    int totalFoodQty;

    //แอตทริบิวต์จำนวนอาหารของตัวใดตัวหนึ่งในการสั่ง
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
    void addFood(Food* inputFood, int inputQty);
    
    //เมธอดลบ Food ใน itemList ตาม index เเละจำนวนที่ต้องการลบ
    void removeFood(int index, int inputQty);

    //เมธอดลบ Food ใน itemlist ทั้งหมด
    void clearMyOrderDetail();

    int getPayTotal();
    //เมธอดรายการอาหารใน Order
    void showOrderDetail();
};

#endif
