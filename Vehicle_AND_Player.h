//
// Created by Amauri on 10/9/2020.
//

#ifndef MAIN_CPP_VEHICLE_AND_PLAYER_H
#define MAIN_CPP_VEHICLE_AND_PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Seat {DriverSeat , FrontSeat5, BackSeatL3, BackSeatR3, BackSeatL2, BackSeatR2, BackSeatM1};
enum Color {RED,BLUE,GREEN,YELLOW, PURPLE};

class Player {
private:
    int ID;
    //This is an array of the ID numbers of the reservations
    static const int memorySize = 100;
    int IDmemory[memorySize];
    string name;

    // Set to be 20
    int seatCredit = 20;
    Seat seatAssignment;

public:
    //Constructors
    Player();
    Player(string name, Seat SeatAssignment);

    //Get Functions
    int * getIDmemory();
    Seat getSeatAssignment();

    //Set Functions
    void setSeatAssignment(Player player, Seat seatAssignment);

    //Utility Functions
    bool contains(int temp);
    void assignID(Player player);

    //Reservation Functions
    void createReservation(Player player, Seat seatAssignment);
    void modifyReservation(Player player, Seat seatAssignment);
    void deleteReservation(Player player, Seat seatAssignment);
};

class Vehicle {
private:
    Color color;
    int seatAmount;
    vector< Seat > mySeats;
    vector< bool > filled;
    Seat seat;

public:
    // Has to be public due to the Player accessing this

    // Makes a vehicle with color red and one seat for driver seat
    Vehicle();

    //Set Functions
    void setColor(Color color);
    void setupMySeats(Seat seat);
    void setMyFill(int seatAmount);
    void setSeat(Player,Seat);

    //Get Functions
    vector< Seat > GetMySeats();
    vector< bool > GetFilled();

    //Utility Functions
    bool isFull(Seat seat);
    vector< bool > printVehicle();
};
#endif //MAIN_CPP_VEHICLE_AND_PLAYER_H