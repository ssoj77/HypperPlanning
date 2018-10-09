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


    QGroupBox *membreSpeciaux = new QGroupBox(tr("Champs spéciaux :"));
    QGridLayout *layoutMembreSpeciaux = new QGridLayout;
    membreSpeciaux->setLayout(layoutMembreSpeciaux);

    typeMembre = new QComboBox;
    typeMembre->addItem("Eleve");
    typeMembre->addItem("Formateur");
    typeMembre->addItem("Administrateur");
    layoutMembreSpeciaux->addWidget(typeMembre, 0, 0);
    QObject::connect(typeMembre, SIGNAL(currentIndexChanged(int)), this, SLOT(afficheElementSupp(int)));

    groupeLabel = new QLabel("Pour les eleves :");
    layoutMembreSpeciaux->addWidget(groupeLabel, 1, 0);
    groupeCombo = new QComboBox;
    groupeCombo->addItem("Groupe A");
    groupeCombo->addItem("Groupe B");
    layoutMembreSpeciaux->addWidget(groupeCombo, 2, 0);

    formateurLabel = new QLabel("Pour les formateurs :");
    formateurLabel->setDisabled(true);
    layoutMembreSpeciaux->addWidget(formateurLabel, 1, 1);
    job = new QLineEdit;
    job->setPlaceholderText("Job");
    job->setDisabled(true);
    layoutMembreSpeciaux->addWidget(job, 2, 1);

    layoutMembre->addWidget(membreSpeciaux);



    ajoutMembre = new QPushButton("Ajouter");
    layoutMembre->addWidget(ajoutMembre);
    QObject::connect(ajoutMembre, SIGNAL(clicked()), this, SLOT(ajouterMembre()));

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

    //Gestion des matières

    layoutMain->addWidget(membre, 0, 0);
    layoutMain->addWidget(cours, 0, 1);

    deconnexionButton = new QPushButton("Deconnexion");
    QObject::connect(deconnexionButton, SIGNAL(clicked()), this, SLOT(deconnexion()));
    layoutMain->addWidget(deconnexionButton, 1, 1);

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

    if(typeMembre->currentText().toStdString() == "Eleve"){
        groupe *groupeA = new groupe("Groupe A");
        eleve *etudiant = new eleve(prenom->text().toStdString(), nom->text().toStdString(), dateNaissance->text().toStdString(), sexePersonne, adresseComplete, telephone->text().toStdString(), groupeA);
        etudiant->affiche();
    }
    else if(typeMembre->currentText().toStdString() == "Formateur"){
        formateur *prof = new formateur(prenom->text().toStdString(), nom->text().toStdString(), dateNaissance->text().toStdString(), sexePersonne, adresseComplete, telephone->text().toStdString());
        prof->affiche();
    }
    else if(typeMembre->currentText().toStdString() == "Administrateur"){

    }
    std::cout << "Membre ajouter" << std::endl;
}

void administrationWindows::ajouterCours(){
    formateur *prof = new formateur("test", "test", "test", "test", "test", "test");

    cours *newCours = new cours(salle->currentText().toStdString(), heureDebut->text().toStdString(), dateCours->text().toStdString(), "Info", prof, "Groupe A");
    gr->addCours(newCours);
    gr->affiche();
}

void administrationWindows::deconnexion(){
    display->setCurrentIndex(0);
}

void administrationWindows::afficheElementSupp(int element){
    if(typeMembre->currentText().toStdString() == "Eleve"){
        groupeCombo->setDisabled(false);
        groupeLabel->setDisabled(false);
        job->setDisabled(true);
        formateurLabel->setDisabled(true);
    }
    else if(typeMembre->currentText().toStdString() == "Formateur"){
        groupeCombo->setDisabled(true);
        groupeLabel->setDisabled(true);
        job->setDisabled(false);
        formateurLabel->setDisabled(false);
    }
    else if(typeMembre->currentText().toStdString() == "Administrateur"){

    }
}

