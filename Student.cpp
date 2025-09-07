#include "LinkedList.h"
#include "Course.h"
#include <string>
#include <iostream>

Student::Student(int id, std::string name, std::string lastName, std::string career, std::string entryDate) {
    this->id = id;
    this->name = name;
    this->lastName = lastName;
    this->career = career;
    this->entryDate = entryDate;
}

