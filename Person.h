#include <string>
using namespace std;

class Person
{
private:
    string firstname;
    string lastname;
    int age;
public:
    Person(string firstname, string lastname, int age);
    string getFirstName();
    void setFirstName(string firstname);
    string getLastName();
    void setLastName(string lastname);
    int getAge();
    void setAge(int age);
};
