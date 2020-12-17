//
//  Grade.cpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#include "Grade.hpp"
#include <iostream>

Grade::Grade(){ }

Grade::Grade(float _nota){
    setNota(_nota);
}

void Grade::setNota(float _nota){
    nota = _nota;
    if(nota >= 91 and nota <= 100){
        letra = 'A';
    }else{
        if(nota >= 81 and nota < 91){
            letra = 'B';
        }else{
            if(nota >= 71 and nota < 81){
                letra = 'C';
            }else{
                if(nota >= 61 and nota < 71){
                    letra = 'D';
                }else{
                    letra = 'F';
                }
            }
        }
    }
}

float Grade::getNota(){
    return nota;
}

char Grade::getLetra(){
    return letra;
}
