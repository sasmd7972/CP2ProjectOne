//
// Created by steve on 10/8/2020.
//

#include "Sedan.h"

Sedan::Sedan(){
    setColor(RED);
    setupMySeats(DriverSeat, true);
    setupMySeats(FrontSeat5, false);
    setupMySeats(BackSeatL3, false);
    setupMySeats(BackSeatR3, false);
}

Sedan::Sedan(Color color) {
    setColor(color);
    setupMySeats(DriverSeat, true);
    setupMySeats(FrontSeat5, false);
    setupMySeats(BackSeatL3, false);
    setupMySeats(BackSeatR3, false);
}