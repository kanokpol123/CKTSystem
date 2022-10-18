#include "Person.h"
#include "Account.h"
using namespace std;

class Customer : public Person
{
private:
    string telephone;
    string address;
    Account custAccount;
public:
    Customer(string telephone, string address, string firstname, string lastname, int age);
    string getTelephone();
    void setTelephone(string telephone);
    string getAddress();
    void setAddress(string address);
    string regis(string username, string password, string name, string address, string telephone);
};