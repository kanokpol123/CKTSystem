#ifndef SYSTEM_H
#define SYSTEM_H

#include "Customer.h"
#include "Clerk.h"
#include "Account.h"
#include <list>
#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class System
{
private:
    list <Customer*> cusList;
    list <Clerk*> clerkList;
public:
    System();
    void readUserFile();
    void printUser();
    list <Customer*> getCusList();
    list <Clerk*> getClerkList();
    string login(string username,string password);
    void regis(string username, string password, string name, string address, string telephone);
    void custInterface(string username);
    void clerkInterface(string username);
};

#endif