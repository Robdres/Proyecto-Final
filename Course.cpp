//
//  Course.cpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#include "Course.hpp"
#include <iostream>
#include "Exceptions.hpp"

Course::Course(){ }

Course::Course(std::string _nrc, int totalCreditos):nrc(_nrc),totalCreditos(totalCreditos){
}

void Course::addStudentGrade(Student* student,Grade grade){
    this->estudiantes.push_back(student);
    notas.push_back(grade);
}

Grade* Course::getGradeByStudent(Student * estudiante){
    for(int i=0; i<totalEstudiantes; i++){
        if(estudiantes[i]->getBannerID() == estudiante->getBannerID()){
            return &notas[i];
        }
    }
    throw BannerIDNotFound();
}

Grade* Course::getGradeByStudent(std::string bannerId){
    for(int i=0; i<totalEstudiantes; i++){
        if(estudiantes[i]->getBannerID() == bannerId){
            return &notas[i];
        }
    }
    throw BannerIDNotFound();
}

std::deque<Student*> Course::getAllStudents(){
    return this->estudiantes;
}

std::deque<Grade> Course::getAllGrades(){
    return this->notas;
}

void Course::setProfesor(Faculty* _profesor){
    this->profesor = _profesor;
}

Faculty* Course::getProfesor(){
    return this->profesor;
}

int Course::getCreditos(){
    return this->totalCreditos;
}

void Course::setCreditos(int creditos){
    this->totalCreditos=creditos;

}


std::string Course::getNRC(){
    return nrc;
}

void Course::setNRC(std::string NRC_){
    this->nrc=NRC_;

}

std::string Course::getPath(){
    return path;
}

void Course::setPath(std::string path_){
    this->path=path_;
}

std::string Course::to_string(){

    return nrc+"\t"+std::to_string(totalCreditos)+" "+this->profesor->getNombre()+" "+this->profesor->getApellido();;
}
