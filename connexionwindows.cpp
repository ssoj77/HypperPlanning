#include "connexionwindows.h"

using namespace std;

connexionWindows::connexionWindows(QWidget *parent, QStackedLayout *monDisplay)
    :QWidget(parent)
{
    display = monDisplay;
    QLabel *title = new QLabel("HyperPlanning");
    title->setStyleSheet("font-weight : bold; font-size: 28pt; margin-right: 25px;");
    title->setMaximumHeight(130);

    login = new QLineEdit;
    login->setMaximumWidth(250);

    QLabel *textLogin = new QLabel("Login :             ");
    textLogin->setStyleSheet("font-weight : bold;");

    mdp = new QLineEdit;
    mdp->setEchoMode(QLineEdit::Password);
    mdp->setMaximumWidth(250);

    QLabel *textMdp = new QLabel("Mot de passe :");
    textMdp->setStyleSheet("font-weight : bold;");

    connexion = new QPushButton("Connexion");

    quitter = new QPushButton("Quitter");

    erreur = new QLabel(" ");
    erreur->setMaximumHeight(50);

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(title, 0, 0, 1, 2, Qt::AlignHCenter);
    layout->addWidget(textLogin, 1, 0, 1, 1, Qt::AlignRight);
    layout->addWidget(login, 1, 1, 1, 1, Qt::AlignLeft);
    layout->addWidget(textMdp, 2, 0, 1, 1, Qt::AlignRight);
    layout->addWidget(mdp, 2, 1, 1, 1, Qt::AlignLeft);
    layout->addWidget(connexion, 3, 0, 1, 2, Qt::AlignHCenter);
    layout->addWidget(quitter, 4, 0, 1, 2, Qt::AlignHCenter);
    layout->addWidget(erreur, 5, 0, 1, 2, Qt::AlignHCenter);

    QObject::connect(connexion, SIGNAL(clicked()), this, SLOT(testIdentifiant()));
    QObject::connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    setLayout(layout);
}

void connexionWindows::testIdentifiant()
{

    if(login->text() == "admin" && mdp->text() == "admin"){
        display->setCurrentIndex(2);
    }
    else if(login->text() == "user" && mdp->text() == "user"){
        display->setCurrentIndex(1);
    }
    else{
        erreur->setText("Veuillez verifier vos identifiants !");
        erreur->setStyleSheet("color: red; font-weight: bold;");
    }
    login->setText("");
    mdp->setText("");
}
