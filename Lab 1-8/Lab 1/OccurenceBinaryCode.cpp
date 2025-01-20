#include <bits/stdc++.h>
using namespace std;

// Function to find the left_most occurrence of the target
int findFirstOccurrence(int arr[], int size, int target) {
    int start = 0, end = size - 1, firstIndex = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            firstIndex = mid; // Potential first occurrence found
            end = mid - 1;    // Continue searching in the left half
        } else if (arr[mid] < target) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1;   // Search in the left half
        }
    }

    return firstIndex;
}

// Function to find the right_most occurrence of the target
int findLastOccurrence(int arr[], int size, int target) {
    int start = 0, end = size - 1, lastIndex = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            lastIndex = mid; // Potential last occurrence found
            start = mid + 1; // Continue searching in the right half
        } else if (arr[mid] < target) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1;   // Search in the left half
        }
    }

    return lastIndex;
}

// Function to count the occurrences of the target
int countOccurrences(int arr[], int size, int target) {
    int first = findFirstOccurrence(arr, size, target);
    int last = findLastOccurrence(arr, size, target);
    if (first == -1) {
        return 0; // Target not found
    }
    return last - first + 1; // Calculate the count of occurrences
}

int main() {
    int size, target;
    // size of the array is n and target is the element to be found
    cin >> size>> target;
    int arr[size];
    for (int i = 0; i < size; i++) 
        cin >> arr[i];
    // Count the occurrences of the target
    int count = countOccurrences(arr, size, target);
    cout << "The element " << target << " is present " << count << " times in the list." << endl;
    return 0;
}
