#include "OrderDetail.h"
#include <iomanip>

OrderDetail::OrderDetail(){
    foodQty = 0;
}

map<Food*, unsigned int> OrderDetail::getFoodList(){return myOrder;}

int OrderDetail::getFoodQty(){return foodQty;}

void OrderDetail::addFood(Food* inputFood, int inputQty){ 
    foodQty = myOrder[inputFood];
    foodQty += inputQty;
    myOrder[inputFood] = foodQty;
    totalFoodQty += inputQty;
    totalPay = stoi(inputFood->getPrice()) * inputQty;
}

void OrderDetail::removeFood(int index, int inputQty){
    int i = 1;
    map <Food*, unsigned int>::iterator itr;
    itr = myOrder.begin();
    while (itr != myOrder.end())
    {
        if (i == index)
        {
            if (inputQty > itr->second)
            {
                cout << "Input Quantity need to equal or less" << endl;
                break;
            }
            else
            {
                itr->second -= inputQty;
                if (itr->second == 0)
                {
                    myOrder.erase(itr);
                }
                break;
            }
        }
        itr++;
        i++;
    }
}

//เมธอดเคลียร์รายการสั่งอาหารทั้งหมด
void OrderDetail::clearMyOrderDetail(){
    myOrder.clear();
}

int OrderDetail::getPayTotal(){return totalPay;}
//เเสดงรายการที่สั่งอาหารทั้งหมด เงินทั้งหมดที่ต้องจ่าย
void OrderDetail::showOrderDetail(){
    totalPay = 0;
    cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl;
    cout << "Order" << endl;
    cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl
         << "||              Name               | Size | Qty |  Price  ||" << endl
         << setfill('=') << setw(60) << "=" << setfill(' ') << endl;
    if(!myOrder.empty()){
        for(const auto i : myOrder){
        cout << "|| " << setw(31) << left << i.first->getFoodName()
             << "|   " << i.first->getSize() << "  "
             << "|   " << "x" + to_string(i.second) << " "
             << "| " << setw(7) << stoi(i.first->getPrice()) * i.second << " ||" << endl;
             //คำนวณเงินทั้งหมดที่ต้องจ่าย
             totalPay += stoi(i.first->getPrice()) * i.second;
        }
        cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl;
    }else{
        cout << "|| " << setw(32) << left << "Empty"
             << "|   " << "-" << " "
             << "|   " << "-" << " "
             << "| " << setw(7) << "-" << "  ||" << endl;
    }
    cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl;
    cout << setw(55) << right << "Total Pay : "
         << setw(7) << left << totalPay << endl;
    cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl;
}