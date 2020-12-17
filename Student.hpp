//
//  Student.hpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

//=================================
// forward declared dependencies
class Course;

#include <stdio.h>
#include <string>
#include "User.hpp"
#include "Course.hpp"
#include "ArrayList.hpp"

class Student : public User{
private:
    std::string carrera;
    ArrayList<Course*> clases;
    int totalClases;
    float gpa{0};
public:
    Student();
    virtual ~Student();
    Student(std::string, std::string, std::string, std::string, std::string, std::string);
    void setCarrera(std::string);
    void calculateGPA();
    void addClass(Course*);
    std::string getCarrera();
    ArrayList<Course*> getClases();
    float getGPA();
    std::string to_string() override;
};

#endif /* Student_hpp */
