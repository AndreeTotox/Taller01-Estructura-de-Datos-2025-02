#pragma once
#include "Course.h"
#include "Student.h"


class NodeStudent {

    private:
    Student* value;
    NodeStudent* next;

    public:

    NodeStudent(Student* data);
    Student* getValue();

    void setValue(Student& data);

    NodeStudent* getNext();

    void setNext(NodeStudent* next);

    ~NodeStudent() {
        //This is a destructor
    }


};

class NodeCourse {

    private:
    Course value;
    NodeCourse* next;

    public:

    NodeCourse(Course& data);
    Course& getValue();

    void setValue(Course& data);

    NodeCourse* getNext();

    void setNext(NodeCourse* next);

    ~NodeCourse() {
        //This is a destructor too
    }


};


class NodeSigned {

};