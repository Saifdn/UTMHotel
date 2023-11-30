#include "UTMHotel.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*=========================================================
    Definition class Account
=========================================================*/
Account::Account() {}

void Account::setName(string _name) { name = _name; }

string Account::getUsername() { return username; }

string Account::getPassword() { return password; }

string Account::getName() { return name; }

string Account::getAddress() { return address; }

string Account::getEmail() { return email; }

string Account::getPhone() { return phone; }

bool Account::authenticate(string username, string password)
{
    fstream file, file2;
    string un, pw;

    file.open("Vendor/" + username + ".txt", ios::in);
    file2.open("Customer/" + username + ".txt", ios::in);

    file >> un >> pw;
    file2 >> un >> pw;

    file.close();
    file2.close();

    if (un == username && pw == password)
        return 1;
    else
        return 0;
}

void Account::logIn()
{
    string un, pw;
    fstream file;

A:
    cout << "*******************************\n"
         << "        ACCOUNT SIGN IN        \n"
         << "-------------------------------\n";
    cout << "Username: ";
    cin >> un;
    cout << "Password: ";
    cin >> pw;

    if (authenticate(un, pw) == true)
    {
        cout << "\n*You have succesfully sign in!\n"
             << endl;

        file.open("Vendor/" + un + ".txt", ios::in);
        getline(file, username);
        getline(file, password);
        getline(file, name);
        getline(file, address);
        getline(file, email);
        getline(file, phone);
        file.close();
    }
    else
    {
        cout << "*The password is incorrect" << endl;
        goto A;
    }
}

void Account::signUp()
{
    cout << "**********************************\n"
         << "        CREATE NEW ACCOUNT        \n"
         << "----------------------------------\n";
    cin.ignore();

    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);
    cout << "Enter full name: ";
    getline(cin, name);
    cout << "Enter address : ";
    getline(cin, address);
    cout << "Enter email   : ";
    getline(cin, email);
    cout << "Enter phone   : ";
    getline(cin, phone);
}

/*=========================================================
    Definition class Customer
=========================================================*/
Customer::Customer() {}

Customer::Customer(string _username, string _password, string _name, string _address, string _email, string _phone)
{
    username = _username;
    password = _password;
    name = _name;
    address = _address;
    email = _email;
    phone = _phone;
}

void Customer::createAccount()
{
    fstream file;

    signUp();
    file.open("Customer/" + username + ".txt", ios::out);
    file << username << endl
         << password << endl
         << name << endl
         << address << endl
         << email << endl
         << phone << endl;
    file.close();
}

/*=========================================================
    Definition class Vendor
=========================================================*/
Clerk::Clerk() {}

Clerk::Clerk(string _username, string _password, string _name, string _address, string _email, string _phone)
{
    username = _username;
    password = _password;
    name = _name;
    address = _address;
    email = _email;
    phone = _phone;
}

void Clerk::createAccount()
{
    fstream file;

    signUp();
    file.open("Vendor/" + username + ".txt", ios::out);
    file << username << endl
         << password << endl
         << name << endl
         << address << endl
         << email << endl
         << phone << endl;
    file.close();
}