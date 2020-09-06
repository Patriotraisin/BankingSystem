#ifndef CheckingsAccount_h
#define CheckingsAccount_h

#include "Account.h"
#include "User.h"

class CheckingsAccount : public Account{
public:
    CheckingsAccount(); // unless u hv factory class or singleton then keep constructor public
    int chequesWritten;
    
    virtual void displayInfo() const;
    void writeCheck(float amount);
    virtual std::string getType();
    std::string toString();
};


#endif /* CheckingsAccount_h */
