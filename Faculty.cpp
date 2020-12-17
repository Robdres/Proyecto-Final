//
//  Faculty.cpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#include <iostream>
#include "Faculty.hpp"

Faculty::Faculty(){ }

Faculty::Faculty(std::string _bannerID, std::string _nombre, std::string _apellido, std::string _contrasenia, std::string _usuario, std::string _carrera):User(_bannerID, _nombre, _apellido, _contrasenia, _usuario), carrera(_carrera){
}

void Faculty::setCarrera(std::string _carrera){
    carrera = _carrera;
}

void Faculty::setCursos(ArrayList<Course*>_cursos, int _totalCursos){
    totalCursos = _totalCursos;
    cursos = _cursos;
}

std::string Faculty::getCarrera(){
    return carrera;
}

ArrayList<Course*> Faculty::getCursos(int & _totalCursos){
    _totalCursos = totalCursos;
    return cursos;
}

std::string Faculty::to_string(){
    return User::to_string() + "\t" + this->getCarrera();
}

void Faculty::addClass(Course* cursoNuevo){
	cursos.add(cursoNuevo);
}
