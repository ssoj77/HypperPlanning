#include "cours.h"

cours::cours(string v_salle, string v_debut, string v_jour, string v_matiere, formateur *v_prof,string v_groupe){
    salle = v_salle;
    heure_Debut = v_debut;
    jour = v_jour;
    matiere = v_matiere;
    prof = v_prof;
    g_Eleve = v_groupe;
}

void cours::affiche(){
    cout << "Cours de " << matiere << " en salle " << salle << " le " << jour << " a " << heure_Debut << endl;
}
