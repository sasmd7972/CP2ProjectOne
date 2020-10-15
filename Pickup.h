//
// Created by steve on 10/8/2020.
//

#ifndef PROJECT_ONE_PICKUP_H
#define PROJECT_ONE_PICKUP_H

#include "Vehicle_AND_Player.h"

class Pickup : public Vehicle {
private:
    //Pick Up only has two seats
    int seatAmount = 2;

public:
    Pickup();
    Pickup(Color color);

    //void PrintPickUp();

};
#endif //PROJECT_ONE_PICKUP_H