#ifndef CONNEXIONWINDOWS_H
#define CONNEXIONWINDOWS_H
#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QApplication>
#include <QLabel>
#include <QStackedLayout>
#include <QLineEdit>

class connexionWindows : public QWidget
{
    Q_OBJECT

    public:
        connexionWindows(QWidget *parent = 0, QStackedLayout *monDisplay = 0);

    public slots:
         void testIdentifiant();

    private:
        QLineEdit *login;
        QLineEdit *mdp;
        QPushButton *quitter;
        QPushButton *connexion;
        QStackedLayout *display;
        QLabel *erreur;

};

#endif // CONNEXIONWINDOWS_H
