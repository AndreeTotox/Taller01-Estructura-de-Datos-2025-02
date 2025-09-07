#pragma once
#include "Student.h"
#include "Course.h"

class StudentList {

    private:
    Student* head;

    public:
    StudentList();
    Student* getHead();
    void addStudent(Student* head);
    bool removeById(int id);
    bool removeByName(std::string name);
    bool isEmpty();

    ~StudentList();

};

class CoursesList {

    private:
    Course* head;

    public:
    CoursesList();
    Course* getHead();
    void addCourse(Course* head);
    bool removeById(int id);
    bool isEmpty();


    ~CoursesList();

};

class GradesList {

};