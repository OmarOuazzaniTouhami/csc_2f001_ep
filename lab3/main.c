#include <stdio.h>
#include "monster.h"
#include "army.h"

int main(int argc, char *argv[]) {
    struct army *army = create_army();
    char buf[32];
    for (int i = 0; i < 10; i++) {
        snprintf(buf, sizeof(buf), "Pikachu-%d", i);
        add_monster_to_army(army, create_monster(buf, 50));
    }

    display_army(army);

    for (int i = 0; i < army->top; i++) {
        delete_monster(army->monsters[i]);
    }
    delete_army(army);
}


