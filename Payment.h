#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Payment
{
private:
    int total;
    string payDate;
    string payTime;
public:
    bool pay(int money, int total);
    string getDate();
    string getTime();
};