#include <string>
#include "LinkedList.h"
#include "Student.h"
#include "Course.h"

StudentList::StudentList() {
    this->head = nullptr;
}

NodeStudent* StudentList::getHead() {
    return this->head;
}

void StudentList::addStudent(Student* student) {
    NodeStudent* studentNode = new NodeStudent(student);
    if (this->isEmpty()) {
        this->head = studentNode;
        return;
    }
    NodeStudent* cursor = this->head;
    while (cursor->getNext() != nullptr)
    {
        cursor = cursor->getNext();
    }

    cursor->setNext(studentNode);
    
}

bool StudentList::remove(int id) {
    if (this->isEmpty()) { 
        return false;
    }
    NodeStudent* current = head;
    NodeStudent* previous = nullptr;
    while (current != nullptr) {
        if (current->getValue()->getId() == id) {
            if (previous == nullptr) {
                head = current->getNext();
            } else {
                previous->setNext(current->getNext());
            }

            delete current;
            return true;
        }
        previous = current;
        current = current->getNext();

    }

    return false;
}


bool StudentList::isEmpty() {
    if (this->head == nullptr) {
        return true;
    }
    return false;
}

StudentList::~StudentList() {
    NodeStudent* current = head;
    while (current != nullptr) {
        NodeStudent* temp = current;

        Student* valueTemp = current->getValue();

        current = current->getNext();
        delete temp;

        delete valueTemp;
    }

    head = nullptr;
}