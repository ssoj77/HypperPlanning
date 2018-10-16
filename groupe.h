#ifndef GROUPE_H
#define GROUPE_H
#include "cours.h"
#include <vector>

class groupe{
    protected:
        vector<cours> planning;
        string nom;

    public:
        groupe(string);
        void addCours(cours*);
        void affiche();
        string getGroupe();
};

#endif // GROUPE_H
