#include <stdio.h>

int sort_get_index(float tab[], int top, float val) {
    int i = 0;
    while (tab[i] < val) {
        i++;
        if (i == top) {
            return top;
        }
    }
    return i;
}

void sort_insert_at(float tab[], int i, int top, float val) {
    for (int j = top-1; j>=i; j--) {
        tab[j+1] = tab[j];
    }
    tab[i] = val;
}

void sort_insert(float tab[], int top, float val) {
    int i = sort_get_index(tab, top, val);
    sort_insert_at(tab, i, top, val);
}

int nb_columns() {
    return 32;
}

int nb_lines() {
    return 16;
}

void grid_init(char grid[], char pixel) {
    for (int i=0; i<(nb_columns()*nb_lines()); i++) {
        grid[i] = pixel;
    }
}

void grid_display(char grid[]) {
    for (int i = 0; i<(nb_columns()*nb_lines()); i++) {
        if (i%32 == 31) {
            printf("%c\n", grid[i]);
        } else {
            printf("%c", grid[i]);
        }
    }
}

int main(int argc, char* argv[]) {    
    char grid[nb_columns()*nb_lines()];
    grid_init(grid, '*');
    grid_display(grid);
}