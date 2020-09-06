#include <stdio.h>
#include <iostream>
#include "CheckingsAccount.h"

CheckingsAccount::CheckingsAccount():chequesWritten(0){
    
}

void CheckingsAccount::displayInfo() const{ // no need for virtual keyword in cpp file only in .h file
    std::cout << "Balance: " << bal << "\n"
    << "ID: " << id << "\n"
    << "Cheques written: " << this->chequesWritten << std::endl;
}
void CheckingsAccount::writeCheck(float amount){
    withdraw(amount);
    chequesWritten++;
}

std::string CheckingsAccount::getType(){
    return "Checking account";
}

std::string CheckingsAccount::toString(){
    std::string returnValue;
    returnValue.append(Account::toString());
    returnValue.append("\nCheques written: ");
    returnValue.append(std::to_string(this->chequesWritten));
    return returnValue;
}
