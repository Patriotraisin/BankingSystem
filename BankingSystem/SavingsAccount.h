#ifndef SavingsAccount_h
#define SavingsAccount_h
#define DEFAULT_INTEREST 1.25f

#include "Account.h"
#include "User.h"

class SavingsAccount : public Account{
public:
    SavingsAccount();
    float interest;
    
    virtual void displayInfo() const;
    void setInterest(float);
    float calculateInterest ();
    virtual std::string getType();
    std::string toString();
    
};

#endif /* SavingsAccount_h */
