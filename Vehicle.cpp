//
// Created by steve on 10/2/2020.
//

#include "Vehicle_AND_Player.h"

//Set Functions
void Vehicle::setColor(Color color){
    this->color = color;
}

// This is very specific that you enter seat in order
void Vehicle::setupMySeats(Seat seat, bool seatBool){
    mySeats.push_back(seat);
    filled.push_back(seatBool);
}

void Vehicle::setSeat(Player player, Seat seat) {
    for (int i = 0; i < mySeats.size(); i++ ){
        if ( mySeats[i] == seat){
            player.setSeatAssignment(player, seat);
            filled[i] = true;
        }
    }
}


//Get Functions
vector< Seat > Vehicle::GetMySeats() {
    return mySeats;
}

vector< bool > Vehicle::GetFilled() {
    return filled;
}
int Vehicle::GetSeatAmount(){
    return seatAmount;
}

// Utility Functions

//Tell you is the seat is empty or not
bool Vehicle::isFull(Seat seat){
    for (int i = 0; i < mySeats.size(); i++ ){
        if ( mySeats[i] == seat && filled[i] == true){
            return true;
        }
    }
    return false;
}

void Vehicle::printVehicle(){
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
        }else if(mySeats[i] == FrontSeat5 && filled[i] == true){
            cout << "(x)" << endl;
        }
        else {
            if (filled[i] == false) {
                if (mySeats[i] == FrontSeat5) {
                    cout << "(5)" << endl;
                } else if (mySeats[i] == BackSeatL3) {
                    cout << "(3)";
                } else if(mySeats[i] == BackSeatR3){
                    cout << "(3)" << endl;
                } else if (mySeats[i] == BackSeatL2) {
                    cout << "(2)";
                } else if ( mySeats[i] == BackSeatR2) {
                    cout << "(2)" << endl;
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