//
// Created by steve on 10/2/2020.
//

#include "Vehicle_AND_Player.h"

Vehicle::Vehicle(){
    color = RED;
    seatAmount = 1;
    mySeats.push_back(DriverSeat);
    filled.push_back(true);
}

//Set Functions
void Vehicle::setColor(Color color){
    this->color = color;
}

// This is very specific that you enter seat in order
void Vehicle::setupMySeats(Seat seat){
    mySeats.push_back(seat);
}

void Vehicle::setMyFill( int seatAmount){
    for ( int i = 0; i < seatAmount; i++){
        if ( i == 0){
            filled.push_back(true);
        } else {
            filled.push_back(false);
        }
    }
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

    enum Color {RED,BLUE,GREEN,YELLOW,PURPLE};

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
}