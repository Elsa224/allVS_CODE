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

//Tete de liste
LISTE tete;

//Initialisation de la liste : on sait qu'au debut, tete = NULL mais bon... a revoir

//Fonction insererLISTE() en tete de liste
LISTE insererLISTE( int num, LISTE Q )
{
    LISTE L;
    L = malloc( sizeof( struct cellule ) ); //allouer(L)
    tete = L;  //Comme on insere en tete, tete doit toujours pointer sur l'element qu'on insere
    L->valeur = num;
    L->suivant = Q; //car le suivant pointe sur un element de type cellule (donc cellule)
    return L;
}

//je m'arrete la pour ce soir
//je me demande meme si c'est juste
//il va regarder aujourd'hui

bool listeVide ( LISTE Q ) {
    return Q->suivant == NULL ;
}

typedef struct cellule elementListe;

//Fonction insererLISTE() en tete de liste : @superPablo_E
void pabloInsererLISTE( LISTE Q )
{
    //Allocation d'un nouvel élément, je te laisse faire la version malloc
    elementListe nouvelElement;
    printf( "Veuillez entrer la cle de votre element : " );
    scanf("%d", &nouvelElement.valeur);
    Q->suivant = &nouvelElement; // succ [ pabloFirstElement ] pointe sur le nouvel élément
    Q = Q->suivant; // pabloListe à son tour pointe sur le nouvel élément
    Q->suivant = NULL;
}

void pabloMultiInsererLISTE( int nbElementToInsert, LISTE Q ) {
    for ( int i = 0; i< nbElementToInsert; i++ )
        pabloInsererLISTE( Q );
}