#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
    private:
        long accountNum;
        double balance;
    public:
        Account(long acc_num, double bal) { accountNum = acc_num; balance = bal; }
        double getBalance() {return balance;}
        long getAcountNum() {return accountNum;}
        void deposit(double x) {balance += x;}
        void withdraw(int x) {balance -= x;}
};

#endif