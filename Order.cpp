#include "Order.h"

Order::Order(){
    totalfoodQty = 0;
    totalPay = 0;
    orderNumber = 0;
    statusOfPayment = "";
    date = "";
    payMeth = "";
}

void Order::orderFood(Food inputFood){
    orderDetail.addFood(&inputFood);
}

void Order::showMyOrder(){
    orderDetail.showOrderDetail();
}

OrderDetail Order::getOrderDetail(){return this->orderDetail;}
