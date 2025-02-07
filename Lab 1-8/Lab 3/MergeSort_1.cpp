#include<bits/stdc++.h>
using namespace std;

// Recursive function to Merge two sorted arrays using divide and conquer approach
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays for left and right halves
    vector<int> L(n1), R(n2);

    // Copy data into temporary arrays L[] and R[]
    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // Merge the temporary arrays back into the original array
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[] into arr[]
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[] into arr[]
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive mergeSort function to divide the array
void mergeSort(vector<int>& arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n; // Input size of the array
    vector<int> arr(n);

    // Input array elements
    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    // Call mergeSort on the whole array
    mergeSort(arr, 0, n - 1);

    // Output the sorted array
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
