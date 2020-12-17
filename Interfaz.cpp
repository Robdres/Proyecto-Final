#include "Interfaz.hpp"
#include "UserManager.hpp"

Interfaz::Interfaz(StudentManager* sm,FacultyManager* fm,CourseManager* cm,UserManager* um):sm(sm),fm(fm),cm(cm),um(um){

}

void Interfaz::pantallaInit(){
    std::string option;
    std::cout<<"Bienvenido al sistema de registro\nIngrese la opción que desea"<<std::endl;
    std::cout<<"1.Administrar Sistema\n2.Acceder Usuario\n3.Salir"<<std::endl;
    std::cin>>option;
    if(option=="1"){
        pantalla1();
    }else if(option=="2"){
        pantallaVer();
    }else if(option=="3"){
        exit(0);
    }else{
        std::cout<<"Ingrese una opción válida"<<std::endl;
        pantallaInit();
    }
}

void Interfaz::pantalla1(){
    
    std::cout<<"1.Administrar Sistema\n"<<std::endl;
    std::cout<<"1.Administrar Todos los Usuarios\n2.Administrar Todos los Estudiantes\n3.Administrar Todos los Profesores\n4.Administrar Todos los Cursos\n5.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;
    
    if(option=="1"){
    
        pantalla1_1();
    
    }else if(option=="2"){
       
        pantalla1_2();
    
    }else if(option=="3"){
   
        pantalla1_3();
    
    }else if (option=="4"){
    
        pantalla1_4();
    
    }else if(option=="5"){
   
        std::cout<<"Ingrese una de las opciones"<<std::endl;
        
        pantallaInit();
    
    }else{
        std::cout<<"Ingrese una opcion correcta"<<std::endl;
        pantalla1();
    }
}


void Interfaz::pantallaVer(){
    
    std::string userAux,contraseniaAux,opcion;
    std::cout<<"Si desea regresar al inicio ingrese el numero 0 en Usuario"<<std::endl;
    
    std::cout<<"Usuario:    ";
    std::cin>>userAux;
    
    std::cout<<"Contrasenia:    ";
    std::cin>>contraseniaAux;
    
    if(userAux=="0"){
    
        pantalla1();
    
    }
    
    this->userActual=um->validateCredentials(userAux,contraseniaAux);


    if (userActual==nullptr){
    
        std::cout<<"Credenciales invalidas"<<std::endl;
        pantallaVer();
    
    }else{
    
        pantalla2(userActual);
    }

}

void Interfaz::pantalla1_1(){
    
    std::cout<<"1.Mostrar Usuarios\n2.Editar Usuarios\n3.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;
    std::deque<Student*> estudiantes=sm->getAllStudents();
    std::deque<Faculty> profesores=fm->getAllFaculty();
    
    if(option=="1"){
        sm->showStudents();
        fm->showAllFaculties();
        pantalla1_1();
    } else if(option=="2"){
        
        std::string banner;
        std::cout<<"Banner Id del usuario que quiere editar"<<std::endl;
        std::cin>>banner;
        

        for(int i=0;i<estudiantes.size();i++){
            
            if(banner==estudiantes[i]->getBannerID()){
        
                sm->editStudent(banner);
                break;
        
            }

        }
        for(int i=0;i<profesores.size();i++){
            
            if(banner==profesores[i].getBannerID()){
        
                fm->editFaculty(banner);
                break; 
            }

        }
        
        pantalla1_1();

    }else if(option=="3"){

        pantalla1();
    
    }else{
    
        std::cout<<"Ingrese una de las opciones"<<std::endl;
        pantalla1_1();
        
    }
}

void Interfaz::pantalla1_2(){
    std::cout<<"1.Crear Estudiante\n2.Editar Estudiante\n3.Mostrar Estudiantes\n4.Mostrar Estudiante\n5.Borrar Estudiante\n6.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;
    if(option=="1"){

        std::string bannerID_;
        std::cout<<"BannerId del nuevo Estudiante "<<std::endl;
        sm->createNewStudent(um);
        
       
        pantalla1_2();
        
    }else if(option=="2"){

        sm->editStudent();

        pantalla1_2();
        
    }else if(option == "3"){
        sm->showStudents();
        pantalla1_2();
    }else if(option=="4"){
        std::string bannerID_;
        std::cout<<"BannerID del estudiante a mostrar"<<std::endl;
        std::cin>>bannerID_;
        Student* showstud = sm->getStudentByID(bannerID_);
        if (showstud){
            std::cout << showstud->to_string()<< std::endl;
        }
        else {
            std::cout << "Error" << std::endl;
        }
        std::cout<<"\n\n"<< std::endl;
        pantalla1_2();
    }else if(option=="5"){
        
        std::string bannerID_;
        std::cout<<"BannerID del estudiante a eliminar"<<std::endl;
        std::cin>>bannerID_;
        sm->deleteStudent(bannerID_);


        pantalla1_2();


    }else if(option=="6"){
    ;
        pantalla1();
        
    }else{
        std::cout<<"Ingrese una opcion correcta"<<std::endl; 
        pantalla1_2();
    }
}

void Interfaz::pantalla1_3(){
    std::cout<<"1.Crear Profesor\n2.Editar Profesor\n3.Mostrar Profesores\n4.Borrar Profesor\n5.Regresar"<<std::endl;

    std::string option;
    std::cin>>option;
    if(option=="1"){
        fm->createNewFaculty(um);
        pantalla1_3();
    }else if(option=="2"){
        fm->editFaculty();
        pantalla1_3();
    }else if(option=="3"){
        fm->showAllFaculties();
        pantalla1_3();
    }else if(option=="4"){
        fm->deleteFaculty();
        pantalla1_3();
    }else if(option=="5"){
        pantalla1();
    }else{
        std::cout<<"Ingrese una opcion valida"<<std::endl; 
        pantalla1_3();
    }
}

void Interfaz::pantalla1_4(){

    std::cout<<"1.Crear Cursos\n2.Editar Cursos\n3.Mostrar Cursos\n4.Borrar Curso\n5.Asociar Profesor a Curso\n6.Asociar Estudiante a Curso\n7.Mostrar lista de curso\n8.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;

    if(option=="1"){
        
        cm->createNewCourse();

        pantalla1_4();
    
    }else if(option=="2"){
    
        cm->editCourse();

        pantalla1_4();

    }else if(option=="3")  {
    
        cm->showCourses();

        pantalla1_4();

    }else if(option=="4"){

        std::string nrc_;
        std::cout<<"Ingrese el NRC de la clase que busca eliminar"<<std::endl;
        std::cin>>nrc_;
        cm->deleteCourse(nrc_);

        std::cout<<"La clase ha sido eliminada"<<std::endl;
        pantalla1_4();

    }else if(option=="5"){

        std::string nrc_,bannerID_;
        std::cout<<"Ingrese el NRC del curso"<<std::endl;
        std::cin>>nrc_;
        std::cout<<"Ingrese el bannerID del profesor"<<std::endl;
        std::cin>>bannerID_;
        cm->getCourseByNRC(nrc_)->setProfesor(fm->getFacultyByID(bannerID_));

        cm->showClassByID(nrc_);
       
        pantalla1_4();


    }else if(option=="6"){

        std::string nrc_,bannerID_;
        std::cout<<"Ingrese el NRC del curso"<<std::endl;
        std::cin>>nrc_;
        std::cout<<"Ingrese el bannerID del estudiante"<<std::endl;
        std::cin>>bannerID_;

        Grade aux{0};
        
        cm->getCourseByNRC(nrc_)->addStudentGrade(sm->getStudentByID(bannerID_),aux);

        pantalla1_4();


    }else if(option=="7"){

        std::string nrc_;
        std::cout<<"Cual es el NRC del curso que desea revisar?"<<std::endl;
        std::cin>>nrc_;
        cm->showClassByID(nrc_);
        
        pantalla1_4();

    }else if(option=="8"){
    
        
        pantalla1();
    
    }else{
        std::cout<<"Ingrese una de las opciones"<<std::endl;
        
        pantalla1_4();
    }
}

void Interfaz::pantalla2(User* usuario_){

    std::cout<<"1.Mostrar Datos\n2.Editar Datos\n3.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;
    
    if(option=="1"){
    
        
        pantalla2_1(usuario_);
    
    }else if(option=="2"){
    
        
        pantalla2_2(usuario_);
    
    }else if(option=="3"){
    
        
        pantallaInit();
    
    }else{
    
        
        std::cout<<"Ingresar una opción correcta"<<std::endl;
        pantalla2(usuario_);
    
    }
    
}


void Interfaz::pantalla2_1(User* usuario_){

    um->showUser(usuario_);


    pantalla2(usuario_);
}

void Interfaz::pantalla2_2(User* usuario_){

    um->editUser(usuario_);

    

    pantalla2(usuario_);

}
