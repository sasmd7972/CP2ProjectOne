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
Player::Player(string name, Seat seatAssignment){
    this->name = name;
    this->seatAssignment = seatAssignment;
}

//Get Functions
int Player::getID() {
    return this->ID;
}
string Player::getName(){
    return this->name;
}
Seat Player::getSeatAssignment() {
    return this->seatAssignment;
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
void Player::createReservation(Seat seatAssignment, int ID){
    this->ID = ID;
    // These take of care of the values system of the seatAssignments
    if (seatAssignment == FrontSeat5){
        this->seatCredit = this->seatCredit - 5;
    }
    else if( seatAssignment== BackSeatL3 ||  seatAssignment== BackSeatR3 ){
        this->seatCredit = this->seatCredit - 3;
    }
    else if( seatAssignment== BackSeatL2 ||  seatAssignment== BackSeatR2 ){
        this->seatCredit = this->seatCredit - 2;
    }
    else{
        this->seatCredit = this->seatCredit - 1;
    }
    //Give player set ID

}

// Get player gets new seat assignment and recounts the seat credit
// ID doesn't change since there is no need
void Player::modifyReservation(Seat seatAssignment, int ID){
    // Gives the player back the seat credit from old seat assignment
    if ( this->getSeatAssignment() == FrontSeat5){
        this->seatCredit = (this->seatCredit + 5);
    }
    else if( this->getSeatAssignment()== BackSeatL3 ||  seatAssignment== BackSeatR3 ){
        this->seatCredit = (this->seatCredit + 3);
    }
    else if( this->getSeatAssignment()== BackSeatL2 ||  seatAssignment== BackSeatR2 ){
        this->seatCredit = (this->seatCredit + 2);
    }
    else{
        this->seatCredit = (this->seatCredit + 1);
    }

    //Assigns the new seat assignment
    this->seatAssignment = seatAssignment;
    this->ID = ID;

    //Counts for the new seat assignment cost
    if (seatAssignment == FrontSeat5){
        this->seatCredit = (this->seatCredit - 5);
    }
    else if( seatAssignment== BackSeatL3 ||  seatAssignment== BackSeatR3 ){
        this->seatCredit = (this->seatCredit - 3);
    }
    else if( seatAssignment== BackSeatL2 ||  seatAssignment== BackSeatR2 ){
        this->seatCredit = (this->seatCredit - 2);
    }
    else{
        this->seatCredit = (this->seatCredit - 1);
    }
}

void Player::deleteReservation(Seat seatAssignment){
    // credits the player back for canceled reservation
    if ( this->seatAssignment == FrontSeat5){
        this->seatCredit = (this->seatCredit + 5);
    }
    else if( this->seatAssignment== BackSeatL3 ||  seatAssignment== BackSeatR3 ){
        this->seatCredit = (this->seatCredit + 3);
    }
    else if( this->seatAssignment== BackSeatL2 ||  seatAssignment== BackSeatR2 ){
        this->seatCredit = (this->seatCredit + 2);
    }
    else{
        this->seatCredit = (this->seatCredit + 1);
    }

    //Go to default settings
    this->seatAssignment = DriverSeat;
    this->ID = 99;

    //Deletes the ID from IDmemory
    for(int & i : IDmemory) {
        if ( i == this->ID ){
            i = 0;
        }
    }
}

int Player::getCredits() {
        return this-> seatCredit;
}