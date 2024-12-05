#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double *data;
    int size;
    int actual_size;
} table_t;

// Fonctions à implémenter
table_t table_new(int n);
table_t table_delete(table_t tab);
void table_printf(table_t tab);
int table_min(table_t tab);
int table_append(double val, table_t *tab);
int table_insert_at(double val, int index, table_t *tab);
int table_remove_at(int index, table_t *tab);


// Créer un tableau

table_t table_new(int n) {
    table_t tab;
    tab.data = (double *)malloc(n * sizeof(double));
    tab.size = n;
    tab.actual_size = 0; // Aucun élément ajouté au début
    return tab;
}

// Supprimer um tableau

table_t table_delete(table_t tab) {
    if (tab.data != NULL) {
        free(tab.data);
        tab.data = NULL;
    }
    tab.size = 0;
    tab.actual_size = 0;
    return tab;
}

// Afficher le tableau

void table_printf(table_t tab) {
    for (int i = 0; i < tab.actual_size; i++) {
        printf("%.2lf ", tab.data[i]);
    }
    printf("\n");
}

// Trouver le minimum du tableau

int table_min(table_t tab) {
    if (tab.actual_size == 0) return -1;
    double min = tab.data[0];
    int min_index = 0;
    for (int i = 1; i < tab.actual_size; i++) {
        if (tab.data[i] < min) {
            min = tab.data[i];
            min_index = i;
        }
    }
    return min_index;
}


// Ajouter un élément à la fin du tableau

int table_append(double val, table_t *tab) {
    if (tab->actual_size == tab->size) {
        tab->size *= 2;
        tab->data = (double *)realloc(tab->data, tab->size * sizeof(double));
        if (tab->data == NULL) return -1;
    }
    tab->data[tab->actual_size++] = val;
    return 0;
}


// Insérer un élément à une position donnée

int table_insert_at(double val, int index, table_t *tab) {
    if (index < 0 || index > tab->actual_size) return -1;
    
    if (tab->actual_size == tab->size) {
        tab->size *= 2;
        tab->data = (double *)realloc(tab->data, tab->size * sizeof(double));
        if (tab->data == NULL) return -1;
    }
    
    for (int i = tab->actual_size; i > index; i--) {
        tab->data[i] = tab->data[i-1];
    }
    tab->data[index] = val;
    tab->actual_size++;
    
    return 0;
}

// Supprimer un élément à une position donnée

int table_remove_at(int index, table_t *tab) {
    if (index < 0 || index >= tab->actual_size) return -1;
    
    for (int i = index; i < tab->actual_size - 1; i++) {
        tab->data[i] = tab->data[i + 1];
    }
    
    tab->actual_size--;
    return 0;
}
