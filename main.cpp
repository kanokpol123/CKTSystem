#include <iostream>
#include <iomanip>
#include <iterator>
#include "System.h"
using namespace std;

bool exceptionCatch(int min, int max, int choice)
{
    return (choice >= min && choice <= max);
}

int main()
{
    System s;
    int choice;
    string username, password;
    mainMenu :
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Lottery BUU" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "1. Login\n"
            "2. Register\n"
            "3. Forget password\n"
            "0. Exit" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Choose Menu : ";
    cin >> choice;

    if (!cin >> choice || !exceptionCatch(1, 3, choice))
    {
        cout << "Choice must be 1-3" << endl;
        cout << "Plseas try again" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        goto mainMenu;
    }

    if (choice == 1)
    {
        int nMax = 0;
        do
        {
            cout << setfill('=') << setw(10) << "=" << " LOGIN " 
                << setfill('=') << setw(11) << "=\n";
            cout << "Username : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;
            if (s.login(username, password) == "NotFound")
            {
                cout << "Not found!" << endl;
                nMax++;
                if (nMax == 3)
                {
                    cout << "Plseas try again later" << endl;
                    goto mainMenu;
                }
            }
            else
            {
                cout << s.login(username, password) << endl;
                if (s.login(username, password) == "Clerk")
                {
                    s.clerkInterface(username);
                }
                else if (s.login(username, password) == "Customer")
                {
                    s.custInterface(username);
                }
            }
        } while (s.login(username, password) == "NotFound");
        goto mainMenu;
    }
    else if (choice == 2)
    {
        string username, password, firstname, lastname, telephone;
        cout << "========== Register ==========" << endl;
        cout << "Username : ";
        cin >> username;
        cout << "Password : ";
        cin >> password;
        cout << "Firstname: ";
        cin >> firstname;
        cout << "Lastname : ";
        cin >> lastname;
        cout << "Telephone : ";
        cin >> telephone;
        s.regis(username, password, firstname, lastname, telephone);
        goto mainMenu;
    }
    return 0;
}