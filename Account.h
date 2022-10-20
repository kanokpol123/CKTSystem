#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
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
    Account(string privilege, string username, string password);
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
};

#endif