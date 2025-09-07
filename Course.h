#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"

class Course {

    private:
    int id;
    std::string name;
    int maxStudents;
    bool isAvaiable;
    std::string career;
    std::string teacher;


    public:
    Course(int id, std::string name, int maxStudents, std::string career, std::string teacher);

    ~Course();

    
};