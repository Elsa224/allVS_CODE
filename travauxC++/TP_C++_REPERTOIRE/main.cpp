/**
 * Date : Dimanche 09 Mai 2021
 * Auteurs : ZOUGOURI Elsa, DIANDUE Archange, DINGA Judicaël
 * 
 * 
 * Travail à faire : 
 * Ecrire un programme traduisant le comportement d'un répertoire (de contacts)
 * dans un téléphone
 * 
 * Astuces :
 * Uiliser les fichiers (créer un fichier REPERTOIRE)
 * Ecrire les fonctions 
 *  ajouterContact(), rechercherContact(), modifierContact(), supprimerContact(), listerRepertoire(), quitter() 
*/

//Fichier contenant la classe contact() et ses méthodes
#include "contact.h"

//Déclaration des constantes et des variables
const int tailleInitialeRep = 20;   //tailleRep = taille du répertoire
int tailleRep = tailleInitialeRep;
contact repertoire[tailleInitialeRep]; // répertoire de 'tailleRep' contacts

//Menu du répertoire
int menu()
{  
    int choixMenu = -1;
    cout << "Bonjour et bienvenue ! :) Que voulez-vous faire ?" << endl;
    cout << "\t\t1 - Ajouter un contact" << endl;
    cout << "\t\t2 - Modifier un contact" << endl;
    cout << "\t\t3 - Rechercher un contact" << endl;
    cout << "\t\t4 - Supprimer un contact" << endl;
    cout << "\t\t5 - Lister tous les contacts" << endl;
    cout << "\t\t6 - Quitter" << endl;
    cout << "\nEntrez votre choix s'il vous plait : ";
    cin >> choixMenu;
    return choixMenu;
}

//Ajouter un contact
void addContact()
{
    string nameFirst, nameLast, email, homePhone, mobilePhone;
    int index = tailleInitialeRep - tailleRep;  
    if (index >= 0)
    {
        cout << "Vous voulez ajouter un contact. Veuillez entrer les infos relatives a ce contact : " << endl;
        cout << "\t\tPrenoms : "; cin  >> nameFirst;
        cout << "\t\tNom : "; cin  >> nameLast ;
        cout << "\t\tAdresse mail : "; cin  >> email ;
        cout << "\t\tNumero domicile : "; cin  >> homePhone ;
        cout << "\t\tNumero mobile : "; cin  >> mobilePhone ;

        repertoire[index].setContact(nameFirst, nameLast, email, homePhone, mobilePhone);
        repertoire[index].showContact();
        tailleRep--;
    }
    
}

//Afficher tous les contacts
void showContacts()
{
    
    for (int i = 0; i < tailleInitialeRep; i++)
        repertoire[i].showContact();
    
}

int main(int argc, char const *argv[])
{
    int menuChoix = menu();
    switch (menuChoix)
    {
        case 1: //ajouter un contact
            addContact();   
        break;

        case 2: //ajouter un contact
              
        break;

        case 3: //ajouter un contact
              
        break;

        case 4: //ajouter un contact
              
        break;

        case 5: //lister tous les contacts
            showContacts();
              
        break;

        case 6: //ajouter un contact
              
        break;
    
        default:
        break;
    }

    return 0;
}







