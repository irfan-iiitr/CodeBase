Liskov Substitution Principle (LSP)

Subtypes should be substitutable for their base types without altering behavior.
The Liskov Substitution Principle (LSP) states that objects of a derived class should be able to replace objects of the base class without affecting the correctness of the program.

Bad Example (Violating LSP):

```cpp

class Bird {
public:
    virtual void fly() { cout << "Bird is flying\n"; }
};

class Penguin : public Bird {
public:
    void fly() override { cout << "Penguins can't fly!\n"; }
};


Here, a Penguin is a Bird, but overriding fly() with different behavior violates LSP.

Fixed Approach: Instead of forcing a fly() method, we separate behavior:

class Bird {};
class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird {
public:
    void fly() override { cout << "Sparrow is flying\n"; }
};

class Penguin : public Bird {};  // No fly() method

```

Now Penguin does not have an unnecessary fly() method.



❌ Violation of LSP (Incorrect Implementation)

```cpp

#include <iostream>
using namespace std;

class Rectangle {
protected:
    int width, height;
public:
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }

    int getArea() const { return width * height; }
};

class Square : public Rectangle {  // ❌ Violates LSP
public:
    void setWidth(int w) override { width = height = w; }   // ❌ Unexpected behavior
    void setHeight(int h) override { width = height = h; }  // ❌ Unexpected behavior
};

void printArea(Rectangle& r) {
    r.setWidth(4);
    r.setHeight(5);
    cout << "Area: " << r.getArea() << endl;
}

int main() {
    Rectangle rect;
    Square sq;

    printArea(rect);  // ✅ Output: Area: 20 (4 * 5)
    printArea(sq);    // ❌ Unexpected Output: Area: 25 (5 * 5) instead of 4 * 5

    return 0;
}

```
❌ Why is this Wrong?
printArea(Rectangle&) expects a rectangle where width and height can be set independently.

When Square is used as a Rectangle, setting width to 4 and height to 5 does not work correctly (because Square forces them to be equal).

LSP is violated because Square does not behave like a Rectangle.



✅ Correct Implementation (Follows LSP)
Instead of making Square inherit from Rectangle, we separate them into different classes.

```cpp

class Shape {
public:
    virtual int getArea() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
protected:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int getArea() const override { return width * height; }
};

class Square : public Shape {
protected:
    int side;
public:
    Square(int s) : side(s) {}
    int getArea() const override { return side * side; }
};

void printArea(Shape& s) {
    cout << "Area: " << s.getArea() << endl;
}

int main() {
    Rectangle rect(4, 5);
    Square sq(5);

    printArea(rect);  // ✅ Output: Area: 20
    printArea(sq);    // ✅ Output: Area: 25

    return 0;
}


```


