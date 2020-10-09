//
// Created by steve on 10/9/2020.
//

#include "Compact.h"

Compact::Compact(){
    setColor(RED);
    setupMySeats(DriverSeat);
    setupMySeats(FrontSeat5);
    setupMySeats(BackSeatL2);
    setupMySeats(BackSeatM1);
    setupMySeats(BackSeatR2);
    setMyFill(seatAmount);
}

Compact::Compact(Color color) {
    setColor(color);
    setupMySeats(DriverSeat);
    setupMySeats(FrontSeat5);
    setupMySeats(BackSeatL2);
    setupMySeats(BackSeatM1);
    setupMySeats(BackSeatR2);
    setMyFill(seatAmount);
}