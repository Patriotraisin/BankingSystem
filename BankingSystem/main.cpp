#include <iostream>
#include "User.h"
#include "SavingsAccount.h"
#include "Interface.h"
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // while the session exists
    // loop menu
    //     1. allow add user
    //     2. access specific user
    //     3. allow to get info or to modify accounts inside.
    Interface interface;
    int menuChoice = 0;
    while (true){ //
        menuChoice = interface.returnMenuChoice(); // takes user input
        if (menuChoice == MainMenu_Exit){ // if you choose to exit
            break; // breaks the loop
        }
        interface.menuFunction(menuChoice); // menu function
    }
    return 0;
}


