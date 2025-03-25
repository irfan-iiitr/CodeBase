#include <bits/stdc++.h>
using namespace std;

// These concepts define relationships between classes in OOP.

// Association → A general relationship between two classes.

// Aggregation → A weak relationship where one class contains another, but the lifecycle is independent.

// Composition → A strong relationship where one class owns another, and the lifecycle is dependent.

///Example of Aggregation (Weak Relationship)

class Student {
public:
    string name;
    Student(string n) : name(n) {}
};

class College {
public:
    Student student;  // Student exists independently

    College(Student s) : student(s) {} //follow this only

    void showStudent() { cout << "Student: " << student.name << endl; }
};
    
int main() {
    Student s1("Irfan");
    College c(s1);
    c.showStudent();
}

// Here, College has a Student, but the Student object exists independently outside College.
    