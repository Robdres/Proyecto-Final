//
//  UnderGraduateStudent.hpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#ifndef UnderGraduateStudent_hpp
#define UnderGraduateStudent_hpp

#include <stdio.h>
#include "Student.hpp"
#include "Proxy.hpp"

class UnderGraduateStudent : public Student{
private:
    Proxy representante;
public:
    UnderGraduateStudent();
    virtual ~UnderGraduateStudent();
    UnderGraduateStudent(std::string, std::string, std::string, std::string, std::string, std::string, Proxy);
    void setRepresentante(Proxy);
    Proxy getRepresentante();
    std::string to_string() override;
};

#endif /* UnderGraduateStudent_hpp */
