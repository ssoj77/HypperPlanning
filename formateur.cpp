#include "formateur.h"

formateur :: formateur(string v_prenom, string v_nom , string v_dateNaissance, string v_sexe, string v_adresse, string v_telephone):user(v_prenom,v_nom,v_dateNaissance,v_sexe,v_adresse,v_telephone){

}

void formateur :: affiche(){
    cout << "Je suis prof !" << endl;
    user::affiche();
}
