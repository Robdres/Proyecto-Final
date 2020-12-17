#ifndef StudentManager_hpp
#define StudentManager_hpp
#include "Student.hpp"
#include <fstream>
#include "Proxy.hpp"
#include "UnderGraduateStudent.hpp"
#include "GraduateStudent.hpp"
#include "Student.hpp"
#include "UserManager.hpp"
#include "GraduateStudent.hpp"
#include <fstream>
#include <deque>
#include "Exceptions.hpp"

class UserManager;

class StudentManager{
private:
    std::deque<Student*> estudiantes;// tiene que ser un deque de punteros para poder hacer el cast
    std::string pathUndergraduate;
    void loadUnderGrads();
    std::string pathGraduate;
    void loadGrads();
    void updateUnderGrads();
    void updateGrads();
public:
    StudentManager(std::string, std::string);
    StudentManager(){};
    void createNewStudent(UserManager*);
    Student* getStudentByID(std::string);
    std::deque<Student*> getAllStudents();
    void editStudent();
    void editStudent(Student*);
    void editStudent(std::string);
    void showStudents();
    void showStudent(std::string);
    void showStudent(Student*);
    void deleteStudent(std::string);
    std::string generateReport(std::string);
};

#endif /* StudentManager_hpp */
