#include <iostream>
#include <fstream>
#include <string>

#include "user.h"
#include "groupe.h"
#include "eleve.h"

using namespace std;

int main()
{
	ifstream fichier("eleve.txt");

	if (fichier) {
		string ligne;
		while (getline(fichier, ligne)) {
			string prenom = ligne;
			string nom;
			getline(fichier,nom);
			string dateNaissance;
			getline(fichier,dateNaissance);
			string sexe;
			getline(fichier,sexe);
			string adresse;
			getline(fichier,adresse);
			string tel;
			getline(fichier,tel);
			string group;
			getline(fichier,group);
			groupe *team = new groupe(group);
			eleve *e = new eleve(prenom,nom,dateNaissance,sexe,adresse,tel,team);
			e->affiche();
		}
	} else {
      	cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
	return 0;
}