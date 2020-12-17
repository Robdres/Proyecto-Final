//
//  Grade.hpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#ifndef Grade_hpp
#define Grade_hpp

#include <stdio.h>

class Grade{
private:
    float nota;
    char letra;
public:
    Grade();
    Grade(float);
    void setNota(float);
    float getNota();
    char getLetra();
    int getValue();
};

#endif /* Grade_hpp */
