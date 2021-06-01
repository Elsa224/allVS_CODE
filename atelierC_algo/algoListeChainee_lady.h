/***Lady's algo header file*****/
#include "headerBase.h"
#include "os.h"

/*******IMPLEMENTATION DES OPERATIONS SUR LES LISTES CHAINEES**********
 * 
 * Une liste chainee simple est constitue d'une suite contigüe de cellules 
 * et chaque cellule est constitue de deux champs : valeur/donnee/cle et suivant/successeur
 * qui est un pointeur sur une cellule.
 * Donc le type LISTE (la liste elle-meme) est un pointeur sur cette suite de cellules
 * 
/*********************************************************/


//Declaration du type cellule
struct cellule
{  
    int valeur;
    struct cellule *suivant;
};
typedef struct cellule *LISTE;

//Tete de liste (on suppose liste vide)
LISTE tete = NULL;

//Initialisation de la liste : on sait qu'au debut, tete = NULL mais bon... a revoir

//Fonction insererLISTE() en tete de liste
LISTE insererLISTE( int num, LISTE L )
{
    LISTE objet;
    objet = ( LISTE )malloc( sizeof( struct cellule ) );
    tete = objet;  //Comme on insere en tete, tete doit toujours pointer sur l'element qu'on insere
    objet->valeur = num;
    objet->suivant = L; //car le suivant pointe sur un element de type cellule (donc cellule)
    return objet;
}