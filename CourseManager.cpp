#include <iostream>
#include "CourseManager.hpp"


void CourseManager::loadCourses(){

    std::ifstream input;
    input.open(this->pathCursos);
    input>>numCursos;

    if (input.is_open()){
        for(int i=0;i<this->numCursos;i++){

            std::string nrcAux,profeAux,pathAux;
            int creditosAux;
            Faculty* profesor;

            input>>nrcAux>>creditosAux>>profeAux>>pathAux;

            Course* cursoAux;
            cursoAux= new Course();
            cursoAux->setNRC(nrcAux);
            cursoAux->setCreditos(creditosAux);
            cursos.add(cursoAux);
            cursos[i]->setPath(pathAux);

            profesor=fm->getFacultyByID(profeAux);
            cursos[i]->setProfesor(profesor);
            
            
            std::ifstream fileEst;    
            int numberEst;

            std::string pathEstudiantes="C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\"+cursos[i]->getPath();
        
            fileEst.open(pathEstudiantes);
            fileEst>>numberEst;
            if(fileEst.is_open()){
                for(int j=0;j<numberEst;j++){

                    std::string BannerIDAux;
                    float notaAux;
                    
                    Grade nota;

                    fileEst>>BannerIDAux>>notaAux;
                  
                    nota=Grade(notaAux);
                    cursos[i]->addStudentGrade(sm->getStudentByID(BannerIDAux),nota);
                }
            }else{
                std::cout<<"Revisar Path en CourseManager"<<std::endl;
                throw FileNotFound();
            }
            
            fileEst.close();

        }
        input.close();
    } else { throw FileNotFound();}
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

