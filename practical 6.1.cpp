include <iostream>
#include <vector>
using namespace std;

class Shape {
protected:
    double radius;

public:
    Shape(double r = 0) {
        radius = (r >= 0) ? r : 0;
    }

    void setRadius(double r) {
        if (r >= 0)
            radius = r;
    }

    double getRadius() {
        return radius;
    }
};

class Circle : public Shape {
public:
    Circle(double r = 0) : Shape(r) {}

    double area() {
        return 3.14159 * radius * radius;
    }

    double circumference() {
        return 2 * 3.14159 * radius;
    }

    string sizeCategory() {
        double a = area();
        if (a < 50) return "Small";
        else if (a < 200) return "Medium";
        else return "Large";
    }

    void display() {
        cout << "Radius: " << radius
             << ", Area: " << area()
             << ", Circumference: " << circumference()
             << ", Category: " << sizeCategory()
             << endl;
    }
};

int main() {
    int n;
    cin >> n;

    Circle* c = new Circle[n];

    for (int i = 0; i < n; i++) {
        double r;
        cin >> r;
        c[i].setRadius(r);
    }

    cout << "\nCircle Details:\n";
    for (int i = 0; i < n; i++) {
        c[i].display();
    }

    cout << "\nStatic Version (fixed 3 circles):\n";
    Circle s[3] = {Circle(2), Circle(5), Circle(10)};

    for (int i = 0; i < 3; i++) {
        s[i].display();
    }

    delete[] c;

    return 0;
}