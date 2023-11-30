/****************************** UTM HOTEL ******************************\
Project: UTMHotel
Data Structure & Algorithm
Semester 1, 2023/2024

Section: 10
Member 1's Name: AHMAD SAIFUDIN BIN NARDI SUSANTO A22EC0035
Member 2's Name: LIO KOCK HOCK A22EC0185

<Application File>
Main program

See https://github.com/Saifdn/UTMHotel.

\************************************************************************/

#include "UTMHotel.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    Room room[15];
    int choice;
    
    cout << "+===================+" << endl
        << "      Main Menu" << endl
        << "+===================+" << endl
        << "1. Reservation" << endl
        << "2. Check-In" << endl
        << "3. Check-Out" << endl
        << "Enter choice: ";
    cin >> choice;

    if(choice == 1){
        readRoom(room);
        printAvailableRoom(room);

        int roomNum;
        cout<<"Enter room no. : ";
        cin>>roomNum;

        
    }
    else if(choice == 2){

    }
    else if(choice == 3){

    }
    else{

    }

    system("PAUSE");
    return 0;
}

