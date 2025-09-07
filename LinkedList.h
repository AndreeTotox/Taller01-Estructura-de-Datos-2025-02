#pragma once
#include "Node.h"
#include "Student.h"
#include "Course.h"

class StudentList {

    private:
    NodeStudent* head;

    public:
    StudentList();
    NodeStudent* getHead();
    void addStudent(Student* student);
    bool remove(int id);
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
    bool remove(int id);
    bool isEmpty();


    ~CoursesList();

};

class GradesList {

};