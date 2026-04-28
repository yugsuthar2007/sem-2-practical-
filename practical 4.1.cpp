#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;

public:
    DynamicArray() {
        arr = nullptr;
        size = 0;
    }

    void insertEnd(int value) {
        int* newArr = new int[size + 1];

        for (int i = 0; i < size; i++)
            newArr[i] = arr[i];

        newArr[size] = value;

        delete[] arr;
        arr = newArr;
        size++;
    }

    void deleteAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position\n";
            return;
        }

        if (size == 1) {
            delete[] arr;
            arr = nullptr;
            size = 0;
            return;
        }

        int* newArr = new int[size - 1];

        for (int i = 0, j = 0; i < size; i++) {
            if (i != pos) {
                newArr[j] = arr[i];
                j++;
            }
        }

        delete[] arr;
        arr = newArr;
        size--;
    }

    void insertAt(int pos, int value) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position\n";
            return;
        }

        int* newArr = new int[size + 1];

        for (int i = 0, j = 0; i < size + 1; i++) {
            if (i == pos)
                newArr[i] = value;
            else
                newArr[i] = arr[j++];
        }

        delete[] arr;
        arr = newArr;
        size++;
    }

    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value)
                return i;
        }
        return -1;
    }

    int count(int value) {
        int c = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value)
                c++;
        }
        return c;
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray d;

    d.insertEnd(10);
    d.insertEnd(20);
    d.insertEnd(30);
    d.insertEnd(40);
    d.insertEnd(50);

    d.display();

    d.deleteAt(2);
    d.display();

    d.insertAt(2, 99);
    d.display();

    cout << d.search(40) << endl;
    cout << d.count(20) << endl;

    d.deleteAt(0);
    d.deleteAt(1);
    d.display();

    return 0;
}