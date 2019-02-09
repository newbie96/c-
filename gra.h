#ifndef GRA_H
#define GRA_H

#include <QDialog>
#include <QPushButton>
#include <cstdlib>
#include "wygrana.h"
#include <windows.h>

namespace Ui {
class gra;
}

class gra : public QDialog
{
    Q_OBJECT

public:
    explicit gra(QWidget *parent = 0);
    ~gra();
    void ust(bool);
private slots:
    void on_P1_clicked();

    void on_P2_clicked();

    void on_P3_clicked();

    void on_P4_clicked();

    void on_P5_clicked();

    void on_P6_clicked();

    void on_P7_clicked();

    void on_P8_clicked();

    void on_P9_clicked();

    void on_reset_clicked();

private:
        void reset();
        void dalej(int);
        void sprawdz();
        void okno(bool);
        QPushButton **wsk[9];
        QString pole;
        bool rodzaj_gry;
        bool gracz;
    Ui::gra *ui;
};

#endif // GRA_H
