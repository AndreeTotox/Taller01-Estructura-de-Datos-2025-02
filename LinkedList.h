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
    void search(std::string name);
    void search(int id);
    bool remove(int id);
    bool isEmpty();

    ~StudentList();

};

class CoursesList {

    private:
    NodeCourse* head;

    public:
    CoursesList();
    NodeCourse* getHead();
    bool addCourse(Course* head);
    bool remove(int id);
    bool isEmpty();


    ~CoursesList();

};

class GradesList {

};