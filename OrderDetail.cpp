#include "OrderDetail.h"

OrderDetail::OrderDetail(){
    foodQty = 0;
}

list<Food*> OrderDetail::getFoodList(){return itemList;}

int OrderDetail::getFoodQty(){return foodQty;}

void OrderDetail::addFood(Food inputFood){ 
    Food *temp = new Food(inputFood.getFoodName(), inputFood.getSize(), inputFood.getType(), inputFood.getPrice());
    itemList.push_back(temp);
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

void OrderDetail::showOrderDetail(){
    for(auto i : itemList){
        cout << i->getFoodName() << endl;
    }
}