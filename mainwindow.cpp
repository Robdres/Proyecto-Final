#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    if (ui->plainTextEdit->toPlainText() == "admin" && ui->plainTextEdit_2->toPlainText() == "admin"){
        as.setManagers(um, fm, cm, sm);
        as.show();//admin screen
        ui->plainTextEdit->clear();
        ui->plainTextEdit_2->clear();
    } else {
        //verificar los datos del estudiante antes de pasar a la segunda pantalla
        try {
            sp.setManagers(um, fm, cm, sm);
            sp.startSystem(ui->plainTextEdit->toPlainText().toStdString(), ui->plainTextEdit_2->toPlainText().toStdString());
            //va a lanzar error si las credenciales no son válidas
            sp.show();
            ui->plainTextEdit->clear();
            ui->plainTextEdit_2->clear();
        }  catch (InvalidCredentials &error) {
            QMessageBox::information(this, tr("ERROR"), tr("Credenciales Inválidas"));
            ui->plainTextEdit->clear();
            ui->plainTextEdit_2->clear();
        }
    }
}

void MainWindow::initManagers(){
        try{
        fm = new FacultyManager("C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\profesores.txt");
        sm = new StudentManager("C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\estudiantes_pregrado.txt", "C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\estudiantes_posgrado.txt");
        cm = new CourseManager("C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\Courses.txt", sm, fm);
        um = new UserManager(fm, sm);
        }
        catch(FileNotFound &error){
            QMessageBox::information(this, tr("ERROR"), tr("No se pudieron encontrar algunos archivos. Revise el path."));
        }
}
