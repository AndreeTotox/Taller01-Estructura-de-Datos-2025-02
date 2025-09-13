#pragma once
#include "Course.h"
#include "Student.h"
#include "LinkedList.h"


class NodeStudent {

    private:
    Student* value;
    NodeStudent* next;

    public:

    NodeStudent(Student* data);
    Student* getValue();

    void setValue(Student* data);

    NodeStudent* getNext();

    void setNext(NodeStudent* next);

    ~NodeStudent();
        //This is a destructor
    


};

class NodeCourse {

    private:
    Course* value;
    NodeCourse* next;

    public:

    NodeCourse(Course* data);
    Course* getValue();

    void setValue(Course* data);

    NodeCourse* getNext();

    void setNext(NodeCourse* next);

    ~NodeCourse();
        //This is a destructor too
    


};

class NodeGrades {

    private:
    double value;
    NodeGrades* next;

    public:
    NodeGrades(double data);
    double getValue();
    void setValue(double data);
    NodeGrades* getNext();
    void setNext(NodeGrades* next);

    ~NodeGrades();

};


class NodeSigned {

    private:
    Student* student;
    Course* course;
    GradesList* grades;
    NodeSigned* next;

    public:
    NodeSigned(Student* student, Course* course);
    Course* getCourse();
    Student* getStudent();
    NodeSigned* getNext();
    void setNext(NodeSigned* next);
    GradesList* getGrades();
    void addGrade(double grade);

    ~NodeSigned();


};