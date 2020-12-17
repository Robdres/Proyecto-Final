#ifndef ADMINSCREEN_H
#define ADMINSCREEN_H

#include <QMainWindow>

namespace Ui {
class AdminScreen;
}

class AdminScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminScreen(QWidget *parent = nullptr);
    ~AdminScreen();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdminScreen *ui;
};

#endif // ADMINSCREEN_H
