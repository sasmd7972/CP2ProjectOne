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

void Vehicle::setMySeats(Seat seat){
    filled.push_back(true);
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

//Place holder for sub classes to modify
void Vehicle::setSeat(Player player, Seat seat) {
    filled.push_back(true);
    player.setSeatAssignment(seat);
}


//Get Functions
vector< Seat > Vehicle::GetMySeats() {
    return mySeats;
}

// Utility Functions
void isFull(Seat seat){
    for (int i = 0; i < seatAmount; i++ ){

    }
}

void Vehicle::printVehicle(){
    for ( int i = 0; i < vehicleInside.size; i++ ){

    }
    return mySeats;
}