//
//  Student.cpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#include <iostream>
#include "Student.hpp"
#include "Grade.hpp"

Student::Student(){}
Student::~Student(){}

Student::Student(std::string _bannerID, std::string _nombre, std::string _apellido, std::string _contrasenia, std::string _usuario, std::string _carrera):User(_bannerID, _nombre, _apellido, _contrasenia, _usuario), carrera(_carrera)
{
}

void Student::setCarrera(std::string _carrera){
    carrera = _carrera;
}

void Student::addClass(Course curso){
    this->clases.add(curso);
}

float Student::getGPA(){
    return gpa;
}

std::string Student::getCarrera(){
    return carrera;
}

void Student::calculateGPA(){
    gpa = 0.0;
    for(int i=0; i<totalClases; i++){
        gpa = gpa + clases[i].getGradeByStudent(this)->getNota();
    }
    gpa = gpa / totalClases;
}

ArrayList<Course> Student::getClases(){
    return clases;
}

std::string Student::to_string(){
    return User::to_string() + " " + this->getCarrera();
}
