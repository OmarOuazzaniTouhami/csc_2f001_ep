#include <iostream>
#include "location.h"
#include "shortest_path.h"

int main() {
    location_t palaiseau { "Palaiseau", 0.850219, 0.0386527 };
    location_t paris { "Paris", 0.852709, 0.041054 };
    location_t strasbourg { "Strasbourg", 0.837758, 0.122173 };
    location_t reims { "Reims", 0.855211, 0.069813 };
    location_t dijon { "Dijon", 0.820304, 0.087266 };
    location_t lemans { "Le Mans", 0.837865, 0.00348291 };
    location_t orleans { "Orléans", 0.836064, 0.0333227 };
    location_t angers { "Angers", 0.828655, -0.0098291 };
    location_t tours { "Tours", 0.827184, 0.0119527 };
    location_t bourges { "Bourges", 0.821719, 0.0418666 };
    location_t poitiers { "Poitiers", 0.812978, 0.00594066 };
    location_t limoges { "Limoges", 0.799948, 0.0220104 };
    location_t angouleme { "Angouleme", 0.796714, 0.00272685 };
    location_t bordeaux { "Bordeaux", 0.782567, -0.0101086 };
    location_t agen { "Agen", 0.77149, 0.0107576 };
    location_t toulouse { "Toulouse", 0.761045, 0.0252062 };
    location_t bayonne { "Bayonne", 0.759095, -0.0257408 };
    location_t pau { "Pau", 0.755642, -0.00647163 };
    location_t sansebastian { "San Sebastian", 0.756048, -0.034579 };
    location_t pampelune { "Pampelune", 0.74722, -0.0287242 };
    location_t bilbao { "Bilbao", 0.755082, -0.0512252 };
    palaiseau.set_neighbors(new location_t*[] { &paris, nullptr });
    paris.set_neighbors(new location_t*[] { &palaiseau, &lemans, &orleans, &reims, &dijon, nullptr });
    reims.set_neighbors(new location_t*[] { &strasbourg, &dijon, nullptr });
    strasbourg.set_neighbors(new location_t*[] { &reims, &dijon, nullptr });
    dijon.set_neighbors(new location_t*[] { &reims, &paris, &bourges, nullptr });
    lemans.set_neighbors(new location_t*[] { &orleans, &tours, &angers, nullptr });
    orleans.set_neighbors(new location_t*[] { &lemans, &paris, &bourges, &tours, nullptr });
    angers.set_neighbors(new location_t*[] { &lemans, &tours, &poitiers, nullptr });
    tours.set_neighbors(new location_t*[] { &angers, &lemans, &orleans, &bourges, &poitiers, nullptr });
    bourges.set_neighbors(new location_t*[] { &limoges, &tours, &orleans, nullptr });
    poitiers.set_neighbors(new location_t*[] { &limoges, &angouleme, nullptr });
    limoges.set_neighbors(new location_t*[] { &agen, &angouleme, &poitiers, nullptr });
    angouleme.set_neighbors(new location_t*[] { &poitiers, &limoges, &agen, &bordeaux, nullptr });
    bordeaux.set_neighbors(new location_t*[] { &angouleme, &agen, &bayonne, nullptr });
    agen.set_neighbors(new location_t*[] { &toulouse, &pau, &bordeaux, &angouleme, &limoges, nullptr });
    toulouse.set_neighbors(new location_t*[] { &agen, &pau, nullptr });
    bayonne.set_neighbors(new location_t*[] { &bordeaux, &pau, &sansebastian, nullptr });
    pau.set_neighbors(new location_t*[] { &pampelune, &bayonne, &agen, &toulouse, nullptr });
    sansebastian.set_neighbors(new location_t*[] { &bayonne, &pampelune, &bilbao, nullptr });
    pampelune.set_neighbors(new location_t*[] { &bilbao, &sansebastian, &pau, nullptr });
    bilbao.set_neighbors(new location_t*[] { &sansebastian, &pampelune, nullptr });
    std::cout << paris.distance_to(&palaiseau) << std::endl;
    shortest_path_t go(&palaiseau, &bilbao);
    go.compute();
    go.display();

    shortest_path_t back(&bilbao, &palaiseau);
    back.compute();
    back.display();

    return 0;
} 
