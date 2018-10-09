#include "planningwindows.h"

planningWindows::planningWindows(QWidget *parent, QStackedLayout *monDisplay)
    :QWidget(parent)
{
    display = monDisplay;

    QLabel *title = new QLabel("HyperPlanning");
    QLabel *lundi = new QLabel("Lundi");
    QLabel *mardi = new QLabel("Mardi");
    QLabel *mercredi = new QLabel("Mercredi");
    QLabel *jeudi = new QLabel("Jeudi");
    QLabel *vendredi = new QLabel("Vendredi");

    for(int i=0; i<11; i++){
        list << new QLabel(QString::number(i+8)+"H");
    }

    layout = new QGridLayout;

    title->setStyleSheet("font-weight : bold; font-size: 28pt;");
    title->setMaximumHeight(130);
    layout->addWidget(title, 0, 0, 1, 12, Qt::AlignHCenter);

    for(int i=0; i<11; i++){
        list[i]->setStyleSheet("border: 1px solid black;");
        list[i]->setMinimumWidth(200);
        list[i]->setMaximumHeight(50);
        layout->addWidget(list[i], 1, i+1, 1, 1, Qt::AlignHCenter);
    }

    layout->addWidget(lundi, 2, 0, 1, 1 , Qt::AlignHCenter);
    layout->addWidget(mardi, 3, 0, 1, 1 , Qt::AlignHCenter);
    layout->addWidget(mercredi, 4, 0, 1, 1 , Qt::AlignHCenter);
    layout->addWidget(jeudi, 5, 0, 1, 1 , Qt::AlignHCenter);
    layout->addWidget(vendredi, 6, 0, 1, 1 , Qt::AlignHCenter);

    deconnexionButton = new QPushButton("Deconnexion");
    QObject::connect(deconnexionButton, SIGNAL(clicked()), this, SLOT(deconnexion()));
    layout->addWidget(deconnexionButton,7, 11);

    ajouteCours(2, 0, 3, "Math");
    ajouteCours(4, 1, 0, "Structure");
    ajouteCours(1, 2, 5, "Francais");
    ajouteCours(3, 3, 2, "C++");
    ajouteCours(1, 4, 8, "BD");


    setLayout(layout);
}

void planningWindows::afficheInformations(){
     QMessageBox::information(this, "Inforamtions", "Cours de 8H à 9H\nSalle C22");
}


void planningWindows::ajouteCours(int duree, int jour, int heureDebut, QString intitule){
    QPushButton *cours = new QPushButton(intitule);
    cours->setStyleSheet("background-color: blue;");
    layout->addWidget(cours, 2+jour, 1+heureDebut, 1, duree);
    QObject::connect(cours, SIGNAL(clicked()), this, SLOT(afficheInformations()));
}

void planningWindows::deconnexion(){
    display->setCurrentIndex(0);
}
