#include <iostream>
using namespace std;

int findFirstOccurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;  // Look for the first occurrence on the left side
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int findLastOccurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;  // Look for the last occurrence on the right side
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int countOccurrences(int arr[], int n, int target) {
    int first = findFirstOccurrence(arr, n, target);
    if (first == -1) {
        return 0;  // Element not found in the list
    }

    int last = findLastOccurrence(arr, n, target);
    return last - first + 1;
}

int main() {
    int n, target;

    cin >> n;

    int arr[n+5];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    int count = countOccurrences(arr, n, target);

    cout << "The element " << target << " is present " << count << " times in the list." << endl;

    return 0;
}

