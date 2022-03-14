#include "pion.h"

pion::pion(int i){
    switch (i) {
        case 1 :
            couleur = Qt::white;
            couleurContour = Qt::black;
            player = 1;
            pixmapDame.load(":/annexes/crown_black.png");
            break;
        case 2 :
            couleur = Qt::black;
            couleurContour = Qt::white;
            player = 2;
            pixmapDame.load(":/annexes/crown_white.png");
            break;
    }
}

void pion::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen p(couleurContour);
    p.setWidth(3);
    painter.setPen(p);
    painter.setBrush(QBrush(couleur));
    painter.drawEllipse(QRect(5, 5, width() - 10, height() - 10));
    if(isDame){
            painter.drawPixmap(QRect(12, 12, width()-25, height()-25), pixmapDame);
    }
}

pion::~pion(){}
