#include <iostream>
#include "accounts.h"
using namespace std;

int min(int a, int b){
    if(a<b) return a;
    else return b;
}

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int main(){
    AccountManager db;
    int cnt = 0;
    while(1){
        cout << "\nJob?" << endl;
        char inst;
        cin >> inst;
        if(inst=='Q') return 0;
        if(inst=='N'){
            if(cnt<10){
                db.createAccount(cnt);
                cout << "Account for user " << cnt << " registered" << endl;
                cout << "Balance of user " << cnt << ": " << db.getAccount(cnt).getBalance() << endl;
                cnt++;
            }
            else cout << "Failure: can only make upto 10 accounts." << endl;
        }
        if(inst=='D'){
            int id, money;
            cin >> id >> money;
            if(db.deposit(id, money)){
                cout << "Success: Deposit to user " << id << " " << money << endl;
                cout << "Balance of user " << id << ": " << db.getAccount(id).getBalance() << endl;
            }
            else{
                if(id>=cnt){
                    cout << "Account does not exist" << endl;
                }
                else{
                    cout << "Failure: Deposit to user " << id << " " << money << endl;
                    cout << "Balance of user " << id << ": " << db.getAccount(id).getBalance() << endl;
                }
            }
        }
        if(inst=='W'){
            int id, money;
            cin >> id >> money;
            if(db.withdraw(id, money)){
                cout << "Success: Withdraw from user " << id << " " << money << endl;
                cout << "Balance of user " << id << ": " << db.getAccount(id).getBalance() << endl;
            }
            else{
                if(id>=cnt){
                    cout << "Account does not exist" << endl;
                }
                else{
                    cout << "Failure: Withdraw from  user " << id << " " << money << endl;
                    cout << "Balance of user " << id << ": " << db.getAccount(id).getBalance() << endl;
                }
            }
        }
        if(inst=='T'){
            int id, target, money;
            cin >> id >> target >> money;
            if(db.transfer(id,target, money)){
                cout << "Success: Transfer from user " << id << " to  " << "user " << target << " " << money << endl;
                cout << "Balance of user " << min(id,target) << ": " << db.getAccount(min(id,target)).getBalance() << endl;
                cout << "Balance of user " << max(id,target) << ": " << db.getAccount(max(id,target)).getBalance() << endl;
            }
            else{
                if(id>=cnt || target>=cnt){
                    cout << "Account does not exist" << endl;
                }
                else{
                    cout << "Failure: Transfer from user " << id << " to  " << "user " << target << " " << money << endl;
                    cout << "Balance of user " << id << ": " << db.getAccount(id).getBalance() << endl;
                    cout << "Balance of user " << target << ": " << db.getAccount(target).getBalance() << endl;
                }
            }
        }
    }
}
            
