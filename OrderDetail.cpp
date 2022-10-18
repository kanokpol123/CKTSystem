#include "OrderDetail.h"

list<Food*> OrderDetail::getFoodList(){return itemList;}

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

