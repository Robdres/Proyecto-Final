#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "segundapantalla.h"
#include "adminscreen.h"
#include "CourseManager.hpp"
#include "StudentManager.hpp"
#include "FacultyManager.hpp"
#include "UserManager.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    SegundaPantalla sp;
    AdminScreen as;
    FacultyManager *fm;
    StudentManager *sm;
    CourseManager *cm;
    UserManager *um;
    void initManagers();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
