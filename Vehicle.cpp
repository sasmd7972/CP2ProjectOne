//
// Created by steve on 10/2/2020.
//

#include "Vehicle.h"

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
            player.setSeatAssignment(seat);
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

vector< bool > Vehicle::printVehicle(){


    return filled;
}