#include <stdio.h>
#include "monster.h"
#include "army.h"

int main(int argc, char *argv[]) {
    struct army *army = create_army();
    char buf[32];
    struct monster *monsters[10];

    for (int i = 0; i < 10; i++) {
        snprintf(buf, sizeof(buf), "Pikachu-%d", i);
        monsters[i] = create_monster(buf, 50);
        add_monster_to_army(army, monsters[i]);
    }

    display_army(army);

    for (int i = 0; i < 10; i++) {
        delete_monster(monsters[i]);
    }
    delete_army(army);
}


