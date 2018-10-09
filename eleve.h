#ifndef ELEVE_H
#define ELEVE_H
#include "user.h"
#include "groupe.h"

class eleve : public user{
protected:
    groupe *groupe_Planning;

public:
    eleve(string,string,string, string, string, string, groupe*);
    void affiche();

};

#endif // ELEVE_H
