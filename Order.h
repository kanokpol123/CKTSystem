#ifndef ORDER_H
#define ORDER_H

//#include <list>
#include <iostream>
#include <fstream>
#include "Customer.h"
#include "OrderDetail.h"

using namespace std;

class Order{
private:

int totalfoodQty, totalPay, orderNumber;
string statusOfPayment, date, payMeth;
OrderDetail orderDetail;
//customer* buyer;

public:
    string username;
    Order();
    Order(string username);
    string getUsername();
    void setUsername(string user);
    void orderFood(Food* inputFood, int inputQty);
    void showMyOrder();
    OrderDetail* getOrderDetail();
    void updateFile(string username);
    void clearOrder();
};


#endif