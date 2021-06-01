/***Lady's algo c file*****/
/**
 * Date : May 31rd, 2021
 * Author : Elsa T.
 * Description : Implementer les pseudos codes pour les listes chainees (INSERER, RECHERCHER, SUPPRIMER)
 *      *Liste chainee simple
 *      *Liste chainee double
 *      *Liste chainee circulaire (sentinelle)
 * 
*/
#include "algoListeChainee_lady.h"

//Declaration des variables
LISTE premierElement, list;
int nombre, compteur;

//Programme pincipal
int main( int argc, char const *argv[] )
{
    OS == 32 || OS == 64 ? system("cls") : system("clear");
    printf( "--------------Test de la fonction inserer en tete de liste-------------\n\n" );
    printf( "Quel entier voulez-vous inserer en dernier ? : " );
    scanf( "%d", &nombre );
    premierElement = insererLISTE( nombre, NULL );

    //Creation de la liste : tete --> | 2 | --> | 4 | --> | 3 | --> | 5 | --> | premierElement | NULL |
    list = insererLISTE(2, insererLISTE( 4, insererLISTE( 3, insererLISTE( 5, premierElement ) ) ) ) ;

    //Affichage de la liste : tant qu'on a pas trouve NULL, on parcoure la liste et on affiche
    printf( "Voici la liste que nous avons creee : \n\n" );
    while ( list != NULL)
    {
        printf( "| %d | --> ", list->valeur );
        list = list->suivant;
    }

    return 0;
}
