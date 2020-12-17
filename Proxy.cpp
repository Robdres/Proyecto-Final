//
//  Proxy.cpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#include "Proxy.hpp"
#include <iostream>

Proxy::Proxy(){ }

Proxy::Proxy(std::string _nombre, std::string _apellido, std::string _email, std::string _numeroTelefonico):
nombre(_nombre), apellido(_apellido), email(_email), numeroTelefonico(_numeroTelefonico)
{
}

void Proxy::setNombre(std::string _nombre){
    nombre = _nombre;
}

void Proxy::setApellido(std::string _apellido){
    apellido = _apellido;
}

void Proxy::setEmail(std::string _email){
    email = _email;
}

void Proxy::setNumeroTelefonico(std::string _numeroTelefonico){
    numeroTelefonico = _numeroTelefonico;
}

std::string Proxy::getNombre(){
    return nombre;
}

std::string Proxy::getApellido(){
    return apellido;
}

std::string Proxy::getEmail(){
    return email;
}

std::string Proxy::getNumeroTelefonico(){
    return numeroTelefonico;
}

std::string Proxy::to_string(){
    return this->getNombre() + "\t" + this->getApellido() + "\t" + this->getEmail() + "\t" + this->getNumeroTelefonico();
}

