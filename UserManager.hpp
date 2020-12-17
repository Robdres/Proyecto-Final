
#ifndef UserManager_hpp
#define UserManager_hpp
#include "User.hpp"
#include <stdio.h>
#include <string>
#include "User.hpp"
#include "StudentManager.hpp"
#include "FacultyManager.hpp"
#include "ArrayList.hpp"
#include <deque>
#include <queue>


class FacultyManager;
class StudentManager;

class UserManager{
private:
    User* usuarios;
    StudentManager* sm;
    FacultyManager* fm;
public:
    UserManager(FacultyManager*, StudentManager*);
    User* validateCredentials(std::string, std::string);
    void editUser(User*);
    void showUser(User*);
    std::string getNewBannerID();
    void addNewUser(User*);
};


#endif /* UserManager_hpp */
