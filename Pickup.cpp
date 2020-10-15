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

/*
void Pickup::PrintPickUp(){
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

    for (int i  = 0; i  < filled.size(); ++i ) {
        if (mySeats[i] == DriverSeat) {
            cout << "(-)";
        } else {
            if (filled[i] == true) {
                if (mySeats[i] == FrontSeat5) {
                    cout << "(5)" << endl;
                } else if (mySeats[i] == BackSeatL3 || mySeats[i] == BackSeatR3) {
                    cout << "(3)";
                } else if (mySeats[i] == BackSeatL2 || mySeats[i] == BackSeatR2) {
                    cout << "(2)";
                } else if (mySeats[i] == BackSeatM1) {
                    cout << "(1)";
                } else {
                    cout << "Seat Type not found";
                }
            } else {
                cout << "(x)";
            }
        }
    }
    cout << endl;
}
*/