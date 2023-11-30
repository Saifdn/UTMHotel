/****************************** UTM HOTEL ******************************\
Project: UTMHotel
Data Structure & Algorithm
Semester 1, 2023/2024

Section: 10
Member 1's Name: AHMAD SAIFUDIN BIN NARDI SUSANTO A22EC0035
Member 2's Name: LIO KOCK HOCK A22EC0185

<Specification File>
Class declaration

See https://github.com/Saifdn/UTMHotel.

\************************************************************************/

#ifndef UTMHOTEL_H
#define UTMHOTEL_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class Customer{
    private:
        int customerId;
        string name;
        string contact;
        int* checkInDate;
        int* checkOutDate;

    public:
        Customer();
        Customer(int, string, string, int[], int[]);
        ~Customer();
        int getCustomerId();
        string getName();
        string getContact();
        int* getCheckInDate();
        int* getCheckOutDate();
        void displayCustomerDetails();


};

class Reservation{
    private:
        int reservationId;
        int customerId;
        int roomNumber;
        int* reservationDate;

    public:
        Reservation();
        Reservation(int, int, int, int[]);
        ~Reservation();
        int getReservationId();
        int getCustomerId();
        int getRoomNumber();
        int* getReservationDate();
        void displayReservationDetails();
};

class Billing{
    private:
        int billingId;
        int customerId;
        int roomNumber;
        float totalAmount;
        int* billingDate;
    public:
        Billing();
        Billing(int, int, int, float, int[]);
        ~Billing();
        int getBillingId();
        int getCustomerId();
        int getroomNumber();
        float getTotalAmount();
        int* getbillingDate();
        void displayBillingDetails();

};  

class Room{
    private:
        int roomNumber;
        string type;
        float roomRate;
        bool isAvailable;
    public:
        Room();
        Room(int, string, float, bool);
        int getRoomNumber();
        string getType();
        float getRoomRate();
        bool getAvailability();
        void displayRoomDetails();
};

#endif