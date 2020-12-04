#include "resources.h"

void init(Bowling *b){
    // Init tableau score (allocation dynamique)
    b->score = (int **)calloc(4,sizeof(int *));

    if(b->score != NULL){
        for(int i = 0; i < 4; i++){
            b->score[i] = (int *)calloc(12,sizeof(int));
            if(b->score[i] == NULL){
                fprintf(stderr,"Erreur allocation mémoire");
                break;
            } else {
                for(int j = 0; j < 12; j++){
                    b->score[i][j] = 0;
                }
            }
        }
    } else {
        fprintf(stderr,"Erreur allocation mémoire");
    }

    // Init tableau symboles (allocation dynamique)

    b->symboles = (char *)calloc(12,sizeof(char));
    if(b->symboles == NULL){
        fprintf(stderr,"Erreur allocation mémoire");
    } else {
        for(int i = 0; i < 12; i++){
            b->symboles[i] = '-';
        }
    }
}

void saisie_tour(int *score_lancer_1, int *score_lancer_2){
    int quillesRestantes = 10;
    do {
        printf("Saisir le nombre de quilles tombées au lancer 1 : ");
        scanf("%d",score_lancer_1);
    } while(*score_lancer_1 < 0 || *score_lancer_1 > 10);

    quillesRestantes -= *score_lancer_1;

    if(*score_lancer_1 != 10){
        do {
            printf("Saisir le nombre de quilles tombées au lancer 2 : ");
            scanf("%d",score_lancer_2);
        } while(*score_lancer_2 < 0 || *score_lancer_2 > quillesRestantes);
    } else {
        *score_lancer_2 = 0;
    }
}

void maj_tab_tour(Bowling *b,int score_lancer_1, int score_lancer_2, int nb_tour){
    int totalScoreTour;
    // Score lancer 1
    b->score[0][nb_tour] = score_lancer_1;

    // Score lancer 2
    b->score[1][nb_tour] = score_lancer_2;


    // Calcul total score du tour
    totalScoreTour = score_lancer_1 + score_lancer_2;

    if(score_lancer_1 == 10){
        b->symboles[nb_tour] = 'X';
    } else if(totalScoreTour == 10){
        b->symboles[nb_tour] = '/';
    }

    b->score[2][nb_tour] = totalScoreTour;

    if(nb_tour != 0){
        if(b->symboles[nb_tour - 1] == '/'){
            b->score[3][nb_tour - 1] += score_lancer_1;
        } else if(b->symboles[nb_tour - 1] == 'X'){
            b->score[3][nb_tour - 1] += 10;
        }
        b->score[3][nb_tour] = b->score[3][nb_tour - 1] + totalScoreTour;
    } else {
        b->score[3][nb_tour] += totalScoreTour;
    }
}

void affichage_tab_score(int **tabScore){
    for(int i = 0; i < 4;i++){
        for(int j = 0; j < 12;j++){
            printf("%d ",tabScore[i][j]);
        }
        printf("\n");
    }
}

void affichage_tab_symboles(char *tabSymboles){
    for(int i = 0; i < 12;i++){
        printf("%c ",tabSymboles[i]);
    }
}

void saisie_lancer(int *score_lancer, int *quillesRestantes){
    do {
        printf("Saisir le nombre de quilles tombées au lancer  : ");
        scanf("%d",score_lancer);
    } while(*score_lancer < 0 || *score_lancer > *quillesRestantes);
}

void partie(Bowling *b){
    int score_lancer_1, score_lancer_2;
    for(int i = 0; i < 10; i++){
        printf("Tour n° %d\n\n",i+1);
        saisie_tour(&score_lancer_1,&score_lancer_2);
        maj_tab_tour(b,score_lancer_1,score_lancer_2,i);
    }


    affichage_tab_score(b->score);
    affichage_tab_symboles(b->symboles);
}
