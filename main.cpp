#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


#include "../Design Project 1/build-files/Players.h"
#include "../Design Project 1/build-files/Vehicles.h"
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
//----------Menu & Category Variables
//-----------------------------------------------------------
    bool stillInMenu = true;
    bool stillInCat = true;
    string userMenuIn = "BLANK";
    char menuChoice = '-';



//----------Player Variables and Vectors
//-----------------------------------------------------------
    string userName = "BLANK";
    bool validName = false;
    int playerId = -1;

    vector<Players> playerList(18);
    Players playerHold;//Stores a single player from the vector Needed to use Players() functions

    char selMethod;//How they user wants to select their seat

    string requestedVehicle = "BLANK";

    string requestedSeat = "BLANK";


//----------Admin Variables
//-----------------------------------------------------------
    string adminPass = "AdminPassword";//Only used by admin to view reservations. Temporary
    string adminIn = "BLANK";



    //-----------------------------------------------------------
    //CODE
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


                cout << "Welcome to the RIT Quidditch Team Reservation System" << endl;//Out of do loop so they don't have to see message multiple times.
//---------------------------------------------------------
//MENU OPTIONS AND DISPLAY BEGINS HERE
//---------------------------------------------------------
    do {
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
                if(playerHold.resID != 99){//Checks if there is already a reservation.
                    cout << "There is already a reservation at this name." << endl;
                    cout << "Select modify (M) to edit it, or select delete (D) to delet it." << endl << endl;
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

                    cout << "Enter C to search by category" << endl;
                    cout << "Enter S to search by specifics" << endl;
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
                            cout << "Enter your requested seat type" << endl;
                            getline(cin, requestedSeat);




                        break;
                        //-----------------------------------------------------------
                        case 's':
                            cout << "Enter your requested vehicle" << endl;
                            cout <<setw(2)<< "Purple Truck" << endl;
                            cout <<setw(2)<< "Red Compact" << endl;
                            cout <<setw(2)<< "Blue Compact" << endl;
                            cout <<setw(2)<< "Yellow Compact" << endl;
                            cout <<setw(2)<< "Blue Sedan" << endl;
                            cout <<setw(2)<< "Green Sedan" << endl;
                            getline(cin, requestedVehicle);

                            for(int i = 0; i < requestedVehicle.length(); i++) {
                                if (isalpha(requestedVehicle.at(i))){
                                    requestedVehicle.at(i) = tolower(requestedVehicle.at(i));
                                }else{
                                   cout << "Error! Invalid Vehicle. Returning to Menu" << endl << endl;
                                   break;
                                }
                            }

                        break;
                        //-----------------------------------------------------------
                        default:
                            stillInCat = false;
                    }
                    } while(stillInCat);




                break;
                //-----------------------------------------------------------

                //----------Modifies Reservation
                //-----------------------------------------------------------
                case 'm':

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

                break;
                //-----------------------------------------------------------

                //----------Print Reservations
                //-----------------------------------------------------------
                case 'r':
                    cout << "Enter the admin password:" << endl;
                    cin >> adminIn;
                    if(adminIn != adminPass){
                        cout << "Admin password not correct!" << endl;
                        continue;
                    }


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
    outFs.open("input-files/quidditch_team.dat");
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
