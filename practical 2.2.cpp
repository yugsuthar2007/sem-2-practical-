#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int marks[3];

public:
    Student() {
        rollNo = 0;
        name = "Test";
        marks[0] = marks[1] = marks[2] = 0;
    }

    Student(int r, string n, int m1, int m2, int m3) {
        rollNo = r;
        name = n;
        setMarks(m1, m2, m3);
    }

    void setMarks(int m1, int m2, int m3) {
        marks[0] = (m1 >= 0 && m1 <= 100) ? m1 : 0;
        marks[1] = (m2 >= 0 && m2 <= 100) ? m2 : 0;
        marks[2] = (m3 >= 0 && m3 <= 100) ? m3 : 0;
    }

    double getAverage() {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    char getGrade() {
        double avg = getAverage();
        if (avg >= 90) return 'A';
        else if (avg >= 75) return 'B';
        else if (avg >= 60) return 'C';
        else if (avg >= 40) return 'D';
        else return 'F';
    }

    void display() {
        cout << "Roll No: " << rollNo
             << ", Name: " << name
             << ", Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2]
             << ", Average: " << getAverage()
             << ", Grade: " << getGrade()
             << endl;
    }
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n--- Student Menu ---\n";
        cout << "1. Add Student (Default)\n";
        cout << "2. Add Student (User Input)\n";
        cout << "3. Display All\n";
        cout << "4. Highest Average\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            students.push_back(Student());
        }
        else if (choice == 2) {
            int r, m1, m2, m3;
            string n;
            cout << "Enter Roll No, Name, Marks (3 subjects): ";
            cin >> r >> n >> m1 >> m2 >> m3;
            students.push_back(Student(r, n, m1, m2, m3));
        }
        else if (choice == 3) {
            for (auto &s : students) {
                s.display();
            }
        }
        else if (choice == 4) {
            if (students.empty()) {
                cout << "No students available.\n";
            } else {
                int idx = 0;
                double maxAvg = students[0].getAverage();

                for (int i = 1; i < students.size(); i++) {
                    if (students[i].getAverage() > maxAvg) {
                        maxAvg = students[i].getAverage();
                        idx = i;
                    }
                }

                cout << "Student with highest average:\n";
                students[idx].display();
            }
        }

    } while (choice != 0);

    return 0;
}