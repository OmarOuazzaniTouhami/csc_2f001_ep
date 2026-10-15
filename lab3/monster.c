#include <stdio.h>
#include <stdlib.h>
#include "monster.h"

struct monster *create_monster(char *name, int hp) {
    struct monster *m = malloc(sizeof(struct monster));
    if (m == NULL) {
        return NULL;
    }
    m->name = name;
    m->hp = hp;
    return m;
}

void display_monster(struct monster *m) {
    if (m == NULL) {
        return;
    }
    printf("Monster : %s (%d HP)\n", m->name, m->hp);
}

void delete_monster(struct monster *m) {
    free(m);
}