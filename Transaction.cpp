#include "Transaction.hpp"

#include <iostream>

void Transaction::print()
{
    std::cout << "Customer: " << customer.getName() << "    Account Number: " << customer.accountNum() << std::endl;
    std::cout << "Start Balace: " << startBalance << std::endl;
    for(auto i = exchanges.begin(); i != exchanges.end(); i++)
    {

    }
}