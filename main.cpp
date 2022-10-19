#include <map>
#include <iterator>
#include <iostream>
//#include "System.h"
using namespace std;
int main()
{
    //System s;
    //s.readUserFile();
    //s.printUser();
    
    map<string, int> myMap;
    string inputFood;
    cout << "Enter FoodName : " << endl;
    int qty = 0;
    for (int i = 0 ; i < 5 ; i++)
    {
        cin >> inputFood;
        qty = myMap[inputFood];
        qty++;
        myMap[inputFood] = qty;
        cout << myMap[inputFood] << endl;

    }
    cout << endl << endl;
    map<string, int>::iterator itr;


    itr = myMap.begin();
    while (itr != myMap.end())
    {
        cout << itr->first << " " << itr->second << endl;
        itr++;
    }
    cout << endl << endl;
    
    for(auto i : myMap){
        cout << i.first << " " << i.second << endl;
    }
    
    return 0;
}