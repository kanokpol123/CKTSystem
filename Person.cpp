#include "Person.h"
Person::Person(string firstname, string lastname, int age)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->age = age;
};
string Person::getFirstName() {return firstname;}
string Person::getLastName() {return lastname;}
int Person::getAge() {return age;}
void Person::setFirstName(string firstname) {this->firstname = firstname;}
void Person::setLastName(string lastname) {this->lastname = lastname;}
void Person::setAge(int age) {this->age = age;}