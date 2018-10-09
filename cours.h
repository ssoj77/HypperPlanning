#ifndef COURS_H
#define COURS_H
#include "formateur.h"

class cours{
    private:
        string salle;
        string heure_Debut;
        formateur *prof;
        string g_Eleve;
        string jour;
        string matiere;

    public:
        cours(string, string, string, string, formateur* ,string);
        void affiche();

};

#endif // COURS_H
