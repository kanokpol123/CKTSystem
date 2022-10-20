#include "Food.h"
#include <vector>
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
    vector <Food*> getMenuList();
    void readMenuFile();
    void addFood(Food* newFood);
    void deleteFood(int index, string foodName);
    void showSearchFood(string foodName);
    int getAmountINMenu();
    void setAmountINMenu(int amount);
    void showAllMenu();
};