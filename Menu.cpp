#include "Menu.h"
void Menu::readMenuFile()
{
    string typeOfFood, foodName, size, price; 
    string line;
    ifstream menuFile;
    menuFile.open("User.txt",ios::in);
    if(menuFile.fail())
    {
        cout << "Can't open user file." << endl;
    }
    else
    {
        while(getline(menuFile,line))
        {
            typeOfFood = line.substr(0,line.find(','));
            line.erase(0,line.find(',')+ 1);
            foodName = line.substr(0,line.find(','));
            line.erase(0,line.find(',')+ 1);
            size = line.substr(0,line.find(','));
            line.erase(0,line.find(',')+ 1);
            price = line.substr(0,line.find(','));
            line.erase(0,line.find(',')+ 1);
            Food* temp = new Food(typeOfFood, foodName, size, price);
            menuList.push_back(temp);
        }
        menuFile.close();
    }
}
vector <Food*> Menu::getMenuList() {return menuList;}

void Menu::addFood(Food* newFood)
{
    Food* temp = new Food(newFood->getType(), newFood->getFoodName(), newFood->getSize(), newFood->getPrice());
    menuList.push_back(temp);
}
void Menu::deleteFood(int index, string foodName)
{
    int i = 1;
    itr = menuList.begin();
    while (itr != menuList.end())
    {
        if (index == i)
        {
            menuList.erase(itr);
            break;
        }
        itr++;
    }
}
void Menu::showSearchFood(string foodName)
{

}
int Menu::getAmountINMenu()
{
    return menuList.size();
}
void Menu::setAmountINMenu(int amount)
{
    
}
void Menu::showAllMenu()
{
    
}