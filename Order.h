#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <list>
#include <iostream>
#include "OrderDetail.h"
#include "Customer.h"

using namespace std;

class Order{
private:
    int totalfoodQty, totalPay, orderNumber, payMeth;
    string statusOfPayment, date;
    Customer* buyer;
    OrderDetail* orderDetail;
    vector <OrderDetail*> orderDetailList;
    list <Order*> Orderlist;
public:
    Order(int totalfoodQty, int totalPay, int orderNumber, int payMeth, string statusOfPayment, string date, Customer* buyer);
    int getTotalFoodQty();
    int getTotalPay();
    int getOrderNumber();
    int getPayMeth();
    string getStatusOfPayment();
    string getDate();
    Customer* getBuyerInfo();
    void addFoodDetail(OrderDetail* orderDetail);
    void showOrder();

    Order();
    void orderFood(Food inputFood);
    void showMyOrder();
    OrderDetail getOrderDetail();
};


#endif