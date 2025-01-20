#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define N 1000000
using namespace std;
vector<ll> v[N];
bool visited[N];
bool dfs(ll ver, ll par) {
    visited[ver] = true;
    for (ll child : v[ver]) {
        if (!visited[child]) {
            if (dfs(child, ver)) return 1;
        } else if (child != par) return 1;
    }
    return false;
}
int main() {
    ll ve, e;
    cin>>ve>> e;
    for (ll i =0; i< e; i++) {
        ll v1, v2;
        cin >> v1 >> v2;
        v[v1].pb(v2);
        v[v2].pb(v1);
    }
    memset(visited, 0,sizeof(visited));
    bool cycle=0;
    for (ll i=1;i<=ve;i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                cycle =1;
                cout<<"YES"<<endl;
                break;
            }
        }
    }
    if (!cycle)
        cout<<"NO cycle"<<endl;
    return 0;
}
