// Inheritance allows a class to acquire properties and behavior from another class.
// This helps in code reuse and hierarchical structuring.

// Does c++ allow multiple inheritance?
// Yes, C++ allows multiple inheritance. A class can inherit
// from more than one class. For example, class C can inherit from class A and class
// B. This is called multiple inheritance. However, it is not recommended to use multiple


#include <iostream>
using namespace std;

class A {
public:
    void displayA() {
        cout << "Class A function" << endl;
    }
};

class B {
public:
    void displayB() {
        cout << "Class B function" << endl;
    }
};

// Multiple Inheritance: C inherits from both A and B
class C : public A, public B {
public:
    void displayC() {
        cout << "Class C function" << endl;
    }
};

class D:public A{
   
};

int main() {
    C obj;
    obj.displayA();  // Inherited from A // Class A function
    obj.displayB();  // Inherited from B // Class B function
    obj.displayC();  // Own function // Class C function
    D obj1; 
    obj1.displayA(); //Class A function
    return 0;
}

//Challenges with Multiple Inheritance


// 1. Diamond Problem
//If two base classes inherit from the same parent and a derived class inherits from both, ambiguity arises when calling the grandparent's method.

class A {
    public:
        void show() {
            cout << "Class A" << endl;
        }
    
};
    
    class B : public A { };
    class C : public A { };
    
    class D : public B, public C { };
    
    int main() {
        D obj;
        obj.show();  // ❌ ERROR: Ambiguous, which 'show' to call?
        return 0;
    }
// Solution: Use virtual inheritance to ensure only one copy of A is inherited.

class A {
    public:
        void show() {
            cout << "Class A" << endl;
        }
    };
    
    class B : virtual public A { };
    class C : virtual public A { };
    
    class D : public B, public C { };
    
    int main() {
        D obj;
        obj.show();  // ✅ No ambiguity
        return 0;
    }

 // 2. Conflicting Method Names
// If two base classes have methods with the same name, ambiguity occurs.


class A {
    public:
        void greet() { cout << "Hello from A" << endl; }
    };
    
    class B {
    public:
        void greet() { cout << "Hello from B" << endl; }
    };
    
    class C : public A, public B {
    };
    
    int main() {
        C obj;
       // obj.greet();  // ❌ ERROR: Ambiguous, A::greet or B::greet?
        return 0;
    }

  //  Solution: Explicitly specify which method to call.
    int main() {
        C obj;
        obj.A::greet();  // ✅ Calls greet from A
        obj.B::greet();  // ✅ Calls greet from B
        return 0;
    }
        

    





