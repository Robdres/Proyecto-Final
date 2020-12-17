//
//  Course.hpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#ifndef Course_hpp
#define Course_hpp

//=================================
// forward declared dependencies
class Student;
class Faculty;
#include <stdio.h>
#include <string>
#include "Student.hpp"
#include "Faculty.hpp"
#include "Grade.hpp"
#include <deque>

class Course{
private:
    std::string nrc{"-1"};
    Faculty *profesor;
    std::deque<Student*> estudiantes;
    std::deque<Grade*> notas;
    int totalEstudiantes{0};
    int totalCreditos{0};
    std::string path{""};
public:
    Course();
    Course(std::string, int);

    void addStudentGrade(Student*,Grade*);
    Grade *getGradeByStudent(Student*);
    Grade *getGradeByStudent(std::string);

    std::deque<Student*> getAllStudents();
    std::deque<Grade*> getAllGrades();

    void setProfesor(Faculty*);
    Faculty* getProfesor();

    void setCreditos(int);
    int getCreditos();

    void setNRC(std::string);
    std::string getNRC();
    
    void setPath(std::string);
    std::string getPath();

    std::string to_string();
   
};

#endif /* Course_hpp */
