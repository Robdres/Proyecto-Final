//
//  Exceptions.hpp
//  997_Tarea02
//
//  Created by Daniel Riofrio on 22/11/20.
//

#ifndef Exceptions_hpp
#define Exceptions_hpp

#include <stdexcept>

class EmptyQueue: public std::runtime_error{
public:
    EmptyQueue(): std::runtime_error("The queue is empty"){}
};

class EmptyArrayList: public std::runtime_error{
public:
    EmptyArrayList(): std::runtime_error("The array list is empty"){}
};

class IndexOutOfBounds: public std::runtime_error{
public:
    IndexOutOfBounds(): std::runtime_error("Index out of bounds"){}
};

class BannerIDNotFound : public std::runtime_error{
public:
    BannerIDNotFound(): std::runtime_error("Banner ID not found"){}
};

class InvalidCredentials: public std::runtime_error{
public:
    InvalidCredentials():std::runtime_error("Invalid Credentials"){}
};

class NRCNotFound: public std::runtime_error{
public:
    NRCNotFound() : std::runtime_error("NRC Not Found"){}
};

class FileNotFound: public std::runtime_error{
public:
    FileNotFound(): std::runtime_error("File not found"){}
};

#endif /* Exceptions_hpp */
