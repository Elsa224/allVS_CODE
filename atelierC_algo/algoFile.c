/**
 * 
 * Date : May 28th, 2021
 * Authors : Elsa Z.
 * Description : Algo de FILE (ENFILER, DEFILER, FILE_VIDE, FILE_PLEINE)
 * 
*/

#include "algoFile.h"

maFILE f;

int main(int argc, char const *argv[])
{
    int option = 1, choice, element;
    
    //Test des operations
    initFILE( &f );    //f.tete = f.queue = 0 on suppose file vide au debut    

    //Menu 
    printf("\n\tImplementation d'une file");
    while ( option ) 
    {
        OS == 32 || OS == 64 ? system("cls") : system("clear");
        printf("\nMenu principal");
        printf("\n\t1.Enfiler \n\t2.Defiler \n\t3.Afficher \n\t4.Verifier si la file est vide \n\t5.Verifier si la file est pleine \n\t6.Quitter");
        printf("\n\nEntrez votre choix: ");
        scanf("%d", &choice);
        switch ( choice ) 
        {
            case 1:
                printf("\nEntrer L'element a enfiler: ");
                scanf("%d", &element);
                ENFILER( &f, element );
            break;

            case 2:
                element = DEFILER( &f );
                element == -1 ? printf("File vide ! Veuillez enfiler au moins un element avant de defiler !") :  printf("\nL'element defile est %d", element);
            break;

            case 3:
                afficherFILE( &f );
            break;

            case 4:
                if ( FILEVIDE( &f ) )
                    printf(" File Vide  ");
                else 
                    printf(" File non vide  ");

            break;

            case 5:
                if ( FILEPLEINE( &f ) )
                    printf(" File pleine  ");
                else 
                    printf(" File non pleine  ");
            break;

            case 6:
                exit( 0 );
            break;

            default:
                //TODO A modifier plus tard : quand l'utilisateur veut planter mon programme    
            break;
        }
        printf("\nVoulez-vous continuer ? Tapez 0(Non) ou 1(Oui) : ");
        scanf("%d", &option);
    }
    return 0;
}

