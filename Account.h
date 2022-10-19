#include <iostream>
using namespace std;

class Account
{
private:
    string username;
    string password;
    string address;
    string sidnedDate;
    string privilege;
public:
    string getUsername();
    void setUsername(string sidnedDate);
    string getPassword();
    void setPassword(string password);
    string getSignedDate();
    void setSignedDate(string sidnedDate);
    string getAddress();
    void setAddress(string address);
    string getPrivilege();
    void setPrivilege(char privilege);
    void login(string username,string password);
};