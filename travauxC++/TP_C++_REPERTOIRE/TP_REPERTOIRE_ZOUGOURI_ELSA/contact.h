/**
 * Creation et description de la classe contact(  )
*/

#include "iostream"
#include "string.h"
#include "stdbool.h"
#include "os.h"
#include "fstream"  //Pour les fichiers
using namespace std;

class contact
{
    string firstName;   //Prenoms
    string lastName;    //Nom
    string email;       //adresse mail
    string phoneHome;   //Home
    string phoneMobile; //Mobile 
    public:
        //Contact constructor
        contact( string preNoms = "", string nom = "", string mail = "", string homePhone = "", string mobilePhone = "" )
        {
            firstName = preNoms;
            lastName = nom;
            email = mail;
            phoneHome = homePhone ;
            phoneMobile = mobilePhone;
        }

        //Methodes declarees
        void showContact( bool showFirstLine ); 
        void editContact(  );
        void deleteContact(  );
        void setContact(  );
        string getFirstName(  );

        void setContact( string preNoms = "", string nom = "", string mail = "", string numTelHome = "", string numTelMobile = "" )
        {
            firstName = preNoms;
            lastName = nom;
            email = mail;
            phoneHome = numTelHome;
            phoneMobile = numTelMobile;
        }  
};

string contact::getFirstName(  )
{
    return firstName;
}

//Afficher un contact
int countContact = 1;
void contact::showContact( bool showFirstLine = false )   //cette variable joue sur la firstLine ( show or not )
{
    if( showFirstLine )
        cout << "\n\nVoici les infos : " << endl;
    cout << countContact << " --> " << firstName << "\t" << lastName << "\t" << email << "\t" << phoneHome + "\t" + phoneMobile << endl;
    countContact++;

    // cout << "\tPrenom( s ) : " << firstName << endl;
    // cout << "\tNom : " << lastName << endl;
    // cout << "\tAdresse mail : " << email << endl;
    // cout << "\tNumero domicile : " << phoneHome << endl;
    // cout << "\tNumero mobile : " << phoneMobile << endl;
}

//EditChoice : choisir l'element du contact à modifier
int editChoice(  )
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
void contact::editContact(  )
{
    int choice = editChoice(  );
    switch ( choice )
    { 
        case 1: //Modifier le( s ) prenom( s )
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
            editContact(  );
        break;
    }  
}

//Supprimer un contact ( toutes les infos == NULL )
void contact::deleteContact(  )
{
    firstName = "";
    lastName = ""; 
    email = "" ;
    phoneHome = "";
    phoneMobile = ""; 
}

//Supprimer une ligne dans un fichier
void eraseLine( string filePathToRead, int lineToErase)
{
    string Buffer = ""; //Variable contenant le texte à réécrire dans le fichier
    ifstream MyFileIn( filePathToRead );
    if ( MyFileIn ) //Si le fichier est trouvé
    {
        string myText;
        int lineToDelete = 0;
        while ( getline( MyFileIn, myText ) ) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            lineToDelete++;
            if( lineToDelete != lineToErase ) //Si la ligne atteinte est différente de la ligne à supprimer...
                Buffer += myText + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
        }
    }
    MyFileIn.close(); //On ferme le fichier en lecture
 
    ofstream MyFileOut( filePathToRead ); //On ouvre ce même fichier en écriture
    MyFileOut << Buffer; //On écris le texte dedans
    MyFileOut.close(); //et on ferme le fichier
}

//Void to read and show a file
void readAndShowFile ( string filePathToRead ) 
{
    if ( filePathToRead == "" ) 
        cout << "Veuillez entrer le chemin absolu du fichier à lire s'il vous plait : ";  
    else {
        string myText;  //Variable qui va contenir le contenu du fichier
        ifstream MyReadFile( filePathToRead );  //Le fichier est ouvert en lecture

        //Fait une boucle afin de lire chaque ligne du fichier
        while ( getline ( MyReadFile, myText ) ) 
        {
            //Output the text from the file
            cout << myText << endl;
        }
        
        //Ferme le fichier
        MyReadFile.close();
    }
}  

//Void to read and show a file
int getNbContacts ( string filePathToRead ) 
{
    int nbContacts = 0;
    if ( filePathToRead == "" ) 
        cout << "Veuillez entrer le chemin absolu du fichier à lire s'il vous plait : ";
    
    else {
        string myText;  //Variable qui va contenir le contenu du fichier
        ifstream MyReadFile( filePathToRead );  //Le fichier est ouvert en lecture

        //Fait une boucle afin de lire chaque ligne du fichier
        while ( getline ( MyReadFile, myText ) ) 
        {
            //Output the text from the file
            nbContacts++;
        }
        
        //Ferme le fichier
        MyReadFile.close();   
    }

    return nbContacts;

}  

//Void to write in a file
void writeFile( string filePathToWrite, string textToInsert ) 
{

    // Create and open a text file
    ofstream MyFile( filePathToWrite  );

    // Write to the file
    MyFile << textToInsert << endl;

    //text to show when your file has been created
    cout << "Le fichier a bien été créé !" << endl;

    // Close the file
    MyFile.close();
}

//Void to append in a file
void appendInFile ( string filePathToAppend, string textToAppend ) 
{
    ofstream MyFileOut;  // Create Object of Ofstream
    ifstream MyFileIn;

    MyFileIn.open( filePathToAppend );
    MyFileOut.open ( filePathToAppend , ios::app); // Append mode

    if( MyFileIn.is_open(  ) )
        MyFileOut << textToAppend << endl; // Append data to file

    MyFileIn.close(  );
    MyFileOut.close(  ); // Closing the file

}