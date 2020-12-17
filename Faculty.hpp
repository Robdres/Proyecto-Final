//
//  Faculty.hpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#ifndef Faculty_hpp
#define Faculty_hpp
//=================================
// forward declared dependencies
class Course;

#include <stdio.h>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
#include "ArrayList.hpp"

class Faculty : public User{
private:
    std::string carrera;
    ArrayList<Course*> cursos;
    int totalCursos;
public:
    Faculty();
    Faculty(std::string, std::string, std::string, std::string, std::string, std::string);
    void setCarrera(std::string);
    void setCursos(ArrayList<Course*>, int);
    std::string getCarrera();
    ArrayList<Course*> getCursos();
    void addClass(Course*);
    std::string to_string() override;
};

#endif /* Faculty_hpp */
