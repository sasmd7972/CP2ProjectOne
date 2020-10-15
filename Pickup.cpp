//
// Created by steve on 10/9/2020.
//

#include "Pickup.h"

Pickup::Pickup(){
    setColor(RED);
    setupMySeats(DriverSeat, true);
    setupMySeats(FrontSeat5, false);
}

Pickup::Pickup(Color color) {
    setColor(color);
    setupMySeats(DriverSeat, true);
    setupMySeats(FrontSeat5, false);
}