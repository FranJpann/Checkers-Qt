#include <iostream>
#include <QApplication>
#include "fenetre.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication * a = new QApplication(argc, argv);

    fenetre f;
    f.setWindowIcon(QIcon(":/annexes/crown_white.png"));
    f.show();

    return a->exec();
}
