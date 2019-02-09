#include "wygrana.h"
#include "ui_wygrana.h"

wygrana::wygrana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wygrana)
{
    ui->setupUi(this);
}

wygrana::~wygrana()
{
    delete ui;
}

void wygrana::on_OK_clicked()
{
    wygrana::close();
}


void wygrana::wyswietl(bool x)
{
    if(x) ui->label->setText("X");
    else ui->label->setText("O");
}
