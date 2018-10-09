#include "eleve.h"

eleve :: eleve(string v_prenom,string v_nom, string v_dateNaissance, string v_sexe, string v_adresse, string v_telephone, groupe *v_groupe):user(v_prenom,v_nom,v_dateNaissance,v_sexe,v_adresse,v_telephone){
    groupe_Planning = v_groupe;
}

void eleve::affiche(){
    cout << "Je suis etudiant du ";
    groupe_Planning->affiche();
    cout << endl;
    user::affiche();
}
