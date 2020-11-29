#include "../include/ex4.h"

/**
 * Indique si le tableau contient au moins une valeur non nulle
 * @param tab Le tableau à scanner
 * @param n Le nombre de cases à parcourir
 * @return Le résultat de la recherche
 */
bool oneNotNullValue(int tab[10], int n){
    bool notNullValue = false;
    for(int i = 0; i < n;i++){
        if(*(tab + i) != 0){
            notNullValue = true;
            break;
        }
    }
    return notNullValue;
}

/**
 * Indique si le tableau contient uniquement des valeurs nulles
 * @param tab Le tableau à scanner
 * @param n Le nombre de cases à parcourir
 * @return Le résultat de la recherche
 */
bool onlyNullValues(int tab[10],int n){
    bool onlyNullValues;
    int nbNullValues = 0;
    for(int i = 0; i < n;i++){
        if(*(tab + i) == 0){
            nbNullValues++;
        }
    }

    if(nbNullValues == n){
        onlyNullValues = true;
    } else {
        onlyNullValues = false;
    }

    return onlyNullValues;
}

/**
 * Indique si une valeur précise est contenue dans le tableau
 * @param tab Le tableau à scanner
 * @param n Le nombre de cases à parcourir
 * @param searchedVal La valeur à rechercher
 * @return Le résultat de la recherche
 */
bool isInTab(int tab[10],int n, int searchedVal){
    bool valInTab = false;
    for(int i = 0; i < n;i++){
        if(*(tab + i) == searchedVal){
            valInTab = true;
            break;
        }
    }

    return valInTab;
}

/**
 * Indique si toutes les valeurs du tableau sont égales
 * @param tab Le tableau à scanner
 * @param n Le nombre de cases à parcourir
 * @return Le résultat de la recherche
 */
bool tabEgalValues(int tab[10],int n){
    bool egalValues = true;
    for(int i = 0; i < n-1;i++){
        if(*(tab + i) != *(tab + (i + 1))){
            egalValues = false;
            break;
        }
    }

    return egalValues;
}

/**
 * Indique si le tableau est trié de manière croissante
 * @param tab Le tableau à scanner
 * @param n Le nombre de cases à parcourir
 * @return Le résultat de la recherche
 */
bool isTriedAsc(int tab[10],int n){
    bool triedTab = true;
    for(int i = 0; i < n - 1;i++){
        if(*(tab + i) > *(tab + (i + 1))){
            triedTab = false;
            break;
        }
    }

    return triedTab;
}

void exec_ex4(){
    int tab[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("%d\n",oneNotNullValue(tab,10));
    printf("%d\n",onlyNullValues(tab,10));
    printf("%d\n",isInTab(tab,10,5));
    printf("%d\n",tabEgalValues(tab,10));
    printf("%d\n",isTriedAsc(tab,10));
}