#include "monster.h"

struct army;

struct army *create_army(void);
int add_monster_to_army(struct army *a, struct monster *m);
void display_army(struct army *a);
void delete_army(struct army *a);