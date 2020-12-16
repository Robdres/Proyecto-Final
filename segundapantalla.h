#ifndef SEGUNDAPANTALLA_H
#define SEGUNDAPANTALLA_H

#include <QMainWindow>

namespace Ui {
class SegundaPantalla;
}

class SegundaPantalla : public QMainWindow
{
    Q_OBJECT

public:
    explicit SegundaPantalla(QWidget *parent = nullptr);
    ~SegundaPantalla();

private:
    Ui::SegundaPantalla *ui;
};

#endif // SEGUNDAPANTALLA_H
