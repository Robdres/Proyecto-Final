#ifndef FacultyManager_hpp
#define FacultyManager_hpp
#include "Faculty.hpp"
#include "UserManager.hpp"
#include <fstream>
#include <iostream>
#include <deque>

class UserManager;


class FacultyManager{
private:
    std::deque<Faculty> profesores;
    std::string pathFaculty;
    void loadFaculty();
    void updateFaculty();
public:
    ~FacultyManager();
    FacultyManager(std::string);//funciona
    FacultyManager(){};
    void createNewFaculty(UserManager*);//funciona
    Faculty* getFacultyByID(std::string);//funciona
    std::deque<Faculty> getAllFaculty();//funciona
    void editFaculty();//ya funciona
    void editFaculty(Faculty* );
    void editFaculty(std::string);
    void showFaculty(std::string);//funciona
    void showAllFaculties();//no era necesario hacia mas facil debugear
    void deleteFaculty(std::string);//funciona
    void deleteFaculty();//sobrecarga
};

#endif /* FacultyManager_hpp */
