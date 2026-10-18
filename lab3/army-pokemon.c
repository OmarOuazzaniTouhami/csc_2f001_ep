#include <stdio.h>
#include <stdlib.h>

#include "army.h"
#include "monster.h"

struct army {
  struct monster** monsters; 
  int top;                   
  int capacity;    
  int stars;          
};

struct army *create_army(void) {
    struct army *a = malloc(sizeof(struct army));
    if (a == NULL)
        return NULL;

    a->monsters = NULL;
    a->top = 0;
    a->capacity = 0;
    return a;
}

int add_monster_to_army(struct army *a, struct monster *m) {
    if (a == NULL || m == NULL)
        return -1;

    if (a->top == a->capacity)
    {
        int new_capacity = (a->capacity == 0) ? 1 : a->capacity * 2;
        struct monster **tmp =
            realloc(a->monsters, new_capacity * sizeof(struct monster *));
        if (tmp == NULL)
            return -1;
        a->monsters = tmp;
        a->capacity = new_capacity;
    }
    a->monsters[a->top] = m;
    a->top++;
    return 0;
}

void display_army(struct army *a) {
    if (a == NULL)
        return;

    printf("An army of %d monsters, capacity of %d\n", a->top, a->capacity);
    for (int i = 0; i < a->top; i++)
        display_monster(a->monsters[i]);
}

void delete_army(struct army *a) {
    if (a == NULL)
        return;

    free(a->monsters);
    free(a);
}