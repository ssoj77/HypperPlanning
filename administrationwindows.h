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
        QComboBox *typeMembre;
        //Element supplmentaire par type
        QComboBox *groupeCombo;
        QLabel *groupeLabel;
        QLabel *formateurLabel;
        QLineEdit *job;
        QLabel *labelJob;
        QPushButton *ajoutMembre;

        //Gestion des cours
        QComboBox *groupeCours;
        QComboBox *salle;
        QComboBox *prof;
        QDateEdit *dateCours;
        QTimeEdit *heureDebut;
        QPushButton *ajoutCours;

        //Gestion des matières


        QStackedLayout *display;
        QPushButton *deconnexionButton;

    public:
        administrationWindows(QWidget *parent = 0, QStackedLayout *monDisplay =0);

    public slots:
        void ajouterMembre();
        void ajouterCours();
        void deconnexion();
        void afficheElementSupp(int);
};

#endif // ADMINISTRATIONWINDOWS_H
