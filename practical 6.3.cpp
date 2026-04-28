#include <iostream>
#include <vector>
using namespace std;

class Fuel {
protected:
    string fuelType;

public:
    Fuel(string f = "Unknown") {
        fuelType = f;
    }
};

class Brand {
protected:
    string brandName;

public:
    Brand(string b = "Unknown") {
        brandName = b;
    }
};

class Car : public Fuel, public Brand {
private:
    string model;

public:
    Car(string f, string b, string m)
        : Fuel(f), Brand(b) {
        model = m;
    }

    void display() {
        cout << "Brand: " << brandName
             << ", Model: " << model
             << ", Fuel: " << fuelType
             << endl;
    }
};

int main() {
    vector<Car> cars;

    cars.push_back(Car("Petrol", "Toyota", "Fortuner"));
    cars.push_back(Car("Diesel", "Mahindra", "XUV"));
    cars.push_back(Car("Electric", "Tata", "Nexon EV"));
    cars.push_back(Car("Petrol", "Honda", "City"));

    cout << "\nAll Cars:\n";
    for (auto &c : cars)
        c.display();

    cout << "\nQueue Processing:\n";
    for (int i = 0; i < cars.size(); i++) {
        cars[i].display();
    }

    cout << "\nPriority (Electric First):\n";
    for (auto &c : cars) {
        if (c.display(), c.fuelType == "Electric") {
        }
    }

    for (auto &c : cars) {
        if (c.fuelType != "Electric") {
        }
    }

    return 0;
}