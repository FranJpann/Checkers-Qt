#ifndef ZONEPLATEAU_H
#define ZONEPLATEAU_H

#include <QtWidgets>
#include "box.h"

class zonePlateau : public QWidget
{
    Q_OBJECT
public:
    zonePlateau();
    ~zonePlateau();

    void enterEvent(QEvent *)
    {
        emit afficheStatusBar();
    }

    void switchPlayer(){
        if(activePlayer == 1) activePlayer = 2;
        else activePlayer = 1;
        emit restartStatusBar();
        emit afficheStatusBar();
    }

    int otherPlayer(){
        if(activePlayer == 1) return 2;
        else return 1;
    }

    void creerDamier();

    void finPartie();

    void showMoves(int posx, int posy);
    void showMovesDame(int posx, int posy);
    void showUnshowDames(int posx, int posy, int c);

    void loadTableauPieces();       //Charge la matrice damier
    void confirmNewTab();
    void loadNewTableauPieces();    //Permet de créer une nouvelle matrice damier et la charge
    void confirmOpenTab();
    void openTableauPieces();       //Ouvre un .save avec une matrice
    void saveTableauPieces();       //Sauvegarde un .save avec une matrice

    Box *damier[10][10];
    int tableauPieces[10][10];
    int activePlayer = 1;
    int pionActif = 0;
    Box *pionActive;

signals:
    void afficheStatusBar();
    void restartStatusBar();
    void saved();
    void loaded();
    void newStarted();
    void fin();
};

#endif // ZONEPLATEAU_H
