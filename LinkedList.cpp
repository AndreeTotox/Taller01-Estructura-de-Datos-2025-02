#include <string>
#include "LinkedList.h"
#include "Student.h"
#include "Course.h"

StudentList::StudentList() {
    head = nullptr;
}

NodeStudent* StudentList::getHead() {
    return head;
}

void StudentList::addStudent(Student* student) {
    NodeStudent* studentNode = new NodeStudent(student);
    if (isEmpty()) {
        head = studentNode;
        return;
    }
    NodeStudent* cursor = head;
    while (cursor->getNext() != nullptr)
    {
        cursor = cursor->getNext();
    }

    cursor->setNext(studentNode);
    
}

bool StudentList::remove(int id, EnrollmentList* enrolls) {
    if (isEmpty()) { 
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
            enrolls->removeStudent(current->getValue()->getId());

            delete current;
            return true;
        }
        previous = current;
        current = current->getNext();

    }

    return false;
}

void StudentList::search(std::string name) {
    NodeStudent* current = head;
    if (isEmpty()){
        std::cout << "No hay alumnos registrados en la lista" << std::endl;
        return;
    } else {
        while (current != nullptr) {
            if (current->getValue()->getName() == name) {
                current->getValue()->showAll();
            }
            current = current->getNext();
        }
    }

}

void StudentList::search(int id) {
    NodeStudent* current = head;
    if (isEmpty()){
        std::cout << "No hay alumnos registrados en la lista" << std::endl;
        return;
    } else {
        while (current != nullptr) {
            if (current->getValue()->getId() == id) {
                current->getValue()->showAll();
                return;
            }
            current = current->getNext();
        }
    }

}

bool StudentList::verifyId(int id) {

    NodeStudent* cursor = head;
    while (cursor != nullptr) {
        if (cursor->getValue()->getId() == id) {
            return true;
        }
        cursor = cursor->getNext();
    }

    return false;

}

Student* StudentList::getStudent(int id) {
    NodeStudent* cursor = head;
    while (cursor != nullptr) {
        if (cursor->getValue()->getId() == id) {
            return cursor->getValue();
        }
        cursor = cursor->getNext();
    }

    return nullptr;

}


bool StudentList::isEmpty() {
    if (head == nullptr) {
        return true;
    }
    return false;
}

void StudentList::showInfo() {
    if (isEmpty()) {
        std::cout << "No hay estudiantes registrados en el sistema" << std::endl;
        return;
    }

    NodeStudent* cursor = head;
    while (cursor != nullptr) {
        cursor->getValue()->showInfo();
        cursor = cursor->getNext();
    }
}

StudentList::~StudentList() {
    NodeStudent* current = head;
    while (current != nullptr) {
        NodeStudent* temp = current;

        Student* valueTemp = current->getValue();

        current = current->getNext();
        delete valueTemp;

        delete temp;
    }

    head = nullptr;
}

CoursesList::CoursesList() {
    head = nullptr;
}

NodeCourse* CoursesList::getHead() {
    return head;
}

void CoursesList::addCourse(Course* data) {
    NodeCourse* courseNode = new NodeCourse(data);
    if (isEmpty()) {
        head = courseNode;
        return;
    }
    NodeCourse* cursor = head;
    while (cursor->getNext() != nullptr)
    {
        cursor = cursor->getNext();
    }

    cursor->setNext(courseNode);

}

bool CoursesList::remove(int id, EnrollmentList* enrolls) {
    if (isEmpty()) { 
        return false;
    }
    NodeCourse* current = head;
    NodeCourse* previous = nullptr;
    while (current != nullptr) {
        if (current->getValue()->getId() == id) {
            if (previous == nullptr) {
                head = current->getNext();
            } else {
                previous->setNext(current->getNext());
            }
            enrolls->removeCourse(current->getValue()->getId());

            delete current;
            return true;
        }
        previous = current;
        current = current->getNext();

    }

    return false;
}

void CoursesList::search(std::string name) {
    NodeCourse* current = head;
    if (isEmpty()){
        std::cout << "No hay cursos registrados en la lista" << std::endl;
        return;
    } else {
        while (current != nullptr) {
            if (current->getValue()->getName() == name) {
                current->getValue()->show();
            }
            current = current->getNext();
        }
    }

}

void CoursesList::search(int id) {
    NodeCourse* current = head;
    if (isEmpty()){
        std::cout << "No hay cursos registrados en la lista" << std::endl;
        return;
    } else {
        while (current != nullptr) {
            if (current->getValue()->getId() == id) {
                current->getValue()->show();
                return;
            }
            current = current->getNext();
        }
    }

}

Course* CoursesList::getCourse(int id) {
    NodeCourse* cursor = head;
    while (cursor != nullptr) {
        if (cursor->getValue()->getId() == id) {
            return cursor->getValue();
        }
        cursor = cursor->getNext();
    }

    return nullptr;

}

bool CoursesList::verifyId(int id) {

    NodeCourse* cursor = head;
    while (cursor != nullptr) {
        if (cursor->getValue()->getId() == id) {
            return true;
        }
        cursor = cursor->getNext();
    }

    return false;

}

void CoursesList::showInfo() {
    if (isEmpty()) {
        std::cout << "No hay cursos registrados en el sistema" << std::endl;
        return;
    }

    NodeCourse* cursor = head;
    while (cursor != nullptr) {
        cursor->getValue()->show();
        cursor = cursor->getNext();
    }
}


bool CoursesList::isEmpty() {
    if (head == nullptr) {
        return true;
    }
    return false;
}

CoursesList::~CoursesList() {
    NodeCourse* current = head;
    while (current != nullptr) {
        NodeCourse* temp = current;

        Course* valueTemp = current->getValue();

        current = current->getNext();
        delete valueTemp;

        delete temp;
    }

    head = nullptr;

}

EnrollmentList::EnrollmentList() {
    head = nullptr;
}

NodeSigned* EnrollmentList::getHead() {
    return head;
}

void EnrollmentList::addEnroll(Student* s, Course* c) {
    NodeSigned* enrollNode = new NodeSigned(s,c);
    enrollNode->getCourse()->addSigned();
    if (isEmpty()) {
        head = enrollNode;
        return;
    }
    NodeSigned* cursor = head;
    while (cursor->getNext() != nullptr)
    {
        cursor = cursor->getNext();
    }

    cursor->setNext(enrollNode);
    

}

bool EnrollmentList::remove(int idS, int idC) {
    if (isEmpty()) { 
        return false;
    }
    NodeSigned* current = head;
    NodeSigned* previous = nullptr;
    while (current != nullptr) {
        if (current->getStudent()->getId() == idS && current->getCourse()->getId() == idC) {
            if (previous == nullptr) {
                head = current->getNext();
            } else {
                previous->setNext(current->getNext());
            }
            current->getCourse()->removeSigned();

            delete current;
            return true;
        }
        previous = current;
        current = current->getNext();

    }

    return false;

}

void EnrollmentList::removeCourse(int id) {
    if (isEmpty()) { 
        return;
    }
    NodeSigned* current = head;
    NodeSigned* previous = nullptr;
    while (current != nullptr) {
        if (current->getCourse()->getId() == id) {
            NodeSigned* aux = current;
            if (previous == nullptr) {
                head = current->getNext();
            } else {
                previous->setNext(current->getNext());
            }
            
            current = current->getNext();
            delete aux;
        } else {
            previous = current;
            current = current->getNext();
        }
    }

}

void EnrollmentList::removeStudent(int id) {
    if (isEmpty()) { 
        return;
    }
    NodeSigned* current = head;
    NodeSigned* previous = nullptr;
    while (current != nullptr) {
        if (current->getStudent()->getId() == id) {
            NodeSigned* aux = current;
            if (previous == nullptr) {
                head = current->getNext();
            } else {
                previous->setNext(current->getNext());
            }
            current->getCourse()->removeSigned();
            
            current = current->getNext();
            delete aux;
        } else {
            previous = current;
            current = current->getNext();
        }
    }

}

bool EnrollmentList::isEmpty() {
    if (head == nullptr) {
        return true;
    }
    return false;
}

EnrollmentList::~EnrollmentList() {
    NodeSigned* current = head;
    while (current != nullptr) {
        NodeSigned* temp = current;
        current = current->getNext();
        delete temp;
    }

    head = nullptr;

}