#ifndef UTMHOTEL_H
#define UTMHOTEL_H

#include <iostream>
#include <fstream>
using namespace std;



// Account creation and Authentication
class Account
{
protected:
    string username;
    string password;
    string name;
    string address;
    string email;
    string phone;

public:
    Account();
    void setName(string);
    string getUsername();
    string getPassword();
    string getName();
    string getAddress();
    string getEmail();
    string getPhone();
    bool authenticate(string, string);
    void logIn();
    void signUp();
    virtual void createAccount() = 0;
};

class Customer : public Account
{
public:
    Customer();
    Customer(string, string, string, string, string, string);
    virtual void createAccount();
};

class Clerk : public Account
{
public:
    Clerk();
    Clerk(string, string, string, string, string, string);
    virtual void createAccount();
};



//main functionality
class FrontDesk{
    void CheckInGuest();
    void CheckOutGuest();
    void manageGuestInfo();
    void assignRoom();
    void handleGuestRequest();
};

class ReservationManager{
    private:

    public:
        void createReservation();
        void modifyReservation();
        void cancelReservation();
        void checkAvaibility();
};

class BillingAndInvoicing{
    private:
    public:
        void generateinvoice();
        void processPayment();
        void trackBillinginfo();

};

class RoomInventoryManager{
    private:
    public:
        void trackAvailableRooms();
        void manageRoomTypes();
        void updateRoomStatus();
};





#endif