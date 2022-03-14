#include "fenetre.h"
#include "zoneplateau.h"
#include <iostream>

void fenetre::aboutCheckers(){
    QMessageBox::about(this, tr("About checkers"),
                       tr("This app was made by CADY Loann as part of a "
                          "computer science project on Qt."));
}

void fenetre::changeLangue(QString s){
    translator->load("JeuDame_"+s+".qm");
    this->setWindowTitle(tr("Checkers"));
    //this->menuBar()->clear();
    menuFile->setTitle(tr("File"));
        ActionNewGame->setText(tr("New Game"));
        ActionNewGame->setStatusTip(tr("Start a new game"));
        ActionSave->setText(tr("Save"));
        ActionSave->setStatusTip(tr("Save the game"));
        ActionLoad->setText(tr("Load"));
        ActionLoad->setStatusTip(tr("Load a save"));
        ActionExit->setText(tr("Exit"));
        ActionExit->setStatusTip(tr("Exit"));
    QList<QAction *> L;
    L = menuAbout->actions();
        L.at(0)->setText(tr("About Qt"));
        L.at(1)->setText(tr("About Checkers"));
}

fenetre::fenetre()
    : QMainWindow()
{
    translator = new QTranslator();
    translator->load("JeuDame_"+QLocale::system().name()+".qm");
    qApp->installTranslator(translator);

    this->setWindowTitle(tr("Checkers"));
    /*--------------------------------*/
    //Menu Fichier

    menuFile = new QMenu(tr("File"));
        ActionNewGame = new QAction(tr("New Game"));
        ActionNewGame->setStatusTip(tr("Start a new game"));
        ActionNewGame->setShortcut(QKeySequence("Ctrl+N"));

        ActionSave = new QAction(tr("Save"));
        ActionSave->setStatusTip(tr("Save the game"));
        ActionSave->setShortcut(QKeySequence("Ctrl+S"));

        ActionLoad = new QAction(tr("Load"));
        ActionLoad->setStatusTip(tr("Load a save"));
        ActionLoad->setShortcut(QKeySequence("Ctrl+O"));

        ActionExit = new QAction(tr("Exit"));
        ActionExit->setStatusTip(tr("Exit"));
        ActionExit->setShortcut(QKeySequence("Ctrl+Q"));
        QObject::connect(ActionExit, &QAction::triggered,
                         this, &QMainWindow::close);

    menuFile->addAction(ActionNewGame);
    menuFile->addAction(ActionSave);
    menuFile->addAction(ActionLoad);
    menuFile->addSeparator();
    menuFile->addAction(ActionExit);

    this->menuBar()->addMenu(menuFile);

    /*--------------------------------*/
    //Menu A propos

    AboutIcon = style()->standardPixmap(QStyle::SP_DialogHelpButton);
    InfoIcon = style()->standardPixmap(QStyle::SP_FileDialogInfoView);

    menuAbout = new QMenu();
        menuAbout->setIcon(AboutIcon);
        menuAbout->addAction(InfoIcon, tr("About Qt"), qApp, &QApplication::aboutQt);
        menuAbout->addAction(InfoIcon, tr("About checkers"), this, &fenetre::aboutCheckers);
    this->menuBar()->addMenu(menuAbout);

    /*--------------------------------*/
    //MenuLangue

    QIcon langueIcon = style()->standardPixmap(QStyle::SP_ComputerIcon);

    QMenu * menuLangue = new QMenu();
    menuLangue->setIcon(langueIcon);
        QAction  * fr_FR = new QAction("Français");
        QObject::connect(fr_FR, &QAction::triggered, [=](){ changeLangue("fr_FR"); });
        QAction * en_US = new QAction("American English");
        QObject::connect(en_US, &QAction::triggered, [=](){ changeLangue("en_US"); });
    menuLangue->addAction(fr_FR);
    menuLangue->addAction(en_US);

    this->menuBar()->addMenu(menuLangue);

    /*--------------------------------*/
    //PlateauPrincipal
    zonePlateau * plateau = new zonePlateau();

    QObject::connect(ActionNewGame, &QAction::triggered,
                     plateau, &zonePlateau::confirmNewTab);

    QObject::connect(ActionLoad, &QAction::triggered,
                     plateau, &zonePlateau::confirmOpenTab);

    QObject::connect(ActionSave, &QAction::triggered,
                     plateau, &zonePlateau::saveTableauPieces);

    this->setCentralWidget(plateau);

    /*--------------------------------*/
    //Status Bar

    this->statusBar()->show();
    QObject::connect(plateau, &zonePlateau::afficheStatusBar,
                     [=](){
            if(b==1) this->statusBar()->showMessage(tr("Active Player: ") +QString::number(plateau->activePlayer));
            else if(b==2) this->statusBar()->showMessage(tr("New game! Active Player: ") +QString::number(plateau->activePlayer));
            else if(b==3) this->statusBar()->showMessage(tr("Game saved."));
            else if(b==4) this->statusBar()->showMessage(tr("Save loaded! Active Player: ") +QString::number(plateau->activePlayer));
            else if(b==5) this->statusBar()->showMessage(tr("Fin de partie !"));
    });
    QObject::connect(plateau, &zonePlateau::restartStatusBar, [=](){ b=1; });
    QObject::connect(plateau, &zonePlateau::newStarted, [=](){b=2;});
    QObject::connect(plateau, &zonePlateau::saved, [=](){b=3;});
    QObject::connect(plateau, &zonePlateau::loaded, [=](){b=4;});
    QObject::connect(plateau, &zonePlateau::fin, [=](){b=5;});

}

fenetre::~fenetre(){}
