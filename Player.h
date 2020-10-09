//
// Created by Steve Salazar on 10/2/2020.
//
#ifndef PROJECT_ONE_PLAYER_H
#define PROJECT_ONE_PLAYER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Vehicle.h"

using namespace std;

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
#endif //PROJECT_ONE_PLAYER_H