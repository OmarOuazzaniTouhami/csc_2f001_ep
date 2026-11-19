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

    for(treemap_t<std::string, double>::iterator_t it = map.begin();
        it.cur != nullptr;
        it.next()) {
      std::cout << it.cur->key << " => " << it.cur->value << std::endl;
    }
}