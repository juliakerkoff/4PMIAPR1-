#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void **data;  // Array de ponteiros para dados
    unsigned int size;  // Tamanho do array
    unsigned int capacity;  // Capacidade máxima do array
    void (*print_data)(void*, FILE*);  // Função para imprimir um elemento
    void* (*delete_data)(void*);  // Função para deletar um elemento
    int (*equal_data)(void*, void*);  // Função para comparar dois elementos
} table_t;


table_t table_new(unsigned int n, void (*print_data)(void*, FILE*), void* (*delete_data)(void*), int (*equal_data)(void*, void*)) {
    table_t table;
    table.data = malloc(sizeof(void*) * n);
    table.size = 0;
    table.capacity = n;
    table.print_data = print_data;
    table.delete_data = delete_data;
    table.equal_data = equal_data;
    return table;
}


table_t table_delete(table_t table) {
    for (unsigned int i = 0; i < table.size; i++) {
        table.delete_data(table.data[i]);
    }
    free(table.data);
    table.size = 0;
    table.capacity = 0;
    return table;
}


void table_printf(table_t table) {
    for (unsigned int i = 0; i < table.size; i++) {
        table.print_data(table.data[i], stdout);
    }
    printf("\n");
}


int table_append(void* val, table_t *table) {
    if (table->size == table->capacity) {
        table->capacity *= 2;
        table->data = realloc(table->data, sizeof(void*) * table->capacity);
    }
    table->data[table->size] = val;
    table->size++;
    return 0;
}


int table_insert_at(void* val, int index, table_t *table) {
    if (index < 0 || index > table->size) return -1;  // Índice inválido
    if (table->size == table->capacity) {
        table->capacity *= 2;
        table->data = realloc(table->data, sizeof(void*) * table->capacity);
    }
    for (int i = table->size; i > index; i--) {
        table->data[i] = table->data[i-1];
    }
    table->data[index] = val;
    table->size++;
    return 0;
}


int table_remove_at(int index, table_t *table) {
    if (index < 0 || index >= table->size) return -1;  // Índice inválido
    table->delete_data(table->data[index]);  // Deletar o elemento
    for (int i = index; i < table->size - 1; i++) {
        table->data[i] = table->data[i+1];
    }
    table->size--;
    return 0;
}


void print_double(void *data, FILE *stream) {
    fprintf(stream, "%lf ", *(double*)data);
}

void* delete_double(void *data) {
    free(data);
    return NULL;
}

int equal_double(void *a, void *b) {
    return (*(double*)a == *(double*)b);
}


// ************************************* TESTE***************************************

int main() {
    table_t table = table_new(10, print_double, delete_double, equal_double);

    // Adicionando valores
    for (int i = 0; i < 10; i++) {
        double *val = malloc(sizeof(double));
        *val = i * 1.1;
        table_append(val, &table);
    }
    
    // Imprimindo a tabela
    printf("Tabela após inserções:\n");
    table_printf(table);

    // Inserindo em uma posição específica
    double *val = malloc(sizeof(double));
    *val = 99.9;
    table_insert_at(val, 5, &table);
    
    printf("Tabela após inserção de 99.9 na posição 5:\n");
    table_printf(table);

    // Removendo um elemento
    table_remove_at(3, &table);
    printf("Tabela após remoção da posição 3:\n");
    table_printf(table);

    // Liberando memória
    table_delete(table);

    return 0;
}
