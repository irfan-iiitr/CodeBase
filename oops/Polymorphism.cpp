//Polymorphism allows methods to have different behaviors based on the object that calls them. 
// It is achieved through function overloading and function overriding.


// Function Over rinding is a type of polymorphism in which a derived class has a definition for one of
// the member functions of the base class.
// This definition is used whenever an object of the derived class calls the function.

// Compile-time Polymorphism (Function Overloading)


// #include <iostream>
// using namespace std;

// class Math {
// public:
//     int add(int a, int b) { return a + b; }
//     double add(double a, double b) { return a + b; } // Function overloading
// };

// int main() {
//     Math m;
//     cout << m.add(2, 3) << endl;      // Calls int version
//     cout << m.add(2.5, 3.5) << endl;  // Calls double version
// }


// Runtime Polymorphism (Function Overriding)

#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { cout << "Base class show()" << endl; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived class show()" << endl; } // Function overriding
};

// int main() {
//     Base* b = new Derived();
//     b->show();  // Calls Derived class method due to virtual function
//     delete b;
// }

//  b->Base::show();  // Calls Base class's show() explicitly

// Here, even though b is a pointer to Base, the derived class’s show() is called because of runtime polymorphism.

int main(){
    Derived d;
    d.show(); // Derived class show()
    delete &d;
    return 0;
}

// int main() {
//     Base* b = new Derived();  // Dynamically allocating Derived object, storing in Base pointer
//     b->show();  // Calls Derived's show() method due to virtual function (if show() is virtual)
//     delete b;  // Properly deletes the object, calls Derived's destructor first if Base has a virtual destructor
// }

// Base* b = new Derived(); involves two memory allocations—one on the heap and one on the stack.
// The pointer b is stored on the stack.
// The Derived object is stored on the heap.

// int main(){
//     Derived d;  // Object created on stack, (automatically destroyed )at end of scope
//     d.show();  // Calls Derived's show() method (no polymorphism needed)
//     delete &d;  // ❌ ERROR: Undefined behavior! 'd' was allocated on the stack, so delete should NOT be used.
//     return 0;
// }




