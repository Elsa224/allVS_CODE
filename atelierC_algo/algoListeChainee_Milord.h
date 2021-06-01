/***Proposition algo liste chainee de Milord*****/

#include "headerBase.h"
#include "os.h"

/*******IMPLEMENTATION DES OPERATIONS SUR LES LISTES CHAINEES**********
 * 
 * Une liste chainee simple est constitue d'une suite contigüe de cellules 
 * et chaque cellule est constitue de deux champs : valeur/donnee/cle et suivant/successeur
 * qui est un pointeur sur une cellule.
 * Donc le type LISTE (la liste elle-meme) est un pointeur sur cette suite de cellules
 * 
 ******************************************************************************
*/

//Declaration du type cellule
struct cellule
{  
    int valeur;
    struct cellule *suivant;
};
typedef struct cellule * LISTE;

//Tete de liste (on suppose liste vide)
LISTE tete = NULL;

bool listeVide ( LISTE Q ) {
    return Q->suivant == NULL ;
}

typedef struct cellule elementListe;

//Fonction insererLISTE() en tete de liste : @superPablo_E
void pabloInsererLISTE( LISTE Q )
{
    //Allocation d'un nouvel élément, je te laisse faire la version malloc
    elementListe *nouvelElement;
    nouvelElement = malloc( sizeof( struct cellule ) ); //apparemment pour un malloc il faut que l'element soit un pointeur donc j'ai change
    printf( "Veuillez entrer la cle de votre element : " );
    scanf("%d", nouvelElement->valeur);
    Q->suivant = &nouvelElement; // succ [ pabloFirstElement ] pointe sur le nouvel élément
    Q = Q->suivant; // pabloListe à son tour pointe sur le nouvel élément
    Q->suivant = NULL;
}

void pabloMultiInsererLISTE( int nbElementToInsert, LISTE Q ) {
    for ( int i = 0; i< nbElementToInsert; i++ )
        pabloInsererLISTE( Q );
}
