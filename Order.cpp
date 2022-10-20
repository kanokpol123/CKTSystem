#include "Order.h"

Order::Order(){
    totalfoodQty = 0;
    totalPay = 0;
    orderNumber = 0;
    statusOfPayment = "";
    date = "";
    payMeth = "";
}

void Order::orderFood(Food* inputFood, int inputQty){
    orderDetail.addFood(inputFood, inputQty);
}

void Order::showMyOrder(){
    orderDetail.showOrderDetail();
}

OrderDetail* Order::getOrderDetail(){return &this->orderDetail;}

void Order::writeFile()
{
    ofstream menuFile;
    menuFile.open("Queue.txt",ios::out);
    if(menuFile.fail())
    {
        cout << "Can't open user file." << endl;
    }
    else
    {
        map <Food*, unsigned int>::iterator itr;
        itr = orderDetail.getFoodList().begin();
        while (itr != orderDetail.getFoodList().end())
        {
            menuFile << itr->first.
            itr++;
        }
        

        menuFile.close();
    }
}