#include <iostream>
using namespace std;

//Abstract Data Type for Array

struct Array {
    int A[100];
    int size;
    int length;
};

void display(Array arr) {
    for (int i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
    cout << endl;
}

void insert(Array &arr, int index, int value) {
    if (index >= 0 && index <= arr.length && arr.length < arr.size) {
        for (int i = arr.length; i > index; i--)
            arr.A[i] = arr.A[i - 1];

        arr.A[index] = value;
        arr.length++;
    }
}

void remove(Array &arr, int index) {
    if (index >= 0 && index < arr.length) {
        for (int i = index; i < arr.length - 1; i++)
            arr.A[i] = arr.A[i + 1];

        arr.length--;
    }
}

int main() {
    Array arr = {{}, 100, 0};

    insert(arr, 0, 10);
    insert(arr, 1, 20);
    insert(arr, 2, 30);

    display(arr);

    remove(arr, 1);
    display(arr);

    return 0;
}