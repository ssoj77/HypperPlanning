#include <QApplication>
#include <QStackedLayout>
#include <iostream>
#include "connexionwindows.h"
#include "planningwindows.h"
#include "administrationwindows.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *main = new QWidget;
    main->resize(1500, 1000);

    QStackedLayout *display = new QStackedLayout;

    connexionWindows connexion(main, display);
    planningWindows planning(main, display);
    administrationWindows administration(main, display);

    display->addWidget(&connexion);
    display->addWidget(&planning);
    display->addWidget(&administration);

    main->setLayout(display);
    main->show();
    main->move(350, 300);

    return app.exec();
}
