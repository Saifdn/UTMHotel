#ifndef UTMHOTEL_H
#define UTMHOTEL_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

const int MAX_ROOMS = 100;

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
class Room {
private:
    int roomNumber;
    string roomType;
    bool isOccupied;

public:
    Room();
    Room(int number, string type);

    int getRoomNumber() const;
    string getRoomType() const;
    bool getIsOccupied() const;

    void setIsOccupied(bool occupied);
    // Additional room attributes/methods can be added
};

class ReservationManager {
private:
    Room rooms[MAX_ROOMS];
    int numOfRooms = 0;

public:
    ReservationManager();
    void displayAvailableRooms() const;
    Room getRoom();

    // Additional reservation management functions can be added
};

class FrontDeskOperations {
private:
    ReservationManager& reservationManager;

public:
    FrontDeskOperations(ReservationManager& rm);

    void checkInGuest(Room& room);
    void checkOutGuest(Room& room);

    // Additional front desk operations can be added
};

class BillingAndInvoicing {
public:
    void generateInvoice();
    void processPayment();

    // Additional billing and invoicing functions can be added
};

class RoomInventoryManager {
private:
    ReservationManager& reservationManager;

public:
    RoomInventoryManager(ReservationManager& rm);

    void displayAvailableRooms() const;

    // Additional room inventory management functions can be added
};

#endif