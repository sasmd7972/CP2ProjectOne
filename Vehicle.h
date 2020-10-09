//
// Created by steve on 10/2/2020.
//

#ifndef PROJECT_ONE_VEHICLE_H
#define PROJECT_ONE_VEHICLE_H

#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "Player.h"

using namespace std;

enum Seat {DriverSeat , FrontSeat5, BackSeatL3, BackSeatR3, BackSeatL2, BackSeatR2, BackSeatM1};
enum Color {RED,BLUE,GREEN,YELLOW, PURPLE};

class Vehicle {
  private:
    Color color;
    int seatAmount;
    Seat seat;
    vector< Seat > mySeats;
    vector< bool > filled;

  public:
    // Makes a vehicle with color red and one seat for driver seat
    Vehicle();

    //Set Functions
    void setColor(Color color);
    void setMySeats(Seat seat);
    void setMyFill(int seatAmount);
    void setSeat(Player player,Seat seat);

    //Get Functions
    vector< Seat > GetMySeats();

    //Utility Functions
    void isFull(Seat seat);
    void printVehicle();
};
#endif //PROJECT_ONE_VEHICLE_H