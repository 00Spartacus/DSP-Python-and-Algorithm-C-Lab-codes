#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int a[MAXN];

long long merge_arrays(int l, int r, int m)
{
    int l_sz = m - l + 1;
    int r_sz = r - m;
    int L[l_sz + 1];
    int R[r_sz + 1];

    for (int i = 0; i < l_sz; i++)
    {
        L[i] = a[i + l];
    }

    for (int j = 0; j < r_sz; j++)
    {
        R[j] = a[j + m + 1];
    }

    L[l_sz] = R[r_sz] = INT_MAX;
    int l_i = 0;
    int r_i = 0;
    long long inversions = 0;

    for (int i = l; i <= r; i++)
    {
        if (L[l_i] <= R[r_i])
        {
            a[i] = L[l_i];
            l_i++;
        }
        else
        {
            a[i] = R[r_i];
            r_i++;
            inversions += (l_sz - l_i);
        }
    }
    return inversions;
}

long long merge_sort(int l, int r)
{
    long long inversion_cnt = 0;
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        inversion_cnt += merge_sort(l, mid);
        inversion_cnt += merge_sort(mid + 1, r);
        inversion_cnt += merge_arrays(l, r, mid);
    }
    return inversion_cnt;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin) ;
        freopen("output.txt" , "w" , stdout) ;
    #endif
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long inversionCount = merge_sort(0, n - 1);
    cout << "Inversion Count: " << inversionCount << endl;
}
