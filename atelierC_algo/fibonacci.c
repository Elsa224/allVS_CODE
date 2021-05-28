#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"  //Les fonctions fibonacci version normale et recursive terminale

int main()
{
    int num, fibT0, fibT1, numb, compteur = 2;
    // do
    // {
    //     printf("Veuillez entrer un nombre entier naturel s'il vous plait : ");
    //     scanf("%d", &num);
    // }while (num < 0);

    // printf("Voici la suite de Fibonacci de %d : fib(%d) = %d.", num, num, fib(num));
    
    // Avec la tail recursive
    printf("Entrez la valeur de fibTerm(0) :\nfibTerm(0) = ");
    scanf("%d", &fibT0);
    printf("Entrez la valeur de fibTerm(1) :\nfibTerm(1) = ");
    scanf("%d", &fibT1);
    printf("Pour quelle valeur voulez-vous calculer fibTerm ? :\nm = ");
    scanf("%d", &numb);

    printf("Avec la methode recursive terminale, on obtient fibTerm(%d) = %d", numb, fibTerm(numb, fibT0, fibT1, compteur+1));

    return 0;
}