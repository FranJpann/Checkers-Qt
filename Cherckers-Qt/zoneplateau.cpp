#include "zoneplateau.h"
#include "pion.h"
#include "box.h"

zonePlateau::zonePlateau()
{
    this->setMinimumSize(500, 500);
    creerDamier();
    loadNewTableauPieces();
}

void zonePlateau::showMoves(int posx, int posy){
    Box * b = this->damier[posx][posy];
    //SI JOUEUR = 1
    if(b->currentPion->player == 1 && activePlayer == 1){
        if(pionActif == 0){
            b->changeColorState(1);
            if(posx < 9 && posy < 9 && !(this->damier[posx+1][posy+1]->hasPiece))
                this->damier[posx+1][posy+1]->changeColorState(2);
            else if(posy < 8 && posx < 8 && this->damier[posx+1][posy+1]->hasPiece && !(this->damier[posx+2][posy+2]->hasPiece) && (this->damier[posx+1][posy+1]->currentPion->player == 2)){
                this->damier[posx+1][posy+1]->changeColorState(2);
                this->damier[posx+2][posy+2]->changeColorState(2);
            }
            if(posx < 9  && posy > 0 && !(this->damier[posx+1][posy-1]->hasPiece))
                this->damier[posx+1][posy-1]->changeColorState(2);
            else if(posy > 1 && posx < 8 && this->damier[posx+1][posy-1]->hasPiece && !(this->damier[posx+2][posy-2]->hasPiece) && (this->damier[posx+1][posy-1]->currentPion->player == 2)){
                this->damier[posx+1][posy-1]->changeColorState(2);
                this->damier[posx+2][posy-2]->changeColorState(2);
            }
            pionActif++;
            b->currentPion->isActivated = true;
            pionActive = b;
        }
        else if(pionActif == 1 && b->currentPion->isActivated){
            b->changeColorState(0);
            if(posx < 9 && posy < 9)
                this->damier[posx+1][posy+1]->changeColorState(0);
            if(posx < 9 && posy > 0)
                this->damier[posx+1][posy-1]->changeColorState(0);
            if(posy < 8 && posx < 8)
                this->damier[posx+2][posy+2]->changeColorState(0);
            if(posy > 1 && posx < 8)
                this->damier[posx+2][posy-2]->changeColorState(0);
            pionActif--;
            b->currentPion->isActivated = false;
        }
    }

    //SI JOUEUR = 2
    else if(b->currentPion->player == 2 && activePlayer == 2){
        if(pionActif == 0){
            b->changeColorState(1);
            if(posx > 0 && posy < 9 && !(this->damier[posx-1][posy+1]->hasPiece))
                this->damier[posx-1][posy+1]->changeColorState(2);
            else if(posy < 8 && posx > 1 && this->damier[posx-1][posy+1]->hasPiece && !(this->damier[posx-2][posy+2]->hasPiece) && (this->damier[posx-1][posy+1]->currentPion->player == 1)){
                this->damier[posx-1][posy+1]->changeColorState(2);
                this->damier[posx-2][posy+2]->changeColorState(2);
            }
            if(posx > 0 && posy > 0 && !(this->damier[posx-1][posy-1]->hasPiece))
                this->damier[posx-1][posy-1]->changeColorState(2);
            else if(posy > 1 && posx > 1 && this->damier[posx-1][posy-1]->hasPiece && !(this->damier[posx-2][posy-2]->hasPiece) && (this->damier[posx-1][posy-1]->currentPion->player == 1)){
                this->damier[posx-1][posy-1]->changeColorState(2);
                this->damier[posx-2][posy-2]->changeColorState(2);
            }
            pionActif++;
            b->currentPion->isActivated = true;
            pionActive = b;
        }
        else if(pionActif == 1 && b->currentPion->isActivated){
            b->changeColorState(0);
            if(posx > 0 && posy < 9)
                this->damier[posx-1][posy+1]->changeColorState(0);
            if(posx > 0 && posy > 0)
                this->damier[posx-1][posy-1]->changeColorState(0);
            if(posx > 1 && posy < 8)
                this->damier[posx-2][posy+2]->changeColorState(0);
            if(posx > 1 && posy > 1)
                this->damier[posx-2][posy-2]->changeColorState(0);
            pionActif--;
            b->currentPion->isActivated = false;
        }
    }
}

void zonePlateau::showUnshowDames(int posx, int posy, int c){

    bool cond = false;
    for(int i = (posx + 1), j = (posy + 1) ; (i < 10 && j < 10 && !cond) ; i++, j++){
        if(damier[i][j]->hasPiece){
            if(i==9 || j==9 || damier[i][j]->currentPion->player == activePlayer || damier[i+1][j+1]->hasPiece) cond = true;
            else damier[i][j]->changeColorState(c);
        }
        else damier[i][j]->changeColorState(c);
    } cond = false;
    for(int i = (posx - 1), j = (posy - 1) ; (i >= 0 && j >= 0 && !cond) ; i--, j--){
        if(damier[i][j]->hasPiece){
            if(i==0 || j==0 || damier[i][j]->currentPion->player == activePlayer || damier[i-1][j-1]->hasPiece) cond = true;
            else damier[i][j]->changeColorState(c);
        }
        else damier[i][j]->changeColorState(c);
    } cond = false;
    for(int i = (posx - 1), j = (posy + 1) ; (i >= 0 && j < 10 && !cond) ; i--, j++){
        if(damier[i][j]->hasPiece){
            if(i==0 || j==9 || damier[i][j]->currentPion->player == activePlayer || damier[i-1][j+1]->hasPiece) cond = true;
            else damier[i][j]->changeColorState(c);
        }
        else damier[i][j]->changeColorState(c);
    } cond = false;
    for(int i = (posx + 1), j = (posy - 1) ; (i < 10 && j >= 0 && !cond) ; i++, j--){
        if(damier[i][j]->hasPiece){
            if(i==9 || j==0 || damier[i][j]->currentPion->player == activePlayer || damier[i+1][j-1]->hasPiece) cond = true;
            else damier[i][j]->changeColorState(c);
        }
        else damier[i][j]->changeColorState(c);
    } cond = false;
}

void zonePlateau::showMovesDame(int posx, int posy){
    Box * b = this->damier[posx][posy];
        if(pionActif == 0 && b->currentPion->player == activePlayer){
            b->changeColorState(1);
            showUnshowDames(posx, posy, 2);
            pionActif++;
            b->currentPion->isActivated = true;
            pionActive = b;
        }
        else if(pionActif == 1 && b->currentPion->isActivated){
            b->changeColorState(0);
            showUnshowDames(posx, posy, 0);
            pionActif--;
            b->currentPion->isActivated = false;
        }
}

void zonePlateau::finPartie(){
    int pionB = 0;
    int pionN = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(damier[i][j]->hasPiece){
                if(damier[i][j]->currentPion->player == 1) pionB++;
                else pionN++;
            }
        }
    }
    if(pionB == 0){
        activePlayer = 0;
        QMessageBox::information(this, tr("End !"), tr("Congratulations Player 2, you won!"));
        emit fin();
    }
    else if(pionN == 0){
        activePlayer = 0;
        QMessageBox::information(this, tr("End !"), tr("Congratulations Player 1, you won!"));
        emit fin();
    }
}

void zonePlateau::creerDamier(){
    QGridLayout * layout = new QGridLayout(this);
    layout->setSpacing(0);
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            int pos[2]= {i, j};
            Box * b = new Box(((j+i)%2), pos);

            //SI UN PION EST CLIQUE
            QObject::connect(b, &Box::activatePion,
                             [=](){
                if(!(b->currentPion->isDame))
                    showMoves(i, j);
                else if(b->currentPion->isDame)
                    showMovesDame(i, j);
                update();
            });

            //SI UNE BOX VERTE EST SELECTIONEE
            QObject::connect(b, &Box::bougePion,
                             [=](){
                int posx = pionActive->position[0]; // position x de l'ancienne box
                int posy = pionActive->position[1]; // position y de l'ancienne box
                int posxNew = b->position[0]; // position x de la nouvelle box
                int posyNew = b->position[1]; // position y de la nouvelle box
                if(!pionActive->currentPion->isDame){
                    showMoves(posx, posy); // Désactive les mouvements possibles du pion
                    // enlève le possible pion mangé
                    if(posxNew == (posx+2) && posyNew == (posy+2)) this->damier[posx+1][posy+1]->removePion();
                    if(posxNew == (posx+2) && posyNew == (posy-2)) this->damier[posx+1][posy-1]->removePion();
                    if(posxNew == (posx-2) && posyNew == (posy+2)) this->damier[posx-1][posy+1]->removePion();
                    if(posxNew == (posx-2) && posyNew == (posy-2)) this->damier[posx-1][posy-1]->removePion();
                    pionActive->hasPiece = false;
                    b->addPion(pionActive->currentPion);
                    //  si pion au bout du terrain, devient dame
                    if((posxNew == 9 && b->currentPion->player == 1) || (posxNew == 0 && b->currentPion->player == 2)) b->currentPion->isDame = true;
                }
                else{
                    showMovesDame(posx, posy); // Désactive les mouvements possibles de la dame
                    //enlève les possibles pions mangés
                    if(posxNew > posx && posyNew > posy){
                        for(int i = (posx+1), j = (posy+1) ; i != posxNew && j != posyNew ; i++, j++){
                            if(damier[i][j]->hasPiece) damier[i][j]->removePion();
                        }
                    }
                    if(posxNew < posx && posyNew < posy){
                        for(int i = (posx-1), j = (posy-1) ; i != posxNew && j != posyNew ; i--, j--){
                            if(damier[i][j]->hasPiece) damier[i][j]->removePion();
                        }
                    }
                    if(posxNew > posx && posyNew < posy){
                        for(int i = (posx+1), j = (posy-1) ; i != posxNew && j != posyNew ; i++, j--){
                            if(damier[i][j]->hasPiece) damier[i][j]->removePion();
                        }
                    }
                    if(posxNew < posx && posyNew > posy){
                        for(int i = (posx-1), j = (posy+1) ; i != posxNew && j != posyNew ; i--, j++){
                            if(damier[i][j]->hasPiece) damier[i][j]->removePion();
                        }
                    }
                    pionActive->hasPiece = false;
                    b->addPion(pionActive->currentPion);
                }
                update();
                switchPlayer();
                finPartie();
            });

            this->damier[i][j] = b;
            layout->addWidget(b, i, j);
        }
    }
    this->setLayout(layout);
}

void zonePlateau::loadTableauPieces(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            Box * b = this->damier[i][j];
            b->changeColorState(0);
            if(b->hasPiece){
                b->removePion();
            }
            if(this->tableauPieces[i][j] == 1) b->addPion(new pion(1));
            else if(this->tableauPieces[i][j] == 2) b->addPion(new pion(2));
            else if(this->tableauPieces[i][j] == 10){
                pion *p = new pion(1);
                p->isDame = true;
                b->addPion(p);
            }
            else if(this->tableauPieces[i][j] == 20){
                pion *p = new pion(2);
                p->isDame = true;
                b->addPion(p);
            }
        }
    }
    pionActif = 0;
}

void zonePlateau::confirmNewTab(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("New game"), tr("Are you sure you want to start a new game?"), QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        loadNewTableauPieces();
        emit newStarted();
    }
}

void zonePlateau::confirmOpenTab(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Load save"), tr("Do you want to load a new save?"), QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        openTableauPieces();
    }
}

void zonePlateau::loadNewTableauPieces(){
        int tabTemp[10][10] {       {0, 1, 0, 1, 0, 1, 0, 1, 0, 1} ,
                                    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0} ,
                                    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1} ,
                                    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0} ,
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                    {0, 2, 0, 2, 0, 2, 0, 2, 0, 2} ,
                                    {2, 0, 2, 0, 2, 0, 2, 0, 2, 0} ,
                                    {0, 2, 0, 2, 0, 2, 0, 2, 0, 2} ,
                                    {2, 0, 2, 0, 2, 0, 2, 0, 2, 0} ,
                                };
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                this->tableauPieces[i][j] = tabTemp[i][j];
            }
        }
        activePlayer = 1;
        loadTableauPieces();
}

void zonePlateau::openTableauPieces(){
    QFile file(QFileDialog::getOpenFileName(this));
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream ts(&file);
        int nombre;
        ts >> nombre;
        activePlayer = nombre;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                ts >> nombre;
                this->tableauPieces[i][j] = nombre;
            }
        }
        loadTableauPieces();
        emit loaded();
    }
    else{
        QMessageBox mb;
        mb.critical(this, tr("Error"), tr("Unexpected error, please retry."));
        mb.setFixedSize(100, 100);
    }
}

void zonePlateau::saveTableauPieces(){
    QFile file(QFileDialog::getSaveFileName(this) + ".save");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream ts(&file);
        ts << activePlayer << endl;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(this->damier[i][j]->hasPiece){
                    ts << this->damier[i][j]->currentPion->player;
                    if(this->damier[i][j]->currentPion->isDame) ts << 0;
                    ts << " ";
                }
                else ts << 0 << " ";
            }
            ts << endl;
        }
        emit saved();
    }
}

zonePlateau::~zonePlateau(){}
