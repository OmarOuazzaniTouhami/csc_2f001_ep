#include <iostream>
#include "treemap.h"

int main() {
    treemap_t<std::string, double> map;
    std::string name;

    map.set_at("Tyrion", 2);
    map.set_at("Jaime", 15);
    map.set_at("Cersei", 63);
    map.set_at("Tywin", 75);
    map.set_at("Kevan", 48);
    map.set_at("Lancel", 70);
    map.set_at("Alton", 54);
    map.set_at("Martyn", 32);
    map.set_at("Willem", 6);

    std::cout << map.at("Kevan") << std::endl;
}