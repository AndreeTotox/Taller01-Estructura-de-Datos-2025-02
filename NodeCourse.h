#pragma once
#include "Course.h"

class NodeCourse {

    private:
    Course value;
    NodeCourse* next;

    public:

    NodeCourse(Course& data);
    Course& getValue();

    void setValue(Course data);

    NodeCourse* getNext();

    void setNext(NodeCourse* next);

    ~NodeCourse() {
        //This is a destructor too
    }


};