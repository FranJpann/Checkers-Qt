#ifndef PION_H
#define PION_H

#include <QLabel>
#include <QWidget>
#include <QPainter>

class pion : public QLabel
{
    Q_OBJECT
public:
    pion(int i);
    ~pion();
    void paintEvent(QPaintEvent *e);

    Qt::GlobalColor couleur;
    Qt::GlobalColor couleurContour;
    int player;
    bool isActivated = false;
    bool isDame = false;
    QPixmap pixmapDame;
};

#endif // PION_H
