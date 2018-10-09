#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>


using namespace std;

class user{
protected:
    string prenom;
    string nom;
    string date_Naissance;
    string sexe;
    string adresse;
    string telephone;

public:
    user(string,string, string, string, string, string);
    void affiche();
};

#endif // USER_H
