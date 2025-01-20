#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

// Comparator function to sort items by value-to-weight ratio
bool cmp(pair<int, int> a, pair<int, int> b) {
    double ratioA = (double)a.first / (double)a.second; // Value-to-weight ratio of item `a`
    double ratioB = (double)b.first / (double)b.second; // Value-to-weight ratio of item `b`
    return ratioA > ratioB; // Sort in descending order of ratio
}

int main() {
    ll n, cap;
    // `n` is the number of items, `cap` is the capacity of the knapsack
    cin >> n >> cap;

    // Store items as {value, weight} pairs in a vector
    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second; // Input value and weight
    }

    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), cmp);

    double maxProfit = 0; // To store the maximum profit

    // Iterate through each item
    for (int i = 0; i < n; i++) {
        if (cap >= items[i].second) {
            // If the knapsack can accommodate the full weight of the item
            maxProfit += items[i].first; // Add the full value of the item
            cap -= items[i].second;     // Reduce the remaining capacity
        } else {
            // If only a portion of the item's weight can be accommodated
            double portion = (double)cap / (double)items[i].second; // Fraction of the item that can fit
            maxProfit += portion * items[i].first;                 // Add the proportional value
            break; // Knapsack is full
        }
    }

    // Output
    cout << maxProfit << endl;

    return 0;
}