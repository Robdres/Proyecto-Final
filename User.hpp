//
//  User.hpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <string>

class User{
private:
    std::string bannerID;
    std::string nombre;
    std::string apellido;
    std::string contrasenia;
    std::string usuario;
public:
    User();
    User(std::string, std::string, std::string, std::string, std::string);
    void setBannerID(std::string);
    void setNombre(std::string);
    void setApellido(std::string);
    void setContrasenia(std::string);
    void setUsuario(std::string);
    std::string getBannerID();
    std::string getNombre();
    std::string getApellido();
    std::string getContrasenia();
    std::string getUsuario();
    virtual std::string to_string();
};

#endif /* User_hpp */
