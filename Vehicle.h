//
// Created by steve on 10/2/2020.
//

#ifndef PROJECT_ONE_VEHICLE_H
#define PROJECT_ONE_VEHICLE_H

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"

using namespace std;

enum Seat {DriverSeat , FrontSeat5, BackSeatL3, BackSeatR3, BackSeatL2, BackSeatR2, BackSeatM1};
enum Color {RED,BLUE,GREEN,YELLOW, PURPLE};

class Vehicle {
  private:
    Color color;
    int seatAmount;
    vector< Seat > mySeats;
    vector< bool > filled;

  public:
    // Has to be public due to the Player accessing this
    Seat seat;

    // Makes a vehicle with color red and one seat for driver seat
    Vehicle();

    //Set Functions
    void setColor(Color color);
    void setupMySeats(Seat seat);
    void setMyFill(int seatAmount);
    void setSeat(Player player,Seat seat);

    //Get Functions
    vector< Seat > GetMySeats();
    vector< bool > GetFilled();

    //Utility Functions
    bool isFull(Seat seat);
    vector< bool > printVehicle();
};
#endif //PROJECT_ONE_VEHICLE_H