# Friend Functions

A friend function in C++ is a function that is not a member of a class but has access to its private and protected members. It is useful when we need external functions to access private data.

## Key Points about Friend Functions:
- Declared using the keyword `friend` inside the class.
- Can be a standalone function or a friend function of multiple classes.
- Not inherited by derived classes.
- Can be useful for operator overloading (e.g., `<<` and `>>` operators for `cout` and `cin`).

## Example of Friend Function

```cpp
#include <iostream>
using namespace std;

class Sample {
private:
    int data;
public:
    Sample(int d) : data(d) {}

    // Declaring friend function
    friend void showData(Sample obj);
};

void showData(Sample obj) { // Friend function definition
    cout << "Private Data: " << obj.data << endl;
}

int main() {
    Sample s(100);
    showData(s); // Friend function can access private members

    return 0;
}
```

**Output:**

```
Private Data: 100
```

## Comparison: Virtual Functions vs Friend Functions

| Feature       | Virtual Function                  | Friend Function                                   |
|---------------|-----------------------------------|--------------------------------------------------|
| Purpose       | Achieves runtime polymorphism     | Allows external function access to private members|
| Declared in   | Base class (as virtual)           | Inside class using `friend` keyword               |
| Overridable?  | Yes (in derived class)            | No (it's not a member function)                   |
| Access Specifier | Can be public, protected, or private | Must be declared inside the class (but not a member) |
| Inheritance   | Yes (inherited and overridden)    | No (not inherited)                                |
| Usage         | Implementing dynamic polymorphism | Operator overloading, private data access         |
