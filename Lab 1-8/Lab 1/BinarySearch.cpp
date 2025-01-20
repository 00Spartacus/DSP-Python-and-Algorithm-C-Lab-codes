#include <bits/stdc++.h>
using namespace std;

// Binary search function
int binarySearch(const vector<int>& arr, int target)
{
    int start = 0; // Replaced 'left' with 'start'
    int end = arr.size() - 1; // Replaced 'right' with 'end'

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return mid; // Element found at index 'mid'
        else if (arr[mid] < target)
            start = mid + 1; // Target is in the right half
        else
            end = mid - 1; // Target is in the left half
    }
    return -1; // Element not found
}
int main()
{
    int n, target;

    // Input the size of the array and the target element
    cin >> n >> target;
    vector<int> arr(n);

    // Input the array elements
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Sort the array for binary search
    sort(arr.begin(), arr.end());

    // Perform binary search
    int index = binarySearch(arr, target);

    // Output the result
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found in the list." << endl;

    return 0;
}