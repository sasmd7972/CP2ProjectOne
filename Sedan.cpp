//
// Created by steve on 10/8/2020.
//

#include "Sedan.h"

Sedan::Sedan(){
    setColor(RED);
    setupMySeats(DriverSeat);
    setupMySeats(FrontSeat5);
    setupMySeats(BackSeatL3);
    setupMySeats(BackSeatR3);
    setMyFill(seatAmount);
}

Sedan::Sedan(Color color) {
    setColor(color);
    setupMySeats(DriverSeat);
    setupMySeats(FrontSeat5);
    setupMySeats(BackSeatL3);
    setupMySeats(BackSeatR3);
    setMyFill(seatAmount);
}