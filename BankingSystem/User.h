#ifndef User_h
#define User_h

#include <string>
#include <vector>
#include "Account.h"


// must template whole class / function
class User{
public:
    std::string fName;
    const std::string lName;
    int userID;
    int accountcount;
    User(std::string, std::string, int);
    ~User(); // destructor
    void addAccount(int);
    Account* getAccount(int);
    void depositAccount(int, float);
    void withdrawAccount(int, float);
    std::vector<Account*> getAccountVector();
//private:
    std::vector<Account*> accounts; // so no one can access
};

#endif /* User_h */
