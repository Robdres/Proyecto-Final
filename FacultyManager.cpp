#include "FacultyManager.hpp"
using namespace std;

template <typename T>
T consoleInput(const char * askfor){
    cout << askfor << endl;
    T retValue;
    cin >> retValue;
    return retValue;
}

void FacultyManager::loadFaculty(){
    ifstream input(this->pathFaculty);
    //formato:
    //bannerid nombre apellido usuario contrasenia carrera
    int total;
    if (input.is_open()){
        input >> total;
        string _bannerId;
        string _nombre;
        string _apellido;
        string _usuario;
        string _contrasenia;
        string _carrera;
        for (int i = 0; i < total ; i ++){
            input >> _bannerId >> _nombre >> _apellido >> _usuario >>_contrasenia >> _carrera;
            this->profesores.push_back(new Faculty{_bannerId, _nombre, _apellido, _contrasenia, _usuario, _carrera});
        }
    input.close();
    return;
    }
    throw FileNotFound();

};

void FacultyManager::updateFaculty(){
    //volver a escribir todos los datos dentro de los archivos
    ofstream output(this->pathFaculty);
    if (output.is_open()) {
        output << profesores.size() << endl;
        for (unsigned int i = 0; i < profesores.size() ; i++) {
            output << profesores[i]->getBannerID() << "\t" << profesores[i]->getNombre() << "\t" << profesores[i]->getApellido() << "\t" << profesores[i]->getUsuario()<< "\t" << profesores[i]->getContrasenia() << "\t" << profesores[i]->getCarrera() << endl;
        }
    } else {
        cerr << "No se pudo encontrar el archivo para  guardar. No se pudo actualizar." << this->pathFaculty<< endl;
        throw FileNotFound();
    }
    output.close();
};

FacultyManager::FacultyManager(string path) : pathFaculty(path){
    loadFaculty();
};


void FacultyManager::createNewFaculty(UserManager* um){
    string _bannerId = um->getNewBannerID();
    string _nombre = consoleInput<string>("Nombre del profesor: ");
    string _apellido = consoleInput<string>("Apellido del profesor: ");
    string _carrera = consoleInput<string>("Carrera: ");
    string _usuario = consoleInput<string>("Nombre de usuario: ");
    string _contrasenia = consoleInput<string>("Contrasenia: ");
    profesores.push_back(new Faculty(_bannerId, _nombre, _apellido, _contrasenia, _usuario, _carrera));
};

Faculty* FacultyManager::getFacultyByID(string BannerID){
    for(unsigned int i = 0; i < profesores.size(); i ++){
        if(profesores[i]->getBannerID() == BannerID){
            return profesores[i];
        }
    }
    throw BannerIDNotFound();
};

deque<Faculty*> FacultyManager::getAllFaculty(){
    return profesores;
};

void FacultyManager::editFaculty(){
    string ID = consoleInput<string>("Banner ID del profesor que desea editar:");
    for(auto &prof: profesores) {
        if (prof->getBannerID() == ID) {
            cout << "PROFESOR ENCONTRADO" << endl;
            cout << prof->to_string() << endl;
//2001    Andrea  HARRIS  AHARRIS AHARRIS6770     QUIMICA
            prof->setNombre(consoleInput<string>("Nombre: "));
            prof->setApellido(consoleInput<string>("Apellido: "));
            prof->setUsuario(consoleInput<string>("Usuario: "));
            prof->setContrasenia(consoleInput<string>("Contrasenia: "));
            prof->setCarrera(consoleInput<string>("Carrera: "));
            return;
        }
    }
    throw BannerIDNotFound();
};

void FacultyManager::editFaculty(Faculty *fac){
    string ID = fac->getBannerID();
    for(auto &prof: profesores) {
        if (prof->getBannerID() == ID) {
            cout << "PROFESOR ENCONTRADO" << endl;
            cout << prof->to_string() << endl;
//2001    Andrea  HARRIS  AHARRIS AHARRIS6770     QUIMICA
            prof->setNombre(consoleInput<string>("Nombre: "));
            prof->setApellido(consoleInput<string>("Apellido: "));
            prof->setUsuario(consoleInput<string>("Usuario: "));
            prof->setContrasenia(consoleInput<string>("Contrasenia: "));
            prof->setCarrera(consoleInput<string>("Carrera: "));
            return;
        }
    }
    throw BannerIDNotFound();
};

void FacultyManager::editFaculty(string bid){
    string ID = bid;
    for(auto &prof: profesores) {
        if (prof->getBannerID() == ID) {
            cout << "PROFESOR ENCONTRADO" << endl;
            cout << prof->to_string() << endl;
//2001    Andrea  HARRIS  AHARRIS AHARRIS6770     QUIMICA
            prof->setNombre(consoleInput<string>("Nombre: "));
            prof->setApellido(consoleInput<string>("Apellido: "));
            prof->setUsuario(consoleInput<string>("Usuario: "));
            prof->setContrasenia(consoleInput<string>("Contrasenia: "));
            prof->setCarrera(consoleInput<string>("Carrera: "));
            return;
        }
    }
    throw BannerIDNotFound();
};

void FacultyManager::showFaculty(string BannerId){
    for (unsigned int i = 0; i < profesores.size(); i ++)  {
        if (profesores[i]->getBannerID() == BannerId) {
            cout << profesores[i]->to_string() << endl;
        }
    }
    throw BannerIDNotFound();
};

void FacultyManager::deleteFaculty(string _BannerId){ //sobrecarga cuando se le pasa el bannerId
    //encontrar el profesor:
    int pos = 0;
    for (auto prof : profesores) {
        if (prof->getBannerID() == _BannerId) {
            profesores.erase(profesores.begin() + pos);//borrar el profesor
            cout << "Profesor Borrado con exito" << endl;
            return;
        }
        pos ++;
    }
    throw BannerIDNotFound();
};

void FacultyManager::deleteFaculty(){//sobrecarga cuando no se le pasa nada
    //encontrar el profesor:
    string _BannerId = consoleInput<string>("Banner Id del profesor que quiere borrar: ");
    int pos = 0;
    for (auto prof : profesores) {
        if (prof->getBannerID() == _BannerId) {
            profesores.erase(profesores.begin() + pos);
            cout << "Profesor Borrado con exito" << endl;
            return;
        }
        pos ++;
    }
    throw BannerIDNotFound();
};

void FacultyManager::showAllFaculties(){
    for(auto prof : profesores){
        cout << prof->to_string() << endl;
    }
}

FacultyManager::~FacultyManager(){
}

std::string FacultyManager::generateReport(std::string BannerId){
    string report = "";
    for (auto prof : profesores){
        if (prof->getBannerID() == BannerId){
            report += "Profesor:\t" + prof->getNombre() + " "  + prof->getApellido() + "\t" +prof->getBannerID() + "\n";
            report += "\nInformación sobre los cursos:\n";
            report += "NRC\tMax\tMin\tMedia\tDesvest\n";
            ArrayList<Course* > cursos = prof->getCursos();
            for (unsigned int i = 0; i < cursos.getSize(); i ++){
                report += cursos[i]->getNRC() + "\t" + to_string(cursos[i]->getNotaMax())+ "\t" + to_string(cursos[i]->getNotaMin())+ '\t' + to_string(cursos[i]->getPromedio()) + '\t' + to_string(cursos[i]->getDesvest()) + "\n";

            }
            return report;
        }
    }
    throw BannerIDNotFound();
}
