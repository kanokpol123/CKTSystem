#include "Account.h"
using namespace std;

Account::Account(string privilege, string username, string password)
{
    this->privilege = privilege;
    this->username = username;
    this->password = password;
}
string Account::getUsername() {return username;}
void Account::setUsername(string user) {this->username = user;}
string Account::getPassword() {return password;}
void Account::setPassword(string pass) {this->password = pass;}
string Account::getSignedDate() {return sidnedDate;}
void Account::setSignedDate(string date) {this->sidnedDate = date;}
string Account::getAddress() {return address;}
void Account::setAddress(string address) {this->address = address;}
string Account::getPrivilege() {return privilege;}
void Account::setPrivilege(char privilege) {this->privilege = privilege;}
