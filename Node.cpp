#include "Node.h"
#include "Student.h"
#include "Course.h"

NodeStudent::NodeStudent(Student* data){
    this->value = data;
    this->next = nullptr;
}

Student* NodeStudent::getValue() {
    return this->value;
}

void NodeStudent::setValue(Student* value) {
    this->value = value;

}

NodeStudent* NodeStudent::getNext() {
    return this->next;
}

void NodeStudent::setNext(NodeStudent* next) {
    this->next = next;
}

NodeStudent::~NodeStudent() {

}

NodeCourse::NodeCourse(Course* data) {
    this->value = data;
    this->next = nullptr;
}

Course* NodeCourse::getValue() {
    return this->value;
}

void NodeCourse::setValue(Course* data) {
    this->value = data;
}

NodeCourse* NodeCourse::getNext() {
    return this->next;
}

void NodeCourse::setNext(NodeCourse* next) {
    this->next = next;
}

NodeCourse::~NodeCourse() {
    //This destroys!
}

NodeSigned::NodeSigned(Student* student, Course* course) {
    this->student = student;
    this->course = course;
    grades = new GradesList();
    next = nullptr;
}

Student* NodeSigned::getStudent() {
    return student;
}

Course* NodeSigned::getCourse() {
    return course;
}

NodeSigned* NodeSigned::getNext() {
    return this->next;
}

void NodeSigned::setNext(NodeSigned* next) {
    this->next = next;
}

GradesList* NodeSigned::getGrades() {
    return grades;
}


NodeSigned::~NodeSigned() {
    delete grades;
}

NodeGrades::NodeGrades(double data) {
    value = data;
    next = nullptr;
}

double NodeGrades::getValue() {
    return value;
}

void NodeGrades::setValue(double data) {
    value = data;
}

NodeGrades* NodeGrades::getNext() {
    return next;
}

void NodeGrades::setNext(NodeGrades* next) {
    this->next = next;
}

NodeGrades::~NodeGrades() {
    
}
