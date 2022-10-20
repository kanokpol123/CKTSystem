#include "Payment.h"
string Payment::getDate()
{
    string day_txt, month_txt;
    time_t t = time(0);
    tm* now = localtime(&t);
    day_txt = to_string(now->tm_mday);
    month_txt = to_string(now->tm_mon + 1);
    (day_txt.length() == 1) ? day_txt = "0" + day_txt : day_txt;  
    (month_txt.length() == 1) ? month_txt = "0" + month_txt : month_txt; 
    return month_txt + '/' + day_txt + '/' + to_string(now->tm_year + 1900);
}
string Payment::getTime()
{
    time_t t = time(0);
    tm* now = localtime(&t); 
    return to_string(now->tm_hour) + ':' + to_string(now->tm_min);
}
bool Payment::pay(int money, int total)
{
    if (money == total)
    {
        payDate = getDate();
        payTime = getTime();
        return true;
    }
    return false;
}