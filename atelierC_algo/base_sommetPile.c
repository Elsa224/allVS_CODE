/**
 * Date : May 29th, 2021
 * Author : Elsa Z.
 * Description : Echanger le bas de la pile avec le sommet de la pile (on peut le faire de "deux" manieres)
*/

#include "algoPile.h"

//Declaration des variables
PILE p;
int base, sommet;

int main(int argc, char const *argv[])
{
    int option = 1, choice, element;
    
    //Test des operations
    initPILE( &p );    //p.sommet = -1 on suppose pile vide au debut    

    //Menu 
    printf("\n\tEchanger la base de la pile avec le sommet");
    while ( option ) 
    {
        OS == 32 || OS == 64 ? system("cls") : system("clear");
        printf("\nMenu principal");
        printf("\n\t1.Empiler \n\t2.Depiler \n\t3.Afficher \n\t4.Echanger base<-->sommet \n\t5.Quitter");
        printf("\n\nEntrez votre choix: ");
        scanf("%d", &choice);
        switch ( choice ) 
        {
            case 1:
                printf("\nEntrer L'element a empiler: ");
                scanf("%d", &element);
                EMPILER( &p, element );
            break;

            case 2:
                element = DEPILER( &p );
                element == -1 ? printf("") :  printf("\nL'element depile est %d", element);
            break;

            case 3:
                afficherPILE( &p );
            break;

            case 4:
                if ( PILEVIDE( &p ) )
                    printf(" Pile Vide. Veuillez empiler au moins 2 elements avant de faire un swap ! ");
                else if( p.sommet < 2 )
                    printf("Veuillez empiler au moins 2 elements avant de faire un swap !");
                else
                {
                    swap( &p );
                    printf("\nL'echange a bien ete effectue ! Tapez 1 ensuite 3 pour l'afficher");
                }
            break;

            case 5:
                exit( 0 );
            break;

            default:      
            break;
        }
        printf("\nVoulez-vous continuer ? Tapez 0(Non) ou 1(Oui) : ");
        scanf("%d", &option);
    }
    return 0;
}
