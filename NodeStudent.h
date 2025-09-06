#pragma once
#include "Student.h"

class NodeStudent {

    private:
    Student value;
    NodeStudent* next;

    public:

    NodeStudent(Student& data);
    Student& getValue();

    void setValue(Student data);

    NodeStudent* getNext();

    void setNext(NodeStudent* next);

    ~NodeStudent() {
        //This is a destructor
    }


};