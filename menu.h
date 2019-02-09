#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_gracz_clicked();

    void on_komputer_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
