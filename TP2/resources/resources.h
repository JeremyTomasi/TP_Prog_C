#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **score;
    char *symboles;
} Bowling;

void init(Bowling *b);

void affichage_tab_score(int **tabScore);

void affichage_tab_symboles(char *tabSymboles);

void saisie_tour(int *score_lancer_1, int *score_lancer_2);

void partie(Bowling *b);