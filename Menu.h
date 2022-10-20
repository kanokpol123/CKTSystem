#ifndef MENU_H
#define MENU_H

#include "Food.h"
#include <vector>
#include <iomanip>
#include <iterator>
#include <fstream>
using namespace std;

class Menu : public Food
{
private:
    int amountInMenu;
    vector <Food*> menuList;
    vector <Food*>::iterator itr;
public:
    Menu();
    vector <Food*> getMenuList();
    string getDate();
    string insertComma(string number);
    Food* getFood(int index);
    void readMenuFile();
    void addFood(Food* newFood);
    void deleteFood(int index);
    void showSearchFood(string foodName);
    int getAmountINMenu();
    void setAmountINMenu(int amount);
    void showAllMenu();
    void SortAsc();
    void SortDes();
    void updateMenu();
    void showOnlyChicken();
    Food* getChickenFood(int index);
    void showOnlySnack();
    Food* getSnackFood(int index);
};

#endif