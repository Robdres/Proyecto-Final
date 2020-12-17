#include "adminscreen.h"
#include "ui_adminscreen.h"
#include "Exceptions.hpp"
#include "CourseManager.hpp"
#include <iostream>
#include <string>
#include <QMessageBox>
#include <QString>

AdminScreen::AdminScreen( QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminScreen)
{
    ui->setupUi(this);
}

AdminScreen::~AdminScreen()
{
    delete ui;
}

void AdminScreen::on_pushButton_clicked()
{
    // su trabajo es reportar en una interfaz gráfica todos los cursos
    //en el que está inscrito el
    //estudiante (NRC) seguido de su nota (Grade) tanto numérica como en letra.
    //Al final del reporte debe imprimir el GPA del estudiante.
    FacultyManager fm("C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\profesores.txt");
    StudentManager sm("C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\estudiantes_pregrado.txt", "C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\estudiantes_posgrado.txt");
    UserManager(&fm, &sm);
    CourseManager cm("C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\Courses.txt", &sm, &fm);
    try {//intentar encontrar el estudiante
        std::string input = ui->lineEdit->text().toStdString();
        std::string report = sm.generateReport(input);
        ui->plainTextEdit->setPlainText(QString::fromStdString(report));
    }  catch (BannerIDNotFound &error) {
        QMessageBox::information(this, tr("ERROR"), tr("No se pudo encontrar el bannerID"));
    }
}

void AdminScreen::on_pushButton_2_clicked()
{
    //su trabajo
    //es reportar la mejor nota (máximo), la peor nota (mínimo), la nota promedio y
    //la desviación estándar por todos los cursos de ese profesor.
    //QString ProfId = ui->lineEdit_2->text();
    FacultyManager fm("C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\profesores.txt");
    StudentManager sm("C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\estudiantes_pregrado.txt", "C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\estudiantes_posgrado.txt");
    UserManager(&fm, &sm);
    CourseManager cm("C:\\Users\\josei\\Documents\\GitHub\\build-Proyecto-Final-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\data\\Courses.txt", &sm, &fm);
    try {//intentar encontrar el profesor
        std::string input = ui->lineEdit_2->text().toStdString();
        std::string report = fm.generateReport(input);
        ui->plainTextEdit->setPlainText(QString::fromStdString(report));
    }  catch (BannerIDNotFound &error) {
        QMessageBox::information(this, tr("ERROR"), tr("No se pudo encontrar el bannerID"));
    }
}
