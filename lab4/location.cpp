#include "location.h"
#include <string>

location_t::location_t(std::string name, double latitude, double longitude)
    : name {name},
    latitude {latitude},
    longitude {longitude},
    neighbors {nullptr},
    nb_neighbors {0} {}