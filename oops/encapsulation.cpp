#include <bits/stdc++.h>
using namespace std;

class BankAccount {
    private:
        double balance;
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

