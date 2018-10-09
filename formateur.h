#ifndef FORMATEUR_H
#define FORMATEUR_H
#include "user.h"

class formateur : public user{
    private:

    public:
        formateur(string , string, string, string, string, string);
        void affiche();

};

#endif // FORMATEUR_H
