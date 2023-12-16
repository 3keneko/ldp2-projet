#include "boardmodel.hpp"
#include "lanes.hpp"
#include <memory>
#include <algorithm>


/// THIS MACRO IS DEFINED FOR DEBUGGING, IT HELPS
/// PRINT OUT THE TUPLE V MORE EASILY
/// IT IS TO BE DELETED BEFORE WE SEND THE PROJECT BACK TO MR. IACONO
#define PRINTTUP(V) std::get<0>(V) << " " << std::get<1>(V)

bool BoardModel::any_collision(Frog& frog) {
    for (auto& lane: lanes) {
        if (lane->getId() == frog.getLane()) {
            /*
            auto try_rl = std::dynamic_pointer_cast<RoadLane>(lane);
            if (try_rl != nullptr) {
                auto car_list = try_rl->getCars();
                return std::any_of(car_list.begin(), car_list.end(),
                                   [&frog](std::shared_ptr<Car> car)
                                   { std::cout << "Frog is " << frog.getColumn()
                                               << " " << frog.getLane()
                                               << " Car is " << PRINTTUP(car->getBoundaries()) << std::endl;
                                       return car->collide(frog); 
                                       });
            
            }
            */
            
        } 

    }
    /*
    // Some tests for when the frog goes outside
    if (!frog.inBoard()) {
        std::cout << "OUT" << std::endl;
    }
    */ 
    return false;
}
