//
// Created by steve on 10/8/2020.
//

#ifndef PROJECT_ONE_SEDAN_H
#define PROJECT_ONE_SEDAN_H

#include "Vehicle.h"

class Sedan : public Vehicle {
    private:
        //Sedans only have five seats
        int seatAmount = 5;

    public:
        Sedan();
        Sedan(Color color, Seat seat);


};


#endif //PROJECT_ONE_SEDAN_H
