#include <iostream>
#include "treemap.h"

int main() {
    treemap_t<std::string, double>::pair_t pair  = {"Tyrion", 2.0};
    std::cout << pair.key << ": " << pair.value << "€" << std::endl;
}