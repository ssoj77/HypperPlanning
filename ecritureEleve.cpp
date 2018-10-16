#include <iostream>
#include <fstream>
#include <string>

#include "user.h"
#include "groupe.h"
#include "eleve.h"
#include "ecritureEleve.h"

using namespace std;

void ecrire(eleve *student) {
	ofstream fichier("eleve.txt", ios::app);
	if (fichier) {
		fichier << student->getPrenom() << endl;
		fichier << student->getNom() << endl;
		fichier << student->getDateNaissance() << endl;
		fichier << student->getSexe() << endl;
		fichier << student->getAdresse() << endl;
		fichier << student->getTelephone() << endl;
		fichier << student->getGroupe() << endl;
	} else {
		cout << "ERREUR : impossible d'ouvrir le fichier" << endl;
	}
}

int main() {
	groupe *g = new groupe("L3-APP-LSI");
	eleve *e = new eleve("Odran","Lariviere","01/01/1998","homme","dan la rue", "0000000001",g);
	e->affiche();
	ecrire(e);
}