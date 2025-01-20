#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pop_back
#define N 1000000
using namespace std;
int main(){
    int map[10000]={0};
    int n,x, mn=INT_MAX;
    int a[n];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mn=min(mn,a[i]);
    }
    for(int i=0;i<n;i++){
        map[a[i]-mn]++;
    }
    cin>>x;
    cout<<map[x-mn]<<" times"<<endl;
    return 0;
}