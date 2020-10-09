//
// Created by steve on 10/8/2020.
//

#include "Sedan.h"

Sedan::Sedan(){
    setMySeats(DriverSeat);
    setMySeats(FrontSeat5);
    setMySeats(BackSeatL2);
    setMySeats(BackSeatM1);
    setMySeats(BackSeatR2);

}

Sedan::Sedan(Color color) {
    setColor(color);
    setMySeats(DriverSeat);
    setMySeats(FrontSeat5);
    setMySeats(BackSeatL2);
    setMySeats(BackSeatM1);
    setMySeats(BackSeatR2);

}