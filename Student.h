#pragma once
#include <string>
#include <iostream>
#include "LinkedList.h"

class Student {

    private:
    int id;
    std::string name;
    std::string lastName;
    std::string career;
    std::string entryDate;
    CoursesList* courses;
    
    public:
    int getId();
    std::string getName();
    std::string getLastName();
    std::string getCareer();
    std::string getEntryDate();
    CoursesList* getCourses();
    



};