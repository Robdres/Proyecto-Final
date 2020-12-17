//
//  User.cpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#include <iostream>
#include "User.hpp"

User::User(){ }

User::User(std::string _bannerID, std::string _nombre, std::string _apellido, std::string _contrasenia, std::string _usuario):
bannerID(_bannerID), nombre(_nombre), apellido(_apellido), contrasenia(_contrasenia), usuario(_usuario)
{
}

void User::setBannerID(std::string _bannerID){
    bannerID = _bannerID;
}

void User::setNombre(std::string _nombre){
    nombre = _nombre;
}

void User::setApellido(std::string _apellido){
    apellido = _apellido;
}

void User::setContrasenia(std::string _contrasenia){
    contrasenia = _contrasenia;
}

void User::setUsuario(std::string _usuario){
    usuario = _usuario;
}

std::string User::getBannerID(){
    return bannerID;
}

std::string User::getNombre(){
    return nombre;
}

std::string User::getApellido(){
    return apellido;
}

std::string User::getContrasenia(){
    return contrasenia;
}

std::string User::getUsuario(){
    return usuario;
}


std::string User::to_string(){
    return this->getBannerID() + "\t" + this->getNombre() + "\t" + this->getApellido() + "\t" + this->getUsuario() + "\t" + this->getContrasenia();
}
