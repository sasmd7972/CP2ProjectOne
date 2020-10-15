//
// Created by steve on 10/8/2020.
//

#ifndef PROJECT_ONE_SEDAN_H
#define PROJECT_ONE_SEDAN_H

#include "Vehicle_AND_Player.h"

class Sedan : public Vehicle {
    private:
        //Sedans only has four seats
        int seatAmount = 4;

    public:
        Sedan();
        Sedan(Color color);
};
#endif //PROJECT_ONE_SEDAN_H