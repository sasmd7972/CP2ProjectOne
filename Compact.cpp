//
// Created by steve on 10/9/2020.
//

#include "Compact.h"

Compact::Compact(){
    setColor(RED);
    setupMySeats(DriverSeat, true);
    setupMySeats(FrontSeat5, false);
    setupMySeats(BackSeatL2, false);
    setupMySeats(BackSeatM1, false);
    setupMySeats(BackSeatR2, false);
}

Compact::Compact(Color color) {
    setColor(color);
    setupMySeats(DriverSeat, true);
    setupMySeats(FrontSeat5, false);
    setupMySeats(BackSeatL2, false);
    setupMySeats(BackSeatM1, false);
    setupMySeats(BackSeatR2, false);
}

/*void Compact::PrintCompact(){
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
}*/