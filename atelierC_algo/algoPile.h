#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "os.h"

/**** IMPLEMENTATION DES OPERATIONS SUR LA PILE*********/

//Taille de la pile
#define taille 10

//Declaration du type PILE
struct pile
{
   int tab[taille];      
   int sommet;   //permettra de pointer sur le premier element de la liste
};
typedef struct pile PILE;

/****************** PROTOTYPES ****************/
void initPILE(PILE *P);
void EMPILER(PILE *P, int a);
int DEPILER(PILE *P);
bool PILEVIDE(PILE *P);
bool PILEPLEINE(PILE *P);
void afficherPILE(PILE *P);
void swap(PILE *P);   //Echanger la base de la pile avec le sommet
/***********************************************/

//Initialisation de la pile
void initPILE(PILE *P)
{
    P->sommet = -1;
}

//Procedure EMPILER()
void EMPILER(PILE *P, int a)
{
    if(!PILEPLEINE(P))
    {
        P->sommet = P->sommet + 1;
        P->tab[P->sommet] = a;
    }
    else
        printf("La pile est pleine! Plus d'ajout possible");
}

//Fonction DEPILER()
int DEPILER(PILE *P)
{
    int nombre;
    if( ( PILEVIDE( P ) ) )
    {
        printf("Pile vide ! Veuillez empiler au moins 1 element avant de depiler ! ");
        nombre = -1;
    }
    else
    {
        nombre = P->tab[P->sommet];
        P->sommet--;
    }
    return nombre;
}

//Fonction PILEVIDE()
bool PILEVIDE(PILE *P)
{
    if(P->sommet == -1)
        return true;
    else
        return false;
}

//Fonction PILEPLEINE()
bool PILEPLEINE(PILE *P)
{
    if (P->sommet == taille)
        return true;  
    else
        return false;        
}

//Procedure afficherPILE
void afficherPILE(PILE *P)
{
    if( PILEVIDE( P ) )
        printf("\nLa pile est vide !");
    else
    {
        for (int i = P->sommet; i >= 0; i--) //l'affichage de la PILE est contraire à l'affichage d'un tableau normal
           printf(" | %d |\n", P->tab[i]);
    }
}

//Ajout de swap(base, sommet)
void swap(PILE *P)
{
    PILE pileTampon;
    initPILE( &pileTampon);
    int numBase, num, numSommet;
    numBase = DEPILER(P);    //On depile P et on sauvegarde l'element sommet dans numBase
    
    while ( P->sommet != 0 ) //Tant qu'on atteint pas fin-1 de la pile, on dépile et on empile dans la pile tampon
        EMPILER( &pileTampon, DEPILER( P ) );
    numSommet = DEPILER(P);  //On depile le dernier element de la pile qui sera le sommet de la pileTampon

    //Maintenant on rempile dans la pile initiale avec numBase en base et numSommet au sommet
    EMPILER( P, numBase );
   while ( pileTampon.sommet != -1 )   //Tant que la pile tampon n'est pas vide, on depile
       EMPILER( P, DEPILER( &pileTampon ) );
   EMPILER(P, numSommet);   //On empile le sommet et c'est fini
   
}