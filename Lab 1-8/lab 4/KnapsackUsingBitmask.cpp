#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
#define endl "\n"
using namespace std;

int main() {
    fastio;

    int n;
    ll cap; 
    // number of items is n and cap is the capacity of the knapsack
    cin >> n >> cap; 

    //taking input value and weight as pairs in a vector
    vector<pair<ll, ll>> items(n); // {value, weight}
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second; // Input value and weight
    }

    ll maxPr = 0; // maximum profit

    // Total subsets (2^n)
    int totalSubsets = 1 << n;

    // Iterates all subsets using bitmasking
    for (int mask = 0; mask < totalSubsets; mask++) {
        ll currWeight = 0, currProfit = 0;

        // Check each item's inclusion in the subset
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { // If the i-th bit is set in mask
                currWeight += items[i].second; // Add item's weight
                currProfit += items[i].first;  // Add item's value
            }
        }

        // Update maximum profit if the weight does not exceed capacity
        if (currWeight <= cap) {
            maxPr = max(maxPr, currProfit);
        }
    }
    cout << maxPr << endl;

    return 0;
}
