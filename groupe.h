#ifndef GROUPE_H
#define GROUPE_H
#include "cours.h"
#include <vector>

class groupe{
    private:
        vector<cours> planning;
        string nom;

    public:
        groupe(string);
        void addCours(cours*);
        void affiche();
};

#endif // GROUPE_H
