#include <iostream>
#include <vector>
using namespace std;

class Grading {
protected:
    double marks;

public:
    Grading(double m = 0) {
        marks = (m >= 0 && m <= 100) ? m : 0;
    }

    virtual char computeGrade() = 0;

    virtual ~Grading() {}
};

class Undergraduate : public Grading {
public:
    Undergraduate(double m) : Grading(m) {}

    char computeGrade() override {
        if (marks >= 85) return 'A';
        else if (marks >= 70) return 'B';
        else if (marks >= 50) return 'C';
        else return 'F';
    }
};

class Postgraduate : public Grading {
public:
    Postgraduate(double m) : Grading(m) {}

    char computeGrade() override {
        if (marks >= 90) return 'A';
        else if (marks >= 75) return 'B';
        else if (marks >= 60) return 'C';
        else return 'F';
    }
};

class ResearchScholar : public Grading {
public:
    ResearchScholar(double m) : Grading(m) {}

    char computeGrade() override {
        if (marks >= 95) return 'A';
        else if (marks >= 80) return 'B';
        else if (marks >= 65) return 'C';
        else return 'F';
    }
};

class Student {
public:
    string name;
    Grading* gradeObj;

    Student(string n, Grading* g) {
        name = n;
        gradeObj = g;
    }

    void display() {
        cout << name << " -> Grade: " << gradeObj->computeGrade() << endl;
    }
};

int main() {
    vector<Student> students;

    students.push_back(Student("A", new Undergraduate(80)));
    students.push_back(Student("B", new Postgraduate(78)));
    students.push_back(Student("C", new ResearchScholar(92)));
    students.push_back(Student("D", new Undergraduate(45)));

    for (auto &s : students)
        s.display();

    for (auto &s : students)
        delete s.gradeObj;

    return 0;
}