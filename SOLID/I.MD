Interface Segregation Principle (ISP)

A class should not be forced to implement methods it does not need.

Bad Example (Violating ISP):

```cpp
class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};

class Robot : public Worker {
public:
    void work() override { cout << "Robot is working\n"; }
    void eat() override { /* Robots don’t eat! */ }
};
```
Robot is forced to implement eat(), which is irrelevant.

Fixed Approach:

```cpp
class Workable {
public:
    virtual void work() = 0;
};

class Eatable {
public:
    virtual void eat() = 0;
};

class Human : public Workable, public Eatable {
public:
    void work() override { cout << "Human is working\n"; }
    void eat() override { cout << "Human is eating\n"; }
};

class Robot : public Workable {
public:
    void work() override { cout << "Robot is working\n"; }
};
```
Now Robot is not forced to implement eat().

Another Example (C++ Banking System)
🔹 Scenario: A Banking System where different types of accounts exist:

Regular Savings Account - Can deposit, withdraw, and calculate interest.

Fixed Deposit Account - Can deposit and calculate interest, but no withdrawals allowed.

❌ Violation of ISP (Incorrect Implementation)
Here, BankAccount has a withdraw() method, which FixedDepositAccount doesn’t need.

```cpp
#include <iostream>
using namespace std;

class BankAccount {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;  // ❌ Fixed Deposit doesn't allow withdrawals
    virtual double calculateInterest() = 0;
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
public:
    void deposit(double amount) override { cout << "Depositing " << amount << " in Savings Account\n"; }
    void withdraw(double amount) override { cout << "Withdrawing " << amount << " from Savings Account\n"; }
    double calculateInterest() override { return 5.0; }  // Example interest rate
};

class FixedDepositAccount : public BankAccount {  // ❌ ISP Violation: Doesn't need withdraw()
public:
    void deposit(double amount) override { cout << "Depositing " << amount << " in Fixed Deposit Account\n"; }
    void withdraw(double amount) override { cout << "❌ Cannot withdraw from Fixed Deposit Account!\n"; }  // ❌ Unnecessary method
    double calculateInterest() override { return 7.5; }  // Higher interest rate
};

int main() {
    SavingsAccount savings;
    FixedDepositAccount fixed;

    savings.withdraw(500);  // ✅ Allowed
    fixed.withdraw(1000);   // ❌ Logically incorrect

    return 0;
}
```

✅ Correct Implementation (Follows ISP)
We split BankAccount into two specific interfaces:

Withdrawable → For accounts that allow withdrawals (e.g., SavingsAccount).

InterestBearingAccount → For accounts that calculate interest (both Savings & Fixed Deposit).

```cpp
#include <iostream>
using namespace std;

class InterestBearingAccount {
public:
    virtual void deposit(double amount) = 0;
    virtual double calculateInterest() = 0;
    virtual ~InterestBearingAccount() {}
};

class Withdrawable {
public:
    virtual void withdraw(double amount) = 0;
    virtual ~Withdrawable() {}
};

class SavingsAccount : public InterestBearingAccount, public Withdrawable {
public:
    void deposit(double amount) override { cout << "Depositing " << amount << " in Savings Account\n"; }
    void withdraw(double amount) override { cout << "Withdrawing " << amount << " from Savings Account\n"; }
    double calculateInterest() override { return 5.0; }
};

class FixedDepositAccount : public InterestBearingAccount {  // ✅ No withdraw() method
public:
    void deposit(double amount) override { cout << "Depositing " << amount << " in Fixed Deposit Account\n"; }
    double calculateInterest() override { return 7.5; }
};

int main() {
    SavingsAccount savings;
    FixedDepositAccount fixed;

    savings.withdraw(500);  // ✅ Allowed
    // fixed.withdraw(1000); // ❌ Compilation Error: No withdraw() method (which is correct)

    return 0;
}
```
