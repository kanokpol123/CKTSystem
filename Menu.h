#include "Food.h"
using namespace std;

class Menu : public Food
{
private:
    int amountInMenu;
public:
    void addFood(Food newFood);
    void deleteFood(int index, string foodName);
    void showSearchFood(string foodName);
    int getAmountINMenu();
    void setAmountINMenu(int amount);
    void showAllMenu();
};