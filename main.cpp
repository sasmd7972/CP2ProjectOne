#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

#include "Vehicle_AND_Player.h"
#include "Pickup.h"
#include "Sedan.h"
#include "Compact.h"



using namespace std;

int main() {
    //-----------------------------------------------------------
    //VARIABLES
    //-----------------------------------------------------------

//----------Variables needed for taking in names and rewriting quidditch.dat
//-----------------------------------------------------------
    ifstream inFs;
    ofstream outFs;
    string holdNames = "BLANK";
//----------Vectors that store the reservation information
//-----------------------------------------------------------
    vector<string> drivers(6);
    vector<string> teamMembers(18);
    vector<Player> playerList(18);
    vector<int> playerCredits(18);
    vector<int> reservationIDs(18);
    fill(reservationIDs.begin(), reservationIDs.end(), 99);
//----------Menu & Category Variables
//-----------------------------------------------------------
    bool stillInMenu = true; //When false, exits out of the main menu
    bool stillInCat = true; //When false, exits out of the category selection menu in the Reservation Option
    string userMenuIn = "BLANK";
    char menuChoice = '-';

    bool returnToMenu = false;//Boolean to return to base menu from within other menus.

    string userIDHold = "BLANK";
    int userIDIn = 99;



//----------Player Variables and Vectors
//-----------------------------------------------------------
    string userName = "BLANK";
    bool validName = false;
    bool validID = false;
    int playerId = 99;
    size_t found;
    string holdCredits;


    Player playerHold;//Stores a single player from the vector Needed to use Players() functions
    char selMethod;//How they user wants to select their seat

    string requestedVehicle = "BLANK";
    string requestedSeat = "BLANK";

//----------OTHERS & MISC
//-----------------------------------------------------------




//----------Admin Variables
//-----------------------------------------------------------
    const string adminPass = "AdminPassword";//Only used by admin to view reservations. Temporary
    string adminIn = "BLANK";//test



//-----------------------------------------------------------
//PROGRAM BEGINS HERE
//-----------------------------------------------------------


    //----------OPENS THE FILE AND READS THE NAMES OF THE MEMBERS
    //-----------------------------------------------------------
    inFs.open("quidditch_team.dat", std::ifstream::in);
    if (!inFs.is_open())//Checks if the input file can be opened
        cout << "Unable to open file for input";
    else {
        for (int i = 0; i < 6; i++) {
            getline(inFs, drivers.at(i));
        }
        for (int i = 0; i < 18; i++) {
            getline(inFs, teamMembers.at(i));
        }
        inFs.close();//Closes the input file
    }
    //----------SEPARATES THE MEMBERS FROM THEIR CREDITS
    //-----------------------------------------------------------
    for (int i = 0; i < 18; i++) {
        holdNames = teamMembers.at(i);
        //Finds the location  last character in string that isn't a digit
        found = holdNames.find_last_not_of("0123456789");
        //sets the string hold credits to the substring of numbers in the name
        holdCredits = holdNames.substr(found + 1);
        //Converts the hold credits string to an integer
        playerCredits.at(i) = stoi(holdCredits);
        //removes all characters from the whitespace before the number until the end of the string
        if (found != std::string::npos) {
            holdNames.erase(found);
        }
        //Converts all the letters in the names to lowercase

        for (int k = 0; k < holdNames.length() - 1; k++) {
            holdNames.at(k) = tolower(holdNames.at(k));
        }
        //Sets the team member name at i to the new value of hold names
        teamMembers.at(i) = holdNames;
    }

    //----------Creates the Vehicle Objects
    //-----------------------------------------------------------

        vector<Vehicle> VehicleList(6);

        Pickup purplePickup;
        purplePickup = Pickup(PURPLE);


        Compact redCompact;
        redCompact = Compact(RED);
        Compact blueCompact;
        blueCompact = Compact(BLUE);
        Compact yellowCompact;
        yellowCompact = Compact(YELLOW);


        Sedan blueSedan;
        blueSedan = Sedan(BLUE);
        Sedan greenSedan;
        greenSedan = Sedan(GREEN);

        VehicleList[0] = purplePickup;
        VehicleList[1] = redCompact;
        VehicleList[2] = blueCompact;
        VehicleList[3] = yellowCompact;
        VehicleList[4] = blueSedan;
        VehicleList[5] = greenSedan;



    cout << "Welcome to the RIT Quidditch Team Reservation System" << endl;//Out of do loop so they don't have to see message multiple times.
//---------------------------------------------------------
//MENU OPTIONS AND DISPLAY BEGINS HERE
//---------------------------------------------------------
    do {
        //----------Resets Variables to default values
        //-----------------------------------------------------------
        //TODO: Finish reset variables to default values
        holdNames = "BLANK";
        stillInCat = true;
        stillInMenu = true;
        menuChoice = '-';
        returnToMenu = false;
        userIDHold = "BLANK";
        userIDIn = 99;
        selMethod = '-';
        userName = "BLANK";
        validName = false;
        playerId = -1;
        requestedVehicle = "BLANK";
        requestedSeat = "BLANK";
        adminIn = "BLANK";


        //----------Displays the menu
        //-----------------------------------------------------------
        cout << setfill('-') << setw(60)<<"-"<<endl;
        cout << "Enter C to create a reservation" << endl;
        cout << "Enter M to modify your reservation" << endl;
        cout << "Enter D to delete your reservation" << endl;
        cout << "Enter V to display the seating diagram" << endl;
        cout << "Enter S to print the passenger list for a single vehicle" << endl;
        cout << "Enter R to print the passenger list for a every vehicle" << endl;
        cout << "Enter E to exit the program" << endl;
        cout << setfill('-') << setw(60)<<"-"<<endl;
        cin >> userMenuIn;


        //----------Checks if their menu choice is an option
        //-----------------------------------------------------------
        if(userMenuIn.length() != 1){
            cout << "Error. Invalid input!"<< endl;
            cout << "Must be single letter:" << endl;
            cout << "Try again!" << endl;
            continue;
        }
        menuChoice = userMenuIn.at(0);
        if(!isalpha(menuChoice)){
            cout << "Error. Invalid input!"<< endl;
            cout << "Must be a letter, not a number:" << endl;
            cout << "Try again!" << endl;
            continue;
        }
        menuChoice = tolower(menuChoice);

        switch (menuChoice) {//Determines which of the menu options was chosen, if any


            //----------Creates Reservation
            //-----------------------------------------------------------
            case 'c':
            cout << "Enter your name to begin: [first last]" << endl;
            cin.ignore();
            getline(cin, userName);

            for(int i = 0; i < userName.length() -1 ; i++){
                userName.at(i) = tolower(userName.at(i));
            }


            for (int i = 0; i < 18; i++) {//checks if their name is in the quidditch.dat file and is not a driver
                if (userName == teamMembers.at(i)) {
                    validName = true;
                    playerId = i;//Player ID is their location in the .dat file // same as ResID
                    break;
                }//end if
            }//end loop

            if(!validName){
                cout << userName << " is not one of the members of the quidditch team that needs a ride." << endl;
                cout << "Returning to menu" << endl;
                continue;
            }//end if

            playerHold = playerList.at(playerId);

                if (playerHold.getID() != 0) {
                    cout << setfill('-') << setw(60) << "-" << endl;
                    cout << "Welcome " << userName << endl;
                    cout << "You have " << playerCredits.at(playerId) << " Credits remaining" << endl;
                    cout << setfill('-') << setw(60) << "-" << endl;



                    //----------Seat Selection
                    //-----------------------------------------------------------

                    cout << "How do you want to select your seat?" << endl;
                    do {

                        cout << setfill('-') << setw(60) << "-" << endl;

                        cout << "Enter [C] to search by category" << endl;
                        cout << "Enter [S] to search by specifics" << endl;
                        cout << setfill('-') << setw(60) << "-" << endl;
                        userMenuIn = '-';//Sets userMenuIn back to a - for its re-use

                        cin >> userMenuIn; //Re-using userMenuIn because it is efficient
                        if (userMenuIn.length() != 1) {//Checks if input is a single character
                            cout << "Error. Invalid input!" << endl;
                            cout << "Must be single letter:" << endl;
                            cout << "Try again!" << endl;
                            continue;
                        }
                        menuChoice = userMenuIn.at(0);
                        if (!isalpha(menuChoice)) {//Checks if input is a letter
                            cout << "Error. Invalid input!" << endl;
                            cout << "Must be a letter, not a number:" << endl;
                            cout << "Try again!" << endl;
                            continue;
                        }
                        menuChoice = tolower(menuChoice);

                        switch (menuChoice) {
                            case 'c':
                                cout << "Enter your requested seat type:" << endl;
                                cout << setw(2) << "[Front] for a front seat" << endl;
                                cout << setw(2) << "[Side] for a left or right back seat in a car without a middle seat"
                                     << endl;
                                cout << setw(2) << "[Edge] for a left or right back seat in a car with a middle seat"
                                     << endl;
                                cout << setw(2) << "[Middle] for a middle back seat in a Sedan" << endl;
                                cin.ignore();
                                getline(cin, requestedSeat);

                                for (int i = 0; i < requestedSeat.length(); i++) {
                                    if (isalpha(requestedSeat.at(i))) {
                                        requestedSeat.at(i) = tolower(requestedSeat.at(i));
                                    } else {
                                        cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                        stillInCat = false;
                                        break;
                                    }
                                }//End For Loop

                                if (requestedSeat == "front") {
                                    if ((playerCredits.at(playerId) < 5) && (playerCredits.at(playerId) != -1)) {
                                        cout << "Error! Too few credits to select seat! Returning to Menu";
                                        stillInCat = false;
                                    } else {


                                        //Checks each seat to see if it is full. If not, it assigns the seat. If so, it goes to the next one
                                        if (!(purplePickup.isFull(FrontSeat5))) {
                                            playerHold.createReservation(playerHold, FrontSeat5, 1);
                                            purplePickup.setSeat(playerHold, FrontSeat5);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!(redCompact.isFull(FrontSeat5))) {
                                            playerHold.createReservation(playerHold, FrontSeat5, 2);
                                            redCompact.setSeat(playerHold, FrontSeat5);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!(blueCompact.isFull(FrontSeat5))) {
                                            playerHold.createReservation(playerHold, FrontSeat5, 5);
                                            blueCompact.setSeat(playerHold, FrontSeat5);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!(yellowCompact.isFull(FrontSeat5))) {
                                            playerHold.createReservation(playerHold, FrontSeat5, 8);
                                            yellowCompact.setSeat(playerHold, FrontSeat5);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!(blueSedan.isFull(FrontSeat5))) {
                                            playerHold.createReservation(playerHold, FrontSeat5, 11);
                                            blueSedan.setSeat(playerHold, FrontSeat5);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!(greenSedan.isFull(FrontSeat5))) {
                                            playerHold.createReservation(playerHold, FrontSeat5, 15);
                                            greenSedan.setSeat(playerHold, FrontSeat5);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else {
                                            cout << "No front seats available. Select another type of seat." << endl;
                                        }


                                    }
                                } else if (requestedSeat == "side") {
                                    if ((playerCredits.at(playerId) < 3) && (playerCredits.at(playerId) != -1)) {
                                        cout << "Error! Too few credits to select seat! Returning to Menu";
                                        stillInCat = false;
                                    } else {

                                        //Finds which seats are filled. If they are not, fills them
                                        if ((!(redCompact.isFull(BackSeatL3)))) {
                                            playerHold.createReservation(playerHold, BackSeatL3, 3);
                                            redCompact.setSeat(playerHold, BackSeatL3);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!(blueCompact.isFull(BackSeatL3))) {
                                            playerHold.createReservation(playerHold, BackSeatL3, 6);
                                            blueCompact.setSeat(playerHold, BackSeatL3);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!(yellowCompact.isFull(BackSeatL3))) {
                                            playerHold.createReservation(playerHold, BackSeatL3, 9);
                                            yellowCompact.setSeat(playerHold, BackSeatL3);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        }
                                        if ((!(redCompact.isFull(BackSeatR3)))) {
                                            playerHold.createReservation(playerHold, BackSeatR3, 4);
                                            redCompact.setSeat(playerHold, BackSeatR3);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!(blueCompact.isFull(BackSeatR3))) {
                                            playerHold.createReservation(playerHold, BackSeatR3, 7);
                                            blueCompact.setSeat(playerHold, BackSeatR3);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!(yellowCompact.isFull(BackSeatR3))) {
                                            playerHold.createReservation(playerHold, BackSeatR3, 10);
                                            yellowCompact.setSeat(playerHold, BackSeatR3);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else {
                                            cout << "No side seats available. Select another type of seat." << endl;
                                        }


                                    }
                                } else if (requestedSeat == "edge") {
                                    if ((playerCredits.at(playerId) < 2) && (playerCredits.at(playerId) != -1)) {
                                        cout << "Error! Too few credits to select seat! Returning to Menu";
                                        stillInCat = false;
                                    } else {


                                        if ((!(blueSedan.isFull(BackSeatL2)))) {
                                            playerHold.createReservation(playerHold, BackSeatL2, 12);
                                            blueSedan.setSeat(playerHold, BackSeatL2);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!(greenSedan.isFull(BackSeatL2))) {
                                            playerHold.createReservation(playerHold, BackSeatL2, 16);
                                            greenSedan.setSeat(playerHold, BackSeatL2);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!(blueSedan.isFull(BackSeatR2))) {
                                            playerHold.createReservation(playerHold, BackSeatR2, 14);
                                            blueSedan.setSeat(playerHold, BackSeatR2);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        }
                                        if ((!(greenSedan.isFull(BackSeatR2)))) {
                                            playerHold.createReservation(playerHold, BackSeatR2, 18);
                                            greenSedan.setSeat(playerHold, BackSeatR2);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else {
                                            cout << "No edge seats available. Select another type of seat." << endl;
                                        }


                                    }
                                } else if (requestedSeat == "middle") {
                                    if ((playerCredits.at(playerId) < 1) && (playerCredits.at(playerId) != -1)) {
                                        cout << "Error! Too few credits to select seat! Returning to Menu";
                                        stillInCat = false;
                                    } else {


                                        if ((!(blueSedan.isFull(BackSeatM1)))) {
                                            playerHold.createReservation(playerHold, BackSeatM1, 13);
                                            blueSedan.setSeat(playerHold, BackSeatM1);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!(greenSedan.isFull(BackSeatL3))) {
                                            playerHold.createReservation(playerHold, BackSeatM1, 17);
                                            greenSedan.setSeat(playerHold, BackSeatM1);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else {
                                            cout << "No back seats available. Select another type of seat." << endl;
                                        }


                                    }
                                } else {
                                    cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                    stillInCat = false;
                                }


                                break;
                                //-----------------------------------------------------------
                            case 's':
                                cout << "Enter your requested vehicle: (Spaces must be included)" << endl;
                                cout << setw(2) << "[Purple Pickup]" << endl;
                                cout << setw(2) << "[Red Compact]" << endl;
                                cout << setw(2) << "[Blue Compact]" << endl;
                                cout << setw(2) << "[Yellow Compact]" << endl;
                                cout << setw(2) << "[Blue Sedan]" << endl;
                                cout << setw(2) << "[Green Sedan]" << endl;
                                cin.ignore();
                                getline(cin, requestedVehicle);

                                for (int i = 0; i <
                                                requestedVehicle.length(); i++) {//Checks if the input is a one of the possible vehicles.
                                    if (isalpha(requestedVehicle.at(i)) || requestedVehicle.at(i) == ' ') {
                                        requestedVehicle.at(i) = tolower(requestedVehicle.at(i));
                                    } else {
                                        cout << "Error! Invalid Vehicle. Returning to Menu" << endl << endl;
                                        stillInCat = false;
                                        break;
                                    }
                                }

                                if (requestedVehicle ==
                                    "purple pickup") {//There is only one seat possible in this vehicle so no seat selection is needed
                                    if (purplePickup.GetFilled().at(1)) {
                                        cout << "That seat is unavailable. Returning to Menu";
                                        stillInCat = false;
                                    } else {
                                        playerHold.createReservation(playerHold, FrontSeat5, 1);
                                        purplePickup.setSeat(playerHold, FrontSeat5);
                                        cout << "Successful reservation. Your Reservation ID is " << playerHold.getID()
                                             << endl;
                                        cout << "Remember it." << endl << endl;
                                    }
                                } else if (requestedVehicle == "red compact") {
                                    cout << "Enter your requested seat type:" << endl;
                                    cout << setw(2) << "[Front] for a front seat" << endl;
                                    cout << setw(2) << "[Side] for a back seat on either the left or right side"
                                         << endl;
                                    cin >> requestedSeat;

                                    for (int i = 0; i <
                                                    requestedSeat.length(); i++) {//Checks if the input is a one of the possible Seats.
                                        if (isalpha(requestedSeat.at(i))) {
                                            requestedSeat.at(i) = tolower(requestedSeat.at(i));
                                        } else {
                                            cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                            stillInCat = false;
                                            break;
                                        }
                                    }

                                    if (requestedSeat == "front") {
                                        if (redCompact.isFull(FrontSeat5)) {
                                            cout << "That seat is unavailable. Returning to Menu" << endl;
                                            stillInCat = false;
                                        } else {
                                            playerHold.createReservation(playerHold, FrontSeat5, 2);
                                            redCompact.setSeat(playerHold, FrontSeat5);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        }
                                    } else if (requestedSeat == "side") {
                                        if (!redCompact.isFull(BackSeatL3)) {
                                            playerHold.createReservation(playerHold, BackSeatL3,3);
                                            redCompact.setSeat(playerHold, BackSeatL3);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!redCompact.isFull((BackSeatR3))) {
                                            playerHold.createReservation(playerHold, BackSeatR3,4);
                                            redCompact.setSeat(playerHold, BackSeatR3);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else {
                                            cout << "All side seats in this vehicle are unavailable. Returning to Menu"
                                                 << endl;
                                            stillInCat = false;
                                        }
                                    } else {
                                        cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                        stillInCat = false;
                                        break;
                                    }


                                } else if (requestedVehicle == "blue compact") {
                                    cout << "Enter your requested seat type:" << endl;
                                    cout << setw(2) << "[Front] for the front seat" << endl;
                                    cout << setw(2) << "[Side] for a back seat on either the left or right side"
                                         << endl;
                                    cin >> requestedSeat;

                                    for (int i = 0; i <
                                                    requestedSeat.length(); i++) {//Checks if the input is a one of the possible Seats.
                                        if (isalpha(requestedSeat.at(i))) {
                                            requestedSeat.at(i) = tolower(requestedSeat.at(i));
                                        } else {
                                            cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                            stillInCat = false;
                                            break;
                                        }
                                    }

                                    if (requestedSeat == "front") {
                                        if (blueCompact.isFull(FrontSeat5)) {
                                            cout << "That seat is unavailable. Returning to Menu" << endl;
                                            stillInCat = false;
                                        } else {
                                            playerHold.createReservation(playerHold, FrontSeat5,5);
                                            blueCompact.setSeat(playerHold, FrontSeat5);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        }
                                    } else if (requestedSeat == "side") {
                                        if (!blueCompact.isFull(BackSeatL3)) {
                                            playerHold.createReservation(playerHold, BackSeatL3,6);
                                            blueCompact.setSeat(playerHold, BackSeatL3);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!blueCompact.isFull((BackSeatR3))) {
                                            playerHold.createReservation(playerHold, BackSeatR3,7);
                                            blueCompact.setSeat(playerHold, BackSeatR3);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else {
                                            cout << "All side seats in this vehicle are unavailable. Returning to Menu"
                                                 << endl;
                                            stillInCat = false;
                                        }
                                    } else {
                                        cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                        stillInCat = false;
                                        break;
                                    }

                                } else if (requestedVehicle == "yellow compact") {
                                    cout << "Enter your requested seat type:" << endl;
                                    cout << setw(2) << "[Front] for the front seat" << endl;
                                    cout << setw(2) << "[Side] for a back seat on either the left or right side"
                                         << endl;
                                    cin >> requestedSeat;

                                    for (int i = 0; i <
                                                    requestedSeat.length(); i++) {//Checks if the input is a one of the possible Seats.
                                        if (isalpha(requestedSeat.at(i))) {
                                            requestedSeat.at(i) = tolower(requestedSeat.at(i));
                                        } else {
                                            cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                            stillInCat = false;
                                            break;
                                        }
                                    }

                                    if (requestedSeat == "front") {
                                        if (yellowCompact.isFull(FrontSeat5)) {
                                            cout << "That seat is unavailable. Returning to Menu" << endl;
                                            stillInCat = false;
                                        } else {
                                            playerHold.createReservation(playerHold, FrontSeat5,8);
                                            yellowCompact.setSeat(playerHold, FrontSeat5);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        }
                                    } else if (requestedSeat == "side") {
                                        if (!yellowCompact.isFull(BackSeatL3)) {
                                            playerHold.createReservation(playerHold, BackSeatL3,9);
                                            yellowCompact.setSeat(playerHold, BackSeatL3);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!yellowCompact.isFull((BackSeatR3))) {
                                            playerHold.createReservation(playerHold, BackSeatR3,10);
                                            yellowCompact.setSeat(playerHold, BackSeatR3);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else {
                                            cout << "All side seats in this vehicle are unavailable. Returning to Menu"
                                                 << endl;
                                            stillInCat = false;
                                        }
                                    } else {
                                        cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                        stillInCat = false;
                                        break;
                                    }

                                } else if (requestedVehicle == "blue sedan") {
                                    cout << "Enter your requested seat type:" << endl;
                                    cout << setw(2) << "[Front] for the front seat" << endl;
                                    cout << setw(2) << "[Edge] for a back seat on either the left or right side"
                                         << endl;
                                    cout << setw(2) << "[Middle] for the back middle seat" << endl;
                                    cin >> requestedSeat;

                                    for (int i = 0; i <
                                                    requestedSeat.length(); i++) {//Checks if the input is a one of the possible Seats.
                                        if (isalpha(requestedSeat.at(i))) {
                                            requestedSeat.at(i) = tolower(requestedSeat.at(i));
                                        } else {
                                            cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                            stillInCat = false;
                                            break;
                                        }
                                    }

                                    if (requestedSeat == "front") {
                                        if (blueSedan.isFull(FrontSeat5)) {
                                            cout << "That seat is unavailable. Returning to Menu" << endl;
                                            stillInCat = false;
                                        } else {
                                            playerHold.createReservation(playerHold, FrontSeat5,11);
                                            blueSedan.setSeat(playerHold, FrontSeat5);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        }
                                    } else if (requestedSeat == "edge") {
                                        if (!blueSedan.isFull(BackSeatL2)) {
                                            playerHold.createReservation(playerHold, BackSeatL2,12);
                                            blueSedan.setSeat(playerHold, BackSeatL2);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!blueSedan.isFull((BackSeatR2))) {
                                            playerHold.createReservation(playerHold, BackSeatR2,14);
                                            blueSedan.setSeat(playerHold, BackSeatR2);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else {
                                            cout << "All side seats in this vehicle are unavailable. Returning to Menu"
                                                 << endl;
                                            stillInCat = false;
                                        }
                                    } else if (requestedSeat == "middle") {
                                        if (!blueSedan.isFull(BackSeatM1)) {
                                            playerHold.createReservation(playerHold, BackSeatM1,13);
                                            blueSedan.setSeat(playerHold, BackSeatM1);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else {
                                            cout << "All side seats in this vehicle are unavailable. Returning to Menu"
                                                 << endl;
                                            stillInCat = false;
                                        }
                                    } else {
                                        cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                        stillInCat = false;
                                        break;
                                    }
                                } else if (requestedVehicle == "green sedan") {
                                    cout << "Enter your requested seat type:" << endl;
                                    cout << setw(2) << "[Front] for the front seat" << endl;
                                    cout << setw(2) << "[Edge] for a back seat on either the left or right side"
                                         << endl;
                                    cout << setw(2) << "[Middle] for the back middle seat" << endl;
                                    cin >> requestedSeat;

                                    for (int i = 0; i <
                                                    requestedSeat.length(); i++) {//Checks if the input is a one of the possible Seats.
                                        if (isalpha(requestedSeat.at(i))) {
                                            requestedSeat.at(i) = tolower(requestedSeat.at(i));
                                        } else {
                                            cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                            stillInCat = false;
                                            break;
                                        }
                                    }

                                    if (requestedSeat == "front") {
                                        if (greenSedan.isFull(FrontSeat5)) {
                                            cout << "That seat is unavailable. Returning to Menu" << endl;
                                            stillInCat = false;
                                        } else {
                                            playerHold.createReservation(playerHold, FrontSeat5,15);
                                            greenSedan.setSeat(playerHold, FrontSeat5);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        }
                                    } else if (requestedSeat == "edge") {
                                        if (!greenSedan.isFull(BackSeatL2)) {
                                            playerHold.createReservation(playerHold, BackSeatL2,16);
                                            greenSedan.setSeat(playerHold, BackSeatL2);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else if (!greenSedan.isFull((BackSeatR2))) {
                                            playerHold.createReservation(playerHold, BackSeatR2,18);
                                            greenSedan.setSeat(playerHold, BackSeatR2);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else {
                                            cout << "All side seats in this vehicle are unavailable. Returning to Menu"
                                                 << endl;
                                            stillInCat = false;
                                        }
                                    } else if (requestedSeat == "middle") {
                                        if (!greenSedan.isFull(BackSeatM1)) {
                                            playerHold.createReservation(playerHold, BackSeatM1,17);
                                            greenSedan.setSeat(playerHold, BackSeatM1);
                                            cout << "Successful reservation. Your Reservation ID is "
                                                 << playerHold.getID()
                                                 << endl;
                                            cout << "Remember it." << endl << endl;
                                            stillInCat = false;
                                        } else {
                                            cout << "All side seats in this vehicle are unavailable. Returning to Menu"
                                                 << endl;
                                            stillInCat = false;
                                        }
                                    } else {
                                        cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                        stillInCat = false;
                                        break;
                                    }
                                } else {
                                    cout << "Error! Invalid Vehicle. Returning to Menu" << endl << endl;
                                    stillInCat = false;
                                }

                                break;
                                //-----------------------------------------------------------
                            default:
                                cout << "Error! Invalid Choice. Returning to Menu";
                                stillInCat = false;
                        }
                    } while (stillInCat);


                    break;
                    //-----------------------------------------------------------

                    //----------Modifies Reservation
                    //-----------------------------------------------------------
                } else {//Checks if there is already a reservation.
                    cout << "There is already a reservation at this name." << endl;
                    cout << "Select modify (M) to edit it, or select delete (D) to delete it." << endl;
                    cout << "Returning to Menu" << endl << endl;
                    cout << setfill('-') << setw(60) << "-" << endl;
                    continue;
                }
            case 'm':
                cout << "Enter your Reservation ID:" << endl;
                cin.ignore();
                getline(cin, userIDHold);
                for (int i = 0; i < userIDHold.length(); i++) {
                    if (!isdigit(userIDHold.at(i))) {
                        cout << "Error! Reservation ID must be a number! Returning to menu.";
                        break;
                    }
                }

                userIDIn = stoi(userIDHold);
                //Checks if the reservation ID is in use
                for(int i = 0; i < 18; i++){
                    if(userIDIn = reservationIDs.at(i)){
                        validID = true;
                    }
                }
                if(!validID){
                    cout << "Error! Reservation ID not in use! Returning to menu.";
                    break;
                }

                break;
                //-----------------------------------------------------------

                //----------Deletes Reservation
                //-----------------------------------------------------------
            case 'd':
                //Takes in the reservation ID
                cout << "Enter your Reservation ID:" << endl;
                cin.ignore();
                getline(cin, userIDHold);
                for (int i = 0; i < userIDHold.length(); i++) {
                    if (!isdigit(userIDHold.at(i))) {
                        cout << "Error! Reservation ID must be a number! Returning to menu.";
                        break;
                    }
                }
                userIDIn = stoi(userIDHold);
                //Checks if the reservation ID is in use
                for(int i = 0; i < 18; i++){
                    if(userIDIn = reservationIDs.at(i)){
                        validID = true;
                    }
                }
                if(!validID){
                    cout << "Error! Reservation ID not in use! Returning to menu.";
                    break;
                }
                playerHold.deleteReservation(playerHold, playerHold.getSeatAssignment());
                cout << "Reservation Deleted Successfully!";
                break;
                //-----------------------------------------------------------
                // Display Vehicles
                // The way it was in the project
                // Display all of the vehicle in the project
                //-----------------------------------------------------------

            case 'v':

                for ( int i = 0; i < VehicleList.size();i++) {
                    if (VehicleList[i].GetMySeats().size() == 2) {
                        cout << "Truck" << endl;
                        cout << "-----" << endl;
                        VehicleList[i].printVehicle();
                        cout << endl;
                    }

                    else if (VehicleList[i].GetMySeats().size() == 1) {
                        cout << "test 1" << endl;
                        cout << "-------" << endl;
                        VehicleList[i].printVehicle();
                        cout << endl;
                    }
                    else if (VehicleList[i].GetMySeats().size() == 3) {
                        cout << "test3" << endl;
                        cout << "-------" << endl;
                        VehicleList[i].printVehicle();
                        cout << endl;
                    }
                    else if (VehicleList[i].GetMySeats().size() == 0) {
                        cout << "test0" << endl;
                        cout << "-------" << endl;
                        VehicleList[i].printVehicle();
                        cout << endl;
                    }





                    else if (VehicleList[i].GetMySeats().size() == 5) {
                        cout << "Compact" << endl;
                        cout << "-------" << endl;
                        VehicleList[i].printVehicle();
                        cout << endl;
                    } else if (VehicleList[i].GetMySeats().size() == 4) {
                        cout << "Sedan" << endl;
                        cout << "-------" << endl;
                        VehicleList[i].printVehicle();
                        cout << endl;
                    }
                }
                break;

                //-----------------------------------------------------------
                // Print Assignments
                // Print one vehicle to a separate file
                // Will show player in vehicle
                //-----------------------------------------------------------
            case 's':
                cout << "Enter your requested vehicle: (Spaces must be included)" << endl;
                cout <<setw(2)<< "[Purple Pickup]" << endl;
                cout <<setw(2)<< "[Red Compact]" << endl;
                cout <<setw(2)<< "[Blue Compact]" << endl;
                cout <<setw(2)<< "[Yellow Compact]" << endl;
                cout <<setw(2)<< "[Blue Sedan]" << endl;
                cout <<setw(2)<< "[Green Sedan]" << endl;
                cin.ignore();
                getline(cin, requestedVehicle);


                for(int i = 0; i < requestedVehicle.length(); i++) {
                    //Checks if the input is a one of the possible vehicles.
                    if (isalpha(requestedVehicle.at(i)) || requestedVehicle.at(i) == ' '){
                        requestedVehicle.at(i) = tolower(requestedVehicle.at(i));
                    }else{
                        cout << "Error! Invalid Vehicle. Returning to Menu" << endl << endl;
                        stillInCat = false;
                        break;
                    }
                }

                // TODO fill with driver location info

                if(requestedVehicle == "purple pickup"){
                    outFs.open("output-files/purple_pickup.txt");
                    if (!outFs.is_open()) {//Checks if the input file can be opened
                        cout << "Unable to open file for output";
                    }else {
                        //outFs << "DRIVER" << endl; FILL WITH DRIVER LOCATION
                        outFs << "Driver Seat: " << drivers[0] << endl;
                        for( int i; i < playerList.size();i++){
                            if ( playerList[i].getID() == 1 ){
                                outFs << "Front Seat: " << playerList[i].getName() << endl;
                            }
                        }
                        outFs.close();//Closes the output file
                    }

                }else if (requestedVehicle == "red compact"){
                    outFs.open("output-files/red_compact.txt");
                    if (!outFs.is_open()) {//Checks if the input file can be opened
                        cout << "Unable to open file for output";
                    }else {
                        //outFs << "DRIVER" << endl; FILL WITH DRIVER LOCATION
                        outFs << "Driver Seat: " << drivers[1] << endl;
                        for( int i; i < playerList.size();i++){
                            if ( playerList[i].getID() == 2 ){
                                outFs << "Front Seat: " << playerList[i].getName()<< endl;
                            }
                            else if ( playerList[i].getID() == 3 ){
                                outFs << "Back Seat Left: " << playerList[i].getName()<< endl;
                            }
                            else if( playerList[i].getID() == 4 ){
                                outFs << "Back Seat Right: " << playerList[i].getName()<< endl;
                            }
                        }
                        outFs.close();//Closes the output file
                    }
                }else if (requestedVehicle == "blue compact"){
                    outFs.open("output-files/blue_compact.txt");
                    if (!outFs.is_open()) {//Checks if the input file can be opened
                        cout << "Unable to open file for output";
                    }else {
                        //outFs << "DRIVER" << endl; FILL WITH DRIVER LOCATION
                        outFs << "Driver Seat: " << drivers[2] << endl;
                        for( int i; i < playerList.size();i++){
                            if ( playerList[i].getID() == 5 ){
                                outFs << "Front Seat: " << playerList[i].getName()<< endl;
                            }
                            else if ( playerList[i].getID() == 6 ){
                                outFs << "Back Seat Left: " << playerList[i].getName()<< endl;
                            }
                            else if( playerList[i].getID() == 7 ){
                                outFs << "Back Seat Right: " << playerList[i].getName()<< endl;
                            }
                        }
                        outFs.close();//Closes the output file
                    }
                }else if (requestedVehicle == "yellow compact"){
                    outFs.open("output-files/yellow_compact.txt");
                    if (!outFs.is_open()) {//Checks if the input file can be opened
                        cout << "Unable to open file for output";
                    }else {
                        //outFs << "DRIVER" << endl; FILL WITH DRIVER LOCATION
                        outFs << "Driver Seat: " << drivers[3] << endl;
                        for( int i; i < playerList.size();i++){
                            if ( playerList[i].getID() == 8 ){
                                outFs << "Front Seat: " << playerList[i].getName()<< endl;
                            }
                            else if ( playerList[i].getID() == 9 ){
                                outFs << "Back Seat Left: " << playerList[i].getName()<< endl;
                            }
                            else if( playerList[i].getID() == 10 ){
                                outFs << "Back Seat Right: " << playerList[i].getName()<< endl;
                            }
                        }
                        outFs.close();//Closes the output file
                    }
                }else if (requestedVehicle == "blue sedan"){
                    outFs.open("output-files/blue_sedan.txt");
                    if (!outFs.is_open()) {//Checks if the input file can be opened
                        cout << "Unable to open file for output";
                    }else {
                        //outFs << "DRIVER" << endl; FILL WITH DRIVER LOCATION
                        outFs << "Driver Seat: " << drivers[4] << endl;
                        for( int i; i < playerList.size();i++){
                            if ( playerList[i].getID() == 11 ){
                                outFs << "Front Seat: " << playerList[i].getName()<< endl;
                            }
                            else if ( playerList[i].getID() == 12 ){
                                outFs << "Back Seat Left: " << playerList[i].getName()<< endl;
                            }
                            else if( playerList[i].getID() == 13 ){
                                outFs << "Back Seat Middle: " << playerList[i].getName()<< endl;
                            }
                            else if( playerList[i].getID() == 14 ){
                                outFs << "Back Seat Right: " << playerList[i].getName()<< endl;
                            }
                        }
                        outFs.close();//Closes the output file
                    }
                }else if (requestedVehicle == "green sedan"){
                    outFs.open("output-files/green_sedan.txt");
                    if (!outFs.is_open()) {//Checks if the input file can be opened
                        cout << "Unable to open file for output";
                    }else {
                        //outFs << "DRIVER" << endl; FILL WITH DRIVER LOCATION
                        outFs << "Driver Seat: " << drivers[5] << endl;
                        for( int i; i < playerList.size();i++){
                            if ( playerList[i].getID() == 15 ){
                                outFs << "Front Seat: " << playerList[i].getName()<< endl;
                            }
                            else if ( playerList[i].getID() == 16 ){
                                outFs << "Back Seat Left: " << playerList[i].getName()<< endl;
                            }
                            else if( playerList[i].getID() == 17 ){
                                outFs << "Back Seat Middle: " << playerList[i].getName()<< endl;
                            }
                            else if( playerList[i].getID() == 18 ){
                                outFs << "Back Seat Right: " << playerList[i].getName()<< endl;
                            }
                        }
                        outFs.close();//Closes the output file
                    }
                }else{
                    cout << "Error! Invalid Vehicle. Returning to Menu" << endl << endl;
                    stillInCat = false;
                }

                break;
                //-----------------------------------------------------------

                //----------Print Reservations

                // Print all vehicles with players in each seat

                //-----------------------------------------------------------
            case 'r':
                cout << "Enter the admin password:" << endl;
                cin >> adminIn;

                //Does not run if admin Password is correct
                if(adminIn != adminPass){
                    cout << "Admin password not correct!" << endl;
                    continue;
                }
                //-----------------------------------------
                // Print file out to this
                outFs.open("output-files/all_reservations.txt");
                if (!outFs.is_open()) {//Checks if the input file can be opened
                    cout << "Unable to open file for output";
                }else {

                    for (int h = 0; h < 6; h++) {
                        switch(h) {
                            case 0:
                                outFs << "Purple Pickup:" << endl << endl;
                                outFs << "Driver Seat: " << drivers[0] << endl;
                                for( int i; i < playerList.size();i++){
                                    if ( playerList[i].getID() == 1 ){
                                        outFs << "Front Seat: " << playerList[i].getName()<< endl;
                                    }
                                }
                                break;
                            case 1:
                                outFs << "Red Compact:" << endl << endl;
                                outFs << "Driver Seat: " << drivers[1] << endl;
                                for( int i; i < playerList.size();i++){
                                    if ( playerList[i].getID() == 2 ){
                                        outFs << "Front Seat: " << playerList[i].getName()<< endl;
                                    }
                                    else if ( playerList[i].getID() == 3 ){
                                        outFs << "Back Seat Left: " << playerList[i].getName()<< endl;
                                    }
                                    else if( playerList[i].getID() == 4 ){
                                        outFs << "Back Seat Right: " << playerList[i].getName()<< endl;
                                    }
                                }
                                break;
                            case 2:
                                outFs << "Blue Compact:" << endl << endl;
                                outFs << "Driver Seat: " << drivers[2] << endl;
                                for( int i; i < playerList.size();i++){
                                    if ( playerList[i].getID() == 5 ){
                                        outFs << "Front Seat: " << playerList[i].getName()<< endl;
                                    }
                                    else if ( playerList[i].getID() == 6 ){
                                        outFs << "Back Seat Left: " << playerList[i].getName()<< endl;
                                    }
                                    else if( playerList[i].getID() == 7 ){
                                        outFs << "Back Seat Right: " << playerList[i].getName()<< endl;
                                    }
                                }
                                break;
                            case 3:
                                outFs << "Yellow Compact:" << endl << endl;
                                outFs << "Driver Seat: " << drivers[3] << endl;
                                for( int i; i < playerList.size();i++){
                                    if ( playerList[i].getID() == 8 ){
                                        outFs << "Front Seat: " << playerList[i].getName()<< endl;
                                    }
                                    else if ( playerList[i].getID() == 9 ){
                                        outFs << "Back Seat Left: " << playerList[i].getName()<< endl;
                                    }
                                    else if( playerList[i].getID() == 10 ){
                                        outFs << "Back Seat Right: " << playerList[i].getName()<< endl;
                                    }
                                }
                                break;
                            case 4:
                                outFs << "Blue Sedan:" << endl << endl;
                                outFs << "Driver Seat: " << drivers[4] << endl;
                                for( int i; i < playerList.size();i++){
                                    if ( playerList[i].getID() == 11 ){
                                        outFs << "Front Seat: " << playerList[i].getName()<< endl;
                                    }
                                    else if ( playerList[i].getID() == 12 ){
                                        outFs << "Back Seat Left: " << playerList[i].getName()<< endl;
                                    }
                                    else if( playerList[i].getID() == 13 ){
                                        outFs << "Back Seat Middle: " << playerList[i].getName()<< endl;
                                    }
                                    else if( playerList[i].getID() == 14 ){
                                        outFs << "Back Seat Right: " << playerList[i].getName()<< endl;
                                    }
                                }
                                break;
                            case 5:
                                outFs << "Green Sedan:" << endl << endl;
                                outFs << "Driver Seat: " << drivers[5] << endl;
                                for( int i; i < playerList.size();i++){
                                    if ( playerList[i].getID() == 15 ){
                                        outFs << "Front Seat: " << playerList[i].getName()<< endl;
                                    }
                                    else if ( playerList[i].getID() == 16 ){
                                        outFs << "Back Seat Left: " << playerList[i].getName()<< endl;
                                    }
                                    else if( playerList[i].getID() == 17 ){
                                        outFs << "Back Seat Middle: " << playerList[i].getName()<< endl;
                                    }
                                    else if( playerList[i].getID() == 18 ){
                                        outFs << "Back Seat Right: " << playerList[i].getName()<< endl;
                                    }
                                }
                                break;
                            default:
                                outFs << "How did you even get here?" << endl;
                        }
                        for (int i = 0; i < 18; i++) {
                            outFs << teamMembers.at(i) << " " << playerCredits.at(i) << endl;
                        }
                        outFs << setfill('-') << setw(15)<<"-"<<endl;

                    }//END for loop
                    outFs.close();//Closes the output file
                }//END Reservation FILE
                break;
                //-----------------------------------------------------------

            case 'e':
                //----------Exits Menu
                //-----------------------------------------------------------
                stillInMenu = false;
                break;
                //-----------------------------------------------------------

            default:
                cout << "Error! Invalid option! Try again!" << endl;
        }
        }while(stillInMenu);//END do while(stillInMenu)


    //----------SAVES quidditch.dat with the updated information.
    //-----------------------------------------------------------
    //--Commented out because it does not accuratly save the information
    outFs.open("quidditch_team.dat", ofstream::trunc);
    if (!outFs.is_open()) {//Checks if the input file can be opened
        cout << "Unable to open file for output";
    }else {
        for(int i = 0; i < 6; i++){
            outFs << drivers.at(i) << endl;
        }
        for(int i = 0; i < 18; i++){
            outFs << teamMembers.at(i) << " " << playerCredits.at(i) << endl;
        }
        outFs.close();//Closes the input file
    }
    return(0);
}//End main.cpp