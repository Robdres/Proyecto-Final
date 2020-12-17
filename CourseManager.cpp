#include <iostream>
#include "CourseManager.hpp"


void CourseManager::loadCourses(){
    std::ifstream input_cursos;
    int totalCursos;
    std::string nrc;
    int totalCreditos;
    std::string bannerIDFaculty;
    std::string path_estudiantes;

    std::ifstream input_detalleClase;
    int totalEstudiantesEnLaClase;
    std::string bannerIDEstudiante;
    float calificacionEstudiante;

    input_cursos.open(this->pathCursos);
    if(input_cursos.is_open()){
        input_cursos >> totalCursos;
        for(int i=0; i<totalCursos; i++){
            input_cursos >> nrc >> totalCreditos >> bannerIDFaculty >> path_estudiantes;
            Course *curso_actual = new Course(nrc, totalCreditos);
            Faculty* profesor = this->fm->getFacultyByID(bannerIDFaculty);
            curso_actual->setProfesor(profesor);
            profesor->addClass(curso_actual);
            input_detalleClase.open(path_estudiantes);
            this->cursos.add(curso_actual);
            if(input_detalleClase.is_open()){
                input_detalleClase >> totalEstudiantesEnLaClase;
                for(int j=0; j<totalEstudiantesEnLaClase; j++){
                    input_detalleClase >> bannerIDEstudiante >> calificacionEstudiante;
                    Student *estudiante = this->sm->getStudentByID(bannerIDEstudiante);
                    Grade nota(calificacionEstudiante);
                    curso_actual->addStudentGrade(estudiante, nota);
                    estudiante->addClass(*curso_actual);
                }
            }
            input_detalleClase.close();
        }
        input_cursos.close();
        return;
    }
    throw FileNotFound();
};

void CourseManager::updateCourses(){


    std::ofstream file;
    file.open(pathCursos,std::ofstream::out | std::ofstream::trunc);
    file<<cursos.getSize()<<"\n";

    for(unsigned int i=0;i<cursos.getSize();i++){
        file<<cursos[i]->getNRC()<<" "<<cursos[i]->getCreditos()<<" "<<cursos[i]->getProfesor()->getBannerID()<<" "<<cursos[i]->getPath()<<std::endl;
    }

    file.close();
    numCursos=cursos.getSize();
    loadCourses();
};


CourseManager::CourseManager(std::string pathCursos_, StudentManager* sm, FacultyManager* fm):pathCursos(pathCursos_),sm(sm),fm(fm){
    loadCourses();
};  

void CourseManager::createNewCourse(){
    
    std::string NRCAux,ProfesorAux;
    int creditosAux;
    
    std::cout<<"NRC de la nueva Clase"<<std::endl;
    std::cin>>NRCAux;
    std::cout<<"Creditos de la Nueva Clase"<<std::endl; 
    std::cin>>creditosAux;
    std::cout<<"BannerID del profesor de la Clase"<<std::endl;
    std::cin>>ProfesorAux;

    std::ofstream file;
    std::string newpath=NRCAux+"_"+ProfesorAux+".txt";
    std::ofstream newfile;
    newfile.open("./data/"+newpath);
    newfile<<"0";
    newfile.close();
    

    
    Course cursoAux{NRCAux,creditosAux};
    cursoAux.setProfesor(fm->getFacultyByID(ProfesorAux));
    cursoAux.setPath(NRCAux+"_"+ProfesorAux+".txt");
    cursos.add(&cursoAux);
    std::cout<<cursos.getSize()<<std::endl;
        
    updateCourses();
    
    
    
    
} 

void CourseManager::editCourse(){

    std::string option,NRCAux;
    std::cout<<"NRC del curso a editar"<<std::endl;
    std::cin>>NRCAux;

    for(int i=0;i<numCursos;i++){

        if(cursos[i]->getNRC()==NRCAux){

            std::cout<<"Que desea cambiar de su Curso\n1.NRC\n2.Profesor\n3.Numero de Creditos"<<std::endl;
            std::cin>>option;

            if(option=="1"){

                std::string nrcAux;
                std::cout<< "Nuevo NRC:    ";
                std::cin>>nrcAux;

                std::string newPath=nrcAux+"_"+cursos[i]->getProfesor()->getBannerID()+".txt";
                rename(("./data/"+cursos[i]->getPath()).c_str(),("./data/"+newPath).c_str());
                cursos[i]->setPath(newPath);
                cursos[i]->setNRC(nrcAux);

                updateCourses();
                std::cout<<"Su Curso ha sido actualizado"<<std::endl;

            }else if(option=="2"){

                std::string ID;
                std::cout<<"BannerID del nuevo profesor:    ";
                std::cin>>ID;
                
                Faculty* nuevoProfesor=fm->getFacultyByID(ID);
                std::string newPath=cursos[i]->getNRC()+"_"+ID+".txt";
                rename(("./data/"+cursos[i]->getPath()).c_str(),("./data/"+newPath).c_str());
                cursos[i]->setPath(newPath);
                cursos[i]->setProfesor(nuevoProfesor);
                nuevoProfesor->addClass(cursos[i]);
                
                updateCourses(); 
                std::cout<<"Su Curso ha sido actualizado"<<std::endl;

            }else if(option=="3"){

                int creditosAux;
                std::cout<<"Creditos nuevos:     ";
                std::cin>>creditosAux;
                
                cursos[i]->setCreditos(creditosAux);
                
                updateCourses();
                std::cout<<"Su Curso ha sido actualizado"<<std::endl;
    

            }else{
 
                std::cout<<"No se ingreso una opcion valida"<<std::endl,
                editCourse();

            }    

            
        }
        return;
    }
    throw NRCNotFound();
}    ;

void CourseManager::showCourses(){

    std::cout<<"Cursos disponibles"<<std::endl;
    
    for(int i=0;i<numCursos;i++){

        std::cout << cursos[i]->to_string() << std::endl;;
    
    }


};


void CourseManager::showClassByID(std::string nrc){

    for(unsigned int i=0;i<cursos.getSize();i++){
        if(cursos[i]->getNRC()==nrc){

            std::cout<<"NRC"<<std::setw(12)<<"Creditos"<<std::setw(10)<<"Profesor"<<std::endl;
            std::cout<<cursos[i]->to_string()<<std::endl;
            std::cout<<"Estudiantes:"<<std::endl;
            std::deque<Student*> stu=cursos[i]->getAllStudents();

            for(unsigned int j=0;j<stu.size();j++){
                std::cout<<stu[j]->to_string()<<std::endl;
            }
            return;
        }  

    }
    throw NRCNotFound();

}

void CourseManager::deleteCourse(std::string nrc){

    for(unsigned int i=0;i<cursos.getSize();i++){

        if(cursos[i]->getNRC()==nrc){

            numCursos--;
            cursos.deleteAt(i);
            updateCourses();
            return;
        }
    }
    throw FileNotFound();
};

Course* CourseManager::getCourseByNRC(std::string nrc_){

    for(int i = 0; i<numCursos;i++){

        if(cursos[i]->getNRC()==nrc_){

            return cursos[i];

        }
    
    }
    throw NRCNotFound();
}

