# Virtual Functions

A virtual function in C++ is a member function in a base class that you expect to be overridden in derived classes. It allows runtime polymorphism, meaning that the function that gets called is determined at runtime based on the actual type of the object, not the pointer type.

## Key Points about Virtual Functions

- Declared in the base class using the `virtual` keyword.
- Allows dynamic dispatch, meaning the function call is resolved at runtime.
- Supports function overriding in the derived class.
- A base class pointer calling a virtual function will execute the derived class function.
- If a class has a virtual function, it maintains a vtable (Virtual Table) for function resolution.
- If a virtual function is not overridden in the derived class, the base class version is used.
- Virtual functions should always have a virtual destructor to ensure proper cleanup of derived objects.

## Example of Virtual Functions

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { // Virtual function
        cout << "Base class show() function" << endl;
    }
    virtual ~Base() { // Virtual destructor
        cout << "Base destructor called" << endl;
    }
};

class Derived : public Base {
public:
    void show() override { // Overriding the virtual function
        cout << "Derived class show() function" << endl;
    }
    ~Derived() {
        cout << "Derived destructor called" << endl;
    }
};

int main() {
    Base* ptr;
    Derived d;
    ptr = &d;

    ptr->show(); // Calls Derived class function due to virtual function (Runtime Polymorphism)

    return 0;
}
```

**Output:**

```
Derived class show() function
Derived destructor called
Base destructor called
```

Since `show()` is virtual, the function from `Derived` is called instead of `Base`.

## What Does "Function Call is Determined at Runtime Based on the Actual Type of the Object, Not the Pointer Type" Mean?

In C++, when we use inheritance, we often work with base class pointers or references to call functions of derived classes. Normally, without virtual functions, function calls are resolved at compile-time based on the pointer type. However, if a function is declared as virtual, the function that gets executed is decided at runtime based on the actual type of the object (not the pointer type).

### Example Without Virtual Function (Compile-Time Binding)

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void show() { // No virtual keyword
        cout << "Base class show() function" << endl;
    }
};

class Derived : public Base {
public:
    void show() { // Function Overriding
        cout << "Derived class show() function" << endl;
    }
};

int main() {
    Base* ptr; // Base class pointer
    Derived d;
    ptr = &d;  // Pointer of Base class pointing to Derived object

    ptr->show(); // Calls Base class function (Compile-Time Binding)

    return 0;
}
```

**Output:**

```
Base class show() function
```

**Explanation:**

The function call `ptr->show();` is resolved at compile-time. Since `ptr` is a Base class pointer, it calls `Base::show()`, even though it actually points to a `Derived` object. This is known as early binding (compile-time binding).

### Example With Virtual Function (Runtime Polymorphism)

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { // Virtual function
        cout << "Base class show() function" << endl;
    }
};

class Derived : public Base {
public:
    void show() override { // Function overriding
        cout << "Derived class show() function" << endl;
    }
};

int main() {
    Base* ptr; // Base class pointer
    Derived d;
    ptr = &d;  // Pointer of Base class pointing to Derived object

    ptr->show(); // Calls Derived class function (Runtime Polymorphism)

    return 0;
}
```

**Output:**

```
Derived class show() function
```

**Explanation:**

`show()` is declared virtual in `Base`, so function calls are resolved at runtime. Even though `ptr` is a Base class pointer, it actually points to a `Derived` object. Since `show()` is virtual, the `Derived` class function gets executed at runtime. This is known as late binding (runtime polymorphism).

## Key Takeaway

- Without virtual functions: The function is determined at compile-time, based on the pointer type.
- With virtual functions: The function is determined at runtime, based on the actual object type.