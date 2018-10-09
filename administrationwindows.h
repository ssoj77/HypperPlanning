#ifndef ADMINISTRATIONWINDOWS_H
#define ADMINISTRATIONWINDOWS_H
#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QDateEdit>
#include <QGridLayout>
#include <QRadioButton>
#include <QPushButton>
#include <iostream>
#include <QComboBox>
#include <QTimeEdit>
#include <QStackedLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QCheckBox>
#include "eleve.h"
#include "formateur.h"
#include "cours.h"
#include "groupe.h"
#include "other.h"

class administrationWindows : public QWidget
{
    Q_OBJECT

    private:
        QGridLayout *layoutMain;
        groupe *gr;

        //Gestion des membres
        QLineEdit *nom;
        QLineEdit *prenom;
        QDateEdit *dateNaissance;
        QRadioButton *homme;
        QRadioButton *femme;
        QLineEdit *adresse;
        QLineEdit *codePostal;
        QLineEdit *ville;
        QLineEdit *telephone;

        //Element supplmentaire par type
        QCheckBox *eleveTest;
        QComboBox *groupeCombo;
        QLabel *groupeLabel;

        QPushButton *ajoutMembre;

        //Gestion des cours
        QComboBox *groupeCours;
        QComboBox *salle;
        QComboBox *prof;
        QDateEdit *dateCours;
        QTimeEdit *heureDebut;
        QPushButton *ajoutCours;

        //Gestion des groupes
        QLineEdit *groupeIntitule;
        QPushButton *ajoutGroupe;


        QStackedLayout *display;
        QPushButton *deconnexionButton;

    public:
        administrationWindows(QWidget *parent = 0, QStackedLayout *monDisplay =0);

    public slots:
        void ajouterMembre();
        void ajouterCours();
        void ajouterGroupe();
        void deconnexion();
        void afficheElementSupp(int);
};

#endif // ADMINISTRATIONWINDOWS_H
