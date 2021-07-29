/**
 * Date : Dimanche 09 Mai 2021
 * Auteurs : ZOUGOURI Elsa, DIANDUE Archange, DINGA Judicaël
 * 
 * 
 * Travail à faire : 
 * Ecrire un programme traduisant le comportement d'un répertoire ( de contacts )
 * dans un téléphone
 * 
 * Astuces :
 * Uiliser les fichiers ( créer un fichier REPERTOIRE )
 * Ecrire les fonctions 
 *  ajouterContact(  ), rechercherContact(  ), modifierContact(  ), supprimerContact(  ), listerRepertoire(  ), quitter(  ) 
*/

//Fichier contenant les default librairies, la classe contact(  ) et ses méthodes
#include "contact.h"

//Déclaration des constantes et des variables
const int tailleInitialeRep = 20;   //tailleRep = taille du répertoire
int tailleRep = tailleInitialeRep, totalRep = 0;
contact repertoire[ tailleInitialeRep ]; // répertoire de 'tailleRep' contacts
const string FILE_PATH = "repertoire.txt";

//Menu du répertoire
int menu(  )
{  
    //By M
    cout << "=================" << endl;
    cout << "You have : " << getNbContacts( FILE_PATH ) << " contact(s)" << endl;
    cout << "=================" << endl;

    int choixMenu = -1;
    cout << "Bonjour et bienvenue ! : ) Que voulez-vous faire ?" << endl;
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
void addContact(  )
{
    int idContact = getNbContacts( FILE_PATH );
    string nameFirst, nameLast, email, homePhone, mobilePhone;
    int index = tailleInitialeRep - tailleRep;  
    if ( index >= 0 )
    {
        cout << "Vous voulez ajouter un contact. Veuillez entrer les infos relatives a ce contact : " << endl;
        cout << "\t\tPrenom( s ) : "; cin  >> nameFirst;
        cout << "\t\tNom : "; cin  >> nameLast;
        cout << "\t\tAdresse mail : "; cin  >> email;
        cout << "\t\tNumero domicile : "; cin  >> homePhone;
        cout << "\t\tNumero mobile : "; cin  >> mobilePhone;

        repertoire[ index ].setContact( nameFirst, nameLast, email, homePhone, mobilePhone );
        repertoire[ index ].showContact( true );    //ici, on affiche la ligne "voici les infos" donc l'argument est à true
        tailleRep--;
        totalRep++;
        ++idContact;


        //Ajout dans le fichier repertoire.txt
        string infosToInsert =   to_string( idContact ) + "-- " + nameFirst + "\t\t\t\t" + nameLast + "\t\t\t\t" + email + "\t\t\t\t" + homePhone + "\t\t\t\t" + mobilePhone + "\n";
        appendInFile( FILE_PATH, infosToInsert );
        cout << "\n\nLes infos ont bien été ajoutées !!" << endl;

    }
    else    
        cout << "Desolee... Repertoire plein! ";    //A changer après avoir ajouté les fichiers
    
    
    
}

//Afficher tous les contacts
void showContacts(  )
{
    //Afficher les contacts à partir du fichier
    readAndShowFile( FILE_PATH);
}

int main( int argc, char const *argv[  ] )
{
    OS == 32 || OS == 64 ? system("cls") : system("clear");
    int quitter = -1;   //pour quitter le programme
    do 
    {
        int menuChoix = menu(  ), retour = -1; 
        int idContactToDelete = 0, nbContacts = getNbContacts( FILE_PATH );
        switch ( menuChoix )
        {
            case 1: //ajouter un contact
                do
                {
                    OS == 32 || OS == 64 ? system("cls") : system("clear");
                    addContact(  );
                    cout << "\n\nTapez 0 pour retourner au menu ou 1 pour ajouter un autre contact : ";
                    cin >> retour ;
                    OS == 32 || OS == 64 ? system("cls") : system("clear");
                }
                while ( retour != 0 || retour != 1 );
            break;

            case 2: //modifier un contact
                cout << "\n\nDesolee... Cette fonctionnalite sera bientot disponible !!! :) :) :)" << endl;
                
            break;

            case 3: //rechercher un contact
                cout << "\n\nDesolee... Cette fonctionnalite sera bientot disponible !!! :) :) :)" << endl;                
            break;

            case 4: //supprimer un contact
                //D'abord on affiche tous les contacts
                idContactToDelete = 0; 
                nbContacts = getNbContacts( FILE_PATH );

                OS == 32 || OS == 64 ? system("cls") : system("clear");
                showContacts( ); 
                do
                {
                    cout << "\nQuel contact voulez-vous supprimer ? ( tapez l'indice du contact ) : ";
                    cin >> idContactToDelete;
                } 
                while ( idContactToDelete <= 0 || idContactToDelete > nbContacts );
                eraseLine( FILE_PATH, idContactToDelete );

                // TODO si tu veux tu peux afficher le répertoire actualisé ou il devra sortir et afficher dans le menu done
                do
                {
                    cout << "\nVoici la liste des contacts après suppression :\n " << endl;
                    showContacts();
                    cout << "\n\nTapez 0 pour retourner au menu ou  4 pour supprimer un autre contact : ";
                    cin >> retour ;
                    OS == 32 || OS == 64 ? system("cls") : system("clear");
                }
                while ( retour != 0 || retour != 4  );

            break;

            case 5: //lister tous les contacts
                do
                {
                    OS == 32 || OS == 64 ? system("cls") : system("clear");
                    showContacts(  );
                    cout << "\n\nTapez 0 pour retourner au menu : ";
                    cin >> retour ;
                    OS == 32 || OS == 64 ? system("cls") : system("clear");
                }
                while ( retour != 0 );
            break;

            case 6: //Quitter l'application
            
            default:
                cout << "Merci et a bientot ! ! ! " << endl; 
                exit( 0 );    //BYE BYE. 
            break;
        }

    }
    while ( quitter != 0 );

    return 0;
}







