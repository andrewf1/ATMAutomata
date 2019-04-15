#ifndef ATM_HPP
#define ATM_HPP

#include "Customer.hpp"

#include <map>

class ATM {
public:
    ATM() = default;
    ~ATM() = default;
    void start();
    void fillCustomers();
    void printMenu();
    void executeTransactions();
    long verifyAccount();
    bool verifyPin(long);
    bool withdraw(Account* acc, int amt);
    bool deposit(Account* acc, double amt);
    double view_balance(Account* acc);
private:
    std::map<long, Customer> customers;
    double cashBalance = 100000;
    bool final = false;
};

#endif