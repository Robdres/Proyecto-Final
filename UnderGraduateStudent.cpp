//
//  UnderGraduateStudent.cpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#include "UnderGraduateStudent.hpp"
#include <iostream>

UnderGraduateStudent::UnderGraduateStudent(){ }

UnderGraduateStudent::UnderGraduateStudent(std::string _bannerID, std::string _nombre, std::string _apellido, std::string _contrasenia, std::string _usuario, std::string _carrera, Proxy _representante): Student(_bannerID, _nombre, _apellido, _contrasenia, _usuario, _carrera), representante(_representante){
}

void UnderGraduateStudent::setRepresentante(Proxy _representante){
    representante = _representante;
}

Proxy UnderGraduateStudent::getRepresentante(){
    return representante;
}

UnderGraduateStudent::~UnderGraduateStudent(){}

std::string UnderGraduateStudent::to_string(){
    return Student::to_string() + " " + this->getRepresentante().to_string();
}
