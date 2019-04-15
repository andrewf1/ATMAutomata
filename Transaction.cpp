#include "Transaction.hpp"

#include <iostream>
#include <iomanip>

void Transaction::print()
{
    std::cout << "Customer: " << customer.getName() << "    Account Number: " << customer.accountNum() << std::endl;
    std::cout << "Start Balace: " << startBalance << std::endl;
    std::cout << std::setprecision(2);
    for(auto it = exchanges.begin(); it != exchanges.end(); it++)
    {
        std::cout << '\t' << it->first << ' ' << it->second << std::endl;
    }
    std::cout << "End Balance: " << currentBalance << std::endl;
}

void Transaction::editTran(char operand, double amount)
{
    if(operand == '-') currentBalance -= amount;
    else currentBalance += amount;
    std::pair<char, double> temp(operand, amount);
    exchanges.push_back(temp);
}