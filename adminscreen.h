#ifndef ADMINSCREEN_H
#define ADMINSCREEN_H

#include <QMainWindow>

#include "StudentManager.hpp"
#include "FacultyManager.hpp"
#include "CourseManager.hpp"
#include "UserManager.hpp"

namespace Ui {
class AdminScreen;
}

class AdminScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminScreen( QWidget *parent = nullptr);
    ~AdminScreen();
    CourseManager *cm;
    FacultyManager *fm;
    StudentManager *sm;
    UserManager *um;
    void setManagers(UserManager *_um, FacultyManager *_fm, CourseManager *_cm, StudentManager *_sm);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdminScreen *ui;
};

#endif // ADMINSCREEN_H
