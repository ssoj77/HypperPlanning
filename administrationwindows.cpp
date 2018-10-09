#include "administrationwindows.h"

administrationWindows::administrationWindows(QWidget *parent, QStackedLayout *monDisplay)
    :QWidget(parent)
{
    gr = new groupe("Groupe A");
    display = monDisplay;
    layoutMain = new QGridLayout;

    //Ajout de membres
    QGroupBox *membre = new QGroupBox(tr("Ajouter un nouveau membre :"));
    QVBoxLayout *layoutMembre = new QVBoxLayout;

    nom = new QLineEdit;
    nom->setPlaceholderText("Nom");
    layoutMembre->addWidget(nom);

    prenom = new QLineEdit;
    prenom->setPlaceholderText("Prenom");
    layoutMembre->addWidget(prenom);

    dateNaissance = new QDateEdit;
    layoutMembre->addWidget(dateNaissance);

    QGroupBox *sexe = new QGroupBox(tr("Sexe :"));
    QGridLayout *layoutSexe = new QGridLayout;
    homme = new QRadioButton(tr("Homme"));
    homme->setChecked(true);
    layoutSexe->addWidget(homme, 0, 0);
    femme = new QRadioButton(tr("Femme"));
    layoutSexe->addWidget(femme, 0, 1);
    sexe->setLayout(layoutSexe);
    layoutMembre->addWidget(sexe);

    adresse = new QLineEdit;
    adresse->setPlaceholderText("Adresse");
    layoutMembre->addWidget(adresse);

    codePostal = new QLineEdit;
    codePostal->setPlaceholderText("Code postal");
    layoutMembre->addWidget(codePostal);

    ville = new QLineEdit;
    ville->setPlaceholderText("Ville");
    layoutMembre->addWidget(ville);

    telephone = new QLineEdit;
    telephone->setPlaceholderText("N° de téléphone");
    layoutMembre->addWidget(telephone);

    eleveTest = new QCheckBox("Le membre à ajouter est-il un eleve ?");
    layoutMembre->addWidget(eleveTest);
    QObject::connect(eleveTest, SIGNAL(stateChanged(int)), this, SLOT(afficheElementSupp(int)));
    groupeLabel = new QLabel("Veuillez selectionner son groupe  :");
    layoutMembre->addWidget(groupeLabel);

    groupeCombo = new QComboBox;
    groupeCombo->addItem("Groupe A");
    groupeCombo->addItem("Groupe B");
    layoutMembre->addWidget(groupeCombo);

    ajoutMembre = new QPushButton("Ajouter");
    layoutMembre->addWidget(ajoutMembre);
    QObject::connect(ajoutMembre, SIGNAL(clicked()), this, SLOT(ajouterMembre()));
    groupeCombo->setDisabled(true);
    groupeLabel->setDisabled(true);

    membre->setLayout(layoutMembre);

    //Gestion des cours
    QGroupBox *cours = new QGroupBox(tr("Ajouter un cours"));
    QVBoxLayout *layoutCours = new QVBoxLayout;

    groupeCours = new QComboBox;
    groupeCours->addItem("Groupe A");
    groupeCours->addItem("Groupe B");
    QLabel *labelGroupe = new QLabel("Groupe :");
    layoutCours->addWidget(labelGroupe);
    layoutCours->addWidget(groupeCours);

    salle = new QComboBox;
    salle->addItem("B11");
    salle->addItem("C22");
    QLabel *labelSalle = new QLabel("Salle :");
    layoutCours->addWidget(labelSalle);
    layoutCours->addWidget(salle);

    prof = new QComboBox;
    prof->addItem("Lalou");
    prof->addItem("Oster");
    QLabel *labelProf = new QLabel("Prof :");
    layoutCours->addWidget(labelProf);
    layoutCours->addWidget(prof);

    QLabel *labelCours = new QLabel("Date et Heure :");
    dateCours = new QDateEdit;
    layoutCours->addWidget(labelCours);
    layoutCours->addWidget(dateCours);

    heureDebut = new QTimeEdit;
    QLabel *labelHeure = new QLabel;
    layoutCours->addWidget(labelHeure);
    layoutCours->addWidget(heureDebut);

    ajoutCours = new QPushButton("Ajouter");
    QObject::connect(ajoutCours, SIGNAL(clicked()), this, SLOT(ajouterCours()));
    layoutCours->addWidget(ajoutCours);
    cours->setLayout(layoutCours);

    //Gestion des groupes
    QGroupBox *groupeBox = new QGroupBox(tr("Créer un nouveau groupe"));
    QVBoxLayout *layoutGroupe = new QVBoxLayout;
    groupeBox->setLayout(layoutGroupe);

    groupeIntitule = new QLineEdit;
    groupeIntitule->setPlaceholderText("Intitule du groupe");
    layoutGroupe->addWidget(groupeIntitule);

    ajoutGroupe = new QPushButton("Ajouter");
    QObject::connect(ajoutGroupe, SIGNAL(clicked()), this, SLOT(ajouterGroupe()));
    layoutGroupe->addWidget(ajoutGroupe);

    layoutMain->addWidget(membre, 0, 0, 2, 1);
    layoutMain->addWidget(groupeBox, 0, 1);
    layoutMain->addWidget(cours, 1, 1);


    deconnexionButton = new QPushButton("Deconnexion");
    QObject::connect(deconnexionButton, SIGNAL(clicked()), this, SLOT(deconnexion()));
    layoutMain->addWidget(deconnexionButton, 2, 1);

    setLayout(layoutMain);

}

void administrationWindows::ajouterMembre(){
    string adresseComplete = adresse->text().toStdString() +", "+  ville->text().toStdString() +", "+ codePostal->text().toStdString();
    string sexePersonne = "Inconnue";
    if(homme->isChecked()){
        sexePersonne = "Homme";
    }
    else{
        sexePersonne = "Femme";
    }

    if(eleveTest->checkState() == 0){
        formateur *prof = new formateur(prenom->text().toStdString(), nom->text().toStdString(), dateNaissance->text().toStdString(), sexePersonne, adresseComplete, telephone->text().toStdString());
        prof->affiche();
    }
    else{
        groupe *groupeA = new groupe("Groupe A");
        eleve *etudiant = new eleve(prenom->text().toStdString(), nom->text().toStdString(), dateNaissance->text().toStdString(), sexePersonne, adresseComplete, telephone->text().toStdString(), groupeA);
        etudiant->affiche();
    }

    std::cout << "Membre ajouter" << std::endl;
}

void administrationWindows::ajouterCours(){
    formateur *prof = new formateur("test", "test", "test", "test", "test", "test");

    cours *newCours = new cours(salle->currentText().toStdString(), heureDebut->text().toStdString(), dateCours->text().toStdString(), "Info", prof, "Groupe A");
    gr->addCours(newCours);
    gr->affiche();
}

void administrationWindows::ajouterGroupe(){
    groupe *newGroupe = new groupe(groupeIntitule->text().toStdString());
    gr->affiche();
}
void administrationWindows::deconnexion(){
    display->setCurrentIndex(0);
}

void administrationWindows::afficheElementSupp(int element){
    if(eleveTest->checkState() == 0){
        groupeCombo->setDisabled(true);
        groupeLabel->setDisabled(true);
    }
    else{
        groupeCombo->setDisabled(false);
        groupeLabel->setDisabled(false);
    }
}

