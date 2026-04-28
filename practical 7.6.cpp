#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base Constructor\n";
    }

    ~Base() {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[5];
        cout << "Derived Constructor\n";
    }

    ~Derived() {
        delete[] data;
        cout << "Derived Destructor\n";
    }
};

class BaseVirtual {
public:
    BaseVirtual() {
        cout << "BaseVirtual Constructor\n";
    }

    virtual ~BaseVirtual() {
        cout << "BaseVirtual Destructor\n";
    }
};

class DerivedVirtual : public BaseVirtual {
private:
    int* data;

public:
    DerivedVirtual() {
        data = new int[5];
        cout << "DerivedVirtual Constructor\n";
    }

    ~DerivedVirtual() {
        delete[] data;
        cout << "DerivedVirtual Destructor\n";
    }
};

int main() {
    Base* b1 = new Derived();
    delete b1;

    BaseVirtual* b2 = new DerivedVirtual();
    delete b2;

    return 0;
}