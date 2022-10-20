#include "System.h"
System::System()
{
    readUserFile();
}
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
            if (privilege == "1")
            {
                Account* tempA = new Account(privilege, username, password);
                Customer* tempC = new Customer(telephone, firstname, lastname, tempA);
                cusList.push_back(tempC);
            }
            else if (privilege == "0")
            {
                Account* tempA = new Account(privilege, username, password);
                Clerk* tempCl = new Clerk("Waitress", firstname, lastname, tempA);
                clerkList.push_back(tempCl);
            }
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
list <Customer*> System::getCusList() {return cusList;}
list <Clerk*> System::getClerkList() {return clerkList;}
string System::login(string username, string password)
{
    for (const auto x : clerkList)
    {
        if(x->getAccount()->getUsername() == username && x->getAccount()->getPassword() == password)
        {
            return "Clerk";
        }
    }
    for (const auto x : cusList)
    {
        if(x->getAccount()->getUsername() == username && x->getAccount()->getPassword() == password)
        {
            return "Customer";
        }
    }
    return "NotFound";
}
void System::regis(string username, string password, string firstname, string lastname, string telephone)
{
    Account* tempA = new Account("1", username, password);
    Customer* tempC = new Customer(telephone, firstname, lastname, tempA);
    cusList.push_back(tempC);

    ofstream myfile;
    myfile.open("User.txt",ios::out);
    if(myfile.fail())
    {
        cout << "Can't open user file." << endl;
    }
    else
    {
        for (const auto x : clerkList)
        {
            myfile << x->getAccount()->getPrivilege() << "," 
                << x->getAccount()->getUsername() << ","
                << x->getAccount()->getPassword() << ","
                << x->getFirstName() << "," << x->getLastName() << ",-" << endl;
        }
        for (const auto x : cusList)
        {
            myfile << x->getAccount()->getPrivilege() << "," 
                << x->getAccount()->getUsername() << ","
                << x->getAccount()->getPassword() << ","
                << x->getFirstName() << "," << x->getLastName() << ","
                << x->getTelephone() << endl;
        }
        myfile.close();
    }
}
void System::custInterface(string username)
{
    for (const auto x : cusList)
    {
        if (x->getAccount()->getUsername() == username)
        {
            cout << setfill('=') << setw(27) << "=" << endl
                << "User" << endl
                << "Name : " << x->getFirstName() + " " + x->getLastName() << endl
                << setfill('=') << setw(10) << "=" << " Menu " 
                << setfill('=') << setw(11) << "=" << endl
                << "1. Order food" << endl
                << "2. View my order" << endl
                << "0. Logout" << endl
                << setfill('=') << setw(27) << "=" << endl;
            break;
        }
    }
}
void System::clerkInterface(string username)
{
    for (const auto x : clerkList)
    {
        if (x->getAccount()->getUsername() == username)
        {
            cout << setfill('=') << setw(27) << "=" << endl
                << "Waitress" << endl
                << "Name : " << x->getFirstName() + " " + x->getLastName() << endl
                << setfill('=') << setw(10) << "="  << " Menu " 
                << setfill('=') << setw(11) << "=" << endl
                << "1. Show food" << endl
                << "2. Show queue" << endl
                << "3. Add food in menu" << endl
                << "4. Delete food in menu" << endl
                << "0. Logout" << endl
                << setfill('=') << setw(27) << "=" << endl;
            break;
        }
    }
}

