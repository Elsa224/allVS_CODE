/********IMPLEMENTATION DES OPERATIONS SUR LA FILE*******/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "os.h"

//Taille de la file
#define taille 10

//Declaration du type FILE
struct file
{
    int tab[taille];
    int tete;
    int queue;
};
typedef struct file maFILE;   //a cause du type FILE (fichier) qui existe déjà j'ecris ma file maFILE

/*********************  PROTOTYPES  *********************/
void initFILE(maFILE *F );
bool FILEVIDE(maFILE *F);
bool FILEPLEINE(maFILE *F);
void ENFILER(maFILE *F, int num);
int DEFILER(maFILE *F);
void afficherFILE(maFILE *F);
/********************************************************/

//Initialisation de la file
void initFILE(maFILE *F )
{
    F->tete = 0;
    F->queue = 0; //ca passe fort fort meme
}

//Fonction FILEVIDE()
bool FILEVIDE(maFILE *F)
{
    if( F->tete == F->queue )
        return true;
    else
        return false;
}

//Fonction FILEPLEINE()
bool FILEPLEINE(maFILE *F)
{
    if( F->tete == F->queue + 1 )
        return true;
    else
        return false;
}

//Procedure EMFILER()
void ENFILER(maFILE *F, int num)
{
    F->tab[F->queue] = num;
    if( F->queue == taille )
        F->queue = 0;
    else
        F->queue = F->queue + 1;
}

//Fonction DEFILER()
int DEFILER(maFILE *F)
{
    if( FILEVIDE( F ) )
        return -1;
    
    int num = F->tab[F->tete];
    if( F->tete == taille )
        F->tete = 0;
     
    else
        F->tete = F->tete + 1;
    return num;
}

//Procedure afficherFILE
void afficherFILE(maFILE *F)
{
    if( FILEVIDE( F ) )
        printf("\nLa file est vide !");
    else
    {
        for (int i = 0; i < F->queue; i++)
            printf("| %d |", F->tab[i]);  
    }
}