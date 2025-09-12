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
    bool remove(int id, EnrollmentList* enrolls);
    bool verifyId(int id);
    Student* getStudent(int id);
    void showInfo();
    bool isEmpty();

    ~StudentList();

};

class CoursesList {

    private:
    NodeCourse* head;

    public:
    CoursesList();
    NodeCourse* getHead();
    void addCourse(Course* head);
    void search(std::string name);
    void search(int id);
    bool remove(int id, EnrollmentList* enrolls);
    bool verifyId(int id);
    Course* getCourse(int id);
    void showInfo();
    bool isEmpty();


    ~CoursesList();

};

class EnrollmentList {

    private:
    NodeSigned* head;

    public:
    EnrollmentList();
    NodeSigned* getHead();
    void addEnroll(Student* s, Course* c);
    bool remove(int idS, int idC);
    void removeStudent(int id);
    void removeCourse(int id);
    bool isEmpty();

    ~EnrollmentList();
};

class GradesList {

    private:
    NodeGrades* head;

    public:
    GradesList();
    int size();

    ~GradesList();

};