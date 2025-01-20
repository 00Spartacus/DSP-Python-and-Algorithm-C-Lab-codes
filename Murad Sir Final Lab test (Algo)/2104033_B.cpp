#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pop_back
#define N 1000000
using namespace std;
bool f(int a[], int n, int s) {
    if (s ==0) return 1;
    if (n==0) return 0;
    if (a[n-1]> s)  return f(a,n-1, s);
    return f(a, n- 1,s)||f(a,n-1,s-a[n-1]);
}
int main() {
    int n, sum;
    cin >> n;
    int arr[n];
    for (int i=0;i <n;i++) {
        cin >> arr[i];
    }
    cin >> sum;
        cout <<f(arr,n,sum)<< endl;
    return 0;
}