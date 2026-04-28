#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double l, w;

public:
    Rectangle(double a, double b) {
        l = a;
        w = b;
    }

    double area() override {
        return l * w;
    }
};

class Circle : public Shape {
private:
    double r;

public:
    Circle(double radius) {
        r = radius;
    }

    double area() override {
        return 3.14159 * r * r;
    }
};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(10, 5));
    shapes.push_back(new Circle(7));
    shapes.push_back(new Rectangle(4, 3));
    shapes.push_back(new Circle(2));

    cout << "Areas:\n";
    for (Shape* s : shapes) {
        cout << s->area() << endl;
    }

    for (Shape* s : shapes) {
        delete s;
    }

    Shape* staticShapes[3];
    staticShapes[0] = new Rectangle(2, 3);
    staticShapes[1] = new Circle(5);
    staticShapes[2] = new Rectangle(6, 1);

    cout << "\nStatic Storage Areas:\n";
    for (int i = 0; i < 3; i++) {
        cout << staticShapes[i]->area() << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete staticShapes[i];
    }

    return 0;
}