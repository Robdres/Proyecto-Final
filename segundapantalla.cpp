#include "segundapantalla.h"
#include "ui_segundapantalla.h"

SegundaPantalla::SegundaPantalla(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SegundaPantalla)
{
    ui->setupUi(this);
}

SegundaPantalla::~SegundaPantalla()
{
    delete ui;
}

void SegundaPantalla::startSystem(std::string usuario, std::string contrasenia){
    try {
        User *exito = um->validateCredentials(usuario, contrasenia);
        //un usuario puede ser undergrad, grad o profesor. tengo que intentar con los tres.
        UnderGraduateStudent * siUndergrad = dynamic_cast<UnderGraduateStudent*>(exito);
        GraduateStudent * siGrad = dynamic_cast<GraduateStudent*>(exito);
        Faculty * siProfesor = dynamic_cast<Faculty*>(exito);
        if (siUndergrad){
            this->ui->label->setText(QString::fromStdString(siUndergrad->getNombre() + " " + siUndergrad->getApellido() + ": Pregrado"));
            this->ui->label_2->setText(QString::fromStdString("Representante: " + siUndergrad->getRepresentante().getNombre() + " " + siUndergrad->getRepresentante().getApellido()));
            this->ui->label_3->setText(QString::fromStdString("BannerID:\t" + siUndergrad->getBannerID()));
            std::string report = sm->generateReport(siUndergrad->getBannerID());
            this->ui->plainTextEdit->setPlainText(QString::fromStdString(report));
        }
        if (siGrad){
            this->ui->label->setText(QString::fromStdString(siGrad->getNombre() + " " + siGrad->getApellido() + ": Posgrado"));
            this->ui->label_2->setText(QString::fromStdString(siGrad->getNivel() + " " + siGrad->getCarrera()));
            this->ui->label_3->setText(QString::fromStdString("BannerID:\t" + siGrad->getBannerID()));
            std::cout << siGrad->getBannerID() << std::endl;
            this->ui->plainTextEdit->setPlainText(QString::fromStdString(sm->generateReport(siGrad->getBannerID())));
        }
        if (siProfesor){
            this->ui->label->setText(QString::fromStdString(siProfesor->getNombre() + " " + siProfesor->getApellido() + ": Profesor"));
            this->ui->label_2->setText(QString::fromStdString("Profesor\t Carrera: " + siProfesor->getCarrera()));
            this->ui->label_3->setText(QString::fromStdString("BannerID:\t" + siProfesor->getBannerID()));
            this->ui->plainTextEdit->setPlainText(QString::fromStdString(fm->generateReport(siProfesor->getBannerID())));
        }
    }  catch (FileNotFound &error) {
        QMessageBox::information(this, tr("ERROR"), tr("No se pudieron encontrar todos los archivos. Revisar el path"));
    }
}

void SegundaPantalla::setManagers(UserManager *_um, FacultyManager *_fm, CourseManager *_cm, StudentManager *_sm){
    this->um = _um;
    this->fm = _fm;
    this->cm = _cm;
    this->sm = _sm;
}
