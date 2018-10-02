#include <iostream>
#include <string>
#include <vector>

using namespace std;

class user{
protected:
    int age;
    string prenom;
    string nom;

public:
    user(string,string,int);
    user(const user&);
    user();
    ~user();

    void viellir();
    void affiche();
    void changeName(string);
};
user :: user(string v_prenom, string v_nom , int v_age){
    age = v_age;
    prenom = v_prenom;
    nom= v_nom;
}
user :: user(const user &u){
    age = u.age;
    nom = u.nom;
    prenom= u.prenom;
}
user :: user(){
    string m_prenom;
    string m_nom;
    int m_age;
    cout<<"Entrez le prenom : ";
    cin>>m_prenom;
    cout<<endl;
    cout<<"Entrez le nom :";
    cin>>m_nom;
    cout<<endl;
    cout<<"Entrez l'age :";
    cin>>age;
    cout<<endl;
    age=m_age;
    prenom=m_prenom;
    nom=m_nom;

}
user :: ~user(){
}
void user :: viellir(){
    age += 1;
}
void user :: affiche(){
    cout << "prenom " << prenom <<" "<< nom <<":"<< age << "ans."<< endl;
}
void user :: changeName(string v_nom){
    nom = v_nom;
}

class eleve : public user{
protected:
    string groupe;
public:
    eleve(string,string,int,string);
    eleve(user,string);
    string getPrenom()const ;
    string getNom()const;
    void setGroupe(string);
    int getAge()const;
    string getGroupe()const;
    ~eleve();

};
eleve :: eleve(string v_prenom,string v_nom,int v_age,string v_groupe):user(v_prenom,v_nom,v_age){
    groupe = v_groupe;
}
eleve :: eleve(user u,string v_groupe):user(u){
    groupe=v_groupe;
}
eleve :: ~eleve(){
}
inline string eleve :: getPrenom()const{
    return prenom;
}
inline string eleve :: getNom()const{
    return nom;
}
inline int eleve :: getAge()const{
    return age;
}
inline string eleve :: getGroupe()const{
    return groupe;
}
void eleve::setGroupe(string v_groupe){
    groupe = v_groupe;
}

class formateur : public user{
    private:
        string job;
    public:
        formateur(string , string , int , string);
        formateur(user, string);
        formateur();
        ~formateur();
        formateur& operator = (const formateur&);                           /// !!!!!!!    A FAIRE !!!!!!!!!
        void doyourthing();
        void affiche();

};
formateur :: formateur(string v_prenom, string v_nom , int v_age ,string v_job):user(v_prenom,v_nom,v_age){
    job = v_job;
}
formateur :: formateur(user u,string v_job):user(u){
    job=v_job;
}
formateur :: formateur():user(){
    string m_job;
    cout<<"Entrez le job :";
    cin>>m_job;
    cout<<endl;
    job=m_job;
}
formateur& formateur::operator=(const formateur &src){
	if(this != &src)
	{
        this->prenom = &src.prenom(); /// Peut etre .getPrenom(); a faire ??
        this.nom = &src.nom;
        this.age = &src.age;
        this.job = &src.job;
	}
	return *this;
}
void formateur :: doyourthing(){
    if(job != "unemployed"){cout<<"I'm teaching :" << job << "."<<endl;}
    else{cout<<"I can't, I'm a fucking loser";}
}
void formateur :: affiche(){
    if(job != "unemployed"){
    cout << "prenom " << prenom <<" "<< nom <<":"<< age << "ans. Je suis prof de :" << job <<"." <<endl;
    }
    else{
            cout << "prenom " << prenom <<" "<< nom <<":"<< age << "ans. Je ne suis pas encore prof "<< endl;
    }
}
formateur :: ~formateur(){
}


class groupe{
protected:
    vector<eleve> listEleve;
    string lettre;
public:
    void remplirList(vector<eleve>& , string);
    void affiche();
    vector<eleve> getList()const;
    groupe& operator = (const groupe&);                             /// !!!!!!!    A FAIRE !!!!!!!!!
    groupe(vector <eleve>& , string);
    groupe(vector<eleve>&);
    groupe(const groupe&);
    groupe();
    ~groupe();
};
groupe::groupe(vector<eleve>& m_List, string m_lettre){
    listEleve = m_List; ///copie de la liste
    lettre = m_lettre; ///on attribut sa lettre au groupe
}
groupe::groupe(vector<eleve>& m_List){

    string m_lettre;                                /// on demande la lettre du groupe qui vient d'etre créé
    cout<<"Entrez la lettre associé au groupe :";
    cin>>m_lettre;
    cout<<endl;
    lettre = m_lettre;

    listEleve=m_List;                               ///copie de la liste d'eleve


    for (unsigned int i=0; i<listEleve.size();i++){
            listEleve[i].setGroupe(m_lettre);
    }
}
groupe::groupe(){
    string m_lettre;
    cout<<"Entrez la lettre associé au groupe :";
    cin>>m_lettre;
    cout<<endl;
    lettre = m_lettre;

    vector<eleve> m_List;
    remplirList(m_List, m_lettre);
    listEleve = m_List;

}
groupe::groupe(const groupe &groupe_Cpy){
    string m_lettre;                                /// on demande la lettre du groupe qui vient d'etre créé
    cout<<"Entrez la lettre associé au groupe :";
    cin>>m_lettre;
    cout<<endl;
    lettre = m_lettre;

    listEleve=groupe_Cpy.getList();                               ///copie de la liste d'eleve


    for (unsigned int i=0; i<listEleve.size();i++){
            listEleve[i].setGroupe(m_lettre);
    }

}
groupe::~groupe(){
    cout<<"Destrcteur groupe"<<endl;
}
inline vector<eleve> groupe::getList()const{
    return listEleve;
}
groupe& groupe::operator=(const groupe &src){
	if(this != &src)
	{
        this->listEleve = &src.listEleve;
        this->lettre = &src.lettre;
	}
	return *this;
}
/*groupe& groupe::operator=(const groupe &src){
	if(this != &src)
	{
        delete tab;
        tab = new char[nb=src.nb];
        for (int i=0;i<nb;i++)
        {
        	tab[i]=src.tab[i];
        }
	}
	return *this;
}*/
void groupe::remplirList(vector<eleve>& listEleve, string v_groupe){ //utilisé pour remplir une list dans le constructeur par défault.

        string prenom;
        string nom;
        int age;

        cout<<"combien d'eleve"<<endl;
        int tailleList;
        cin>>tailleList;

        for (int i=0; i<tailleList;i++){
            cout<<"Entrez le prenom de l'eleve :";
            cin>>prenom;
            cout<<"Entrez le nom de l'eleve :";
            cin>>nom;
            cout<<"Entrez l'age de l'eleve :";
            cin>>age;
            eleve newEleve(prenom, nom, age, v_groupe);
            listEleve.push_back(newEleve);cout<<endl;
        }
        cout<<endl;
}
void groupe::affiche(){

    unsigned int taille = listEleve.size();
    for(unsigned int i=0;i<taille;i++){
        cout << "L'etudiant numero :" << i+1 << "s'appelle" << listEleve[i].getPrenom() << "," << listEleve[i].getNom() << endl;
        cout << "Il a :" << listEleve[i].getAge() << "ans." << "Il fait partie du groupe : " << listEleve[i].getGroupe() << endl;
    }
}


class cours{

private:

    string salle;           //go to constru
    int heure_Debut;        //go to constru
    formateur prof;
    groupe g_Eleve;
    string jour;            //go to constru

public:
    cours(string, int, string , formateur ,groupe);

};
cours::cours(string v_salle, int v_debut, string v_jour, formateur v_prof, groupe v_groupe){ //il me faut 2 surcharge de operateur = pour prof et groupe
    salle = v_salle;
    heure_Debut = v_debut;
    jour = v_jour;
    prof = v_prof;
    g_Eleve = v_Groupe;

}

void remplirList(vector<eleve>&, string);
void afficheList(vector<eleve>&);
void remplirList(vector<eleve>& listEleve, string v_groupe){

        string prenom;
        string nom;
        int age;
        string groupe;

        cout<<"combien d'eleve"<<endl;
        int tailleList;
        cin>>tailleList;

        for (int i=0; i<tailleList;i++){
            cout<<"Entrez le prenom de l'eleve :";
            cin>>prenom;
            cout<<"Entrez le nom de l'eleve :";
            cin>>nom;
            cout<<"Entrez l'age de l'eleve :";
            cin>>age;
            eleve newEleve(prenom, nom, age, v_groupe);
            listEleve.push_back(newEleve);cout<<endl;
        }
        cout<<endl;
}
void afficheList(vector<eleve>& listEleve){

    unsigned int taille = listEleve.size();
    for(unsigned int i=0;i<taille;i++){
        cout << "L'etudiant numero :" << i+1 << "s'appelle" << listEleve[i].getPrenom() << "," << listEleve[i].getNom() << endl;
        cout << "Il a :" << listEleve[i].getAge() << "ans." << "Il fait partie du groupe : " << listEleve[i].getGroupe() << endl;
        cout << endl;
    }
}

int main(){// a faire le tableau ! plus getteur du metier du formateur pour connaitre le sujet du cours.

    string v_G;
    cout<<"Entrez la lettre du groupe :"<<endl;
    cin>>v_G;cout<<endl;

    ///dynamic list of student
    vector<eleve> listEleve;
    remplirList(listEleve,v_G);
    afficheList(listEleve);


    cout<<"\n! Creation des groupes !\n"<<endl;
    cout<<"groupe A :\n"<<endl;
    groupe groupeA(listEleve); //bug

    groupe groupeB(groupeA);
    cout<<"Affichage : "<< endl;
    groupeA.affiche();
    groupeB.affiche();

    return 0;
}


























//il n'y a pas besoin de mettre des matieres dans les cours car les prof n'enseigne qu'une matiere, il suffit de regarder leur metier ( prof de math ou français etc)
/*                                                      Classe A
__________________________________________________________________________________________________________________________
|        lundi          |       mardi           |        mercredi       |        jeudi          |        vendredi       |
__________________________________________________________________________________________________________________________
|        cours A        |       cours D         |        cours B        |        cours A        |        cours A        |
__________________________________________________________________________________________________________________________
|        cours A        |       cours D         |        cours B        |        cours A        |        cours A        |
__________________________________________________________________________________________________________________________
|        cours A        |       cours D         |        cours B        |        cours A        |        cours A        |
__________________________________________________________________________________________________________________________
|        cours A        |       cours D         |        cours B        |        cours A        |        cours A        |
__________________________________________________________________________________________________________________________

__________________________________________________________________________________________________________________________
|        cours B        |       cours A         |        cours C        |        cours D        |        cours C        |
__________________________________________________________________________________________________________________________
|        cours B        |       cours A         |        cours C        |        cours D        |        cours C        |
__________________________________________________________________________________________________________________________
|        cours C        |       cours A         |        cours C        |        cours B        |        cours C        |
__________________________________________________________________________________________________________________________
|        cours C        |       cours A         |        cours C        |        cours B        |        cours C        |
__________________________________________________________________________________________________________________________

                                                        Classe B
__________________________________________________________________________________________________________________________
|        lundi          |       mardi           |        mercredi       |        jeudi          |        vendredi       |
__________________________________________________________________________________________________________________________
|        cours A        |       cours D         |        cours B        |        cours A        |        cours A        |
__________________________________________________________________________________________________________________________
|        cours A        |       cours D         |        cours B        |        cours A        |        cours A        |
__________________________________________________________________________________________________________________________
|        cours A        |       cours D         |        cours B        |        cours A        |        cours A        |
__________________________________________________________________________________________________________________________
|        cours A        |       cours D         |        cours B        |        cours A        |        cours A        |
__________________________________________________________________________________________________________________________

__________________________________________________________________________________________________________________________
|        cours B        |       cours A         |        cours C        |        cours D        |        cours C        |
__________________________________________________________________________________________________________________________
|        cours B        |       cours A         |        cours C        |        cours D        |        cours C        |
__________________________________________________________________________________________________________________________
|        cours C        |       cours A         |        cours C        |        cours B        |        cours C        |
__________________________________________________________________________________________________________________________
|        cours C        |       cours A         |        cours C        |        cours B        |        cours C        |
__________________________________________________________________________________________________________________________





*/
