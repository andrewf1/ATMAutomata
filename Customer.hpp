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
        Customer(std::string f, std::string l, int pin) {fname = f; lname = l; pinNum = pin;}
        std::string getName() {return fname + ' ' + lname;}
        Account* getAccount() {return &account;}
        bool verifyPin(int num) {if(num == pinNum) return true; else return false;}
        double accountBalance() { return account.getBalance();}
        void setAccount(Account a) {account = a;}
};

#endif