#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) {
        name = n;
        age = (a >= 0) ? a : 0;
    }

    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Employee : public Person {
protected:
    int empID;

public:
    Employee(string n = "", int a = 0, int id = 0)
        : Person(n, a) {
        empID = id;
    }

    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << empID << endl;
    }
};

class Manager : public Employee {
private:
    string department;

public:
    Manager(string n = "", int a = 0, int id = 0, string d = "")
        : Employee(n, a, id) {
        department = d;
    }

    void displayManager() {
        displayEmployee();
        cout << "Department: " << department << endl;
    }

    string getDepartment() {
        return department;
    }

    int getID() {
        return empID;
    }
};

int main() {
    vector<Manager> managers;

    managers.push_back(Manager("A", 40, 101, "HR"));
    managers.push_back(Manager("B", 45, 102, "IT"));
    managers.push_back(Manager("C", 38, 103, "Finance"));

    cout << "\nAll Managers:\n";
    for (auto &m : managers)
        m.displayManager();

    cout << "\nSearch by Department (IT):\n";
    for (auto &m : managers) {
        if (m.getDepartment() == "IT")
            m.displayManager();
    }

    return 0;
}