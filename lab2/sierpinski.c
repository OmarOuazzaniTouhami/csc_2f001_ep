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

int main(int argc, char* argv[]) {    
    float tab[5] = {1, 3, 5, 7, 0};
    printf("Insert 0 at %d, 3.5 at %d, 10 at %d\n", sort_get_index(tab, 4, 0), sort_get_index(tab, 4, 3.5), sort_get_index(tab, 4, 10));
    sort_insert_at(tab, sort_get_index(tab, 4, 3.5), 4, 3.5);
    for(int i = 0; i<5; i++) {
        printf("%f ", tab[i]);
    }
}