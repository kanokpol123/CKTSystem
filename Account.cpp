#include "Account.h"
using namespace std;

Account::Account(string perivilege, string username, string password)
{
    this->privilege = privilege;
    this->username = username;
    this->password = password;
}

string Account::getUsername(){
    
}
void Account::setUsername(string user){
    
}

string Account::getPassword(){
    
}

void Account::setPassword(string pass){

}

string Account::getSignedDate(){
    
}

void Account::setSignedDate(string date){

}

string Account::getAddress(){
    
}

void Account::setAddress(string address){

}

string Account::getPrivilege(){
    
}

void Account::setPrivilege(char privilege){

}

void Account::login(string user, string pass){
    login:
    cout << "=== Login ===" << endl;
    cout << "Enter username :";

    cout << "Enter password :";

    cout << "=============" << endl;

    if(false){
        cout<< "Please login again!!!"<<endl;
        goto login;
    }
}