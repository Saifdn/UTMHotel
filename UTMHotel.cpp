/****************************** UTM HOTEL ******************************\
Project: UTMHotel
Data Structure & Algorithm
Semester 1, 2023/2024

Section: 10
Member 1's Name: AHMAD SAIFUDIN BIN NARDI SUSANTO A22EC0035
Member 2's Name: LIO KOCK HOCK A22EC0185

<Implementation File>
Class definition, function definition, algorithm

See https://github.com/Saifdn/UTMHotel.

\************************************************************************/

#include "UTMHotel.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*=========================================================
    Functions Definition
=========================================================*/
void checkFile(fstream& file) {
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        exit(1);
    }
}

void readRoom(Room room[]){

    fstream file;

    file.open("Room/room.txt",ios::in);

    checkFile(file);

    int roomNumber;
    string type;
    float price;
    int availability;
    int count = 0;

    while (file >> roomNumber >> type >> price >> availability && count < 15) {
        bool isAvailable = (availability == 1);
        room[count++] = Room(roomNumber, type, price, isAvailable);
    }

    file.close();
}

int printAvailableRoom(Room room[]){
    int count=0;
    for(int i = 0; i < 15; i++){
        if(room[i].getAvailability()){
            cout<<left
                <<setw(4)<<room[i].getRoomNumber()
                <<setw(8)<<room[i].getType()
                <<setw(3)<<"RM "
                <<setw(4)<<room[i].getRoomRate()<<" per night"<<endl;
            count++;
        }
    }

    return count;
}


/*=========================================================
    Improved Bubble Sort
=========================================================*/
void bubbleSort(Room data[], int n){
    Room temp;
    bool sorted = false;

    for(int pass = 1; (pass < n) && !sorted; ++pass){
        sorted = true;
        for(int x = 0; x < n - pass; ++x){
            if(data[x].getRoomRate() > data[x+1].getRoomRate()){
                temp = data[x];
                data[x] = data[x+1];
                data[x+1] = temp;
                sorted = false;
            }
        }
    }
}


/*=========================================================
    Merge Sort
=========================================================*/
void merge(Customer data[], int first, int mid, int last){
    
    Customer tempData[100];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    for(; (first1 <= last1) && (first2 <= last2); ++index){
        
        int val1 = 0, val2 =0;

        int *array1 = data[first1].getCheckInDate();
        int *array2 = data[first2].getCheckInDate();

        for(int j = 0; j < 3; j++){
            val1 += array1[j];
            val2 += array2[j];
        }
        
        if(val1 < val2){
            tempData[index] = data[first1];
            ++first1;
        }
        else{
            tempData[index] = data[first2];
            ++first2;
        }
    }

    for(; first1 <= last1; ++first1, ++index){
        tempData[index] = data[first1];
    }

    for(; first2 <= last2; ++first2, ++index){
        tempData[index] = data[first2];
    }
    
    for(index = first; index <= last; ++index){
       data[index] = tempData[index];
    }
}

void mergeSort(Customer data[], int first, int last){
    if(first < last){
        int mid = (first + last)/2;
        mergeSort(data, first, mid);
        mergeSort(data, mid + 1, last);
        merge(data, first, mid, last);
    }
}


/*=========================================================
    Quick Sort based on Room Number
=========================================================*/
int partitionRoomNumber(Room room[], int first, int last){
    int pivot;
    Room temp;
    int loop, cutPoint, bottom, top;
    pivot = room[first].getRoomNumber(); //identify pivot
    bottom = first; top = last;
    loop=1; //always TRUE

    while(loop)
    {
        while(room[top].getRoomNumber()>pivot){top--;}
        while(room[bottom].getRoomNumber()<pivot){bottom++;}
        if(bottom<top)
        {
            temp = room[bottom];
            room[bottom]= room[top];
            room[top] = temp;
        }

        else{
            loop = 0;
            cutPoint = top;
        }
    }
    return cutPoint;
}

void quickSortRoomNumber(Room room[], int first, int last){
    int cut;
    if(first<last){
        cut = partitionRoomNumber(room, first, last);
        quickSortRoomNumber(room, first, cut);
        quickSortRoomNumber(room, cut+1, last);
    }
}


/*=========================================================
    Quick Sort based on Customer ID
=========================================================*/
int partitionCustID(Customer cust[], int first, int last){
    int pivot;
    Customer temp;
    int loop, cutPoint, bottom, top;
    pivot = cust[first].getCustomerId(); //identify pivot
    bottom = first; top = last;
    loop=1; //always TRUE

    while(loop)
    {
        while(cust[top].getCustomerId()>pivot){top--;}
        while(cust[bottom].getCustomerId()<pivot){bottom++;}
        if(bottom<top)
        {
            temp = cust[bottom];
            cust[bottom] = cust[top];
            cust[top] = temp;
        
        }

        else{
            loop = 0;
            cutPoint = top;
        }
    }
    return cutPoint;
}

void quickSortCustID(Customer cust[], int first, int last){
    int cut;
    if(first<last){
        cut = partitionCustID(cust, first, last);
        quickSortCustID(cust, first, cut);
        quickSortCustID(cust, cut+1, last);
    }
}


/*=========================================================
    Quick Sort based on Billing ID
=========================================================*/
int partitionBillID(Billing bill[], int first, int last){
    int pivot;
    Billing temp;
    int loop, cutPoint, bottom, top;
    pivot = bill[first].getCustomerId(); //identify pivot
    bottom = first; top = last;
    loop=1; //always TRUE

    while(loop)
    {
        while(bill[top].getBillingId()>pivot){top--;}
        while(bill[bottom].getBillingId()<pivot){bottom++;}
        if(bottom<top)
        {
            //swap Room Number
            temp = bill[bottom];
            bill[bottom] = bill[top];
            bill[top] = temp;
        
        }

        else{
            loop = 0;
            cutPoint = top;
        }
    }
    return cutPoint;
}

void quickSortBillID(Billing bill[], int first, int last){
    int cut;
    if(first<last){
        cut = partitionBillID(bill, first, last);
        quickSortBillID(bill, first, cut);
        quickSortBillID(bill, cut+1, last);
    }
}

/*=========================================================
    Binary Search based on Customer ID
=========================================================*/
int binarySearch(int searchkey, int arraysize, Customer cust[]){
    bool found = false;
    int index = -1;
    int middle, left = 0, right = arraysize-1;

    while((left<=right) && (!found)){
        middle = (left + right)/2;
        if(cust[middle].getCustomerId() == searchkey){
            index = middle;
            found = true;
        }

        else if(cust[middle].getCustomerId() > searchkey)
            right = middle-1;

        else 
            left = middle+1;
    }
    return index;
}


/*=========================================================
    Binary Search based on Room Number
=========================================================*/
int binarySearch(int searchkey, int arraysize, Room room[]){
    bool found = false;
    int index = -1;
    int middle, left = 0, right = arraysize-1;

    while((left<=right) && (!found)){
        middle = (left + right)/2;
        if(room[middle].getRoomNumber() == searchkey){
            index = middle;
            found = true;
        }

        else if(room[middle].getRoomNumber() > searchkey)
            right = middle-1;

        else 
            left = middle+1;
    }
    return index;
}



/*=========================================================
    Definition class Customer
=========================================================*/
Customer::Customer() {
    checkInDate = new int [3];
    checkOutDate = new int [3];
}

Customer::Customer(int customerId, string name, string contact, int checkInDate[], int checkOutDate[]) {
    this -> customerId = customerId;
    this -> name = name;
    this -> contact = contact;
    checkInDate = new int [3];
    checkOutDate = new int [3];
    for(int i = 0; i < 3; i++){
        this -> checkInDate[i] = checkInDate[i];
        this -> checkOutDate[i] = checkOutDate[i];
    } 
}

Customer::~Customer() {
    delete [] checkInDate;
    delete [] checkOutDate;
}

int Customer::getCustomerId() {return customerId;}

string Customer::getName() {return name;}

string Customer::getContact() {return contact;}

int* Customer::getCheckInDate() {return checkInDate;}

int* Customer::getCheckOutDate() {return checkOutDate;}

void Customer::displayCustomerDetails(){
    cout<<"Customer ID      : "<<customerId<<endl
        <<"Name             : "<<name<<endl
        <<"Contact No.      : "<<contact<<endl;
    
    cout<<"Check-in Date    : ";
    for(int i = 0; i < 3; i++){
        cout<<checkInDate[i]<<"/";
    }
    cout<<endl;
    
    cout<<"Check-out Date    : ";
    for(int i = 0; i < 3; i++){
        cout<<checkOutDate[i]<<"/";
    }
    cout<<endl;
}


/*=========================================================
    Definition class Reservation
=========================================================*/
Reservation::Reservation() {
    reservationDate = new int[3];
}

Reservation::Reservation(int reservationId, int customerId, int roomNumber, int Date[]){
    this -> reservationId = reservationId;
    this -> customerId = customerId;
    this -> roomNumber = roomNumber;
    reservationDate = new int[3];
    for(int i = 0; i < 3; i++){
        reservationDate[i] = Date[i];
    }
    
}

Reservation::~Reservation(){
    delete [] reservationDate;
}

int Reservation::getReservationId() {return reservationId;}

int Reservation::getCustomerId() {return customerId;}

int Reservation::getRoomNumber() {return roomNumber;}

int* Reservation::getReservationDate() {return reservationDate;}

void Reservation::displayReservationDetails(){
    cout<<"Reservation ID   : "<<reservationId<<endl
        <<"Customer ID      : "<<customerId<<endl
        <<"Room Number      : "<<roomNumber<<endl;
    
    cout<<"Reservation Date : ";
    for(int i = 0; i < 3; i++){
        cout<<reservationDate[i]<<"/";
    }
    cout<<endl;
};

void Reservation::createReservation(Room room[], int roomIndex){
    fstream outfile;
    outfile.open("Reservation/reservation.txt", ios::app);
    outfile << reservationId << " " << customerId << " " << roomNumber << " ";
    for(int i=0; i<3; i++){
        if(i<2)
            outfile << reservationDate[i] <<"/";
        else
            outfile << reservationDate[i];
    }
    outfile << endl;

    readRoom(room);
    room[roomIndex].setAvailability(0);

    fstream file;
    file.open("Room/room.txt", ios::out);
    for(int i=0; i<15; i++){
        file << room[i].getRoomNumber() << " " << room[i].getType() << " " << room[i].getRoomRate() << " " << room[i].getAvailability() << endl;
    }

    file.close();

}




/*=========================================================
    Definition class Billing
=========================================================*/
Billing::Billing() {
    billingDate = new int[3];
}

Billing::Billing(int billingId, int customerId, int roomNumber, float totalAmount, int billingDate[]) {
    this -> billingId = billingId;
    this -> customerId = customerId;
    this -> roomNumber = roomNumber;
    this -> totalAmount = totalAmount;
    billingDate = new int[3];
    for(int i = 0; i < 3; i++){
        this -> billingDate[i] = billingDate[i];
    }
}

Billing::~Billing(){
    delete [] billingDate;
}

int Billing:: getBillingId() {return billingId;}

int Billing:: getCustomerId() {return customerId;}

int Billing:: getroomNumber() {return roomNumber;}

float Billing:: getTotalAmount() {return totalAmount;}

int* Billing:: getbillingDate() {return billingDate;}

void Billing:: displayBillingDetails() {
    cout << "Billing ID     : " << billingId   << endl
         << "Customer ID    : " << customerId  << endl
         << "Room Number    : " << roomNumber  << endl
         << "Total Amount   : " << totalAmount << endl;

    cout<< "Billing Date    : ";
    for(int i = 0; i < 3; i++){
        cout<<billingDate[i]<<"/";
    }
    cout<<endl;
}


/*=========================================================
    Definition class Room
=========================================================*/
Room::Room() {}

Room::Room(int roomNumber, string type, float roomRate, bool isAvailable) {
    this -> roomNumber = roomNumber;
    this -> type = type;
    this -> roomRate = roomRate;
    this -> isAvailable = isAvailable;
}

int Room:: getRoomNumber() {return roomNumber;}

string Room:: getType() {return type;}

float Room:: getRoomRate() {return roomRate;}

void Room:: setAvailability (bool availability){isAvailable = availability;}

bool Room:: getAvailability() {return isAvailable;}

void Room:: displayRoomDetails(){
    cout << "Room Number    : " << roomNumber  << endl
         << "Room Type      : " << type        << endl
         << "Availability   : " << isAvailable << endl;
    cout << endl;
}