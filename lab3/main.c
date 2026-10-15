#include <stdio.h>
#include "monster.h"

int main(int argc, char *argv[]) {
    struct monster *m = create_monster("Pikachu", 50);
    if (m == NULL) {
        printf("Error: could not create monster\n");
        return 1;
    }
    display_monster(m);
    delete_monster(m);
}


