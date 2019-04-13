#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Account.hpp"

#include <string>

class Customer
{
    private:
        std::string fname, lname;
        Account account;
        int pinNum;
    public:
        // had to change constructor syntax to accept the Account object, I think we need this..
        Customer(std::string f, std::string l, int pin, Account acc) : fname{f}, lname{l}, pinNum{pin}, account{acc} {} 
        std::string getName() {return fname + ' ' + lname;}
        Account* getAccount() {return &account;}
        bool verifyPin(int num) {if(num == pinNum) return true; else return false;}
        double accountBalance() { return account.getBalance();}
        void setAccount(Account a) {account = a;}
};

void createCustomers() {
    Account acc(123456789, 25.00);
    Customer cust("Michael", "Scott", 1234, acc);

    Account acc2(987654321, 500.82);
    Customer cust2("Dwight", "Schrute", 4321, acc2);

    Account acc3(123459876, 10256.24);
    Customer cust3("Oscar", "Martinez", 9512, acc3);

    Account acc4(987651234, 256.24);
    Customer cust4("Kelly", "Kapur", 1478, acc4);

    Account acc5(715932468, 102.77);
    Customer cust5("Stanley", "Hudson", 2468, acc5);
}

#endif