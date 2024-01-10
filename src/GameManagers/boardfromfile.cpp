#include "boardfromfile.hpp"

#include <fstream>
#include <memory>
#include <pthread.h>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "../View/laneview.hpp"
#include "../View/scoreview.hpp"

#include "../Model/lanes.hpp"
#include "../Model/score.hpp"


template <class T>
std::shared_ptr<T> init_big_from_stream(std::stringstream& ss) {
    unsigned id_num, by_pack, between_elems, between_packs, size;
    int first_placement, speed;
    ss >> id_num >> by_pack >>  between_elems >> between_packs
                >> first_placement >> size >> speed;
    return std::make_shared<T>(id_num, by_pack, between_elems, between_packs,
                            first_placement, size, speed);

}

std::shared_ptr<Lane> processStringAsLane(std::stringstream& ss) {
    char laneType;
    ss >> laneType;
    unsigned id_num;
    switch (laneType) {
        case 'S':
            ss >> id_num;
            return std::make_shared<SafeLane>(id_num);
        case 'R':
            return init_big_from_stream<RoadLane>(ss);
        case 'T':
            return init_big_from_stream<TurtleLane>(ss);
        case 'L':
            return init_big_from_stream<LogLane>(ss);
        case 'F':
            ss >> id_num;
            return std::make_shared<FinishLane>(id_num);
        default:
            throw std::runtime_error("No matching lane!");

    }
}

std::vector<std::shared_ptr<Lane>> file_as_board(std::string const& path_to_file) {
    std::vector<std::shared_ptr<Lane>> lanes {};
    std::ifstream myFile(path_to_file);
    if (!myFile.is_open()) throw std::runtime_error("Could not open " + path_to_file);
    std::string line;
    if (myFile.good()) {
        while (std::getline(myFile, line)) {
            std::stringstream ss(line);
            lanes.push_back(processStringAsLane(ss));
        }
    }
    myFile.close();
    return lanes;
}


void BoardFromFile::init_from_file(std::string const& path_to_file) {
    auto lanes = file_as_board(path_to_file);
    std::vector<std::shared_ptr<LaneView>> v {};
    for (auto& lane: lanes) {
        v.push_back(LaneView::makeView(lane));
    }
    bm = std::make_shared<BoardModel>(lanes);
    board = std::make_shared<BoardView>(v, bm);
}

void BoardFromFile::init_from_lvl(unsigned i) {
    std::string path_file = "levels/level" + std::to_string(i) + ".csv";
    this->init_from_file(path_file);
    ssv = std::make_unique<ScoreSaver>(i);
}

std::shared_ptr<BoardView> BoardFromFile::getBoardView() {
    return board;
}

std::shared_ptr<Frog> BoardFromFile::getFrog() {
    return frg;
}

std::shared_ptr<BoardModel> BoardFromFile::getBoardModel() {
    return bm;
}

std::shared_ptr<FrogView> BoardFromFile::getFrogView() {
    return fv;
}

std::unique_ptr<ScoreSaver> BoardFromFile::getScoreSaver() {
    return std::move(ssv);
}
