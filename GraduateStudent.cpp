//
//  GraduateStudent.cpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#include <iostream>
#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent(){ }

GraduateStudent::GraduateStudent(std::string _bannerID, std::string _nombre, std::string _apellido, std::string _contrasenia, std::string _usuario, std::string _carrera, std::string _nivel): Student(_bannerID, _nombre, _apellido, _contrasenia, _usuario, _carrera), nivel(_nivel){
}

void GraduateStudent::setNivel(std::string _nivel){
    nivel = _nivel;
}

std::string GraduateStudent::getNivel(){
    return nivel;
}

std::string GraduateStudent::to_string(){
    return Student::to_string() + " " + this->getNivel();
}
