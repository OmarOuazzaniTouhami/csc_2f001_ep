#include "location.h"
#include <string>

location_t::location_t(std::string name, double latitude, double longitude)
    : name {name},
    latitude {latitude},
    longitude {longitude},
    neighbors {nullptr},
    nb_neighbors {0} {}

void location_t::set_neighbors(location_t* list[]) {
    neighbors = list;
    nb_neighbors = 0;
    while (list[nb_neighbors] != nullptr) {
        nb_neighbors++;
    }
}