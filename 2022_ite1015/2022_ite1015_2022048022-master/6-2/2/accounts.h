#pragma once

class Account{
    private:
        int ID;
        int balance;
        bool didD;
        bool didT;
        bool didW;

    public:
        Account();
        int getBalance();
        bool getD();
        bool getT();
        bool getW();
        void changeBalance(int _diff);
        void setD();
        void setT();
        void setW();
        Account(int _ID);
};

class AccountManager{
    public:
        AccountManager();
    private:
        Account accounts[10];
        int count; //number of accounts made
    public:
        void createAccount(int _ID);
        bool deposit(int _ID, int _money);
        bool withdraw(int _ID, int _money);
        bool transfer(int _ID, int _target, int _money);
        Account getAccount(int _ID);
};

