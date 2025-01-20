#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dpp[105][100005], coin[105], n;

/// 'yes' 'no' variation

bool call(int idx , int rem) {
    if(rem < 0) return 0;  // If remainder is negative, return false
    if(rem == 0) return 1;  // If remainder is zero, return true
    if(idx > n) return 0;  // If we have exhausted all coins, return false
    if(dpp[idx][rem] != -1) return dpp[idx][rem];  // If already computed, return the result
    return dpp[idx][rem] = call(idx + 1, rem) | call(idx + 1, rem - coin[idx]);
}

int main() {
    fastio;
    int val;
    cin >> n >> val;  // Input the number of coins and the target value
    for(int i = 1; i <= n; i++) cin >> coin[i];  // Input the coin denominations
    memset(dpp, -1, sizeof dpp);  // Initialize DP table with -1 (uncomputed state)
    
    // If it's possible to form the target value, print "YES", otherwise "NO"
    if(call(1, val)) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}
