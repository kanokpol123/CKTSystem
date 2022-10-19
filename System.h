#include <list>
#include "Customer.h"
using namespace std;

class System
{
private:
    list <Customer*> cusList;
public:
    void readUserFile();
    void read_request(){
        string user1,rqmoney,status1,d11,d22;
        string line;
        ifstream myfile;
        string d = ",";
        myfile.open("..\\request top up.txt",ios::in);
        if(myfile.fail()){
            cout << "Can't open file" << endl;
        }else{
            while(getline(myfile,line)){
                user1 = line.substr(0,line.find(d));
                line.erase(0,line.find(d)+ d.length());
                rqmoney = line.substr(0,line.find(d));
                line.erase(0,line.find(d)+ d.length());
                status1 = line.substr(0,line.find(d));
                line.erase(0,line.find(d)+ d.length());
                d11 = line.substr(0,line.find(d));
                line.erase(0,line.find(d)+ d.length());
                d22 = line.substr(0,line.find(d));
                line.erase(0,line.find(d)+ d.length());

                add_request(user1,rqmoney,status1,d11,d22);
            }
            myfile.close();
        }
    }
};