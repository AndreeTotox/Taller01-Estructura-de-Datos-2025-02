#include "Node.h"
#include "Student.h"
#include "Course.h"

NodeStudent::NodeStudent(Student* data){
    this->value = data;
    this->next = nullptr;
}

void NodeStudent::setNext(NodeStudent* next) {
    this->next = next;
}
