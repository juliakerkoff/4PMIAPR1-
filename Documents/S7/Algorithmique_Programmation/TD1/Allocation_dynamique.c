#include <stdio.h>
#include <stdlib.h>

/* MALLOC*/
/* CALLOC*/

int main(void){

    int njogador = 0;
    int *lista_jogadores = NULL;
    int i;

    printf("Quantos jogadores?");
    scanf("%d", &njogador);

    lista_jogadores = malloc(njogador * sizeof(int));
    
    if(lista_jogadores == NULL)
        exit(1);


        
    for(i = 0; i < njogador ; i++){

        printf("Jogador %d -> numero %d\n", i + 1, i * 3);
        lista_jogadores[i] = i * 3;

    }        
    

    for(i = 0; i < njogador ; i++){

        printf("[%d]", lista_jogadores[i]);
        
    }

    free(lista_jogadores);

    return 0;
}