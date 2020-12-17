//
//  Proxy.hpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#ifndef Proxy_hpp
#define Proxy_hpp

#include <stdio.h>
#include <string>

class Proxy{
private:
    std::string nombre;
    std::string apellido;
    std::string email;
    std::string numeroTelefonico;
public:
    Proxy();
    Proxy(std::string, std::string, std::string, std::string);
    void setNombre(std::string);
    void setApellido(std::string);
    void setEmail(std::string);
    void setNumeroTelefonico(std::string);
    std::string getNombre();
    std::string getApellido();
    std::string getEmail();
    std::string getNumeroTelefonico();
    std::string to_string();
};

#endif /* Proxy_hpp */
