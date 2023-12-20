#include "maininit.hpp"
#include "Model/boardmodel.hpp"
#include "Model/lanes.hpp"
#include <fstream>
#include <memory>
#include <pthread.h>
#include <sstream>
#include <stdexcept>
#include <string>

/*
template <class T>
std::shared_ptr<T> init_from_init_vec(std::vector<int> init_vec, char type) {
    if (type == 'S' || type=='F') return std::make_shared<T>(init_vec.at(0));
    else return std::make_shared<T>(init_vec.at(0), init_vec.at(1), init_vec.at(2),
                                    init_vec.at(3), init_vec.at(4), init_vec.at(5), init_vec.at(6));
}

std::shared_ptr<Lane> processStringAsLane(std::stringstream& ss) {
    char laneType;
    ss >> laneType;
#include <iostream>
    std::cout << laneType << "\n";
    std::string value;
    std::vector<int> init_list {};
    while (std::getline(ss, value, ',' )) {
        try {
            int val = std::stoi(value);
            init_list.push_back(val);
        }
        catch (...) {}
    }
    std::cout << laneType << init_list[0] << "\n";
    switch (laneType) {
        case 'S':
            return init_from_init_vec<SafeLane>(init_list, 'S');
        case 'R':
            return init_from_init_vec<RoadLane>(init_list, 'R');
        case 'T':
            return init_from_init_vec<TurtleLane>(init_list, 'T');
        case 'L':
            return init_from_init_vec<LogLane>(init_list, 'L');
        case 'F':
            return init_from_init_vec<FinishLane>(init_list, 'F');
        default:
            throw std::runtime_error("No matching lane!");
    }
}


void MainInit::init_from_file(std::string path_to_file) {
    Frog frog {0, 250};
    frg = std::make_shared<Frog>(frog);
    fv = std::make_shared<FrogView>(frg);

    // https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp/
    std::ifstream myFile(path_to_file);

    if (!myFile.is_open()) throw std::runtime_error("Could not open file!");

    std::string line;

    if (myFile.good()) {
        while (std::getline(myFile, line)) {
            std::stringstream ss(line);
            bm->addLane(processStringAsLane(ss));
        }
    }

    myFile.close();
    std::vector<std::shared_ptr<LaneView>> v {};

    for (auto& lane: bm->getLanes()) {
        v.push_back(LaneView::makeView(lane));
    }

    board = std::make_shared<BoardView>(v, bm);

}
*/

void MainInit::classic_init() {
            // Intializing the frog
            Frog frog {0, 250};
            frg = std::make_shared<Frog>(frog);
            fv = std::make_shared<FrogView>(frg);

            // Initializing the lanes
            std::vector<std::shared_ptr<Lane>> lanes;
            lanes.push_back(std::make_shared<SafeLane>(1));
            lanes.push_back(std::make_shared<SafeLane>(2));
            lanes.push_back(std::make_shared<RoadLane>(3, 3, 150, 350, 0, 30, 1));
            lanes.push_back(std::make_shared<RoadLane>(4, 3, 150, 350, 0, 30, 2));
            lanes.push_back(std::make_shared<RoadLane>(5, 10, 150, 350, 0, 40, 3));
            lanes.push_back(std::make_shared<RoadLane>(6, 3, 150, 350, 0, 40, -2));
            lanes.push_back(std::make_shared<SafeLane>(7));
            lanes.push_back(std::make_shared<TurtleLane>(8, 5, 10, 200, 0, 50, 1));
            lanes.push_back(std::make_shared<TurtleLane>(9, 5, 10, 200, 0, 50, -1));
            lanes.push_back(std::make_shared<LogLane>(10, 3, 30, 350, 2, 200, 1));
            lanes.push_back(std::make_shared<LogLane>(11, 3, 30, 350, -2, 200, 2));
            lanes.push_back(std::make_shared<LogLane>(12, 3, 30, 350, 2, 200, -1));
            lanes.push_back(std::make_shared<FinishLane>(13));

            std::vector<std::shared_ptr<MovingObjectLane>> v1 { };
            for (auto& lane: lanes) {
                auto moving_object_lane = std::dynamic_pointer_cast<MovingObjectLane>(lane);
                if (moving_object_lane != nullptr) {
                    v1.push_back(moving_object_lane);
                }
            }

            std::vector<std::shared_ptr<LaneView>> v {};

            for (auto& lane: lanes) {
                v.push_back(LaneView::makeView(lane));
            }
            // Putting the frog and the lanes together; initializing the board
            bm = std::make_shared<BoardModel>(lanes);
            board = std::make_shared<BoardView>(v, bm) ;
}
