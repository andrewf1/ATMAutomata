#ifndef ATM_HPP
#define ATM_HPP

#include "Account.hpp"

class ATM {
public:
    ATM() = default;
    ~ATM() = default;
    bool withdraw(Account* acc, int amt);
    bool deposit(Account* acc, double amt);
    double view_balance(Account* acc);
private:
    double cashBalance = 100000;
    bool final = false;
};

#endif