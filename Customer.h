#include "Person.h"
using namespace std;

class Customer : public Person
{
private:
    string telephone;
    string address;
public:
    Customer(string telephone, string address, string firstname, string lastname, int age);
    string getTelephone();
    void setTelephone(string telephone);
    string getAddress();
    void setAddress(string address);
};