#include <iostream>
#include "UserManager.hpp"
#include "Exceptions.hpp"

UserManager::UserManager(FacultyManager* _facultyManager, StudentManager* _studentManager){
	this->fm=_facultyManager;
	this->sm=_studentManager;
};

User* UserManager::validateCredentials(std::string userName, std::string contrasenia){


	std::deque<Student*> estudiantes=sm->getAllStudents();
	std::deque<Faculty> profesores=fm->getAllFaculty();

  	for(int i=0;i<estudiantes.size();i++){

		if(estudiantes[i]->getUsuario()==userName and estudiantes[i]->getContrasenia()==contrasenia){
			
    		return estudiantes[i];  	

     	}

 	}
 	for(int i=0;i<profesores.size();i++){

 		if(profesores[i].getUsuario()==userName and profesores[i].getContrasenia()==contrasenia){

 			return &profesores[i];

 		}

 	}
    throw InvalidCredentials();
};


void UserManager::editUser(User* usuarioAux)
{

	std::string usuario_,contrasenia_,nombre_,apellido_,option;
 
	std::cout<<"Que desea editar"<<std::endl;
	std::cout<<"1.Usuario\n2.Contrasenia\n3.Nombre\n4.Apellido"<<std::endl;
	std::cin>>option;

	if(option=="1"){
		std::cout<<"Usuario Actual:    "<<usuarioAux->getUsuario()<<std::endl;
		std::cout<<"Editar Usuario:"<<std::endl;
		std::cin>>usuario_;
		usuarioAux->setUsuario(usuario_);

	}else if(option=="2"){
		std::cout<<"Contrasenia Actual:    "<<usuarioAux->getContrasenia()<<std::endl;
		std::cout<<"Editar Contrasenia:"<<std::endl;
		std::cin>>contrasenia_;
		usuarioAux->setContrasenia(contrasenia_);
	}else if(option=="3"){
			std::cout<<"Nombre Actual:    "<<usuarioAux->getNombre()<<std::endl;
 		std::cout<<"Editar Nombre:"<<std::endl;
 		std::cin>>nombre_;
 		usuarioAux->setNombre(nombre_);
	}else if(option=="4"){
		std::cout<<"Apellido Actual:    "<<usuarioAux->getApellido()<<std::endl; 
 		std::cout<<"Editar Apellido:"<<std::endl;
 		std::cin>>apellido_;
 		usuarioAux->setApellido(apellido_);
	}else{
		std::cout<<"Ingrese una opcion correcta"<<std::endl;
		editUser(usuarioAux);
	}       
};

void UserManager::showUser(User* usuario)
{
    std::cout << usuario->to_string() << std::endl;
};

std::string UserManager::getNewBannerID(){
  	std::priority_queue<int> bannerID;
  	std::deque<Student*> estudiantes= sm->getAllStudents();
  	std::deque<Faculty> profesores= fm->getAllFaculty();

  	for(int i=0;i<estudiantes.size();i++){
  		bannerID.push(stoi(estudiantes[i]->getBannerID()));
  	}

  	for(int i=0;i<profesores.size();i++){
  		bannerID.push(stoi(profesores[i].getBannerID()));
  	}

  	int banMax=bannerID.top();
  	return std::to_string(banMax+1);
};

void UserManager::addNewUser(User* usuario){

}
