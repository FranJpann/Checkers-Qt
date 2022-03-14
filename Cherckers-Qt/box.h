#ifndef BOX_H
#define BOX_H

#include <QtWidgets>
#include "pion.h"

class Box : public QWidget
{
    Q_OBJECT
public:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);

    void addPion(pion *p);
    void removePion();

    Box(bool pair, int pos[2]);
    ~Box();

    pion * currentPion;
    bool hasPiece = false;

    int position[2];

    QColor couleurTemp;
    QColor couleurBase;
    QColor couleurActivated = QColor(Qt::green);
    QColor couleurPossibleMove = QColor(Qt::blue);

    void changeColorState(int i){
        switch (i) {
            case 0 : this->couleurTemp = couleurBase; break;
            case 1 : this->couleurTemp = couleurActivated; break;
            case 2 : this->couleurTemp = couleurPossibleMove; break;
        }
    }

signals:
    void activatePion();
    void bougePion();

};


#endif
