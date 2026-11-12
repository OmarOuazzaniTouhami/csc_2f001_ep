#include <iostream>
#include "treemap.h"

int main() {
    treemap_t<std::string, double> map;
    std::string name;

    name = "Tyrion";
    map.lookup(&map.root, nullptr, &name, true);
    name = "Jaime";
    map.lookup(&map.root, nullptr, &name, true);
    name = "Cersei";
    map.lookup(&map.root, nullptr, &name, true);
}