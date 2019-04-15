#include "Account.hpp"
#include "Transaction.hpp"
#include "ATM.hpp"

#include <iostream>
#include <iomanip>

void ATM::fillCustomers()
{
    std::cout << "inside fillCustomers()" << std::endl;
    Account acc(123456789, 25.00);
    Customer cust("Michael", "Scott", 1234, acc);
    std::pair<long, Customer> temp(cust.accountNum(), cust);
    customers.insert(temp);

    Account acc2(987654321, 500.82);
    Customer cust2("Dwight", "Schrute", 4321, acc2);
    std::pair<long, Customer> temp2(cust2.accountNum(), cust2);
    customers.insert(temp2);

    Account acc3(123459876, 10256.24);
    Customer cust3("Oscar", "Martinez", 9512, acc3);
    std::pair<long, Customer> temp3(cust3.accountNum(), cust3);
    customers.insert(temp3);

    Account acc4(987651234, 256.24);
    Customer cust4("Kelly", "Kapur", 1478, acc4);
    std::pair<long, Customer> temp4(cust4.accountNum(), cust4);
    customers.insert(temp4);

    Account acc5(715932468, 102.77);
    Customer cust5("Stanley", "Hudson", 2468, acc5);
    std::pair<long, Customer> temp5(cust5.accountNum(), cust5);
    customers.insert(temp5);
}

void ATM::printMenu()
{
    std::cout << "1. View Balance" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. Deposit" << std::endl;
}

bool ATM::verifyPin(long accountNum)
{
    int pin;
    int count = 0;
    while(true)
    {
        std::cout << "Enter Pin Number" << std::endl;
        std::cin >> pin;
        if(customers[accountNum].verifyPin(pin)) return true;
        else
        {
            count++;
            std::cout << "Wrong PIN" << std::endl;
            if(count == 3)
            {
                std::cout << "No more attempts. Returning to begining." << std::endl;
                return false;
            }
            else
            {
                std::cout << "Attempt " << count+1 << " of 3" << std::endl;
            }   
        }
    }
}

long ATM::verifyAccount()
{
    std::cout << "Enter account number:" << std::endl;
    long accountNum;
    std::cin >> accountNum;
    int count = 1;
    while(count < 3)
    {
        if(customers.find(accountNum) != customers.end()) break;
        if(std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        std::cout << "Doesn't match any account number. Please try again." << std::endl;
        std::cin >> accountNum;
        count++;
    }
    if(count == 3) return -1;
    else return accountNum;
}

void ATM::withdraw(Account* acc, int amt) {
    acc->withdraw(amt);
    cashBalance -= amt;
}

void ATM::deposit(Account* acc, double amt) {
    acc->deposit(amt);
    cashBalance += amt;
}

double ATM::view_balance(Account* acc) {
    return acc->getBalance();
}

void ATM::start()
{
    fillCustomers();
    while(true)
    {
        std::cout << "1. Make transaction" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "Choose one:" << std::endl;
        int action;
        std::cin >> action;
        if(action == 2) return;
        long accountNum = verifyAccount();
        if(accountNum == -1) continue;
        if(!verifyPin(accountNum)) continue;
        Transaction t(customers[accountNum]);
        // Bad variable name
        bool tBool = true;
        while(tBool)
        {
            printMenu();
            std::cin >> action;
            int amount;
            switch(action)
            {
                case 1:
{                    double tempBal = view_balance(customers[accountNum].getAccount());
                    std::cout << "Current Balance: $" << std::setprecision(2) << std::fixed << tempBal << std::endl;
                    break;}
                case 2:
{                    std::cout << "Enter Amount: " << std::endl;
                    std::cin >> amount;
                    std::cout << "Dispensing..." << std::endl;
                    if(amount > customers[accountNum].accountBalance())
                    {
                        std::cout << "Insufficient Funds" << std::endl;
                        break;
                    }
                    if(amount % 10 != 0)
                    {
                        std::cout << "Can only dispense $10 or higher bills" << std::endl;
                        break;
                    } 
                    withdraw(customers[accountNum].getAccount(), amount);
                    t.editTran('+', amount);
                    break;}
                case 3:
{                    std::cout << "Enter Amount: " << std::endl;
                    std::cin >> amount;
                    std::cout << "Depositing..." << std::endl;
                    deposit(customers[accountNum].getAccount(), amount);
                    t.editTran('-', amount);
                    break;}
            }
            std::cout << "Finished? (y/n)" << std::endl;
            char yesOrNo;
            std::cin >> yesOrNo;
            if(yesOrNo == 'y') tBool = false;
        }
        t.print();
    }
}