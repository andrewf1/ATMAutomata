#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include "Customer.hpp"

#include <vector>

class Transaction 
{ //has info for reciept
    public:
        Transaction(Customer c) {customer = c; startBalance = customer.accountBalance(); currentBalance = startBalance;}
        void editTran(char, double);
        void print();

    private:
        Customer customer;
        double startBalance, currentBalance;
        std::vector<std::pair<char, double>> exchanges;

};

#endif