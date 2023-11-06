#ifndef LANE_H_
#define LANE_H_
#include <cstdint>

class Lane {
    private:
        uint8_t id_num;
        uint8_t length;
    public:
        Lane(uint8_t id_num, uint8_t length):
            id_num(id_num), length(length) {};
        uint8_t getId();
        ~Lane() {};
};

class RoadLane: public Lane {
    public:
        RoadLane();
        ~RoadLane();
};

class SafeLane: public Lane {
    public:
        SafeLane();
        ~SafeLane();
};

class WaterLane: public Lane {
    public:
        WaterLane();
        ~WaterLane();
};

class LogLane: public WaterLane {
    public:
        LogLane();
        ~LogLane();
};

class FinishLane: public WaterLane {
    public:
        FinishLane();
        ~FinishLane();
};

class TurtleLane: public WaterLane {
    public:
        TurtleLane();
        ~TurtleLane();
};
#endif // LANE_H_
