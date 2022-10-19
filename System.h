#include <list>
#include "Customer.h"
using namespace std;

class System
{
private:
    list <Customer*> cusList;
public:
    void readUserFile();
};