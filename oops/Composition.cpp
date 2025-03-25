// Composition is a "has-a" relationship. 
// It is a strong type of aggregation.
// In composition, both the objects are dependent on each other.
// If the parent object is destroyed, all its child objects will also be destroyed.

// Example: A car has an engine. If the car is destroyed, the engine is also destroyed.

// Composition is a design technique in object-oriented programming to implement has-a relationships between objects.

// Composition is a design principle where one class contains an object of another class instead of inheriting from it.

// This promotes code reusability while avoiding the drawbacks of deep inheritance hierarchies.

#include <iostream>
using namespace std;

class Engine {
public:
    void start() { cout << "Engine started\n"; }
};

class Car {
private:
    Engine engine;  // Car has an Engine

public:
    void startCar() { 
        engine.start(); 
        cout << "Car is running\n"; 
    }
};

int main() {
    Car myCar;
    myCar.startCar();
}


// 💡 When to use Composition?

// When objects should have a strong relationship but not necessarily be a subtype (e.g., a Car has-an Engine but is not an Engine).

// Prevents the fragile base class problem (changing the base class affects all derived classes).






