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
    FacultyManager fm("C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\profesores.txt");
    StudentManager sm("C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\estudiantes_pregrado.txt", "C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\estudiantes_posgrado.txt");
    UserManager um(&fm, &sm);
    CourseManager cm("C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\Courses.txt", &sm, &fm);

    try {
        User *exito = um.validateCredentials(usuario, contrasenia);
        //un usuario puede ser undergrad, grad o profesor. tengo que intentar con los tres.
        UnderGraduateStudent * siUndergrad = dynamic_cast<UnderGraduateStudent*>(exito);
        GraduateStudent * siGrad = dynamic_cast<GraduateStudent*>(exito);
        Faculty * siProfesor = dynamic_cast<Faculty*>(exito);
        if (siUndergrad){
            this->ui->label->setText(QString::fromStdString(siUndergrad->getNombre() + " " + siUndergrad->getApellido() + ": Pregrado"));
            this->ui->label_2->setText(QString::fromStdString("Representante: " + siUndergrad->getRepresentante().getNombre() + " " + siUndergrad->getRepresentante().getApellido()));
            this->ui->label_3->setText(QString::fromStdString(siUndergrad->getBannerID()));
            std::string report = sm.generateReport(siUndergrad->getBannerID());
            this->ui->plainTextEdit->setPlainText(QString::fromStdString(report));
        }
        if (siGrad){
            this->ui->label->setText(QString::fromStdString(siGrad->getNombre() + " " + siGrad->getApellido() + ": Posgrado"));
            this->ui->label_2->setText(QString::fromStdString(siGrad->getNivel() + " " + siGrad->getCarrera()));
            this->ui->label_3->setText(QString::fromStdString(siGrad->getBannerID()));
            std::cout << siGrad->getBannerID() << std::endl;
            this->ui->plainTextEdit->setPlainText(QString::fromStdString(sm.generateReport(siGrad->getBannerID())));
        }
        if (siProfesor){
            this->ui->label->setText(QString::fromStdString(siProfesor->getNombre() + " " + siProfesor->getApellido() + ": Profesor"));
        }
    }  catch (FileNotFound &error) {
        QMessageBox::information(this, tr("ERROR"), tr("No se pudieron encontrar todos los archivos. Revisar el path"));
    } catch (InvalidCredentials &error) {
        QMessageBox::information(this, tr("ERROR"), tr("Las credenciales no son validas"));
    }
}
