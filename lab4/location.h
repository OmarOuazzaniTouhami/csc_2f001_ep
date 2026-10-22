#include <string>

struct location_t {
    std::string name;
    double latitude;
    double longitude;
    location_t** neighbors;
    size_t nb_neighbors;

    location_t(std::string name, double latitude, double longitude);
    void set_neighbors(location_t* list[]);
};

