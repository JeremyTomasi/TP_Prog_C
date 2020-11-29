#include "../include/ex3.h"

/**
 * Permet de saisir le nombre de valeurs à saisir dans le tableau
 * @return Le nombre de valeurs à saisir dans le tableau
 */
int nbValTab(){
    int nbVal = -1;
    do {
        printf("Saisir le nombre de valeurs a rentrer (entre 1 et 20) : ");
        scanf("%d",&nbVal);
    } while(nbVal < 1 || nbVal > 20);

    return nbVal;
}

/**
 * Saisit les valeurs dans les n cases du tableau
 * @param tab Le tableau où saisir les valeurs
 * @param n Le nombre de valeurs à saisir
 */
void saisirNTab(int tab[20], int n){
    for(int i = 0; i < n;i++){
        printf("Saisir une valeur : ");
        scanf("%d",(tab + i));
    }
}

/**
 * Affiche les valeurs saisies dans le tableau
 * @param tab Le tableau à afficher
 * @param n Le nombre de valeurs à afficher
 */
 void afficherTab(int tab[20],int n){
    for(int i = 0; i < n;i++){
        printf("tab[%d] = %d\n",i,*(tab+i));
    }
}

/**
 * Retourne la valeur maximale contenue dans le tableau
 * @param tab Le tableau où rechercher la valeur maximale
 * @param n Le nombre de cases à parcourir
 * @return La valeur maximale du tableau
 */
int max(int tab[20],int n){
    int max = tab[0];

    for(int i = 1; i < n;i++){
        if(*(tab + i) > max){
            max = *(tab + i);
        }
    }

    return max;
}

/**
 * Retourne la somme des valeurs du tableau
 * @param tab Le tableau à sommer
 * @param n Le nombre de cases à sommer
 * @return La somme des valeurs du tableau
 */
int sommeTab(int tab[20],int n){
    int somme = 0;

    for(int i = 0; i < n;i++){
        somme += *(tab + i);
    }

    return somme;
}

/**
 * Affiche le menu
 */
void menu(){
    printf("1 - Saisie du nombre de valeurs\n");
    printf("2 - Saisie des valeurs\n");
    printf("3 - Affichage des valeurs\n");
    printf("4 - Valeur maximale du tableau\n");
    printf("5 - Somme des valeurs du tableau\n");
    printf("6 - Quitter");
}

/**
 * Exécute l'exercice 3
 */
void exec_ex3(){
    int continuer = 1;
    int choix;
    int nbVal, maxVal, somme;
    int tab[20] = {0};

    while(continuer){
        menu();
        printf("\n");

        printf("Votre choix :");
        scanf("%d",&choix);

        switch(choix){
            case 1:
                nbVal = nbValTab();
                break;
            case 2:
                saisirNTab(tab,nbVal);
                break;
            case 3:
                afficherTab(tab,nbVal);
                break;
            case 4:
                maxVal = max(tab,nbVal);
                printf("La valeur maximale du tableau est : %d\n",maxVal);
                break;
            case 5:
                somme = sommeTab(tab,nbVal);
                printf("La somme des valeurs du tableau est egale a : %d\n",somme);
                break;
            case 6:
                continuer = 0;
                break;
        }
    }
}