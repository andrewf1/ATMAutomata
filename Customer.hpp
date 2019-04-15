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
        Customer() = default;
        Customer(std::string f, std::string l, int pin, Account acc) {fname = f; lname = l; pinNum = pin; account = acc;} 
        std::string getName() {return fname + ' ' + lname;}
        Account* getAccount() {return &account;}
        bool verifyPin(int num) {if(num == pinNum) return true; else return false;}
        double accountBalance() { return account.getBalance();}
        long accountNum() {return account.getAcountNum();}
        void setAccount(Account a) {account = a;}
};


#endif