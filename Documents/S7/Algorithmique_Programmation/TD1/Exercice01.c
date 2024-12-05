#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura que representa uma tabela de números reais (double)
typedef struct {
    double *data;    // Ponteiro para os dados (números reais)
    int capacity;    // Capacidade do array (quantos elementos podem ser armazenados)
    int size;        // Tamanho atual do array (quantos elementos estão de fato no array)
} table_double;


// Cria uma tabela com a estrutura acima
table_double table_new(int n) {
    table_double tab;
    tab.data = (double*)malloc(n * sizeof(double)); // Aloca memória para `n` elementos
    tab.capacity = n;  // Define a capacidade inicial da tabela
    tab.size = 0;      // No início, o número de elementos é 0
    return tab;
}


// Limpa a memória
table_double table_delete(table_double tab) {
    free(tab.data);    // Libera a memória alocada
    tab.data = NULL;
    tab.capacity = 0;
    tab.size = 0;
    return tab;
}


// Imprime todos os elementos da tabela
void table_printf(table_double tab) {
    for (int i = 0; i < tab.size; i++) {
        printf("%lf ", tab.data[i]);
    }
    printf("\n");
}


// Retorna o menor índice da tabela 
int table_min(table_double tab) {
    if (tab.size == 0) return -1; // Caso a tabela esteja vazia
    
    int min_index = 0;
    for (int i = 1; i < tab.size; i++) {
        if (tab.data[i] < tab.data[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}



// Adiciona um elemento ao final da tabela
int table_append(double val, table_double *tab) {
    if (tab->size == tab->capacity) {
        return -1;  // Tabela cheia, não é possível adicionar mais elementos
    }
    tab->data[tab->size] = val;
    tab->size++;
    return 0;
}



// Inserir um elemento em uma posição específica
int table_insert_at(double val, int index, table_double *tab) {
    if (index < 0 || index > tab->size || tab->size == tab->capacity) {
        return -1; // Índice inválido ou tabela cheia
    }
    // Desloca elementos para abrir espaço para o novo valor
    for (int i = tab->size; i > index; i--) {
        tab->data[i] = tab->data[i - 1];
    }
    tab->data[index] = val;
    tab->size++;
    return 0;
}


// Remove o elemento na posição index
int table_remove_at(int index, table_double *tab) {
    if (index < 0 || index >= tab->size) {
        return -1; // Índice inválido
    }
    // Desloca os elementos à esquerda para cobrir o espaço removido
    for (int i = index; i < tab->size - 1; i++) {
        tab->data[i] = tab->data[i + 1];
    }
    tab->size--;
    return 0;
}

