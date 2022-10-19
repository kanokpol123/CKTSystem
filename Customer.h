#include "Person.h"
#include "Account.h"
#include <list>
using namespace std;

class Customer : public Person 
{
private:
    string telephone;
    string address;
    Account* custAccount;
    list <Customer*> myList; 
public:
    Customer(string telephone, string address, string firstname, string lastname, int age, Account* a);

    string getTelephone();
    void setTelephone(string telephone);
    string getAddress();
    void setAddress(string address);
    void regis(string username, string password, string name, string address, string telephone);
};