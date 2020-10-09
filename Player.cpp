//
// Created by steve on 10/2/2020.
//

#include "Player.h"

// This is the default is not variables are placed in the constuctor
Player::Player(){
    ID = NULL;
    name = ' ';
    //Set to be 20 as that is what the project requested
    seatAssignment = DriverSeat;
}

// This constructor is used for main to be able to create a player with wanted data
Player::Player(string name, Seat SeatAssignment){
    this->name = name;
    this->seatAssignment = seatAssignment;
}

//Get Functions
int * Player::getIDmemory() {
    return IDmemory;
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

void Player::assignID(Player player) {
    // Get the ID random for reservation
    // if ID exist make new one until its not
    int temp;
    while ( contains(temp) ){
        srand(time(0));
        temp = (rand() % 100) + 1;
        if (!contains(temp)) {
            player.ID = temp;
        } else {
            temp = (rand() % 100) + 1;
        }
    }
}

//Reservation Functions

// This creates the reservation
void Player::createReservation(Player player, Seat seatAssignment){
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
    // This get the player with a unique ID
    assignID(player);

    //This sets the player to a seatAssignment
    player.seatAssignment = seatAssignment;
}

// Get player gets new seat assignment and recounts the seat credit
// ID doesn't change since there is no need
void Player::modifyReservation(Player player, Seat seatAssignment){
    // Gives the player back the seat credit from old seat assignment
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

    //Assigns the new seat assignment
    player.seatAssignment = seatAssignment;

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
    player.ID = NULL;

    //Deletes the ID from IDmemory
    for(int & i : IDmemory) {
        if ( i == player.ID ){
            i = 0;
        }
    }
}