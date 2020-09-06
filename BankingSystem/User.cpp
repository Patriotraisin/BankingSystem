#include <stdio.h>
#include <iostream>
#include "User.h"
#include "SavingsAccount.h"
#include "CheckingsAccount.h"
#include "Account.h"


// users

User::User(std::string f, std::string l, int u):fName(f),lName(l){
    userID = u;
}

User::~User(){
    for (std::vector<Account*>::iterator account = accounts.begin(); account != accounts.end(); ++account){
        // account is the name of the variable of type iterator
        // iterator account points to address of an element
        // * dereferences the address so we can delete
        delete (*account); // goes through every element in the accounts vector and deletes it
    }
}
void User::addAccount(int type){
    switch (type){
        case 1:
            accounts.push_back(new CheckingsAccount());
            break;
        case 2:
            accounts.push_back(new SavingsAccount());
            break;
        default:
            break;
    }
    accountcount+=1;
}

Account* User::getAccount(int x){
    for (std::vector<Account*>::iterator account = accounts.begin(); account != accounts.end(); ++account){
        if ((*account)->getID() == x){
            return *account;
        }
    }
    throw ("not a valid account type on this user");
}

void User::depositAccount(int account, float x){
    getAccount(account)->deposit(x);
}
void User::withdrawAccount(int account, float x){
    getAccount(account)->withdraw(x);
}

std::vector<Account*> User::getAccountVector(){
    return accounts;
}

