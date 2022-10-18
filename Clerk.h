#include "Person.h"
using namespace std;

class Clerk : public Person
{
private:
    string position;
public:
    Clerk(string position, string firstname, string lastname, int age);
    void setPosition(string position);
    string getPosition();
};