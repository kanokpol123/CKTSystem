#include "OrderDetail.h"

OrderDetail::OrderDetail(){
    foodQty = 0;
}

list<Food*> OrderDetail::getFoodList(){return itemList;}

int OrderDetail::getFoodQty(){return foodQty;}

void OrderDetail::addFood(Food inputFood){ 
    itemList.push_back(&inputFood);
    foodQty++;
}

void OrderDetail::removeFood(int index){
    int i = 0;
    for(auto j : itemList){
        if(i == index){
            itemList.remove(j);
            break;
        }
        i++;
    }
}