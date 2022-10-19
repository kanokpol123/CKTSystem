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
    orderDetail.addFood(inputFood);
}

void Order::showMyOrder(){
    for(auto i : orderDetail.getFoodList()){
        cout << i->getFoodName() << " " << i->getSize() << " " << i->getPrice() << endl;
        totalPay = stoi(i->getPrice());
        totalfoodQty++;
    }
    cout << "Quantity : " << totalfoodQty << endl;
    cout << "Total : " << totalPay << " Baht" << endl;
    
}

OrderDetail Order::getOrderDetail(){return this->orderDetail;}
