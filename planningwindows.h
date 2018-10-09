#ifndef PLANNINGWINDOWS_H
#define PLANNINGWINDOWS_H
#include <iostream>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QList>
#include <QMessageBox>
#include <QStackedLayout>
#define MAX 80

class planningWindows : public QWidget
{
    Q_OBJECT
    public:
        planningWindows(QWidget *parent = 0, QStackedLayout *monDisplay = 0);
        void ajouteCours(int, int, int, QString);

    public slots:
        void afficheInformations();
        void deconnexion();

    private:
        QPushButton *deconnexionButton;
        QGridLayout *layout;
        QList<QLabel*> list;
        QStackedLayout *display;
};

#endif // PLANNINGWINDOWS_H
