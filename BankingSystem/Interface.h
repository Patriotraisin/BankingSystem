#ifndef Interface_h
#define Interface_h

#include <vector>
#include "User.h"
/*
 std::cout << "1: Access existing user" << std::endl;
 std::cout << "2: Add new user" << std::endl;
 std::cout << "3: Withdraw from existing user" << std::endl;
 std::cout << "4: Deposit to existing user" << std::endl;
 std::cout << "5: Delete existing user" << std::endl;
 std::cout << "6: User settings" << std::endl;
 std::cout << "7: Exit" << std::endl;
 */
enum menuChoice{ // list
    MainMenu,
    Access_User,
    Add_User,
    Withdraw_User,
    Deposit_User,
    Delete_User,
    User_Settings,
    MainMenu_Exit,
    PromptMenu,
    Display_User_Info,
    Modify_User_Info,
    PromptMenu_Exit

};

class Interface{
public:
    Interface();
    Interface(unsigned int);
    ~Interface();
    
    int returnMenuChoice() const;
    void menuFunction(int x);
    
    /*
     std::cout << "Would you like to:" << std::endl;
     std::cout << "1: Access existing user" << std::endl;
     std::cout << "2: Add new user" << std::endl;
     std::cout << "3: Withdraw from existing user" << std::endl;
     std::cout << "4: Deposit to existing user" << std::endl;
     std::cout << "5: Delete existing user" << std::endl;
     std::cout << "6: User settings" << std::endl;
     std::cout << "7: Exit" << std::endl;
     */
    void accessUser(User*);
    void addUser(unsigned int u);
    void withdrawUser(User*);
    void depositUser(User*);
    void deleteUser(User*, int);
    
     // two similar functions below.
    User* askUserInput();
    User* getUser(int ID);
    
    size_t getUserCount() const;
    int promptUserSettings() const;
    void userAction(int choice);

private:
    std::vector<User*> users;
    
};
#endif /* Interface_h */
