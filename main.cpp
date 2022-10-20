#include <iostream>
#include <iomanip>
//#include <iterator>
//#include "Queue.h"
#include "Menu.h"
#include "System.h"
#include "Order.h"
#include "Payment.h"
#include "Queue.h"
using namespace std;

bool exceptionCatch(int min, int max, int choice)
{
    return (choice >= min && choice <= max);
}

int main()
{
    System s;
    Menu m;
    Queue resQueue;
    Payment pay;
    int choice;
    string username, password;
    mainMenu :
    //Queue q;
    //q.showQueue();
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Chicken Torch" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "1. Login\n"
            "2. Register\n"
            "0. Exit" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Choose Menu : ";
    cin >> choice;

    if (!cin >> choice || !exceptionCatch(0, 2, choice))
    {
        cout << "Choice must be 0-2" << endl;
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
                << setfill('=') << setw(11) << "=" << endl;
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
                Order myOrder(username);
                int option;
                interface :
                if (s.login(username, password) == "Customer")
                {
                    s.custInterface(username);
                    cout << "Choose Menu : ";
                    cin >> option;
                    if (!cin >> option || !exceptionCatch(0, 2, option))
                    {
                        cout << "Choice must be 0-2" << endl;
                        cout << "Plseas try again" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        goto interface;
                    }
                    if (option == 1) //Order Food
                    {
                        system("CLS");
                        m.showAllMenu();
                        customerOrder :
                        cout << setfill('=') << setw(34) << "=" << endl;
                        cout << "||        + Order food +        ||" << endl;
                        cout << setfill('=') << setw(34) << "=" << endl;
                        cout << "1. Show by decending price" << endl; // search by low to high price
                        cout << "2. Show by ascending price" << endl; // search by high to low price
                        cout << "0. Back" << endl; // back
                        cout << setfill('=') << setw(34) << "=" << endl;
                        int order;
                        int inputIndex = 0;
                        int inputQty;
                        cout << "Choose Menu : ";
                        cin >> order;
                        if (!cin >> order || !exceptionCatch(0, 2, order))
                        {
                            cout << "Choice must be 0-2" << endl;
                            cout << "Plseas try again" << endl;
                            cin.clear();
                            cin.ignore(1000, '\n');
                            goto customerOrder;
                        }

                        if (order == 1)
                        {
                            system("CLS");
                            cout << setfill('=') << setw(34) << "=" << endl;
                            cout << "Show menu by decending price" << endl;
                            cout << setfill('=') << setw(34) << "=" << endl;
                            m.SortDes();
                            m.showAllMenu();
                            cout << "Choose Food : ";
                            cin >> inputIndex;
                            cout << "Enter Quantity : ";
                            cin >> inputQty;
                            myOrder.orderFood(m.getFood(inputIndex), inputQty);
                            
                        }
                        else if (order == 2)
                        {
                            system("CLS");
                            cout << setfill('=') << setw(34) << "=" << endl;
                            cout << "Show menu by ascending price" << endl;
                            cout << setfill('=') << setw(34) << "=" << endl;
                            m.SortAsc();
                            m.showAllMenu();
                            cout << "Choose Food : ";
                            cin >> inputIndex;
                            cout << "Enter Quantity : ";
                            cin >> inputQty;
                            myOrder.orderFood(m.getFood(inputIndex), inputQty);
                        }
                        else if (order == 0)
                        {
                            goto interface;
                        }
                        goto interface;
                    }
                    else if (option == 2) //View my Order
                    {
                        system("CLS");
                        viewOrder :
                        myOrder.showMyOrder();
                        /*cout << setfill('=') << setw(34) << "=" << endl;
                        cout << "||      + view my order +       ||" << endl;
                        cout << setfill('=') << setw(34) << "=" << endl;*/
                        cout << "1. Confirm order" << endl; // search by type
                        cout << "2. Delete food (input quantity)" << endl; // search by low to high price
                        cout << "3. Clear my Order" << endl;
                        cout << "0. Back" << endl; // back
                        cout << setfill('=') << setw(34) << "=" << endl;
                        int inputIndex;
                        int inputQty;
                        int inputMoney;
                        int payment;
                        int view;
                        cout << "Choose Menu : ";
                        cin >> view;
                        if (!cin >> view || !exceptionCatch(0, 3, view))
                        {
                            cout << "Choice must be 0-3" << endl;
                            cout << "Plseas try again" << endl;
                            cin.clear();
                            cin.ignore(1000, '\n');
                            goto viewOrder;
                        }
                        if (view == 1)
                        {
                            system("CLS");
                            paymentMethod:
                            cout << setfill('=') << setw(34) << "=" << endl;
                            cout << "Confirm order" << endl;
                            cout << setfill('=') << setw(34) << "=" << endl;
                            cout << "Select Payment" << "\n"
                                 << "1.Transfer money" << "\n"
                                 << "2.Cash on delivery\n" 
                                 << "3.Back" << endl;
                            cout << "Choose Menu : ";
                            cin >> payment;

                            if(payment == 1){
                                transfer:
                                cout << "Your Total Payment : " << myOrder.getOrderDetail()->getPayTotal() << endl;
                                cout << "Enter Money : ";
                                cin >> inputMoney;
                                if(pay.pay(inputMoney, myOrder.getOrderDetail()->getPayTotal())){
                                    cout << "Your order is now added to queue!" << endl;
                                    resQueue.enQueue(myOrder);
                                    myOrder.clearOrder();
                                }else{
                                    int choice;
                                    cout << "Your money are not equal with your total pay\n"
                                         << "Please try again." << endl;
                                    cout << "1.I want change my payment method\n"
                                         << "2.I want to try again" << endl;
                                    cout << "Choose Menu : ";
                                    cin >> choice;
                                    
                                    if(choice == 1){
                                        goto paymentMethod;
                                    }else if(choice == 2){
                                        goto transfer;
                                    }
                                }
                            }else if(payment == 2){
                                cout << "Your order is now added to queue!" << endl;
                                resQueue.enQueue(myOrder);
                                myOrder.clearOrder();
                            }

                        }
                        if (view == 2)
                        {
                            system("CLS");
                            myOrder.showMyOrder();
                            cout << setfill('=') << setw(34) << "=" << endl;
                            cout << "Delete food (input quantity)" << endl;
                            cout << setfill('=') << setw(34) << "=" << endl;
                            cout << "Choose Food : ";
                            cin >> inputIndex;
                            cout << "Enter Quantity : ";
                            cin >> inputQty;
                            myOrder.getOrderDetail()->removeFood(inputIndex, inputQty);
                            goto viewOrder;
                        }
                        if (view == 3)
                        {
                            system("CLS");
                            cout << setfill('=') << setw(34) << "=" << endl;
                            cout << "Clear My Order" << endl;
                            cout << setfill('=') << setw(34) << "=" << endl;
                            myOrder.getOrderDetail()->clearMyOrderDetail();
                            goto viewOrder;
                        }
                        else if (view == 0)
                        {
                            goto interface;
                        }
                        goto interface;
                    }
                    else if (option == 0) //Exit to main menu
                    {
                        goto mainMenu;
                    }
                }
                else if (s.login(username, password) == "Clerk")
                {
                    s.clerkInterface(username);
                    cout << "Choose Menu : ";
                    cin >> option;
                    if (!cin >> option || !exceptionCatch(0, 4, option))
                    {
                        cout << "Choice must be 0-4" << endl;
                        cout << "Plseas try again" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        goto interface;
                    }
                    if (option == 1) //Show Food
                    {
                        showFood :
                        cout << setfill('=') << setw(34) << "=" << endl;
                        cout << "||        + Show food +        ||" << endl;
                        cout << setfill('=') << setw(34) << "=" << endl;
                        cout << "1. Show by decending price" << endl; // search by low to high price
                        cout << "2. Show by ascending price" << endl; // search by high to low price
                        cout << "0. Back" << endl; // back
                        cout << setfill('=') << setw(34) << "=" << endl;
                        int show;
                        cout << "Choose Menu : ";
                        cin >> show;
                        if (!cin >> show || !exceptionCatch(0, 2, show))
                        {
                            cout << "Choice must be 0-2" << endl;
                            cout << "Plseas try again" << endl;
                            cin.clear();
                            cin.ignore(1000, '\n');
                            goto showFood;
                        }

                        if (show == 1)
                        {
                            system("CLS");
                            cout << setfill('=') << setw(34) << "=" << endl;
                            cout << "Show menu by decending price" << endl;
                            cout << setfill('=') << setw(34) << "=" << endl;
                            m.SortDes();
                            m.showAllMenu();
                        }
                        else if (show == 2)
                        {
                            system("CLS");
                            cout << setfill('=') << setw(34) << "=" << endl;
                            cout << "Show menu by ascending price" << endl;
                            cout << setfill('=') << setw(34) << "=" << endl;
                            m.SortAsc();
                            m.showAllMenu();
                        }
                        else if (show == 0)
                        {
                            goto interface;
                        }
                        goto interface;
                    }
                    else if (option == 2) //Show Queue
                    {
                        showQueue :
                        cout << setfill('=') << setw(34) << "=" << endl;
                        cout << "||        + show queue +        ||" << endl;
                        cout << setfill('=') << setw(34) << "=" << endl;
                        
                        resQueue.showQueue();
                        cout << "1. Remove lastest queue" << endl; // search by type
                        cout << "2. Remove by select queue" << endl; // search by low to high price
                        cout << "0. Back" << endl; // back
                        cout << setfill('=') << setw(34) << "=" << endl;
                        int inputIndex;
                        int show;
                        cout << "Choose Menu : ";
                        cin >> show;
                        if (!cin >> show || !exceptionCatch(0, 2, show))
                        {
                            cout << "Choice must be 0-2" << endl;
                            cout << "Plseas try again" << endl;
                            cin.clear();
                            cin.ignore(1000, '\n');
                            goto showQueue;
                        }
                        if (show == 1)
                        {
                            cout << setfill('=') << setw(34) << "=" << endl;
                            cout << "Remove latest queue" << endl;
                            cout << setfill('=') << setw(34) << "=" << endl;
                            resQueue.deQueueLastOrder();
                        }
                        if (show == 2)
                        {
                            cout << setfill('=') << setw(34) << "=" << endl;
                            cout << "Remove select queue" << endl;
                            cout << setfill('=') << setw(34) << "=" << endl;
                            cout << "Choose Queue : ";
                            cin >> inputIndex;
                            resQueue.deQueueByIndex(inputIndex);
                        }
                        else if (show == 0)
                        {
                            goto interface;
                        }
                        goto interface;
                    }
                    else if (option == 3) //Add food in menu
                    {
                        
                        string type;
                        string foodName;
                        string size;
                        string price;
                        cout << setfill('=') << setw(34) << "=" << endl;
                        cout << "Add food" << endl;
                        cout << setfill('=') << setw(34) << "=" << endl;
                        cout << "Enter Type : ";
                        cin >> type;
                        cout << "Enter Food Name : ";
                        cin >> foodName;
                        cout << "Enter Size : ";
                        cin >> size;
                        cout << "Enter Price : ";
                        cin >> price;
                        Food *temp = new Food(type, foodName, size, price);
                        m.addFood(temp);
                        cout << "Successfully Added" << endl;
                    }
                    else if (option == 4) //Remove food in menu
                    {
                        m.showAllMenu();
                        int index;
                        cout << setfill('=') << setw(34) << "=" << endl;
                        cout << "Select food want to delete" << endl;
                        cout << setfill('=') << setw(34) << "=" << endl;
                        cout << "Select Food : ";
                        cin >> index;
                        m.deleteFood(index);
                        cout << "Successfully removed" << endl;
                    }
                    else if (option == 0)
                    {
                        goto mainMenu;
                    }
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
    else if (choice == 0)
    {
        resQueue.updateFile(username);
    }
    return 0;
}