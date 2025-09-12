#include "LinkedList.h"
#include "Course.h"
#include "Node.h"
#include <string>
#include <iostream>

Course::Course(int id, std::string name, int maxStudents, std::string career, std::string teacher) {
    this->id = id;
    this->name = name;
    this->maxStudents = maxStudents;
    signedStudents = 0;
    available = true;
    this->career = career;
    this->teacher = teacher;
}

int Course::getId() {
    return id;
}

std::string Course::getName() {
    return name;
}
int Course::getMaxStudents() {
    return maxStudents;
}

int Course::getSigned() {
    return signedStudents;
}

bool Course::addSigned() {
    if (signedStudents >= maxStudents) {
        return false;
    }

    signedStudents++;

    available = (signedStudents < maxStudents);
}

bool Course::removeSigned() {
    if (signedStudents <= 0) {
        return false;
    }

    signedStudents--;

    available = (signedStudents < maxStudents);

    return true;
}

bool Course::isAvailable() {
    return available;
}


std::string Course::getCareer() {
    return career;
}

std::string Course::getTeacher() {
    return teacher;
}

void Course::show() {
    std::cout << "ID: " << id << ", Nombre: " << name << ", Estudiantes inscritos: " << signedStudents << " / " << maxStudents << ", Carrera: " << career << ", Profesor: " << teacher << std::endl;
}

