D - Dependency Inversion Principle (DIP)

High-level modules should not depend on low-level modules.

Bad Example (Violating DIP):

```cpp
class Keyboard {
public:
    void input() { cout << "Keyboard Input\n"; }
};

class Computer {
private:
    Keyboard keyboard;  // Tight coupling
public:
    void useKeyboard() { keyboard.input(); }
};
```
Here, Computer is tightly coupled with Keyboard.

Fixed Approach (Following DIP - Using Abstraction):

```cpp
class InputDevice {
public:
    virtual void input() = 0;
};

class Keyboard : public InputDevice {
public:
    void input() override { cout << "Keyboard Input\n"; }
};

class Computer {
private:
    InputDevice* device;
public:
    Computer(InputDevice* d) : device(d) {}
    void useInput() { device->input(); }
};
```
Now Computer depends on abstraction, making it flexible.

Dependency Inversion Principle (DIP) in C++

🔹 Definition: High-level modules should not depend on low-level modules. Both should depend on abstractions.
🔹 Problem: If high-level modules directly depend on low-level modules, code becomes rigid and hard to modify.
🔹 Solution: Use interfaces (abstract classes) to decouple dependencies.

❌ Violation of DIP (Incorrect Implementation)
Here, OrderProcessor directly depends on CreditCardPayment, making it tightly coupled.
If we want to add PayPal or another payment method, we must modify OrderProcessor (bad design).

```cpp
#include <iostream>
using namespace std;

class CreditCardPayment {
public:
    void pay(int amount) { cout << "Paid " << amount << " using Credit Card\n"; }
};

class OrderProcessor {
private:
    CreditCardPayment paymentProcessor;  // ❌ Direct dependency on a concrete class
public:
    void processOrder(int amount) {
        paymentProcessor.pay(amount);  // ❌ Hardcoded to Credit Card
    }
};

int main() {
    OrderProcessor order;
    order.processOrder(500);  // ❌ Can't switch to PayPal easily

    return 0;
}
```

✅ Correct Implementation (Follows DIP)
Instead of directly depending on CreditCardPayment, we introduce a PaymentMethod interface.
Now, OrderProcessor is decoupled and works with any payment method (e.g., PayPal, Credit Card, UPI, etc.).

```cpp
#include <iostream>
using namespace std;

class PaymentMethod {  // ✅ Abstract interface (Dependency Inversion)
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCardPayment : public PaymentMethod {
public:
    void pay(int amount) override { cout << "Paid " << amount << " using Credit Card\n"; }
};

class PayPalPayment : public PaymentMethod {
public:
    void pay(int amount) override { cout << "Paid " << amount << " using PayPal\n"; }
};

class OrderProcessor {
private:
    PaymentMethod* paymentProcessor;  // ✅ Depends on abstraction, not a concrete class
public:
    OrderProcessor(PaymentMethod* payment) : paymentProcessor(payment) {}

    void processOrder(int amount) {
        paymentProcessor->pay(amount);  // ✅ Can work with any payment method
    }
};

int main() {
    CreditCardPayment cc;
    PayPalPayment paypal;

    OrderProcessor order1(&cc);
    OrderProcessor order2(&paypal);

    order1.processOrder(500);  // ✅ Works with Credit Card
    order2.processOrder(700);  // ✅ Works with PayPal

    return 0;
}
```
