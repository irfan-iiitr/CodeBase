# Single Responsibility Principle (SRP)

A class should have only one reason to change.

## Bad Example (Violating SRP):

```cpp
class Report {
public:
    void generateReport() { cout << "Generating Report\n"; }
    void printReport() { cout << "Printing Report\n"; }
};
```

Here, the class does two things—generating and printing a report.

This violates SRP since changes in printing may affect report generation.

## Fixed (Following SRP):

```cpp
class ReportGenerator {
public:
    void generateReport() { cout << "Generating Report\n"; }
};

class ReportPrinter {
public:
    void printReport() { cout << "Printing Report\n"; }
};
```