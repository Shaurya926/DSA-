#include <iostream>
using namespace std;
//Function to arrange the array in ascending order
void arrangeArrayAscending(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int arr[] = {45, 23, 78, 12, 56, 89, 34};
    int length = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    arrangeArrayAscending(arr, length);
    
    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}