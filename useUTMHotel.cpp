#include <iostream>
#include <fstream>
#include <string>
#include "UTMHotel.hpp"
#include "UTMHotel.cpp"
using namespace std;

int main() {
    ReservationManager reservationManager;
    FrontDeskOperations frontDesk(reservationManager);
    BillingAndInvoicing billing;
    RoomInventoryManager roomInventory(reservationManager);

    roomInventory.displayAvailableRooms();

    Room selectedRoom = reservationManager.getRoom();

    frontDesk.checkInGuest(selectedRoom);

    billing.generateInvoice();
    billing.processPayment();

    frontDesk.checkOutGuest(selectedRoom);

    return 0;
}