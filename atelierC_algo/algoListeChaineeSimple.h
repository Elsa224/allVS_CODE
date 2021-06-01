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
    int position;
};
typedef struct cellule *LISTE;

//Tete de liste (on suppose liste vide)
LISTE tete = NULL;

//Initialisation de la liste : on sait qu'au debut, tete = NULL mais bon... a revoir

//Fonction insererLISTE()
LISTE insererLISTE( LISTE P )
{
    P = ( LISTE )malloc(  sizeof( struct cellule ) );   //Allouer un espace memoire pour l'element a ajouter
    scanf( "%d", &P->valeur );   //saisir la valeur de l'element
    P->suivant = tete;  //l'element insere sera en tete de liste
    tete = P;   //et tete pointe maintenant sur l'element P
    return P;
}

//Fonction rechercherElement()
LISTE rechercherElement( int cle, LISTE P)
{
    //Si la liste est vide on retourne NULL
    if (P == NULL)
       return NULL;
    else
    {
        P->position = 0;
        printf( "On rentre dans le while...\n" );
        while ( P != NULL && P->valeur != cle )
        {
            printf( "\nDans le while... element pas trouve" );
            P = P->suivant;
            P->position = P->position + 1;  
        }
        printf( "\nOn sort du while...\n" );                
        if ( P->valeur != cle) 
            return NULL;
        else
            return P;
    }
}
        
//Procedure afficherLISTE(LISTE P)
void afficherLISTE( LISTE P )
{
    while ( P != NULL)
    {
        printf(" | %d | <-- ", P->valeur);
        P = P->suivant;
    }
    printf( "NULL\n" );
}

//Fonction LISTEVIDE
bool LISTEVIDE( LISTE P )
{
    if ( P == NULL )
        return true;
    else
        return false;
    
}