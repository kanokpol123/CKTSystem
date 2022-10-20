
#include "Queue.h"
#include "Food.h"
#include <ctime>
#include <iomanip>

Queue::Queue(){
    readQueue();
}

Queue::Queue(int queueNumber){
    queueNumber = queueNumber;
}

int Queue::getQueueFromFile(){
    string qNum;
    string line;
    ifstream menuFile;
    menuFile.open("history.txt",ios::in);
    if(menuFile.fail())
    {
        cout << "Can't open user file." << endl;
    }
    else
    {
        while(getline(menuFile,line))
        {
            qNum = line.substr(0,line.find(','));
        }
        Queue(qNum);
        menuFile.close();
    }
}

void Queue::enQueue(Order inputOrder){
    Order *temp = new Order();
    *temp = inputOrder;
    queueList.push(temp);
}

void Queue::deQueueLastOrder(){
    queueList.pop();
}

void Queue::deQueueByIndex(int index){
    int i = 1;
    while(!queueList.empty()){
        if(i != index){
            queueList.push(queueList.front());
            queueList.pop();
            i++;
        }
        else
        {
            queueList.pop();
            break;
        }
    }
}

void Queue::readQueue(){

    string username, foodType, foodName, foodSize, foodPrice, foodQty;
    string line;
    ifstream queueFile;
    Order *tempOrder = new Order();
    queueFile.open("Queue.txt", ios::in);
    while(getline(queueFile, line))
    {
        if(line.find('*') != string::npos)
        {
            line.erase(0,1);
            username = line;
            tempOrder->username = username;
        }else if(line.find('&') != string::npos){
            enQueue(*tempOrder);
            tempOrder->clearOrder();
        }else{
            foodType = line.substr(0,line.find(','));
            line.erase(0, line.find(',')+1);

            foodName = line.substr(0,line.find(','));
            line.erase(0, line.find(',')+1);

            foodSize = line.substr(0,line.find(','));
            line.erase(0, line.find(',')+1);

            foodPrice = line.substr(0,line.find(','));
            line.erase(0, line.find(',')+1);

            foodQty = line.substr(0,line.find(','));
            line.erase(0, line.find(',')+1);

            Food *foodTemp = new Food(foodType, foodName, foodSize, foodPrice);
            tempOrder->orderFood(foodTemp, stoi(foodQty));
            
        }
    }
    queueFile.close();
}

void Queue::showQueue(){
    int index = 1;
        queue<Order*> tempQueueList = queueList; 
        while(!tempQueueList.empty()){
            cout << "Queue : " << index <<endl;
            cout << setfill('=') << setw(57) << "=" << setfill(' ') << endl;
            cout << "Customer : " << tempQueueList.front()->getUsername() << endl;
            tempQueueList.front()->showMyOrder();
            tempQueueList.pop();
            
            index++;
        }
}

void Queue::updateFile(string username){
    ofstream queueFile;
    queueFile.open("C:\\Users\\Asus\\Documents\\GitHub\\CKTSystem\\Queue.txt",ios::out);

    if(queueFile.fail())
    {
        cout << "Can't open user file." << endl;
    }
    else
    {
        while(!queueList.empty()){
            queueFile << "*" << queueList.front()->getUsername() << "\n";
            for(auto x : queueList.front()->getOrderDetail()->getFoodList())
            {
                queueFile << x.first->getType() << ","
                         << x.first->getFoodName() << ","
                         << x.first->getSize() << ","
                         << x.first->getPrice() << ","
                         << x.second << "\n";
            }
            queueFile << "&\n";
            queueList.pop();
        }
        queueFile.close();
    }
}