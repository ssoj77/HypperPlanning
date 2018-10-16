#include "user.h"

user :: user(string v_prenom, string v_nom , string v_dateNaissance, string v_sexe, string v_adresse, string v_telephone){
    prenom = v_prenom;
    nom= v_nom;
    date_Naissance = v_dateNaissance;
    sexe = v_sexe;
    adresse = v_adresse;
    telephone = v_telephone;
}
void user :: affiche(){
    cout << "Identite :" << endl;
    cout << "	-" << prenom << endl;
    cout << "	-" << nom << endl;
    cout << "	-" << date_Naissance << endl;
    cout << "	-" << sexe << endl;
    cout << "	-" << adresse << endl;
    cout << "	-" << telephone << endl << endl;
}

string user::getNom() {
    return nom;
}

string user::getPrenom() {
    return prenom;
}

string user::getDateNaissance() {
    return date_Naissance;
}

string user::getSexe() {
    return sexe;
}

string user::getAdresse() {
    return adresse;
}

string user::getTelephone() {
    return telephone;
}