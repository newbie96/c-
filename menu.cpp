#include "menu.h"
#include "ui_menu.h"
#include "gra.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_gracz_clicked()
{
    gra p;
    p.ust(false);
    p.exec();
}

void Menu::on_komputer_clicked()
{
    gra p;
    p.ust(true);
    p.exec();
}
