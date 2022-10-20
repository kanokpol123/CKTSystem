#include "OrderDetail.h"

OrderDetail::OrderDetail(){
    foodQty = 0;
}

int OrderDetail::getFoodQty() {return foodQty;}

vector <Food*> OrderDetail::getFoodList(){return itemList;}

map<Food*, unsigned int> OrderDetail::getFoodList(){return myOrder;}

int OrderDetail::getFoodQty(){return foodQty;}

void OrderDetail::addFood(Food* inputFood){ 
    int qty = 0;
    qty = myOrder[inputFood->getFoodName()];
    qty++;
    myOrder[inputFood->getFoodName()] = qty;
    
    foodQty++;
}

void OrderDetail::removeFood(int index){

    
}

void OrderDetail::showOrderDetail(){
    for(auto i : myOrder){
        cout << i.first();
    }
}

void OrderDetail::setFoodOrder(Food* food) {this->foodOrder = food;}
Food* OrderDetail::getFoodOrder() {return foodOrder;}