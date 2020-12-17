#include <iostream> 
#include "StudentManager.hpp"
using namespace std;

template <typename T>
T consoleInput(const char * askfor){
    cout << askfor << endl;
    T retValue;
    cin >> retValue;
    return retValue;
}


void StudentManager::loadUnderGrads(){
    int total;
    ifstream input;
    input.open(this->pathUndergraduate);
    if (input.is_open()){
        input>>total;
        for(int i=0;i<total;i++){
            std::string bannerIDAux;
            std::string nombreAux;
            std::string apellidoAux;
            std::string usuarioAux;
            std::string contraseniaAux;
            std::string carreraAux;
            std::string pnombreAux;
            std::string papellidoAux;
            std::string pemailAux;
            std::string ptelefAux;
            input>>bannerIDAux>>nombreAux>>apellidoAux>>usuarioAux>>contraseniaAux>>carreraAux>>pnombreAux>>papellidoAux>>pemailAux>>ptelefAux;
            Proxy proxyAux(pnombreAux,papellidoAux,pemailAux,ptelefAux);


            UnderGraduateStudent* newUnder = new UnderGraduateStudent(bannerIDAux,nombreAux,apellidoAux,usuarioAux,contraseniaAux,carreraAux,proxyAux);
            Student *Stptr(&*newUnder);
            estudiantes.push_back(Stptr);
        }
    }
    else {
        throw FileNotFound();
    }
};

void StudentManager::loadGrads(){
    int total;
    std::ifstream input;
    input.open(this->pathGraduate);
    if(input.is_open()){
        input>>total;
        for(int i=0;i<total;i++){
            std::string bannerIDAux;
            std::string nombreAux;
            std::string apellidoAux;
            std::string usuarioAux;
            std::string contraseniaAux;
            std::string carreraAux;
            std::string nivelAux;
            input>>bannerIDAux>>nombreAux>>apellidoAux>>usuarioAux>>contraseniaAux>>carreraAux>>nivelAux;
            estudiantes.push_back(new GraduateStudent(bannerIDAux,nombreAux,apellidoAux,contraseniaAux,usuarioAux,carreraAux,nivelAux));
        }
    }
    else {
        throw FileNotFound();
    }
};

void StudentManager::updateUnderGrads(){
    std::ofstream file;
    file.open(pathUndergraduate,std::ofstream::out | std::ofstream::trunc);
    int counter=0;
    for(auto &estud: estudiantes) {
        UnderGraduateStudent* UnderGradStud = dynamic_cast<UnderGraduateStudent*>(estud);//uno de los dos dynamic cas tiene que ser 0
        if (UnderGradStud){
            counter++;
        }
    }
    file<<counter<<"\n";
    for(auto &estud: estudiantes) {
        UnderGraduateStudent* UnderGradStud = dynamic_cast<UnderGraduateStudent*>(estud);//uno de los dos dynamic cas tiene que ser 0

        if (UnderGradStud){
//87      Jordan  PATTERSON       JPATTERSON      JPATTERSON7638  MATEMATICA      Danielle        PATTERSON       DPATTERSON@outlook.com  716-457-4008
            file<<estud->getBannerID()<<"\t"<<estud->getNombre()<<"\t"<<estud->getApellido()<<"\t"<<estud->getUsuario()<<"\t"<<estud->getContrasenia()<<"\t"<<estud->getCarrera()<<"\t"<<UnderGradStud->getRepresentante().getNombre()<<"\t"<<UnderGradStud->getRepresentante().getApellido()<<"\t"<<UnderGradStud->getRepresentante().getEmail() <<"\t"<<UnderGradStud->getRepresentante().getNumeroTelefonico()<<"\n";
        }
    }
    loadUnderGrads();
};

void StudentManager::updateGrads(){
    
    std::ofstream file;
    file.open(pathUndergraduate,std::ofstream::out | std::ofstream::trunc);
    int counter=0;
    for(auto &estud: estudiantes) {
        GraduateStudent* GradStud = dynamic_cast<GraduateStudent*>(estud);
        if (GradStud){
            counter++;
        }
    }
    file<<counter<<"\n";
    for(auto &estud: estudiantes) {
        GraduateStudent* GradStud = dynamic_cast<GraduateStudent*>(estud);//uno de los dos dynamic cas tiene que ser 0
        //1100    Ethan    HAYES    EHAYES    EHAYES8667    QUIMICA    Doctorado
        if (GradStud){
            file<<estud->getBannerID()<<"\t"<<estud->getNombre()<<"\t"<<estud->getApellido()<<"\t"<<estud->getUsuario()<<"\t"<<estud->getContrasenia()<<"\t"<<estud->getCarrera()<<"\t"<<GradStud->getNivel()<<"\n";
        }
    }
    loadGrads();
};



StudentManager::StudentManager(std::string pathUndergrad, std::string pathGrad) : pathUndergraduate(pathUndergrad), pathGraduate(pathGrad){
    loadUnderGrads();
    loadGrads();
};

void StudentManager::createNewStudent(UserManager* um){
    cout << "Pregrado o posgrado? \n1. Pregrado\n2. Posgrado" << endl;
    int opt;
    cin >> opt;
    cout << endl;

    if (opt == 2){
        string _bannerId = um->getNewBannerID();
        std::string nombreAux = consoleInput<string>("Nombre: ");
        std::string apellidoAux = consoleInput<string>("Apellido: ");
        std::string usuarioAux = consoleInput<string>("Usuario: ");
        std::string contraseniaAux = consoleInput<string>("Contrasenia: ");
        std::string carreraAux = consoleInput<string>("Carrera: ");
        std::string nivelAux = consoleInput<string>("Nivel: ");
        estudiantes.push_back( new GraduateStudent(_bannerId,nombreAux,apellidoAux,contraseniaAux,usuarioAux,carreraAux,nivelAux));
        updateGrads();
    }
    else if (opt == 1) {
        std::string bannerIDAux = um->getNewBannerID();
        std::string nombreAux = consoleInput<string>("Nombre: ");
        std::string apellidoAux = consoleInput<string>("Apellido: ");
        std::string usuarioAux = consoleInput<string>("Usuario: ");
        std::string contraseniaAux = consoleInput<string>("Contrasenia: ");
        std::string carreraAux = consoleInput<string>("Carrera: ");
        std::string pnombreAux = consoleInput<string>("Nombre del representante: ");
        std::string papellidoAux = consoleInput<string>("Apellido del representante: ");
        std::string pemailAux = consoleInput<string>("Email del representante: ");
        std::string ptelefAux = consoleInput<string>("Telefono del representante: ");
        Proxy proxyAux(pnombreAux,papellidoAux,pemailAux,ptelefAux);

        estudiantes.push_back(new UnderGraduateStudent(bannerIDAux,nombreAux,apellidoAux,usuarioAux,contraseniaAux,carreraAux,proxyAux));
        updateUnderGrads();

    }
    else {
        cout << "No es una opcion valida" << endl;
    }
   
    
};

Student* StudentManager::getStudentByID(string BannerID){
    for(int i = 0; i < estudiantes.size(); i ++){
        if (estudiantes[i]->getBannerID() == BannerID){
            return estudiantes[i];
        }
    }//cambiar por array list
    throw BannerIDNotFound();
};

deque<Student*> StudentManager::getAllStudents(){
    return this->estudiantes;
}

void StudentManager::editStudent(){// sobrecarga para no mandarle nada por si acaso se necesita
    string _bannerId = consoleInput<string>("Banner ID del estudiante que quiere editar:");
    Student* Edit{0};//estudiante para editar
    bool found = false;
    //encontrar el estudiante con ese bannerID
    for(auto &estud: estudiantes) {
        if (estud->getBannerID() == _bannerId){
            cout << "ESTUDIANTE ENCONTRADO." << endl;
            cout << estud->to_string() << endl;
            GraduateStudent* GradStud = dynamic_cast<GraduateStudent*>(estud);
            UnderGraduateStudent* UnderGradStud = dynamic_cast<UnderGraduateStudent*>(estud);//uno de los dos dynamic cas tiene que ser 0
            if (UnderGradStud){
                UnderGradStud->setNombre(consoleInput<string>("Nombre: "));
                UnderGradStud->setApellido(consoleInput<string>("Apellido: "));
                UnderGradStud->setUsuario(consoleInput<string>("Usuario: "));
                UnderGradStud->setContrasenia(consoleInput<string>("Contrasenia: "));
                UnderGradStud->setCarrera(consoleInput<string>("Carrera: "));
                Proxy repr{consoleInput<string>("Nombre del Representante: "), consoleInput<string>("Apellido del representante: "), consoleInput<string>("Correo del representante: "), consoleInput<string>("Telefono del representante: ")};
                UnderGradStud->setRepresentante(repr);
                updateUnderGrads();
            }
            if (GradStud){
                GradStud->setNombre(consoleInput<string>("Nombre: "));
                GradStud->setApellido(consoleInput<string>("Apellido: "));
                GradStud->setUsuario(consoleInput<string>("Usuario: "));
                GradStud->setContrasenia(consoleInput<string>("Contrasenia: "));
                GradStud->setCarrera(consoleInput<string>("Carrera: "));
                GradStud->setNivel(consoleInput<string>("Nivel: "));
                updateGrads();
            }
            return;
        }
    }
    throw BannerIDNotFound();
};

void StudentManager::editStudent(string bid){ //sobrecarga para mandarle el banner ID, facilita la interfaz
    string _bannerId = bid;
    Student* Edit{0};//estudiante para editar
    bool found = false;
    //encontrar el estudiante con ese bannerID
    for(auto &estud: estudiantes) {
        if (estud->getBannerID() == _bannerId){
            cout << "ESTUDIANTE ENCONTRADO." << endl;
            cout << estud->to_string() << endl;
            GraduateStudent* GradStud = dynamic_cast<GraduateStudent*>(estud);
            UnderGraduateStudent* UnderGradStud = dynamic_cast<UnderGraduateStudent*>(estud);//uno de los dos dynamic cas tiene que ser 0
            if (UnderGradStud){
                UnderGradStud->setNombre(consoleInput<string>("Nombre: "));
                UnderGradStud->setApellido(consoleInput<string>("Apellido: "));
                UnderGradStud->setUsuario(consoleInput<string>("Usuario: "));
                UnderGradStud->setContrasenia(consoleInput<string>("Contrasenia: "));
                UnderGradStud->setCarrera(consoleInput<string>("Carrera: "));
                Proxy repr{consoleInput<string>("Nombre del Representante: "), consoleInput<string>("Apellido del representante: "), consoleInput<string>("Correo del representante: "), consoleInput<string>("Telefono del representante: ")};
                UnderGradStud->setRepresentante(repr);
                updateUnderGrads();
            }
            if (GradStud){
                GradStud->setNombre(consoleInput<string>("Nombre: "));
                GradStud->setApellido(consoleInput<string>("Apellido: "));
                GradStud->setUsuario(consoleInput<string>("Usuario: "));
                GradStud->setContrasenia(consoleInput<string>("Contrasenia: "));
                GradStud->setCarrera(consoleInput<string>("Carrera: "));
                GradStud->setNivel(consoleInput<string>("Nivel: "));
                updateGrads();
            }
            return;
        }
    }
    throw BannerIDNotFound();
};

void StudentManager::editStudent(Student* stud){//sobrecarga a la que se le pasa un student*
    string _bannerId = stud->getBannerID();
    Student* Edit{0};//estudiante para editar
    bool found = false;
    //encontrar el estudiante con ese bannerID
    for(auto &estud: estudiantes) {
        if (estud->getBannerID() == _bannerId){
            cout << "ESTUDIANTE ENCONTRADO." << endl;
            cout << estud->to_string() << endl;
            GraduateStudent* GradStud = dynamic_cast<GraduateStudent*>(estud);
            UnderGraduateStudent* UnderGradStud = dynamic_cast<UnderGraduateStudent*>(estud);//uno de los dos dynamic cas tiene que ser 0
            if (UnderGradStud){
                UnderGradStud->setNombre(consoleInput<string>("Nombre: "));
                UnderGradStud->setApellido(consoleInput<string>("Apellido: "));
                UnderGradStud->setUsuario(consoleInput<string>("Usuario: "));
                UnderGradStud->setContrasenia(consoleInput<string>("Contrasenia: "));
                UnderGradStud->setCarrera(consoleInput<string>("Carrera: "));
                Proxy repr{consoleInput<string>("Nombre del Representante: "), consoleInput<string>("Apellido del representante: "), consoleInput<string>("Correo del representante: "), consoleInput<string>("Telefono del representante: ")};
                UnderGradStud->setRepresentante(repr);
                updateUnderGrads();
            }
            if (GradStud){
                GradStud->setNombre(consoleInput<string>("Nombre: "));
                GradStud->setApellido(consoleInput<string>("Apellido: "));
                GradStud->setUsuario(consoleInput<string>("Usuario: "));
                GradStud->setContrasenia(consoleInput<string>("Contrasenia: "));
                GradStud->setCarrera(consoleInput<string>("Carrera: "));
                GradStud->setNivel(consoleInput<string>("Nivel: "));
                updateGrads();
            }
            return;
        }
    }
    throw BannerIDNotFound();
};

void StudentManager::showStudents(){
    cout << "LISTA DE TODOS LOS ESTUDIANTES: \n";
    for (auto stud : estudiantes) {
        cout << stud->to_string() << "\n";
    }
    cout << flush; //revisar si hay errores al compilar 
};

void StudentManager::deleteStudent(std::string bannerID_){
    int pos = 0;
    for(auto stud : estudiantes) {
        if (stud->getBannerID() == bannerID_) {
            estudiantes.erase(estudiantes.begin() + pos);
            break;
        }
        pos ++;
    }
    updateUnderGrads();
    updateGrads();
};

void StudentManager::showStudent(string bannerId) {
    for(auto stud : estudiantes) {
        if (stud->getBannerID() == bannerId) {
            cout << stud->to_string() << endl;
            return;
        }
    }
    throw BannerIDNotFound();
}

void StudentManager::showStudent(Student* estud) {//para que no se le dañe lo que hizo el roberto 
    cout << estud->to_string() << endl;
} //<3 

