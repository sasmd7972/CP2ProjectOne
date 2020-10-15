//
// Created by steve on 10/9/2020.
//

#ifndef PROJECT_ONE_COMPACT_H
#define PROJECT_ONE_COMPACT_H

#include "Vehicle_AND_Player.h"

class Compact : public Vehicle {
private:
    //Sedans only has five seats
    int seatAmount = 5;

public:
    Compact();
    Compact(Color color);
};
#endif //PROJECT_ONE_COMPACT_H