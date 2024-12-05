// ************************************* TESTE***************************************

#define NBTESTS 1000
#define NBCAS 4
#include "Exercice01.c"


int main() {
    srand(time(NULL));  // Inicializa o gerador de números aleatórios

    table_double t1 = table_new(100);  // Cria uma nova tabela com capacidade para 100 elementos
    double x;
    int pos;

    for (int j = 0; j < NBTESTS; j++) {  // Executa 1000 operações aleatórias
        switch (rand() % NBCAS) {  // Escolhe aleatoriamente uma operação (0 a 3)
            case 0:
            case 1:
                // Adiciona um número aleatório ao final da tabela
                x = (double)(rand() % 100);
                printf("Append de %lf\n", x);
                table_append(x, &t1);
                break;
            case 2:
                // Insere um número aleatório em uma posição aleatória
                x = (double)(rand() % 100);
                pos = rand() % (t1.size + 1);  // Posição aleatória válida
                printf("Insertion de %lf en position %d\n", x, pos);
                table_insert_at(x, pos, &t1);
                break;
            case 3:
                // Remove um elemento de uma posição aleatória, se houver
                if (t1.size > 0) {
                    pos = rand() % t1.size;
                    printf("Suppression de l'élément en position %d\n", pos);
                    table_remove_at(pos, &t1);
                }
                break;
        }
        table_printf(t1);  // Imprime a tabela após cada operação
    }

    printf("Libération du tableau\n");
    t1 = table_delete(t1);  // Libera a memória da tabela

    return 0;
}