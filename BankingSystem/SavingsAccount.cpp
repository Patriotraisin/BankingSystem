#include <stdio.h>
#include <iostream>
#include "SavingsAccount.h"


SavingsAccount::SavingsAccount():interest(DEFAULT_INTEREST){ // sets to what is defined in savingsaccount.h (atm 1.25f)
    
}

void SavingsAccount::displayInfo() const{
    std::cout << "Balance: " << bal << "\n"
    << "ID: " << id << "\n"
    << "Interest rate: " << interest << std::endl;
}

void SavingsAccount::setInterest(float f){
    interest = f;
}

float SavingsAccount::calculateInterest (){
    float interestAccrued = interest * bal;
    return interestAccrued;
}

std::string SavingsAccount::getType(){
    return "Savings account";
}

std::string SavingsAccount::toString(){
    std::string returnValue;
    returnValue.append(Account::toString());
    returnValue.append("\nInterest Rate: ");
    returnValue.append(std::to_string(this->interest));
    return returnValue;
}
