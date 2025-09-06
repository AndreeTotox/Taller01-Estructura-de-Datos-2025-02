#pragma once
#include <string>
#include <iostream>

class Student {

    private:
    int id;
    std::string name;
    std::string lastName;
    std::string career;
    std::string entryDate;
    
    public:
    int getId();
    std::string getName();
    std::string getLastName();
    std::string getCareer();
    std::string getEntryDate();



};