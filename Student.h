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
    EnrollmentList* courses;
    
    public:
    Student(int id, std::string name, std::string lastName, std::string career, std::string entryDate);
    int getId();
    std::string getName();
    std::string getLastName();
    std::string getCareer();
    std::string getEntryDate();
    EnrollmentList* getCourses();
    void addCourse(Course* course);
    void removeCourse(int id);
    void show();
    void showCourses();

    ~Student();


};