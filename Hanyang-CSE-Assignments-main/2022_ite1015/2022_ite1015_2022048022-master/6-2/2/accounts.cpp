#include "accounts.h"

Account::Account(){}

Account::Account(int _ID){
    this->ID = _ID;
    this->balance = 0;
    this->didD = false;
    this->didT = false;
    this->didW = false;
}

bool Account::getD(){
    return (this->didD);
}

bool Account::getT(){
    return (this->didT);
}

bool Account::getW(){
    return (this->didW);
}

int Account::getBalance(){
    return (this->balance);
}

void Account::changeBalance(int _diff){
    this->balance += _diff;
}

void Account::setD(){
    this->didD = true;
}

void Account::setT(){
    this->didT = true;
}

void Account::setW(){
    this->didW = true;
}

AccountManager::AccountManager(){
    this->count = 0;
}

void AccountManager::createAccount(int _ID){
    Account tmp(_ID);
    this->accounts[_ID] = tmp;
    this->count += 1;
}

bool AccountManager::deposit(int _ID, int _money){
    if(_ID >= this->count) return false;
    if(accounts[_ID].getD()) return false;
    if(accounts[_ID].getBalance() + _money>1000000 || accounts[_ID].getBalance() + _money<0) return false;
    accounts[_ID].changeBalance(_money);
    accounts[_ID].setD();
    return true;
}

bool AccountManager::withdraw(int _ID, int _money){
    if(_ID >= this->count) return false;
    if(accounts[_ID].getW()) return false;
    if(accounts[_ID].getBalance() - _money>1000000 || accounts[_ID].getBalance() - _money<0) return false;
    accounts[_ID].changeBalance(-1*_money);
    accounts[_ID].setW();
    return true;
}

bool AccountManager::transfer(int _ID, int _target, int _money){
    if(_ID >= this->count || _target >= this->count) return false;
    if(accounts[_ID].getT()) return false;
    if(accounts[_ID].getBalance() - _money>1000000 || accounts[_ID].getBalance() - _money<0) return false;
    if(accounts[_target].getBalance() + _money>1000000 || accounts[_target].getBalance() + _money<0) return false;
    accounts[_ID].changeBalance(-1*_money);
    accounts[_target].changeBalance(_money);
    accounts[_ID].setT();
    return true;
}

Account AccountManager::getAccount(int _ID){
    return accounts[_ID];
}
