// Abstraction hides complex implementation details and only exposes the necessary functionalities to the user.
// It is achieved using classes and abstract classes.

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw(){ //virtual keyword is used to make the function virtual
        // virtual functions are used to create a list of base class pointers and call methods of derived classes through them
        cout << "Drawing a Shape" << endl;
    } // Pure virtual function (Abstract class)
};

class Circle :public Shape { //: public is necessary here to inherit the draw() function 
    // if not public- error: 'Shape' is an inaccessible base of 'Circle' .. to make Circle publicly inherit from Shape
public:
    void draw() override {  // override keyword is used to ensure that the function is actually overriding a function in the base class
        cout << "Drawing a Circle" << endl;
    }
};

int main() {
    Shape* s = new Circle();
    s->draw();  // Only necessary functionality is exposed
    delete s;
}

// Output -> Drawing a Circle


// The user does not need to know how draw() is implemented—only that it exists.

