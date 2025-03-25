Open/Closed Principle (OCP)

Classes should be open for extension but closed for modification.

Bad Example (Violating OCP):

```cpp
class Rectangle {
public:
    void draw() { cout << "Drawing Rectangle\n"; }
};

class Circle {
public:
    void draw() { cout << "Drawing Circle\n"; }
};

void drawShape(Rectangle r) { r.draw(); }
void drawShape(Circle c) { c.draw(); }
```

Adding a new shape requires modifying drawShape(), violating OCP.

Fixed (Following OCP - Using Polymorphism):

```cpp
class Shape {
public:
    virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
    void draw() override { cout << "Drawing Rectangle\n"; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing Circle\n"; }
};

void drawShape(Shape* shape) { shape->draw(); }
```

Now, adding a new shape does not require modifying existing code.

The reason we define draw() as a pure virtual function (= 0) in the Shape class and override it in derived classes is to enforce polymorphism. This ensures that every shape must implement its own draw() function.

If we do not define draw() in Shape and only define it in Rectangle and Circle, we lose polymorphism. This means we cannot write a function like:

```cpp
void drawShape(Shape* shape) { shape->draw(); }  // Won't work if Shape has no draw()
```

Since Shape does not define draw(), the compiler does not know that Shape objects (or derived objects) should have a draw() method. Thus, shape->draw(); will result in a compilation error.

```cpp
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
};
```

Forces all derived classes to implement draw() (ensures consistency).

✅ Example with Pure Virtual Function (Polymorphism Works)

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function (forces override)
};

class Rectangle : public Shape {
public:
    void draw() override { cout << "Drawing Rectangle\n"; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing Circle\n"; }
};

// Function that works with any Shape-derived object
void drawShape(Shape* shape) { shape->draw(); }  

int main() {
    Shape* s1 = new Rectangle();
    Shape* s2 = new Circle();

    drawShape(s1);  // Output: Drawing Rectangle
    drawShape(s2);  // Output: Drawing Circle

    delete s1;
    delete s2;
    return 0;
}
