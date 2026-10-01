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

int main(int argc, char* argv[]) {    
    float tab[5] = {1, 3, 5, 7, 0};
    printf("Insert 0 at %d, 3.5 at %d, 10 at %d\n", sort_get_index(tab, 4, 0), sort_get_index(tab, 4, 3.5), sort_get_index(tab, 4, 10));
    for(int i = 0; i<5; i++) {
        printf("%f ", tab[i]);
    }
}