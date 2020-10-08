//
// Created by steve on 10/2/2020.
//

#include "Vehicle.h"

Vehicle::Vehicle() {
    color = RED;
    seat = FrontSeat5;
}

Vehicle::Vehicle(Color color, Seat seat, int seatAmount, string mySeats[]){
    this->color = color;
    this->seat = seat;
    this->seatAmount = seatAmount;
    this->mySeats = mySeats[seatAmount];
}

//Set Functions
void Vehicle::setSeatAmount(int seatAmount) {
    mySeats = mySeats[seatAmount];
}
void Vehicle::setColor(Color color){
    this->color = color;
}

//Get Functions
string Vehicle::GetMySeats() {
    return mySeats;
}

void Vehicle::printVehicle(){
    for ( int i = 0; i < mySeats.size; i++ ){

    }
}