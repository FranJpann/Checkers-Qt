#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QtWidgets>

class fenetre : public QMainWindow
{
    Q_OBJECT
public:
    fenetre();
    ~fenetre();

    void aboutCheckers();
    void changeLangue(QString s);

    QTranslator * translator;
    QIcon AboutIcon;
    QIcon InfoIcon;

    QMenu * menuFile;
    QAction * ActionNewGame;
    QAction * ActionSave;
    QAction * ActionLoad;
    QAction * ActionExit;
    QMenu * menuAbout;

    int b = 1;
};

#endif // FENETRE_H
