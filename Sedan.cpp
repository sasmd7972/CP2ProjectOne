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

/*
void Sedan::PrintSedan(){
    if ( color == 0){
        cout << "RED" << endl;
    }
    else if( color == 1){
        cout << "BLUE" << endl;
    }
    else if( color == 2){
        cout << "GREEN" << endl;
    }
    else if( color == 3){
        cout << "YELLOW" << endl;
    }
    else if( color == 4){
        cout << "PURPLE" << endl;
    }
}
 */