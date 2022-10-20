#include "Menu.h"

string Menu::getDate()
{
    string day_txt, month_txt;
    time_t t = time(0);
    tm* now = localtime(&t);
    day_txt = to_string(now->tm_mday);
    month_txt = to_string(now->tm_mon + 1);
    (day_txt.length() == 1) ? day_txt = "0" + day_txt : day_txt;  
    (month_txt.length() == 1) ? month_txt = "0" + month_txt : month_txt; 
    return month_txt + '/' + day_txt + '/' + to_string(now->tm_year + 1900);
}
string Menu::insertComma(string number)
{
    float temp_num = stof(number);
    string num_text = to_string(temp_num);
    string num = num_text.substr(0, num_text.find('.') + 3);
    int index = num.length() - 6;
    int check_negative = (temp_num >= 0) ? 0 : 1;
    while (index > check_negative)
    {
        num.insert(index, ",");
        index -= 3;
    }
    return num;
}
Menu::Menu()
{
    readMenuFile();
}
void Menu::SortAsc()
{
    for (const auto x : menuList)
    {
        for (const auto y : menuList)
        {
            if (stoi(x->getPrice()) > stoi(y->getPrice()))
            {
                swap(*x, *y);
            }
        }
    }
}
void Menu::SortDes(){
    for (const auto x : menuList)
    {
        for (const auto y : menuList)
        {
            if (stoi(x->getPrice()) < stoi(y->getPrice()))
            {
                swap(*x, *y);
            }
        }
    }
}
void Menu::readMenuFile()
{
    string typeOfFood, foodName, size, price; 
    string line;
    ifstream menuFile;
    menuFile.open("Menu.txt",ios::in);
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
void Menu::updateMenu(){
    ofstream myfile;
    myfile.open("Menu.txt",ios::out);
    if(myfile.fail())
    {
        cout << "Can't open user file." << endl;
    }
    else
    {
        for (const auto x : menuList)
        {
            myfile << x->getType() << "," << x->getFoodName() << "," << x->getSize() << "," << x->getPrice() << endl;
        }
        myfile.close();
    }
}
void Menu::addFood(Food* newFood)
{
    bool haveYet = true;
    for (const auto x : menuList)
    {
        if(newFood->getFoodName() == x->getFoodName() && newFood->getSize() == x->getSize())
        {
            cout << "This food already have in menu !!!" << endl;
            haveYet = false;
        }
    }
    if (haveYet)
    {
        Food* temp = new Food(newFood->getType(), newFood->getFoodName(), newFood->getSize(), newFood->getPrice());
        menuList.push_back(temp);
    }
    updateMenu();
}
void Menu::deleteFood(int index)
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
int Menu::getAmountINMenu()
{
    return menuList.size();
}
void Menu::showAllMenu()
{
    int i = 1;
    cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl
         << "|| No  |              Name               | Size |  Price  ||" << endl
         << setfill('=') << setw(60) << "=" << setfill(' ') << endl;
    for (const auto x : menuList)
    {
        cout << "|| " << setw(4) << left << to_string(i) + "." 
             << "| " << setw(32) << left << x->getFoodName()
             << "|   " << x->getSize() << "  "
             << "| " << setw(7) << insertComma(x->getPrice()) + ".-" << " ||" << endl;
             i++;
    }
    cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl;
}
Food* Menu::getFood(int index)
{
    int i = 1;
    itr = menuList.begin();
    while (itr != menuList.end())
    {
        if (index == i)
        {
            return (*itr);
        }
        i++;
        itr++;
    }
}

