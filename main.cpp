#include <map>
#include <iterator>
#include <iostream>
#include <iomanip>
//#include "System.h"
using namespace std;
int main()
{
    //System s;
    //s.readUserFile();
    //s.printUser();
    
    map <pair<string, string>, int> myMap;
    string name, size; int qty = 0;
    int i = 0;
    while (i < 8)
    {
        cout << "Enter Name 'n' Size\n";
        cin >> name >> size;
        qty = myMap[make_pair(name, size)];
        qty++;
        myMap[make_pair(name, size)] = qty;
        i++;
    }
   
    cout << setfill('=') << setw(34) << "=" << setfill(' ') << endl
         << "||       Name      | Size | Qty ||" << endl
         << setfill('=') << setw(34) << "=" << setfill(' ') << endl;
    for (auto x : myMap)
    {
        cout << "|| " << setw(16) << left << x.first.first 
             << "| " << setw(5) << x.first.second 
             << "| " << setw(4) << x.second << "||" << endl;
    }
    cout << setfill('=') << setw(34) << "=" << setfill(' ') << endl;
    return 0;
}