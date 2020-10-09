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
    int playerId = -1;

    vector<Player> playerList(18);
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
    inFs.open("input-files/quidditch_team.dat");
    if (!inFs.is_open())//Checks if the input file can be opened
        cout << "Unable to open file for input";
    else {
        for (int i = 0; i < 5; i++) {
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


        playerCredits.at(i) = holdNames.back();


        holdNames.pop_back();
        holdNames.pop_back();
        teamMembers.at(i) = holdNames;
    }

    //----------Creates the Vehicle Objects
    //-----------------------------------------------------------
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




                cout << "Welcome to the RIT Quidditch Team Reservation System" << endl;//Out of do loop so they don't have to see message multiple times.
//---------------------------------------------------------
//MENU OPTIONS AND DISPLAY BEGINS HERE
//---------------------------------------------------------
    do {
        //----------Resets Variables to default values
        //-----------------------------------------------------------
        //TODO: Reset variables to default values
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
            getline(cin, userName);

            for (int i = 0; i < 18; i++) {//checks if their name is in the quidditch.dat file and is not a driver
                if (userName == teamMembers.at(i+6)) {
                    validName = true;
                    playerId = i;//Player ID is their location in the .dat file // same as ResID
                    break;
                }//end if
            }//end loop

            if(!validName){//Makes the user reenter name if not in file
                cout << userName << " is either a driver or is not a part of the Quidditch Team" << endl;
                cout << "Enter your name to begin: [first last]" << endl;
                continue;
            }//end if

            playerHold = playerList.at(playerId);
            if(* playerHold.getIDmemory() != 99){//Checks if there is already a reservation.
                cout << "There is already a reservation at this name." << endl;
                cout << "Select modify (M) to edit it, or select delete (D) to delete it." << endl;
                cout << "Returning to Menu" << endl << endl;

                cout << setfill('-') << setw(60)<<"-"<<endl;
                continue;
            }
            cout << setfill('-') << setw(60)<<"-"<<endl;
            cout << "Welcome " << userName << endl;
            cout << "You have " << playerCredits.at(playerId) << " Credits remaining" << endl;
            cout << setfill('-') << setw(60)<<"-"<<endl;

            //----------Seat Selection
            //-----------------------------------------------------------

                cout << "How do you want to select your seat?" << endl;
            do {

                cout << setfill('-') << setw(60)<<"-"<<endl;

                cout << "Enter [C] to search by category" << endl;
                cout << "Enter [S] to search by specifics" << endl;
                cout << setfill('-') << setw(60)<<"-"<<endl;
                userMenuIn = '-';//Sets userMenuIn back to a - for its re-use

                cin >> userMenuIn; //Re-using userMenuIn because it is efficient
                if(userMenuIn.length() != 1){//Checks if input is a single character
                    cout << "Error. Invalid input!"<< endl;
                    cout << "Must be single letter:" << endl;
                    cout << "Try again!" << endl;
                    continue;
                }
                menuChoice = userMenuIn.at(0);
                if(!isalpha(menuChoice)){//Checks if input is a letter
                    cout << "Error. Invalid input!"<< endl;
                    cout << "Must be a letter, not a number:" << endl;
                    cout << "Try again!" << endl;
                    continue;
                }
                menuChoice = tolower(menuChoice);

                switch(menuChoice){
                    case 'c':
                        cout << "Enter your requested seat type:" << endl;
                        cout << setw(2) << "[Front] for a front seat" << endl;
                        cout << setw(2) << "[Side] for a left or right back seat in a car without a middle seat" << endl;
                        cout << setw(2) << "[Edge] for a left or right back seat in a car with a middle seat" << endl;
                        cout << setw(2) << "[Middle] for a middle back seat in a Sedan" << endl;
                        getline(cin, requestedSeat);

                        for (int i = 0; i < requestedSeat.length(); i++){
                            if (isalpha(requestedSeat.at(i))){
                                requestedSeat.at(i) = tolower(requestedSeat.at(i));
                            }else{
                                cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                                stillInCat = false;
                                break;
                            }
                        }//End For Loop

                        if(requestedSeat == "front"){
                            if((playerCredits.at(playerId) < 5) && (playerCredits.at(playerId) != -1)){
                                cout << "Error! Too few credits to select seat! Returning to Menu";
                                stillInCat = false;
                            }else{
                                //TODO Find any front seats available
                            }
                        }else if(requestedSeat == "side"){
                            if((playerCredits.at(playerId) < 3) && (playerCredits.at(playerId) != -1)){
                                cout << "Error! Too few credits to select seat! Returning to Menu";
                                stillInCat = false;
                            }else{
                                //TODO Find any side seats available
                            }
                        }else if (requestedSeat == "edge"){
                            if((playerCredits.at(playerId) < 2) && (playerCredits.at(playerId) != -1)){
                                cout << "Error! Too few credits to select seat! Returning to Menu";
                                stillInCat = false;
                            }else{
                                //TODO Find any edge seats available
                            }
                        }else if (requestedSeat == "middle"){
                            if((playerCredits.at(playerId) < 1) && (playerCredits.at(playerId) != -1)){
                                cout << "Error! Too few credits to select seat! Returning to Menu";
                                stillInCat = false;
                            }else{
                                //TODO Find any back middle seats available
                            }
                        }else{
                            cout << "Error! Invalid Seat. Returning to Menu" << endl << endl;
                            stillInCat = false;
                        }





                    break;
                    //-----------------------------------------------------------
                    case 's':
                        cout << "Enter your requested vehicle: (Spaces must be included)" << endl;
                        cout <<setw(2)<< "[Purple Pickup]" << endl;
                        cout <<setw(2)<< "[Red Compact]" << endl;
                        cout <<setw(2)<< "[Blue Compact]" << endl;
                        cout <<setw(2)<< "[Yellow Compact]" << endl;
                        cout <<setw(2)<< "[Blue Sedan]" << endl;
                        cout <<setw(2)<< "[Green Sedan]" << endl;
                        getline(cin, requestedVehicle);

                        for(int i = 0; i < requestedVehicle.length(); i++) {//Checks if the input is a one of the possible vehicles.
                            if (isalpha(requestedVehicle.at(i))){
                                requestedVehicle.at(i) = tolower(requestedVehicle.at(i));
                            }else{
                               cout << "Error! Invalid Vehicle. Returning to Menu" << endl << endl;
                               stillInCat = false;
                               break;
                            }
                        }

                        if(requestedVehicle == "purple pickup"){//There is only one seat possible in this vehicle so no seat selection is needed
                            if(purplePickup.GetFilled().at(1)){
                                cout << "That seat is unavailable. Returning to Menu";
                            }else{
                                purplePickup.setSeat(* playerHold.getIDmemory(),FrontSeat5);
                                cout << "Seat assignment successful. Returning to Menu";
                            }
                        }else if (requestedVehicle == "red compact"){
                            cout << "Enter your requested seat type:" << endl;
                            cout <<setw(2)<< "[Front] for a front seat" << endl;
                            cout <<setw(2)<< "[Side] for a back seat on either the left or right side" << endl;


                        }else if (requestedVehicle == "blue compact"){
                            cout << "Enter your requested seat type:" << endl;
                            cout <<setw(2)<< "[Front] for the front seat" << endl;
                            cout <<setw(2)<< "[Side] for a back seat on either the left or right side" << endl;


                        }else if (requestedVehicle == "yellow compact"){
                            cout << "Enter your requested seat type:" << endl;
                            cout <<setw(2)<< "[Front] for the front seat" << endl;
                            cout <<setw(2)<< "[Side] for a back seat on either the left or right side" << endl;


                        }else if (requestedVehicle == "blue sedan"){
                            cout << "Enter your requested seat type:" << endl;
                            cout <<setw(2)<< "[Front] for the front seat" << endl;
                            cout <<setw(2)<< "[Edge] for a back seat on either the left or right side" << endl;
                            cout <<setw(2)<< "[Middle] for the back middle seat" << endl;

                        }else if (requestedVehicle == "green sedan"){
                            cout << "Enter your requested seat type:" << endl;
                            cout <<setw(2)<< "[Front] for the front seat" << endl;
                            cout <<setw(2)<< "[Edge] for a back seat on either the left or right side" << endl;
                            cout <<setw(2)<< "[Middle] for the back middle seat" << endl;
                        }else{
                            cout << "Error! Invalid Vehicle. Returning to Menu" << endl << endl;
                            stillInCat = false;
                        }

                    break;
                    //-----------------------------------------------------------
                    default:
                        cout << "Error! Invalid Choice. Returning to Menu";
                        stillInCat = false;
                }
                } while(stillInCat);




            break;
            //-----------------------------------------------------------

            //----------Modifies Reservation
            //-----------------------------------------------------------
            case 'm':
                cout << "Enter your Reservation ID:" << endl;
                getline(cin, userIDHold);
                for (int i = 0; i < userIDHold.length(); i++) {
                    if (!isdigit(userIDHold.at(i))) {
                        cout << "Error! Reservation ID must be a number! Returning to menu.";
                        break;
                    }
                }

                userIDIn = stoi(userIDHold);

                //TODO understand how the reservations are stored and use that to check if there is already one






            break;
            //-----------------------------------------------------------

            //----------Deletes Reservation
            //-----------------------------------------------------------
            case 'd':

            break;
            //-----------------------------------------------------------

            //----------Display Vehicles
            //-----------------------------------------------------------
            case 'v':



            break;
            //-----------------------------------------------------------

            //----------Print Assignments
            //-----------------------------------------------------------
            case 's':
                cout << "Enter your requested vehicle: (Spaces must be included)" << endl;
                cout <<setw(2)<< "[Purple Pickup]" << endl;
                cout <<setw(2)<< "[Red Compact]" << endl;
                cout <<setw(2)<< "[Blue Compact]" << endl;
                cout <<setw(2)<< "[Yellow Compact]" << endl;
                cout <<setw(2)<< "[Blue Sedan]" << endl;
                cout <<setw(2)<< "[Green Sedan]" << endl;
                getline(cin, requestedVehicle);

                for(int i = 0; i < requestedVehicle.length(); i++) {//Checks if the input is a one of the possible vehicles.
                    if (isalpha(requestedVehicle.at(i))){
                        requestedVehicle.at(i) = tolower(requestedVehicle.at(i));
                    }else{
                        cout << "Error! Invalid Vehicle. Returning to Menu" << endl << endl;
                        stillInCat = false;
                        break;
                    }
                }
                //TODO fill with driver location info
                if(requestedVehicle == "purple pickup"){
                    outFs.open("output-files/purple_pickup.txt");
                    if (!outFs.is_open()) {//Checks if the input file can be opened
                        cout << "Unable to open file for output";
                    }else {
                        //outFs << "DRIVER" << endl; FILL WITH DRIVER LOCATION
                        for(int i = 0; i < 18; i++){
                            outFs << teamMembers.at(i) << " " << playerCredits.at(i) << endl;
                        }
                        outFs.close();//Closes the output file
                    }
                }else if (requestedVehicle == "red compact"){
                    outFs.open("output-files/red_compact.txt");
                    if (!outFs.is_open()) {//Checks if the input file can be opened
                        cout << "Unable to open file for output";
                    }else {
                        //outFs << "DRIVER" << endl; FILL WITH DRIVER LOCATION
                        for(int i = 0; i < 18; i++){
                            outFs << teamMembers.at(i) << " " << playerCredits.at(i) << endl;
                        }
                        outFs.close();//Closes the output file
                    }
                }else if (requestedVehicle == "blue compact"){
                    outFs.open("output-files/blue_compact.txt");
                    if (!outFs.is_open()) {//Checks if the input file can be opened
                        cout << "Unable to open file for output";
                    }else {
                        //outFs << "DRIVER" << endl; FILL WITH DRIVER LOCATION
                        for(int i = 0; i < 18; i++){
                            outFs << teamMembers.at(i) << " " << playerCredits.at(i) << endl;
                        }
                        outFs.close();//Closes the output file
                    }
                }else if (requestedVehicle == "yellow compact"){
                    outFs.open("output-files/yellow_compact.txt");
                    if (!outFs.is_open()) {//Checks if the input file can be opened
                        cout << "Unable to open file for output";
                    }else {
                        //outFs << "DRIVER" << endl; FILL WITH DRIVER LOCATION
                        for(int i = 0; i < 18; i++){
                            outFs << teamMembers.at(i) << " " << playerCredits.at(i) << endl;
                        }
                        outFs.close();//Closes the output file
                    }
                }else if (requestedVehicle == "blue sedan"){
                    outFs.open("output-files/blue_sedan.txt");
                    if (!outFs.is_open()) {//Checks if the input file can be opened
                        cout << "Unable to open file for output";
                    }else {
                        //outFs << "DRIVER" << endl; FILL WITH DRIVER LOCATION
                        for(int i = 0; i < 18; i++){
                            outFs << teamMembers.at(i) << " " << playerCredits.at(i) << endl;
                        }
                        outFs.close();//Closes the output file
                    }
                }else if (requestedVehicle == "green sedan"){
                    outFs.open("output-files/green_sedan.txt");
                    if (!outFs.is_open()) {//Checks if the input file can be opened
                        cout << "Unable to open file for output";
                    }else {
                        //outFs << "DRIVER" << endl; FILL WITH DRIVER LOCATION
                        for(int i = 0; i < 18; i++){
                            outFs << teamMembers.at(i) << " " << playerCredits.at(i) << endl;
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
                outFs.open("output-files/all_reservations.txt");
                if (!outFs.is_open()) {//Checks if the input file can be opened
                    cout << "Unable to open file for output";
                }else {

                    for (int h = 0; h < 6; h++) {
                        switch(h) {
                            case 0:
                                outFs << "Purple Pickup:" << endl << endl;
                                outFs << "DRIVER" << endl;//FILL WITH DRIVER INFO
                                break;
                            case 1:
                                outFs << "Red Compact:" << endl << endl;
                                outFs << "DRIVER" << endl;//FILL WITH DRIVER INFO
                                break;
                            case 2:
                                outFs << "Blue Compact:" << endl << endl;
                                outFs << "DRIVER" << endl;//FILL WITH DRIVER INFO
                                break;
                            case 3:
                                outFs << "Yellow Compact:" << endl << endl;
                                outFs << "DRIVER" << endl;//FILL WITH DRIVER INFO
                                break;
                            case 4:
                                outFs << "Blue Sedan:" << endl << endl;
                                outFs << "DRIVER" << endl;//FILL WITH DRIVER INFO
                                break;
                            case 5:
                                outFs << "Green Sedan:" << endl << endl;
                                outFs << "DRIVER" << endl;//FILL WITH DRIVER INFO
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
    outFs.open("input-files/quidditch_team.dat", ofstream::trunc);
    if (!outFs.is_open()) {//Checks if the input file can be opened
        cout << "Unable to open file for output";
    }else {
        for(int i = 0; i < 5; i++){
            outFs << drivers.at(i) << endl;
        }
        for(int i = 0; i < 18; i++){
            outFs << teamMembers.at(i) << " " << playerCredits.at(i) << endl;
        }
        outFs.close();//Closes the input file
    }
    return(0);
}//End main.cpp
