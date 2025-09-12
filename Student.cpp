#include "Student.h"
#include "LinkedList.h"
#include "Course.h"
#include "Node.h"
#include <string>
#include <iostream>

Student::Student(int id, std::string name, std::string lastName, std::string career, std::string entryDate) {
    this->id = id;
    this->name = name;
    this->lastName = lastName;
    this->career = career;
    this->entryDate = entryDate;
}

int Student::getId() {
    return this->id;
}

std::string Student::getName() {
    return this->name;
}

std::string Student::getLastName() {
    return this->lastName;
}

std::string Student::getCareer() {
    return this->career;
}

std::string Student::getEntryDate() {
    return this->entryDate;
}




void Student::showInfo() {
    std::cout << "ID: " << id << ", Nombre: " << name << std::endl;
}

void Student::showAll() {
    std::cout << "ID: " << this->id << ", Nombre: " << this->name << ", Apellido: " << this->lastName << ", Carrera: " << this->career << ", Fecha de Ingreso: " << this->entryDate << std::endl;
    showCourses();
    std::cout << "-----------------" << std::endl;

}


Student::~Student() {

}
