#include "shortest_path.h"
#include <iostream>

shortest_path_t::shortest_path_t(location_t* from, location_t* to)
    : head{nullptr}, base{nullptr}, from {from}, to {to} {}

void shortest_path_t::compute() {
    head = new node_t{nullptr, from, nullptr, 0.0, from->distance_to(to), false};
    while (true) {
        base = nullptr;
        for (node_t* n = head; n != nullptr; n = n->next) {
            if (!n->visited && (base == nullptr || n->total < base->total)) {
                base = n;
            }
        }
        if (base == nullptr || base->location == to) {
            return;
        }
        base->visited = true;
        for (size_t i = 0; i < base->location->nb_neighbors; i++) {
            location_t* cur = base->location->neighbors[i];
            double from_origin = base->from_origin + base->location->distance_to(cur);
            double total = from_origin + cur->distance_to(to);
            node_t* found = nullptr;
            for (node_t* n = head; n != nullptr; n = n->next) {
                if (n->location == cur) {
                    found = n;
                    break;
                }
            }
            if (found == nullptr) {
                head = new node_t{head, cur, base, from_origin, total, false};
            } else {
                if (found->from_origin < from_origin) {
                } else {
                    found->from = base;
                    found->from_origin = from_origin;
                    found->total = total;
                    found->visited = false;
                }
            }
        }
    }
}

void shortest_path_t::display() {
    if (base == nullptr) {
        std::cout << "unable to find a path from " << from->name
                  << " to " << to->name << std::endl;
        return;
    }
    std::cout << "path from " << from->name << " to " << to->name << std::endl;
    int count = 0;
    for (node_t* n = base; n != nullptr; n = n->from) {
        count++;
    }
    for (int i = count - 1; i >= 0; i--) {
        node_t* n = base;
        for (int j = 0; j < i; j++) {
            n = n->from;
        }
        std::cout << "  * " << n->location->name
                  << " at " << n->from_origin
                  << " km from " << from->name << std::endl;
    }
}