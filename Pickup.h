//
// Created by steve on 10/8/2020.
//

#ifndef PROJECT_ONE_SEDAN_H
#define PROJECT_ONE_SEDAN_H

#include "Vehicle.h"

class Pickup : public Vehicle {
private:
    //Sedans only have five seats
    int seatAmount = 5;

public:
    Pickup();
    Pickup(Color color);
};
#endif //PROJECT_ONE_SEDAN_H