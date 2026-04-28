#include <iostream>
using namespace std;

template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

template <typename T>
void reverseArray(T arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

template <typename T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
void findLeaders(T arr[], int n) {
    T maxFromRight = arr[n - 1];
    cout << maxFromRight << " ";

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            maxFromRight = arr[i];
            cout << maxFromRight << " ";
        }
    }
    cout << endl;
}

int main() {
    int n = 6;

    int arr1[] = {16, 17, 4, 3, 5, 2};
    float arr2[] = {1.5, 3.2, 2.8, 4.1, 0.9};
    char arr3[] = {'a', 'd', 'c', 'b', 'e'};

    cout << "Int Array:\n";
    display(arr1, n);
    cout << "Max: " << findMax(arr1, n) << endl;
    reverseArray(arr1, n);
    display(arr1, n);
    findLeaders(arr1, n);

    cout << "\nFloat Array:\n";
    display(arr2, 5);
    cout << "Max: " << findMax(arr2, 5) << endl;
    reverseArray(arr2, 5);
    display(arr2, 5);
    findLeaders(arr2, 5);

    cout << "\nChar Array:\n";
    display(arr3, 5);
    cout << "Max: " << findMax(arr3, 5) << endl;
    reverseArray(arr3, 5);
    display(arr3, 5);
    findLeaders(arr3, 5);

    return 0;
}