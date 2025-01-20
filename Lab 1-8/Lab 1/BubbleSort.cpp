#include <bits/stdc++.h>
using namespace std;
int main() {
    int size; // size of the array
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) 
        cin >> arr[i];
    // Bubble Sort Algorithm
    for (int pass = 0; pass < size - 1; pass++) { 
        // Perform passes through the array
        for (int index = 0; index < size - pass - 1; index++) {
            // Comparing adjacent elements and swaping when arr[index] > arr[index + 1]
            if (arr[index] > arr[index + 1]) { 
                // Swap arr[index] and arr[index + 1]
                int temp = arr[index];
                arr[index] = arr[index + 1];
                arr[index + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
