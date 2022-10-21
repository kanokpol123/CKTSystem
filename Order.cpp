#include "Order.h"

Order::Order(){
    totalfoodQty = 0;
    totalPay = 0;
    orderNumber = 0;
    statusOfPayment = "";
    date = "";
    payMeth = "";
}

Order::Order(string username){
    this->username = username;
}

string Order::getUsername(){return username;}

void Order::orderFood(Food* inputFood, int inputQty){
    orderDetail.addFood(inputFood, inputQty);
}

void Order::showMyOrder(){
    orderDetail.showOrderDetail();
}

OrderDetail* Order::getOrderDetail(){return &this->orderDetail;}

void Order::updateFile(string username)
{
    ofstream menuFile;
    menuFile.open("Queue.txt",ios::app);

    if(menuFile.fail())
    {
        cout << "Can't open user file." << endl;
    }
    else
    {
        menuFile << "*" << username << "\n";
        for(const auto x : orderDetail.getFoodList()){
            menuFile << x.first->getType() 
            << "," << x.first->getFoodName() 
            << "," << x.first->getSize() 
            << "," << stoi(x.first->getPrice())
            << "," << x.second << "\n";
        }
        menuFile.close();
    }
}

void Order::clearOrder(){
    orderDetail.clearMyOrderDetail();
    totalfoodQty = 0;
    totalPay = 0;
}