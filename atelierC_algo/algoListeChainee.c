/**
 * Date : May 31rd, 2021
 * Author : Elsa T.
 * Description : Implementer les pseudos codes pour les listes chainees (INSERER, RECHERCHER, SUPPRIMER)
 *      *Liste chainee simple
 *      *Liste chainee double
 *      *Liste chainee circulaire (sentinelle)
 * 
*/
#include "algoListeChainee.h"

//Declaration des variables

//Programme pincipal
int main( int argc, char const *argv[] )
{
    //Declaration et allocation d'un element cellule
    LISTE list;
    list = malloc( sizeof( struct cellule ) );
    tete = list; //tete contient l'adresse du premier element de la liste


    LISTE pabloListe;
    elementListe pabloFirstElement;
    pabloFirstElement.suivant = NULL; // Premier élément de la liste 
    pabloListe = &pabloFirstElement; // La liste dont le premier élément ( son succ ) est NULL donc liste vide
    int number;
    listeVide( pabloListe ) ? printf( "Liste vide\n" ) : printf( "Liste non vide\n" ); // après initialisation si nous sommes en fin de liste alors la liste est vide
    // pabloInsererLISTE( pabloListe );
    pabloMultiInsererLISTE( 2 , pabloListe );
    printf( "Derniere cle entree est : %d\n", pabloListe->suivant->valeur );
    listeVide( pabloListe ) ? printf( "Liste non vide\n" )  : printf( "Liste vide\n" ); // après initialisation si nous sommes en fin de liste alors la liste est vide




    return 0;
}
