//
// Created by steve on 10/2/2020.
//

#include "Vehicle_AND_Player.h"

// This is the default is not variables are placed in the constructor
Player::Player(){
    ID = 99;
    name = ' ';
    seatAssignment = DriverSeat;
}

// This constructor is used for main to be able to create a player with wanted data
Player::Player(string name, Seat SeatAssignment){
    this->name = name;
    this->seatAssignment = seatAssignment;
}

//Get Functions
int Player::getID() {
    return ID;
}
Seat Player::getSeatAssignment() {
    return seatAssignment;
}

//Set Functions
void Player::setSeatAssignment(Player player, Seat seatAssignment) {
    player.seatAssignment = seatAssignment;
}

//Utility Functions
bool Player::contains(int temp) {
    bool notIn = true;

    for(int i : IDmemory){
        if (i != temp) {
            notIn = true;
        }
        else
            notIn = false;
        }
    return notIn;
}

void Player::setID(Player player, int ID) {
    player.ID = ID;
}

//Reservation Functions

// This creates the reservation
void Player::createReservation(Player player, Seat seatAssignment, int ID){
    // These take of care of the values system of the seatAssignments
    if (seatAssignment == FrontSeat5){
        player.seatCredit = player.seatCredit - 5;
    }
    else if( seatAssignment== BackSeatL3 ||  seatAssignment== BackSeatR3 ){
        player.seatCredit = player.seatCredit - 3;
    }
    else if( seatAssignment== BackSeatL2 ||  seatAssignment== BackSeatR2 ){
        player.seatCredit = player.seatCredit - 2;
    }
    else{
        player.seatCredit = player.seatCredit - 1;
    }
    //Give player set ID
    setID(player,ID);
}

// Get player gets new seat assignment and recounts the seat credit
// ID doesn't change since there is no need
void Player::modifyReservation(Player player, Seat seatAssignment, int ID){
    // Gives the player back the seat credit from old seat assignment
    if ( player.getSeatAssignment() == FrontSeat5){
        player.seatCredit = player.seatCredit + 5;
    }
    else if( player.getSeatAssignment()== BackSeatL3 ||  seatAssignment== BackSeatR3 ){
        player.seatCredit = player.seatCredit + 3;
    }
    else if( player.getSeatAssignment()== BackSeatL2 ||  seatAssignment== BackSeatR2 ){
        player.seatCredit = player.seatCredit + 2;
    }
    else{
        player.seatCredit = player.seatCredit + 1;
    }

    //Assigns the new seat assignment
    player.seatAssignment = seatAssignment;
    setID(player,ID);

    //Counts for the new seat assignment cost
    if (seatAssignment == FrontSeat5){
        player.seatCredit = player.seatCredit - 5;
    }
    else if( seatAssignment== BackSeatL3 ||  seatAssignment== BackSeatR3 ){
        player.seatCredit = player.seatCredit - 3;
    }
    else if( seatAssignment== BackSeatL2 ||  seatAssignment== BackSeatR2 ){
        player.seatCredit = player.seatCredit - 2;
    }
    else{
        player.seatCredit = player.seatCredit - 1;
    }
}

void Player::deleteReservation(Player player, Seat seatAssignment){
    // credits the player back for canceled reservation
    if ( player.seatAssignment == FrontSeat5){
        player.seatCredit = player.seatCredit + 5;
    }
    else if( player.seatAssignment== BackSeatL3 ||  seatAssignment== BackSeatR3 ){
        player.seatCredit = player.seatCredit + 3;
    }
    else if( player.seatAssignment== BackSeatL2 ||  seatAssignment== BackSeatR2 ){
        player.seatCredit = player.seatCredit + 2;
    }
    else{
        player.seatCredit = player.seatCredit + 1;
    }

    //Go to default settings
    player.seatAssignment = DriverSeat;
    player.ID = 99;

    //Deletes the ID from IDmemory
    for(int & i : IDmemory) {
        if ( i == player.ID ){
            i = 0;
        }
    }
}
