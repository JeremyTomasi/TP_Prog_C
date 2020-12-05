#include "../include/ex2.h"

/**
 * Affiche les tables de mutliplication de 1 à 10 entre a et b
 * @param a
 * @param b
 */
void table_multi(int a, int b){
    for(int i = a; i < b; i++){
        for(int j = 1; j <= 10;j++){
            printf("%d * %d = %d\n",i,j,i*j);
        }
        printf("\n");
    }
}

/**
 * Exécute l'exercice 2
 */
void exec_ex2(){
    int a,b;

    printf("Saisir une valeur pour a : ");
    scanf("%d",&a);

    printf("Saisir une valeur pour b : ");
    scanf("%d",&b);

    table_multi(a,b);
}