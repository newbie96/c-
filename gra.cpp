#include "gra.h"
#include "ui_game.h"

gra::gra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gra)
{
        gracz=true;
        wsk[0]=&ui->P1;
        wsk[1]=&ui->P2;
        wsk[2]=&ui->P3;
        wsk[3]=&ui->P4;
        wsk[4]=&ui->P5;
        wsk[5]=&ui->P6;
        wsk[6]=&ui->P7;
        wsk[7]=&ui->P8;
        wsk[8]=&ui->P9;
        rodzaj_gry=true;
        ui->setupUi(this);
}

gra::~gra()
{
    delete ui;
}

void gra::okno(bool x)
{
    wygrana okno;
    okno.wyswietl(x);
    okno.exec();
    for(int i=0;i<9;i++) (*wsk[i])->setEnabled(false);
}

void gra::ust(bool x)
{
    rodzaj_gry=x;
}
void gra::sprawdz()
{
    if(ui->P1->text()=="X"&& ui->P2->text()=="X"&&ui->P3->text()=="X") okno(true);
    else if(ui->P4->text()=="X"&& ui->P5->text()=="X"&&ui->P6->text()=="X") okno(true);
    else if(ui->P7->text()=="X"&& ui->P8->text()=="X"&&ui->P9->text()=="X") okno(true);
    else if(ui->P1->text()=="X"&& ui->P4->text()=="X"&&ui->P7->text()=="X") okno(true);
    else if(ui->P2->text()=="X"&& ui->P5->text()=="X"&&ui->P8->text()=="X") okno(true);
    else if(ui->P3->text()=="X"&& ui->P6->text()=="X"&&ui->P9->text()=="X") okno(true);
    else if(ui->P1->text()=="O"&& ui->P4->text()=="O"&&ui->P7->text()=="O") okno(false);
    else if(ui->P2->text()=="O"&& ui->P5->text()=="O"&&ui->P8->text()=="O") okno(false);
    else if(ui->P3->text()=="O"&& ui->P6->text()=="O"&&ui->P9->text()=="O") okno(false);
    else if(ui->P1->text()=="O"&& ui->P2->text()=="O"&&ui->P3->text()=="O") okno(false);
    else if(ui->P4->text()=="O"&& ui->P5->text()=="O"&&ui->P6->text()=="O") okno(false);
    else if(ui->P7->text()=="O"&& ui->P8->text()=="O"&&ui->P9->text()=="O") okno(false);
    else  if(ui->P1->text()=="X"&& ui->P5->text()=="X"&&ui->P9->text()=="X") okno(true);
    else  if(ui->P3->text()=="X"&& ui->P5->text()=="X"&&ui->P7->text()=="X") okno(true);
    else  if(ui->P1->text()=="O"&& ui->P5->text()=="O"&&ui->P9->text()=="O") okno(false);
    else  if(ui->P3->text()=="O"&& ui->P5->text()=="O"&&ui->P7->text()=="O") okno(false);

}

void gra::dalej(int x)
{
    bool check=true;
        do{

        if(rodzaj_gry)
        {
            if(!gracz)
            {

              do  {
                x=rand()%9;

                 for(int i=0;i<pole.length();i++)
                 {

                     if(pole[i]==QString::number(x))
                     {
                         check=true;
                         break;
                      }
                     else
                     {
                    check=false;
                    }
                }
               }while(check);


               }
         pole+=QString::number(x);

            }
    if(gracz)
    {
       (*wsk[x])->setText("X");
       (*wsk[x])->setEnabled(false);
        gracz=false;
        ui->rundagracza->setText("O");
        sprawdz();
    }
    else
    {
        (*wsk[x])->setText("O");
         (*wsk[x])->setEnabled(false);
        gracz=true;
        ui->rundagracza->setText("X");
        sprawdz();


    }

}while(!gracz && rodzaj_gry);
}

void gra::on_P1_clicked()
{
dalej(0);
}

void gra::on_P2_clicked()
{
dalej(1);
}

void gra::on_P3_clicked()
{
dalej(2);
}

void gra::on_P4_clicked()
{
dalej(3);
}

void gra::on_P5_clicked()
{
dalej(4);
}

void gra::on_P6_clicked()
{
dalej(5);
}

void gra::on_P7_clicked()
{
dalej(6);
}

void gra::on_P8_clicked()
{
dalej(7);
}

void gra::on_P9_clicked()
{
dalej(8);
}

void gra::on_reset_clicked()
{
reset();
}


void gra::reset()
{
    for(int i=0;i<9;i++)
    {
        (*wsk[i])->setText(" ");
        (*wsk[i])->setEnabled(true);
    }
    pole="";
    gracz=true;
    ui->rundagracza->setText("X");
}
