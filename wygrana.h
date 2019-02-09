#ifndef WYGRANA_H
#define WYGRANA_H

#include <QDialog>


namespace Ui {
class wygrana;
}

class wygrana : public QDialog
{
    Q_OBJECT

public:
    explicit wygrana(QWidget *parent = 0);
    void wyswietl(bool);
    ~wygrana();

private slots:
    void on_OK_clicked();

private:
    Ui::wygrana *ui;
};

#endif // WYGRANA_H
