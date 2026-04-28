#include <iostream>
#include <vector>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l = 0, double w = 0) {
        setDimensions(l, w);
    }

    void setDimensions(double l, double w) {
        if (l >= 0 && w >= 0) {
            length = l;
            width = w;
        } else {
            cout << "Invalid dimensions! Setting to 0.\n";
            length = 0;
            width = 0;
        }
    }

    double getLength() { return length; }
    double getWidth() { return width; }

    double getArea() {
        return length * width;
    }

    double getPerimeter() {
        return 2 * (length + width);
    }

    bool isSquare() {
        return (length == width && length != 0);
    }

    void display() {
        cout << "Length: " << length
             << ", Width: " << width
             << ", Area: " << getArea()
             << ", Perimeter: " << getPerimeter();

        if (isSquare())
            cout << " (Square)";
        cout << endl;
    }

    bool isLargerThan(Rectangle r) {
        return this->getArea() > r.getArea();
    }
};

int main() {
    vector<Rectangle> rects;
    int choice;

    do {
        cout << "\n--- Rectangle Menu ---\n";
        cout << "1. Add Rectangle\n";
        cout << "2. Update Rectangle\n";
        cout << "3. Display All\n";
        cout << "4. Compare Two Rectangles\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            double l, w;
            cout << "Enter length and width: ";
            cin >> l >> w;
            rects.push_back(Rectangle(l, w));
        }
        else if (choice == 2) {
            int index;
            double l, w;
            cout << "Enter rectangle index: ";
            cin >> index;

            if (index >= 0 && index < rects.size()) {
                cout << "Enter new length and width: ";
                cin >> l >> w;
                rects[index].setDimensions(l, w);
            } else {
                cout << "Invalid index!\n";
            }
        }
        else if (choice == 3) {
            if (rects.empty()) {
                cout << "No rectangles available.\n";
            } else {
                for (int i = 0; i < rects.size(); i++) {
                    cout << "Rectangle " << i << ": ";
                    rects[i].display();
                }
            }
        }
        else if (choice == 4) {
            int i1, i2;
            cout << "Enter two rectangle indices: ";
            cin >> i1 >> i2;

            if (i1 >= 0 && i1 < rects.size() && i2 >= 0 && i2 < rects.size()) {
                if (rects[i1].isLargerThan(rects[i2]))
                    cout << "Rectangle " << i1 << " is larger.\n";
                else if (rects[i2].isLargerThan(rects[i1]))
                    cout << "Rectangle " << i2 << " is larger.\n";
                else
                    cout << "Both have equal area.\n";
            } else {
                cout << "Invalid indices!\n";
            }
        }

    } while (choice != 0);

    return 0;
}