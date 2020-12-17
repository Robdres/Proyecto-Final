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
        as.show();//admin screen
    } else {
        //verificar los datos del estudiante antes de pasar a la segunda pantalla
        sp.startSystem(ui->plainTextEdit->toPlainText().toStdString(), ui->plainTextEdit_2->toPlainText().toStdString());
        sp.show();
    }
    close();
}
