#include <Order.h>

Order::Order(int totalfoodQty, int totalPay, int orderNumber, int payMeth, string statusOfPayment, string date, Customer* buyer)
{
    this->totalfoodQty = totalfoodQty;
    this->totalPay = totalPay;
    this->orderNumber = orderNumber;
    this->payMeth = payMeth;
    this->statusOfPayment = statusOfPayment;
    this->date = date;
    this->buyer = buyer;
}
int Order::getTotalFoodQty() {return totalfoodQty;}
int Order::getTotalPay() {return totalPay;}
int Order::getOrderNumber() {return orderNumber;}
int Order::getPayMeth() {return payMeth;}
string Order::getStatusOfPayment() {return statusOfPayment;}
string Order::getDate() {return date;}
Customer* Order::getBuyerInfo() {return buyer;}

void Order::addFoodDetail(OrderDetail* orderDetail)
{
    this->orderDetail = orderDetail;
}

void Order::showOrder()
{
    for (auto x : orderDetailList)
    {
        cout << x->getFoodOrder() << " " << x->getFoodQty() << endl;
    }
}