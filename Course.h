#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"

class Course {

    private:
    int id;
    std::string name;
    int maxStudents;
    bool avaiable;
    std::string career;
    std::string teacher;


    public:
    Course(int id, std::string name, int maxStudents, std::string career, std::string teacher);
    int getId();
    std::string getName();
    int getMaxStudents();
    void setMaxStudents();
    bool isAvaiable();
    void setAvaiable(bool status);
    std::string getCareer();
    std::string getTeacher();
    void setTeacher(std::string teacher);


    ~Course();

    
};