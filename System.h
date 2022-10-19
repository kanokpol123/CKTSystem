#ifndef SYSTEM_H
#define SYSTEM_H

#include "Customer.h"
#include <list>
#include <fstream>
using namespace std;

class System
{
private:
    list <Customer*> cusList;
public:
    void readUserFile();
    void printUser();
};

#endif