#include<bits/stdc++.h>
using namespace std;

vector<int> nums;                 
vector<vector<int>> permutations; // 2D vector to store all the permutations

// Recursive function to find all permutations
void generatePermutations(int index) {
    // Base case: If the current index is at the end of the array, store the permutation
    if (index >= nums.size()) {
        permutations.push_back(nums);
        return;
    }

    // Recursive case: Generate all possible permutations by swapping elements
    for (int currentIndex = index; currentIndex < nums.size(); currentIndex++) {
        // Swap the current element with the element at the 'index'
        swap(nums[index], nums[currentIndex]);

        // Recursively generate permutations with the next index
        generatePermutations(index + 1);

        // Backtrack: Undo the swap to explore other permutations
        swap(nums[index], nums[currentIndex]);
    }
}

int main() {
    int n;
    // the number of elements in the array is n
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++) 
        cin >> nums[i];

    // Generate all permutations starting from index 0
    generatePermutations(0);

    for (int i = 0; i < permutations.size(); i++) {
        for (int j = 0; j < permutations[i].size(); j++) {
            cout << permutations[i][j] ;
        }
        cout << " ";
    }
    return 0;
}