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

#include <string>
#include <fstream>

using namespace std;

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
        void setAvailability(bool);
        bool getAvailability();
        void displayRoomDetails();
};

class Reservation{
    private:
        int reservationId;
        int customerId;
        int roomNumber;
        int* reservationDate;

    public:
        Reservation();
        Reservation(int, int, int, int*);
        ~Reservation();
        int getReservationId();
        int getCustomerId();
        int getRoomNumber();
        int* getReservationDate();
        void displayReservationDetails();
        void createReservation(Room room[], int);
};

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
        void checkIn(Reservation reservation[], int count);
        void checkOut(int, int);
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

void bubbleSort(Room [], int);

void mergeSort(Customer [], int, int);

void quickSortRoomNumber(Room [], int, int);

void quickSortCustID(Customer [], int, int);

void quickSortBillID(Billing [], int, int);

int binarySearch(int, int, Customer []);

int binarySearch(int, int, Room []);

int binarySearch(int, int, Reservation []);

void checkFile(fstream&);

void readRoom(Room []);

int readReservation(Reservation []);

int readCustomer(Customer []);

int printAvailableRoom(Room []);

#endif