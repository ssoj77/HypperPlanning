#include "groupe.h"

groupe::groupe(string monNom){
    nom = monNom;
}

void groupe::affiche(){
    cout << nom <<endl;
    unsigned int taille = planning.size();
    for(unsigned int i=0;i<taille;i++){
        planning[i].affiche();
    }
}

void groupe::addCours(cours *new_Cours){
    planning.push_back(*new_Cours);
}
