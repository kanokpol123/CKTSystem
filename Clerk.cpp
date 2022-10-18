#include "Clerk.h"
Clerk::Clerk(string position, string firstname, string lastname, int age) : Person(firstname, lastname, age)
{
    this->position = position;
}