//
// Created by steve on 10/2/2020.
//

#ifndef PROJECT_ONE_VEHICLE_H
#define PROJECT_ONE_VEHICLE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

enum Seat {DriverSeat , FrontSeat, BackSeatL3, BackSeatR3, BackSeatL2, BackSeatR2, BackSeatM1}dir;
enum Color {RED,BLUE,GREEN,YELLOW, PURPLE};

class Vehicle {
    private:
        Color color;
        //Seat mySeats[];
        Seat Seat;

    public:
        Vehicle();
        Vehicle(Color color, Seat seat);
        void changeColor(Color color);
        void printVehicle();
};
#endif //PROJECT_ONE_VEHICLE_H
