#ifndef ORDER_H
#define ORDER_H

#include <list>
#include <iostream>
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
    void orderFood(Food inputFood);
    void showMyOrder();
    OrderDetail getOrderDetail();
};


#endif