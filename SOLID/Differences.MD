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

int main(){
    Rectangle r;
    Circle c;

    r.draw(); // Drawing Rectangle
    c.draw(); // Drawing Circle
}
```

🚀 **Key Differences Between Two Approaches**

| Approach | Pros | Cons |
| --- | --- | --- |
| **Polymorphic Approach (First main())**<br>(Using `Shape* s1 = new Rectangle();`) | ✅ Allows handling multiple shapes via a common interface (`Shape*`).<br>✅ Supports dynamic dispatch (calls correct `draw()` function at runtime).<br>✅ Essential for collections of shapes (e.g., storing `Shape*` objects in a vector). | ❌ Requires `new` and manual `delete` calls (prone to memory leaks).<br>❌ Slightly more complex syntax. |
| **Direct Object Approach (Second main())**<br>(Using `Rectangle r; Circle c;`) | ✅ Simple and easy to understand.<br>✅ No need for `new` and `delete` (automatic memory management).<br>✅ Slightly more efficient (avoids heap allocation). | ❌ No polymorphism → Cannot store `Rectangle` and `Circle` in the same container (`vector<Shape*>`).<br>❌ Requires writing separate `draw()` calls for each shape. |

🔍 **When to Use Which Approach?**

✅ Use the Polymorphic Approach (`Shape*`) if:
- You need a generic function (`drawShape(Shape* shape)`) that works for multiple shapes.
- You plan to store objects in a container (`vector<Shape*>`).
- You want dynamic behavior (e.g., selecting shape type at runtime).

✅ Use Direct Object Approach (`Rectangle r; Circle c;`) if:
- You know all shapes at compile time.
- You don't need polymorphism.
- You want a simpler approach without `new`/`delete`.

📌 **Example Where Polymorphism is Needed**

Imagine you want to store multiple shapes in an array and call `draw()` dynamically.
This won't work with direct object creation but works with `Shape*`.

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
    virtual ~Shape() {}       // Virtual destructor to avoid memory leaks
};

class Rectangle : public Shape {
public:
    void draw() override { cout << "Drawing Rectangle\n"; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing Circle\n"; }
};

int main() {
    vector<Shape*> shapes;
    
    shapes.push_back(new Rectangle());
    shapes.push_back(new Circle());

    // Draw all shapes dynamically
    for (Shape* shape : shapes) {
        shape->draw();  // Calls the correct overridden function
    }

    // Free memory
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
```

🔹 **Why use `Shape*`?**

- You can store different shape types (`Rectangle`, `Circle`) in the same container.
- You can iterate through them and call `draw()` dynamically.

✅ **Conclusion**

- For simple cases, use direct object creation (`Rectangle r; c.draw();`).
- For flexibility & polymorphism, use `Shape*` with virtual functions.

