#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
    private:
        long accountNum;
        double balance;

    public:
        double getBalance() {return balance;}
        void deposit(double x) {balance += x;}
        void withdraw(int x) {balance -= x;}
};

#endif