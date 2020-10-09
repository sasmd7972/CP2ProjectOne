//
// Created by steve on 10/9/2020.
//

#include "Pickup.h"

Pickup::Pickup(){
    setColor(RED);
    setupMySeats(DriverSeat);
    setupMySeats(FrontSeat5);
}

Pickup::Pickup(Color color) {
    setColor(color);
    setupMySeats(DriverSeat);
    setupMySeats(FrontSeat5);
}