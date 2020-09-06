#ifndef Account_h
#define Account_h

#include <string>
#include <vector>

class Account{
protected:
    static int currentID;
    int id;
    float bal;
    
public:
    Account();
    virtual ~Account();
    
    virtual void displayInfo() const = 0;
    void deposit(float a);
    void withdraw(float a);
    float balance();
    int getID();
    virtual std::string toString();
    virtual std::string getType() = 0;
};

#endif /* Account_h */
