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
