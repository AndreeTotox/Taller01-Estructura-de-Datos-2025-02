#pragma once
#include "Node.h"
#include "Student.h"
#include "Course.h"

class CourseList;
class StudentList;
class EnrollmentList;
class GradesList;
class NodeCourse;
class NodeStudent;
class NodeGrades;
class NodeSigned;
class Course;
class Student;

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
    void showCareerInfo(std::string career);
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
    NodeSigned* getData(int idS, int idC);
    void showStudentInfo(int id);
    double getGradeAverage(int idS, int idC);
    double getGradeAll(int id);
    bool isEmpty();

    ~EnrollmentList();
};

class GradesList {

    private:
    NodeGrades* head;

    public:
    GradesList();
    int size();
    void addGrade(double grade);
    double getAverage();
    bool isEmpty();

    ~GradesList();

};