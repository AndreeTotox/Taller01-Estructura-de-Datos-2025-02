#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"

class Course {

    private:
    int id;
    std::string name;
    int maxStudents;
    int signedStudents;
    bool available;
    std::string career;
    std::string teacher;


    public:
    Course(int id, std::string name, int maxStudents, std::string career, std::string teacher);
    int getId();
    std::string getName();
    int getMaxStudents();
    int getSigned();
    bool addSigned();
    bool removeSigned();
    bool isAvailable();
    void setAvailable(bool status);
    std::string getCareer();
    std::string getTeacher();
    void show();

    ~Course();

    
};