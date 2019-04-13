#include "ATM.hpp"

bool ATM::withdraw(Account* acc, int amt) {
    acc->withdraw(amt);
    cashBalance -= amt;
}
bool ATM::deposit(Account* acc, double amt) {
    acc->deposit(amt);
    cashBalance += amt;
}

double view_balance(Account* acc) {
    return acc->getBalance();
}