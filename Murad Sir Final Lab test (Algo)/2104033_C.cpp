#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pop_back
#define N 1000000
using namespace std;
int cutrod(int p[], int n) {
    vector<int> dp(n +1,0);
    for (int i=1; i<=n;i++) {
        for (int j=0; j<i;j++) {
            dp[i]=max(dp[i], p[j]+dp[i-j-1]);
        }
    }
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    int p[n];
    for (int i = 0; i < n; ++i) 
        cin>>p[i];
    cout <<cutrod(p, n) << endl;
    return 0;
}