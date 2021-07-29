/**
 * Creation et description de la classe contact()
*/

#include "iostream"
#include "string.h"
#include "stdbool.h"
using namespace std;

class contact
{
    string firstName;   //Prenoms
    string lastName;    //Nom
    string email;       //adresse mail
    string phoneHome;   //Home
    string phoneMobile; //Mobile 
    public:
        contact(string, string, string, string, string);
        //Methodes declarees
        void showContact(bool showFirstLine); 
        void editContact();
        void deleteContact();
        void setContact();
        string getFirstName();

        void setContact(string, string, string, string, string);   
};

//Ce que ma classe contact fait
contact::contact(string, string, string, string, string )
{
    firstName = "";
    lastName = "";
    email = "";
    phoneHome = "" ;
    phoneMobile = "";
}

void contact::setContact(string preNoms = "", string nom = "", string mail = "", string numTelHome = "", string numTelMobile = "")
{
    firstName = preNoms;
    lastName = nom;
    email = mail;
    phoneHome = numTelHome;
    phoneMobile = numTelMobile;
}

string contact::getFirstName()
{
    return firstName;
}

//Afficher un contact
void contact::showContact(bool showFirstLine = false)   //cette variable joue sur la firstLine (show or not)
{
    if(showFirstLine)
        cout << "\n\nVoici les infos : " << endl;
    cout << "\tPrenom(s) : " << firstName << endl;
    cout << "\tNom : " << lastName << endl;
    cout << "\tAdresse mail : " << email << endl;
    cout << "\tNumero domicile : " << phoneHome << endl;
    cout << "\tNumero mobile : " << phoneMobile << endl;
}

//EditChoice : choisir l'element du contact à modifier
int editChoice()
{
    int choix = -1;
    cout << "Que voulez-vous modifier ?" << endl;
    cout << "\t1 - Prenoms" << endl;
    cout << "\t2 - Nom" << endl;
    cout << "\t3 - Adresse mail" << endl;
    cout << "\t4 - Numero domicile" << endl;
    cout << "\t5 - Numero mobile" << endl;
    cin >> choix;
    return choix;
}

//Modifier un contact
void contact::editContact()
{
    int choice = editChoice();
    switch (choice)
    { 
        case 1: //Modifier le(s) prenom(s)
            cin >> firstName;
        break;

        case 2: //Modifier le nom
            cin >> lastName;
        break;

        case 3: //Modifier l'adresse mail
            cin >> email;
        break;

        case 4: //Modifier le numero domicile 
            cin >> phoneHome;
        break;

        case 5: //Modifier le numero mobile
            cin >> phoneMobile;
        break;

        case -1 :   //si choice = -1, le user n'a rien choisi donc il recommence
        default:
            editContact();
        break;
    }  
}

//Supprimer un contact (toutes les infos == NULL)
void contact::deleteContact()
{
    firstName = "";
    lastName = ""; 
    email = "" ;
    phoneHome = "";
    phoneMobile = ""; 
}

