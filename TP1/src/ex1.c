#include <stdio.h>
#include "../include/ex1.h"

/**
 * Retourne le résultat de l'opération entre a et b en fonction de l'opérateur
 * @param a
 * @param b
 * @param operateur
 * @return Le résultat de l'opération entre a et b en fonction de l'opérateur
 */
 double op(double a, double b, char operateur){
    double resultat = 0;
    switch(operateur){
        case '+':
            resultat = a + b;
            break;
        case '-':
            resultat = a - b;
            break;
        case '*':
            resultat = a * b;
            break;
        case '/':
            if (b != 0){
                resultat = a / b;
            }
            break;
    }
    return resultat;
}

/**
 * Exécute l'exercice 1
 */
void exec_ex1(){
    double resultat;
    int a,b;
    char operateur;

    printf("Saisir une valeur pour a : ");
    scanf("%d",&a);

    printf("\n");

    printf("Saisir une valeur pour b : ");
    scanf("%d",&b);

    printf("\n");

    printf("Saisir l'operateur de l'operation : ");
    scanf(" %c",&operateur);

    printf("\n");

    resultat = op(a,b,operateur);

    printf("Resultat de l'operation %d %c %d : %lf",a,operateur,b,resultat);
}