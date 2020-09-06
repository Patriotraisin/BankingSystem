#include <stdio.h>
#include <iostream>
#include "Interface.h"

Interface::Interface(){
}

Interface::~Interface(){
    for (std::vector<User*>::iterator user = users.begin(); user != users.end(); ++user){
        // account is the name of the variable of type iterator
        // iterator account points to address of an element
        // * dereferences the address so we can delete
        delete (*user); // goes through every element in the accounts vector and deletes it
    }
}

int Interface::returnMenuChoice() const{
    int choice = 0;
    while ((choice < Access_User)||(choice> MainMenu_Exit)){
        std::cout << "Would you like to:" << std::endl;
        std::cout << "1: Access existing user" << std::endl;
        std::cout << "2: Add new user" << std::endl;
        std::cout << "3: Withdraw from existing user" << std::endl;
        std::cout << "4: Deposit to existing user" << std::endl;
        std::cout << "5: Delete existing user" << std::endl;
        std::cout << "6: User settings" << std::endl;
        std::cout << "7: Exit" << std::endl;
        std::cin>>choice;
        choice+=MainMenu;
        if (!((choice >= Access_User) && (choice <= MainMenu_Exit))){
            std::cout << "Bad input.";
            }
    }
    return choice;
}

void Interface::menuFunction(int x){
    switch (x){
        case Access_User:
            break;
        case Add_User:
            addUser(1);
            break;
        case Withdraw_User:
            withdrawUser(askUserInput());
            break;
        case Deposit_User:
            depositUser(askUserInput());
            break;
        case Delete_User:
            break;
        case User_Settings:
            userAction(promptUserSettings());
            break;
        default:
            break;
    }

}

void Interface::accessUser(User* user){
    //
}
void Interface::withdrawUser(User* user){
    int acc = 0;
    float amount = 0;
    std::cout << "Input amount you want to withdraw from user " << user->fName << " " << user->lName << "." << std::endl;
    std::cin >> amount;
    user->withdrawAccount(user->getAccount(acc)->getID(), amount);
}
void Interface::depositUser(User* user){
    int acc = 0;
    float amount = 0;
    std::cout << "Input amount you want to deposit for user " << user->fName << " " << user->lName << "." << std::endl;
    std::cin >> amount;
    user->depositAccount(user->getAccount(acc)->getID(), amount);
}


void Interface::deleteUser(User* user, int userID){
    if(user->userID == userID){
        //delete user*;
    }
    else{
        throw "Not a valid user.";
    }
}

void Interface::addUser(unsigned int u){
    for (int x = 0; x != u; ++x){
        users.push_back(new User("John", "Doe", (int)getUserCount() ));
    }
}

size_t Interface::getUserCount() const{ // size_t used with vectors, templated type set by OS
    return users.size();
}

int Interface::promptUserSettings() const{
    int input = 0;
    while ((input< Display_User_Info) || (input > PromptMenu_Exit)){
        std::cout << "1. Display user info\n" << "2. Modify user info\n" << "3. Exit" << std::endl;
        std::cin >> input;
        input+=PromptMenu;
        if (!((input <= PromptMenu_Exit) && (input >= Display_User_Info))){
            std::cout << ("Input does not lie within 1 and 3. Invalid input");
        }
    }
    return input;
}

void Interface::userAction(int choice){ // 6 in the main ting
    switch(choice){
        case Display_User_Info:
            
            break;
        case Modify_User_Info:
            
            break;
        case PromptMenu_Exit:
            
            break;
        default: // error.
            std::cout << "something went horribly wrong." << std::endl;
            break;
    }
}

User* Interface::getUser(int ID){ // cannot be made into const, users.begin() function creates an iterator, qualifies as a modification of state
    //return users[ID];
    for (std::vector<User*>::iterator user = users.begin(); user != users.end(); ++user){
        if ((*user)->userID == ID){
            return *user;
        }
    }
    throw ("not a valid user in the database");
}


User* Interface::askUserInput(){ // cannot be made into const, users.begin() function creates an iterator, qualifies as a modification of state
    //return users[ID];
    int ID;
    std::cout << "Input user ID." << std::endl;
    std::cin >> ID;
    for (std::vector<User*>::iterator user = users.begin(); user != users.end(); ++user){
        if ((*user)->userID == ID){
            return *user;
        }
    }
    throw ("not a valid user in the database");
}



