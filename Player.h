//
// Created by steve on 10/2/2020.
//

#ifndef PROJECT_ONE_PLAYER_H
#define PROJECT_ONE_PLAYER_H

#include <iostream>
#include <string>

#include "Vehicle.h"

using namespace std;

class Player {
    private:
        int ID;
        string name;
        int seatCredit = 20;
        Seat seatAssignment;

    public:
        Player(int ID,string name, int seatAssignmentValue,Seat SeatAssignment);
        void createReservation(string name, int seatCredit, int seatAssignmentValue);
        void modifyReservation(int ID, int seatCredit, int seatAssignmentValue);
        void deleteReservation(string name, int seatCredit, int seatAssignmentValue);
};


#endif //PROJECT_ONE_PLAYER_H
