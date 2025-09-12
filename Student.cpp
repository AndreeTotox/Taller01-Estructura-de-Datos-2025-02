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
    this->courses = new EnrollmentList();
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

EnrollmentList* Student::getCourses() {
    return this->courses;
}

void Student::addCourse(Course* course) {
    this->courses->addCourse(course);
}

void Student::removeCourse(int id) {
    if (this->courses->remove(id)) {
        std::cout << "Successfully removed course!" << std::endl;
    } else {
        std::cout << "Could Not Remove Course" << std::endl;
    }
}

void Student::showCourses() {

    NodeSigned* cursor = courses->getHead();
    std::cout << "Cursos Inscritos: " << std::endl;
    if (this->courses->isEmpty()) {
        std::cout << "No hay cursos inscritas";
    } else {
        while (cursor != nullptr) {
            Course* aux = cursor->getValue();
            std::cout << "-" << aux->getName() << std::endl;

            cursor = cursor->getNext();
        }
    
    }
    std::cout << std::endl;
}

void Student::show() {
    std::cout << "ID: " << this->id << ", Nombre: " << this->name << ", Apellido: " << this->lastName << ", Carrera: " << this->career << ", Fecha de Ingreso: " << this->entryDate << std::endl;
    this->showCourses();
    std::cout << "-----------------" << std::endl;

}


Student::~Student() {
    delete courses;
}
