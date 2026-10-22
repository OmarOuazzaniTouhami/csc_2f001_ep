#include "location.h"
#include <string>
#include <numbers>
#include <cmath>

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

double location_t::distance_to(location_t* to) {
    double lat1 = this->latitude;
    double long1 = this->longitude;
    double lat2 = to->latitude;
    double long2 = to->longitude;
    double R = 6378;
    return R * (std::numbers::pi/2 - std::asin(std::sin(lat2) * std::sin(lat1) + std::cos(long2 - long1) * std::cos(lat2) * std::cos(lat1)));
}

location_t::~location_t() {
    delete[] neighbors;
}