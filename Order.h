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
    Order();
    void orderFood(Food* inputFood, int inputQty);
    void showMyOrder();
    OrderDetail* getOrderDetail();
    void writeFile();
};


#endif