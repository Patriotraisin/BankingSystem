#include <stdio.h>
#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingsAccount.h"

// account

int Account::currentID = 0; // still need to implement variable (like function), hence int

Account::Account(){
    this->bal = 0;
    this->id = ++Account::currentID;
}

Account::~Account(){
    //nothing
}

int Account::getID(){
    return id;
}
void Account::deposit(float a){
    this->bal += a;
}
void Account::withdraw(float a){
    this->bal -= a;
}
float Account::balance(){
    return bal;
}

std::string Account::toString(){ // inherited by checkings/savingsaccount
    std::string returnValue;
    // returns id
    returnValue.append("ID: ");
    returnValue.append(std::to_string(this->getID()));
    // returns type
    returnValue.append("\nType: ");
    returnValue.append(this->getType());
    // returns balance
    returnValue.append("\nBalance: ");
    returnValue.append(std::to_string(this->balance()));

    return returnValue;
}


