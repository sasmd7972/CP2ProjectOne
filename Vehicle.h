//
// Created by steve on 10/2/2020.
//

#ifndef PROJECT_ONE_VEHICLE_H
#define PROJECT_ONE_VEHICLE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

enum Seat {DriverSeat , FrontSeat5, BackSeatL3, BackSeatR3, BackSeatL2, BackSeatR2, BackSeatM1}dir;
enum Color {RED,BLUE,GREEN,YELLOW, PURPLE};

class Vehicle {
  private:
    Color color;
    int seatAmount;
    string mySeats[];
    Seat seat;

  public:
    Vehicle();
    Vehicle(Color color, Seat seat, int seatAmount, string mySeats[]);

    //Set Functions
    void setSeatAmount(int seatAmount);
    void setColor(Color color);

    //Get Functions
    string GetMySeats();

    //Utility Functions
    void printVehicle();
};
#endif //PROJECT_ONE_VEHICLE_H
