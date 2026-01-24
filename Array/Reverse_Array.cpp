#include <iostream>
using namespace std;

//Function to reverse the array
void reverseArray(int arr[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        // Swap arr[start] and arr[end]
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    reverseArray(arr, length);
    
    cout << "Reversed array: ";
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
