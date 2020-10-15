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