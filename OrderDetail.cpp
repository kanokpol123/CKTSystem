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
    qty = myOrder[inputFood];
    qty++;
    myOrder[inputFood] = qty;
    foodQty++;
}

void OrderDetail::removeFood(int index){
    int i = 0;
    index--;

    for(auto x : myOrder){
        if (i == index)
        {
            if(x.second > 1){
                x.second--;
            }else{
                myOrder.erase(x.first);
            }
        }
        i++;
    }
}

void OrderDetail::showOrderDetail(){
    for(auto i : myOrder){
        cout << i.first->getFoodName() << " " << i.first->getSize() << " " << i.first->getPrice() << " " << i.second << endl;
    }
}

void OrderDetail::setFoodOrder(Food* food) {this->foodOrder = food;}
Food* OrderDetail::getFoodOrder() {return foodOrder;}