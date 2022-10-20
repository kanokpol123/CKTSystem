#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Account.h"
using namespace std;

class Customer : public Person 
{
private:
    string telephone;
    string address;
    Account* custAccount; 
public:
    Customer(string telephone, string address, string firstname, string lastname, int age, Account* a);
    Customer(string telephone, string firstname, string lastname, Account* a);
    string getTelephone();
    void setTelephone(string telephone);
    string getAddress();
    void setAddress(string address);
    void regis(string username, string password, string name, string address, string telephone);
};

#endif