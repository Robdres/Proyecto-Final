
#include "Course.hpp"
#include "StudentManager.hpp"
#include "FacultyManager.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include <iomanip>
#include <fstream>
#include "Grade.hpp"
#include "Exceptions.hpp"
#include "ArrayList.hpp"


#ifndef CourseManager_hpp
#define CourseManager_hpp
#include <iostream>
#include "Course.hpp"

class StudentManager;
class FacultyManager;

class CourseManager{
private:
    ArrayList<Course*> cursos;
    int numCursos;
    std::string pathCursos;
    StudentManager* sm;
    FacultyManager* fm;
    void loadCourses();
    void updateCourses();
public:
    CourseManager(std::string,StudentManager*, FacultyManager*);
    void createNewCourse();
    void editCourse();
    void showCourses();
    void showClassByID(std::string);
    void deleteCourse(std::string);

    Course* getCourseByNRC(std::string);
    
};

#endif /* CourseManager_hpp */
