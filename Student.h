#pragma once
#include <string>
#include <iostream>
#include "LinkedList.h"

class GradesList;
class CoursesList;
class StudentList;
class EnrollmentList;

class Student {

    private:
    int id;
    std::string name;
    std::string lastName;
    std::string career;
    std::string entryDate;
    
    public:
    Student(int id, std::string name, std::string lastName, std::string career, std::string entryDate);
    int getId();
    std::string getName();
    std::string getLastName();
    std::string getCareer();
    std::string getEntryDate();
    void showAll();
    void showInfo();

    ~Student();


};