#include "Clerk.h"
Clerk::Clerk(string position, string firstname, string lastname, Account* a) : Person(firstname, lastname)
{
    this->position = position;
    this->clerkAccount = a;
}
Account* Clerk::getAccount() {return clerkAccount;};