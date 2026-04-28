#include <iostream>
#include <vector>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    Employee(string n, double b) {
        name = n;
        basicSalary = (b >= 0) ? b : 0;
        bonus = 1000;
    }

    Employee(string n, double b, double bo) {
        name = n;
        basicSalary = (b >= 0) ? b : 0;
        bonus = (bo >= 0) ? bo : 0;
    }

    inline double totalSalary() {
        return basicSalary + bonus;
    }

    void updateBonus(double b) {
        if (b >= 0)
            bonus = b;
    }

    string getGrade() {
        double t = totalSalary();
        if (t >= 100000) return "A";
        else if (t >= 70000) return "B";
        else if (t >= 40000) return "C";
        else return "D";
    }

    void display() {
        cout << "Name: " << name
             << ", Basic: " << basicSalary
             << ", Bonus: " << bonus
             << ", Total: " << totalSalary()
             << ", Grade: " << getGrade()
             << endl;
    }
};

int main() {
    vector<Employee> emp;

    emp.push_back(Employee("A", 50000));
    emp.push_back(Employee("B", 60000, 5000));
    emp.push_back(Employee("C", 30000));
    emp.push_back(Employee("D", 80000, 10000));
    emp.push_back(Employee("E", 45000, 2000));

    for (auto &e : emp) {
        e.display();
    }

    return 0;
}