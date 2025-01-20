#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pop_back
#define N 1000000
using namespace std;
struct edge {
    int a, b, w;
};
int par[10005];
int nodeRank[10005];
edge ar[100005];
bool cmp(edge a, edge b) {
    return a.w < b.w;
}
int find(int a) {
    if (par[a] ==-1) return a;
    par[a]=find(par[a]);
    return par[a];
}
void union_sets(int a, int b) {
    int rootA=find(a);
    int rootB=find(b);
    if (rootA!=rootB) {
        if (nodeRank[rootA]>nodeRank[rootB]) {
            par[rootB]=rootA;
            nodeRank[rootA] +=nodeRank[rootB];
        } else {
            par[rootA]=rootB;
            nodeRank[rootB] +=nodeRank[rootA];
        }
    }
}
int main() {
    int n, m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        par[i] = -1;
        nodeRank[i] = 1;
    }
    for (int i=0; i<m; i++) {
        cin>>ar[i].a >> ar[i].b >> ar[i].w;
    }
    sort(ar, ar + m, cmp);
    int sum = 0;
    for (int i= 0; i<m;i++) {
        int a=find(ar[i].a);
        int b =find(ar[i].b);
        if (a!=b) {
            sum +=ar[i].w;
            union_sets(a, b);
        }
    }
    cout<<sum<< endl;
    return 0;
}