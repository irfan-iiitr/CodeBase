#include <iostream>
using namespace std;

class BankAccount {
    private:
        double balance; //data security - cant access balance directly
    public:

    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds" << endl;
        }
    }

    double getBalance() {
        return balance;
    }

};

int main() {
    BankAccount myAccount(1000);
    myAccount.deposit(500);
    myAccount.withdraw(200);
    cout << myAccount.getBalance() << endl; // // Encapsulation ensures safe access to the class members
    return 0;
}


// Here, balance is private and can only be accessed via public methods, ensuring data security.

// Encapsulation is the technique of making the fields in a class private and
// providing access to the fields via public methods. It's a protective barrier that keeps the data safe within the class and
// prevents the data from being modified by external classes or methods.

// BankAccount myAccount(1000); whas the fddiffrence wbtween BankAccount* acc= new BANKACCOUNT(1000) .

// The difference is in object creation and memory management:

// BankAccount myAccount(1000);
// Creates an object on the stack.
// Memory is managed automatically; object is destroyed when it goes out of scope.
// No need to manually delete.
// BankAccount* acc = new BankAccount(1000);
// Creates an object on the heap using new.
// You must manually delete it with delete acc; to avoid memory leaks.
// Useful if you need the object to outlive the current scope or share it.