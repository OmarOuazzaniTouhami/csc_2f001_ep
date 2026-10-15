#include <stdio.h>
#include "monster.h"

int main(int argc, char *argv[]) {
    struct monster *army[10];
    char buf[32];
    for (int i = 0; i < 10; i++) {
        snprintf(buf, sizeof(buf), "Pikachu-%d", i);
        army[i] = create_monster(buf, 50);
    }
    for (int i = 0; i < 10; i++) {
       display_monster(army[i]);
    }
    for (int i = 0; i < 10; i++) {
        delete_monster(army[i]);
    }
}


