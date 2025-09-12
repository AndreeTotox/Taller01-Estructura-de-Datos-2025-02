#include <iostream>
#include <string>
#include <cctype>
#include "LinkedList.h"
#include "Node.h"
#include "Student.h"
#include "Course.h"

bool isNumber(std::string& str) {
    if (str.empty()) {
        return false;
    }
    for (char c : str) {
        if(!isdigit(c)) {
            return false;
        }
    }
    return true;

}

std::string askForData(std::string output) {
    std::string value;
    std::cout << output;
    std::getline(std::cin, value);
    std::cout << "\n";
    return value;
}

int main() {
    bool menu = true;
    std::string input;
    int choice;

    StudentList* students = new StudentList();
    CoursesList* courses = new CoursesList();
    EnrollmentList* enrolls = new EnrollmentList();

    while (menu) {
        std::cout << "--MENU PRINCIPAL--" << std::endl;
        std::cout << "1-. Gestion de alumnos" << std::endl;
        std::cout << "2-. Gestion de cursos" << std::endl;
        std::cout << "3-. Inscripciones" << std::endl;
        std::cout << "4-. Notas" << std::endl;
        std::cout << "5-. Reportes y Consulta" << std::endl;
        std::cout << "Seleccione su opcion con el numero correspondiente";
        std::getline(std::cin, input);
        std::cout << "\n";

        if(isNumber(input)) {
            choice = stoi(input);
        } else {
            std::cout << "Entrada invalida, ingrese un valor correspondiente." << std::endl;
            continue;
        }


        switch (choice)
        {
        case 1:
            std::cout << "MANEJO DE ALUMNOS" << std::endl;
            studentManagement(input, choice, students, enrolls);
            break;

        case 2:
            std::cout << "MANEJO DE CURSOS" << std::endl;
            courseManagement(input, choice, courses, enrolls);
            break;

        case 3:
            std::cout << "MANEJO DE INSCRIPCIONES" << std::endl;
            registering(input, choice, students, courses, enrolls);
            break;

        case 4:
            std::cout << "MANEJO DE NOTAS\n";
            break;

        case 5:
            std::cout << "REPORTES Y CONSULTA\n";
            break;

        case 6:
            std::cout << "Saliendo del programa...";
            menu = false;
            break;
        
        default:
        std::cout << "Ingrese un numero que este dentro de los parametros";
            break;
        }
    }


    delete enrolls;
    delete courses;
    delete students;


    return 0;
}

void studentManagement(std::string input, int choice, StudentList* students, EnrollmentList* enrolls) {
    std::cout << "----------------------" << std::endl;
    std::cout << "1-. Crear alumno" << std::endl;
    std::cout << "2-. Buscar alumno por ID" << std::endl;
    std::cout << "3-. Buscar alumno por nombre" << std::endl;
    std::cout << "4-. Eliminar alumno" << std::endl;
    std::cout << "Indique su eleccion con el numero correspondiente" << std::endl;
    std::cout << "Cualquier caso fuera de lugar lo llevara devuelta al menu principal: ";
    std::getline(std::cin, input);
    std::cout << "\n";

    if(isNumber(input)) {
        choice = stoi(input);
    } else {
        std::cout << "Regresando..." << std::endl;
        return;
    }

    switch (choice)
    {
    case 1: {
        int id;
        std::cout << "Ingrese el ID del alumno a agregar: ";
        std::getline(std::cin, input);
        std::cout << "\n";
        if (isNumber(input)){
            id = stoi(input);
        } else {
            std::cout << "FORMATO INVALIDO! Regresando..." << std::endl;
            return;
        }
        if (students->verifyId(id)) {
            std::cout << "ERROR: El id que trata de ingresar ya existe en el sistema" << std::endl;
            return;
        }
        std::string name = askForData("Ingrese el nombre del alumno a agregar: ");
        std::string lastName = askForData("Ingrese el apellido del alumno a agregar: ");
        std::string career = askForData("Ingrese la carrera del alumno a agregar: ");
        std::string day = askForData("Ingrese el dia del mes que ingreso a la universidad: ");
        std::string month = askForData("Ingrese el mes que ingreso a la universidad: ");
        std::string year = askForData("Ingrese el año del alumno a agregar: ");
        std::string entryDate = day + "/" + month + "/" + year;

        Student* s = new Student(id, name, lastName, career, entryDate);
        students->addStudent(s);
        std::cout << "Alumno agregado exitosamente" << std::endl;
        return;
    }

    case 2: {
        int id;

        std::cout << "Ingrese el ID del alumno a buscar: ";
        std::getline(std::cin, input);
        std::cout << "\n";
        if (isNumber(input)){
            id = stoi(input);
        } else {
            std::cout << "FORMATO INVALIDO! Regresando..." << std::endl;
            return;
        }
        students->search(id);
        return;

    }

    case 3: {
        std::string name = askForData("Ingrese el nombre del alumno a buscar: ");
        students->search(name);
        return;
    }

    case 4: {
        int id;

        std::cout << "Ingrese el ID del alumno a eliminar: ";
        std::getline(std::cin, input);
        std::cout << "\n";
        if (isNumber(input)){
            id = stoi(input);
        } else {
            std::cout << "FORMATO INVALIDO! Regresando..." << std::endl;
            return;
        }
        if (students->remove(id, enrolls)){
            std::cout << "El alumno a sido removido exitosamente!" << std::endl;
        } else {
            std::cout << "No se pudo remover al alumno debido a que el ID entregado no es valido o no existe" << std::endl;
        }
        return;

    }
    
    default:
        std::cout << "Regresando...";
        return;
    }



}

void courseManagement(std::string input, int choice, CoursesList* courses, EnrollmentList* enrolls) {
    std::cout << "----------------------" << std::endl;
    std::cout << "1-. Crear curso" << std::endl;
    std::cout << "2-. Buscar curso por ID" << std::endl;
    std::cout << "3-. Buscar curso por nombre" << std::endl;
    std::cout << "4-. Eliminar Curso" << std::endl;
    std::cout << "Indique su eleccion con el numero correspondiente" << std::endl;
    std::cout << "Cualquier caso fuera de lugar lo llevara al menu principal: ";
    std::getline(std::cin, input);
    std::cout << "\n";

    if(isNumber(input)) {
        choice = stoi(input);
    } else {
        std::cout << "Regresando..." << std::endl;
        return;
    }

    switch (choice)
    {
    case 1: {
        int id;
        std::cout << "Ingrese el ID del curso a agregar: ";
        std::getline(std::cin, input);
        std::cout << "\n";
        if (isNumber(input)){
            id = stoi(input);
        } else {
            std::cout << "FORMATO INVALIDO! Regresando..." << std::endl;
            return;
        }
        if (courses->verifyId(id)) {
            std::cout << "ERROR: El id que trata de ingresar ya existe en el sistema" << std::endl;
            return;
        }
        std::string name = askForData("Ingrese el nombre del curso a agregar: ");
        int maxStudents;
        std::cout << "Ingrese el numero maximo de estudiantes que se pueden registrar al curso: ";
        std::getline(std::cin, input);
        std::cout << "\n";
        if (isNumber(input)){
            id = stoi(input);
        } else {
            std::cout << "FORMATO INVALIDO!! Regresando..." << std::endl;
        }
        std::string career = askForData("Ingrese la carrera del alumno a agregar: ");
        std::string teacher = askForData("Ingrese el profesor que dicta la asignatura: ");

        Course* c = new Course(id, name, maxStudents, career, teacher);
        courses->addCourse(c);
        std::cout << "Curso agregado exitosamente" << std::endl;
        return;
    }

    case 2: {
        int id;

        std::cout << "Ingrese el ID del curso a buscar: ";
        std::getline(std::cin, input);
        std::cout << "\n";
        if (isNumber(input)){
            id = stoi(input);
        } else {
            std::cout << "FORMATO INVALIDO! Regresando..." << std::endl;
            return;
        }
        courses->search(id);
        return;
    }

    case 3: {
        std::string name = askForData("Ingrese el nombre completo del curso a buscar: ");
        courses->search(name);
        return;
    }

    case 4: {
        int id;
        std::cout << "Ingrese el ID del curso a eliminar: ";
        std::getline(std::cin, input);
        std::cout << "\n";
        if (isNumber(input)){
            id = stoi(input);
        } else {
            std::cout << "FORMATO INVALIDO! Regresando..." << std::endl;
            return;
        }
        if (courses->remove(id, enrolls)){
            std::cout << "El curso a sido removido exitosamente!" << std::endl;
        } else {
            std::cout << "No se pudo remover el curso debido a que el ID entregado no es valido o no existe" << std::endl;
        }
        return;
    }

    
    default:
        std::cout << "Regresando..." << std::endl;
        return;
    }

}

void registering(std::string input, int choice, StudentList* students, CoursesList* courses, EnrollmentList* enrolls) {
    std::cout << "------------------------" << std::endl;
    std::cout << "1-. Inscribir a un alumno a un curso" << std::endl;
    std::cout << "2-. Eliminar a un alumno de un curso" << std::endl;
    std::cout << "Ingrese su opcion con el numero correspondiente" << std::endl;
    std::cout << "(Cualquier parametro fuera de lugar lo devolvera al menu principal): ";
    std::getline(std::cin, input);
    std::cout << "\n";

    if (isNumber(input)) {
        choice = stoi(input);
    } else {
        std::cout << "ERROR DE FORMATO! Regresando..." << std::endl;
        return;
    }

    switch (choice)
    {
    case 1: {
        int id;
        students->showInfo();
        std::cout << "Ingrese el ID del alumno para inscripcion: " << std::endl;
        getline(std::cin, input);
        std::cout << "\n";
        if (isNumber(input)) {
            id = stoi(input);
        } else {
            std::cout << "FORMATO INVALIDO! Regresando..." << std::endl;
            return;
        }
        Student* s = students->getStudent(id);
        if (s == nullptr) {
            std::cout << "ID INVALIDO! Regresando..." << std::endl;
            return;
        }

        courses->showInfo();
        std::cout << "Ingrese el ID del curso a inscribir: ";
        std::getline(std::cin, input);
        std::cout << "\n";
        if (isNumber(input)) {
            id = stoi(input);
        } else {
            std::cout << "FORMATO INVALIDO! Regresando..." << std::endl;
            return;
        }
        Course* c = courses->getCourse(id);
        if (s == nullptr) {
            std::cout << "ID INVALIDO! Regresando..." << std::endl;
            return;
        }
        if (s->getCareer() != c->getCareer()) {
            std::cout << "ERROR! ALUMNO Y CURSO NO SON COMPATIBLES! DIFERENTES CARRERAS!" << std::endl;
            return;
        }

        enrolls->addEnroll(s,c);
        std::cout << "Proceso finalizado" << std::endl;
        return;
    }

    case 2: {
        int id;
        students->showInfo();
        std::cout << "Ingrese el ID del alumno: " << std::endl;
        getline(std::cin, input);
        std::cout << "\n";
        if (isNumber(input)) {
            id = stoi(input);
        } else {
            std::cout << "FORMATO INVALIDO! Regresando..." << std::endl;
            return;
        }
        Student* s = students->getStudent(id);
        if (s == nullptr) {
            std::cout << "ID INVALIDO! Regresando..." << std::endl;
            return;
        }

        courses->showInfo();
        std::cout << "Ingrese el ID del curso a renunciar: ";
        std::getline(std::cin, input);
        std::cout << "\n";
        if (isNumber(input)) {
            id = stoi(input);
        } else {
            std::cout << "FORMATO INVALIDO! Regresando..." << std::endl;
            return;
        }
        Course* c = courses->getCourse(id);
        if (s == nullptr) {
            std::cout << "ID INVALIDO! Regresando..." << std::endl;
            return;
        }

        if (enrolls->remove(s->getId(), c->getId())) {
            std::cout << "Alumno removido exitosamente" << std::endl;
            return;
        } else {
            std::cout << "Algo salio mal" << std::endl;
        }
    }
    
    default:
        std::cout << "Regresando..." << std::endl;
        return;
    }

}