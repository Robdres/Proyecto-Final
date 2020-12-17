#include "adminscreen.h"
#include "ui_adminscreen.h"
#include "Exceptions.hpp"
#include <QMessageBox>
#include <QString>

AdminScreen::AdminScreen(QWidget *parent) :
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
    QMessageBox::information(this, tr("ERROR"), tr("No se pudo encontrar el bannerID"));
    QString StudentId = ui->lineEdit->text();
    // su trabajo es reportar en una interfaz gráfica todos los cursos
    //en el que está inscrito el
    //estudiante (NRC) seguido de su nota (Grade) tanto numérica como en letra.
    //Al final del reporte debe imprimir el GPA del estudiante.
    try {//intentar encontrar el estudiante

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
    try {//intentar encontrar el profesor

    }  catch (BannerIDNotFound &error) {
        QMessageBox::information(this, tr("ERROR"), tr("No se pudo encontrar el bannerID"));
    }
}
