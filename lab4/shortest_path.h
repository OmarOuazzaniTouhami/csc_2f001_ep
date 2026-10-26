#include "location.h"

struct node_t {
    node_t* next;
    location_t* location;
    node_t* from;
    double from_origin;
    double total;
    bool visited;
};

struct shortest_path_t {
    node_t* head;
    node_t* base;
    location_t* from;
    location_t* to;

    shortest_path_t(location_t* from, location_t* to);
    void compute();
    void display();
}
