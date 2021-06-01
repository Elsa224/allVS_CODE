/**
 * Date : May 31rd, 2021
 * Author : Elsa T.
 * Description : Implementer les pseudos codes pour les listes chainees (INSERER, RECHERCHER, SUPPRIMER)
 *      *Liste chainee simple
 *      *Liste chainee double
 *      *Liste chainee circulaire (sentinelle)
 * 
*/
#include "algoListeChaineeSimple.h"

//Declaration des variables
LISTE list, seekElement, P;
int nbElement, element;

//Programme pincipal
int main( int argc, char const *argv[] )
{
    tete = NULL;

    //Creation de la liste
    printf( "\nQuelle est la taille de votre liste : " );
    scanf( "%d", &nbElement );
    printf( "\nVeuillez entrer les valeurs du dernier au premier s'il vous plait :\n" );
    for ( int i = 1; i <= nbElement; i++ )
    {
        printf( "\n\tElement %d : ", i );
        list = insererLISTE( P );
    }

    //Affichage de la liste
    printf( "\n\nVoici votre liste :\n\t" );
    afficherLISTE( list );

    //Rechercher element dans liste
    printf(  "\n\nQuel element dans la liste recherchez-vous ? : " );
    scanf( "%d", &element );
    seekElement = rechercherElement( element, list );
    if ( seekElement == NULL)
        printf( "Desolee. L'element recherche ne figure pas dans la liste" );
    else
        printf( "Nous avons trouve L'element ! %d se trouve a la position %d", seekElement->valeur, seekElement->position );
    
    return 0;
}
