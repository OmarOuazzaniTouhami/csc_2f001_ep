#include <stdio.h>
#include <stdlib.h>

#include "army.h"
#include "monster.h"

struct node {
    struct monster *monster;
    struct node *next;
};

struct army {
  struct node *first;
  struct node *last;
  int top;                      
  int stars;          
};

struct army *create_army(void) {
    struct army *a = malloc(sizeof(struct army));
    a->first = NULL;
    a->last = NULL;
    a->stars = 0;
    a->top = 0;
    return a;
}

int add_monster_to_army(struct army *a, struct monster *m) {
    if (a == NULL || m == NULL) {
        return -1;
    }

    struct node *n = malloc(sizeof(struct node));
    n->monster = m;
    n->next = NULL;
    if (a->last == NULL) {
        a->first = n;
    } else {
        a->last->next = n;
    }
    a->last = n;
    a->top++;
    return 0;
}

void display_army(struct army *a) {
    if (a == NULL)
        return;
    printf("This is a %d stars army.\n", a->stars);
    printf("An army of %d monsters.\n", a->top);
    for (struct node *n = a->first; n!=NULL; n = n->next) {
        display_monster(n->monster);
    }
}

void delete_army(struct army *a) {
    if (a == NULL)
        return;

    struct node *n = a->first;
    while (n != NULL) {
        struct node *next = n->next;
        free(n);
        n = next;
    }
    free(a);
}