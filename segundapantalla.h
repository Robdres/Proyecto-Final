#ifndef SEGUNDAPANTALLA_H
#define SEGUNDAPANTALLA_H

#include <QMainWindow>
#include "StudentManager.hpp"
#include "UserManager.hpp"
#include "FacultyManager.hpp"
#include "CourseManager.hpp"
#include <QMessageBox>
#include <QString>
#include <string>

namespace Ui {
class SegundaPantalla;
}

class SegundaPantalla : public QMainWindow
{
    Q_OBJECT

public:
    explicit SegundaPantalla(QWidget *parent = nullptr);
    ~SegundaPantalla();
    void startSystem(std::string , std::string);//se le pasa las credenciales para intentar iniciar sesion
private:
    Ui::SegundaPantalla *ui;
};

#endif // SEGUNDAPANTALLA_H
