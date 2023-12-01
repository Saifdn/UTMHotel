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

        int sort1;
        cout<<"Sort by: 1. Room Number 2. Price";
        cin>>sort1;

        if(sort1 == 1)
            quickSortRoomNumber(room, 15-15, 15-1);
        else
            bubbleSort(room, 15);

        int numOfRooms = printAvailableRoom(room);

        int roomNum;
        cout<<"Enter room no. : ";
        cin>>roomNum;

        int roomIndex = binarySearch(roomNum, 15, room);

        if(roomIndex>=0){
            int date[3];
            for(int i=0; i<3; i++){
                if(i==0)      cout<<"Enter day      : ";
                else if(i==1) cout<<"Enter month    : ";
                else          cout<<"Enter year     : ";
                cin>>date[i];
            }

            Reservation reservation(16-numOfRooms, 16-numOfRooms, roomNum, date);
            reservation.createReservation(room, roomIndex);
        }
    }
    else if(choice == 2){
        string name, number;
        int roomNumber, inDate[3], outDate[3];
        cout<<"Enter Name           : ";
        cin>>name;
        cout<<"Enter Phone Number   : ";
        cin>>number;
        cout<<"Enter Room Reserved  : ";
        cin>>roomNumber;

        cout<<"Check-In Date!!"<<endl;
        for(int i=0; i<3; i++){
            if(i==0)      cout<<"Enter day      : ";
            else if(i==1) cout<<"Enter month    : ";
            else          cout<<"Enter year     : ";
            cin>>inDate[i];
        }
        cout<<"Check-Out Date!!"<<endl;
        for(int i=0; i<3; i++){
            if(i==0)      cout<<"Enter day      : ";
            else if(i==1) cout<<"Enter month    : ";
            else          cout<<"Enter year     : ";
            cin>>outDate[i];
        }

        Reservation reservation[15];
        int numberOfReservation = readReservation(reservation);
        int index = binarySearch(roomNumber, numberOfReservation, reservation);
        Customer customer(reservation[index].getCustomerId(), name, number, inDate, outDate);
        customer.checkIn();
    }
    else if(choice == 3){

    }
    else{

    }

    system("PAUSE");
    return 0;
}

