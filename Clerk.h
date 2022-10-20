#include "Person.h"
#include "Account.h"
using namespace std;

class Clerk : public Person
{
private:
    string position;
    Account* clerkAccount;
public:
    Clerk(string position, string firstname, string lastname, Account* a);
    Account* getAccount();
    void setPosition(string position);
    string getPosition();
};