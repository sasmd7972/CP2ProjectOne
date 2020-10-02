//
// Created by steve on 10/2/2020.
//

#include "Vehicle.h"

Vehicle::Vehicle() {
    color = RED;
    Seat = FrontSeat;
}

Vehicle::Vehicle(Color color, Seat seat) {
    this->color = color;
    this->Seat =seat;
}

void Vehicle::changeColor(Color color){
    this->color = color;
}
void Vehicle::printVehicle(){
    for ( int i = 0; i <; i++ )
}