#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)  // Sentinel value representing an impossible case
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dpp[105][100005], coin[105], n;

/// minimum number of coins needed

int call(int idx, int rem) {
    if (rem < 0) return MAX;  // If remainder is negative, return MAX (invalid)
    if (rem == 0) return 0;   // If remainder is 0, return 0 (no coins needed)
    if (idx > n) return MAX;  // If all coins are exhausted, return MAX (impossible)
    if (dpp[idx][rem] != -1) return dpp[idx][rem];  // If already computed, return stored value
    
    // Two choices: Exclude the current coin or include the current coin
    return dpp[idx][rem] = min(call(idx + 1, rem), call(idx + 1, rem - coin[idx]) + 1);
}

int main() {
    fastio;
    int val;
    cin >> n >> val;  // Input number of coins and the target value
    for (int i = 1; i <= n; i++) cin >> coin[i];  // Input coin denominations
    memset(dpp, -1, sizeof dpp);  // Initialize DP table with -1 (uncomputed state)
    
    // Output the minimum number of coins needed
    int ans = call(1, val);
    if (ans >= MAX) ans = -1;  // If it's impossible to form the sum, return -1
    cout << ans << endl;
    return 0;
}
