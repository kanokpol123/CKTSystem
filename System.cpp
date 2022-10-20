#include "System.h"
void System::readUserFile()
{
    string privilege, username, password, firstname, lastname, telephone; 
    string line;
    ifstream myfile;
    myfile.open("User.txt",ios::in);
    if(myfile.fail())
    {
        cout << "Can't open user file." << endl;
    }
    else
    {
        while(getline(myfile,line))
        {
            privilege = line.substr(0,line.find(','));
            line.erase(0,line.find(',')+ 1);
            username = line.substr(0,line.find(','));
            line.erase(0,line.find(',')+ 1);
            password = line.substr(0,line.find(','));
            line.erase(0,line.find(',')+ 1);
            firstname = line.substr(0,line.find(','));
            line.erase(0,line.find(',')+ 1);
            lastname = line.substr(0,line.find(','));
            line.erase(0,line.find(',')+ 1);
            telephone = line.substr(0,line.find(','));
            line.erase(0,line.find(',')+ 1);
            Account* tempA = new Account(privilege, username, password);
            Customer* tempC = new Customer(telephone, firstname, lastname, tempA);
            cusList.push_back(tempC);
        }
        myfile.close();
    }
}
void System::printUser()
{
    for (auto x : cusList)
    {
        cout << x->getFirstName() << " " << x->getLastName() << endl;
    }
}