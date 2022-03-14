#include "box.h"

Box::Box(bool pair, int pos[2]){
    this->setMinimumSize(50, 50);
    this->setLayout(new QGridLayout());
    this->layout()->setMargin(0);
    if(pair){
        couleurBase = QColor(88, 41, 0);
        couleurTemp = couleurBase;
    }
    else{
        couleurBase = QColor(139, 108, 66);
        couleurTemp = couleurBase;
    }

    position[0] = pos[0];
    position[1] = pos[1];
}

void Box::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    painter.setBrush(couleurTemp);
    painter.drawRect(QRect(0, 0, width(), height()));
}

void Box::mousePressEvent(QMouseEvent *e){
        if(e->button() == Qt::LeftButton){
            if(this->hasPiece) emit activatePion();
            else {
                if(this->couleurTemp == couleurPossibleMove){
                    emit bougePion();
                }
            }
        }
}

void Box::addPion(pion *p){
    this->currentPion = p;
    this->layout()->addWidget(this->currentPion);
    this->hasPiece = true;
}

void Box::removePion(){
    delete this->currentPion;
    this->currentPion = nullptr;
    this->hasPiece = false;
}

Box::~Box(){}
