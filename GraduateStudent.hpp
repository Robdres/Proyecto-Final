//
//  GraduateStudent.hpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#ifndef GraduateStudent_hpp
#define GraduateStudent_hpp

#include <stdio.h>
#include <string>
#include "Student.hpp"

class GraduateStudent: public Student{
private:
    std::string nivel;
public:
    GraduateStudent();
    GraduateStudent(std::string, std::string, std::string, std::string, std::string, std::string, std::string);
    void setNivel(std::string);
    std::string getNivel();
    std::string to_string() override;
};

#endif /* GraduateStudent_hpp */
