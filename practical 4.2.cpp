#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    Point& move(int dx, int dy) {
        x += dx;
        y += dy;
        return *this;
    }

    double distanceFromOrigin() {
        return sqrt(x * x + y * y);
    }

    void setAbsolute(int nx, int ny) {
        x = nx;
        y = ny;
    }

    void display() {
        cout << "(" << x << ", " << y << ")\n";
    }

    friend void reset(Point* p);
};

void reset(Point* p) {
    if (p != nullptr) {
        p->x = 0;
        p->y = 0;
    }
}

int main() {
    Point p(2, 3);

    p.move(2, 3).move(-1, 4).move(5, -2);

    p.display();

    cout << p.distanceFromOrigin() << endl;

    p.setAbsolute(10, 10);
    p.display();

    reset(&p);
    p.display();

    return 0;
}