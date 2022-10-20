#ifndef QUEUE_H
#define QUEUE_H
#include <queue>
#include "Order.h"

class Queue
{
private:
static int queueNumber;
queue<Order*> queueList;

public:
Queue();
Queue(int queueNumber);
int getQueueFromFile();
string getCurrentDate();
void enQueue(Order inputOrder);
void deQueueLastOrder();
void deQueueByIndex(int index);
void readQueue();
void showQueue();
void updateFile(string username);
};

#endif