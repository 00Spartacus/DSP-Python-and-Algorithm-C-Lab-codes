#include<bits/stdc++.h>
#define N 1000
#define ll long long
using namespace std;
vector<pair<ll,ll>>v[N];

ll n,e;

void djikstra(ll src)
{
    vector<int> dis(N, INT_MAX);
    vector<bool> vis(N, false);

    priority_queue<pair<ll,ll>> qu;
    dis[src]=0;
    qu.push({0,src});
    while(!qu.empty())
    {
        ll cur=qu.top().second;
        qu.pop();
        if(vis[cur])    continue;
        vis[cur]=true;
        for(auto x: v[cur])
        {
            ll ch=x.first;
            ll w=x.second;
            ll val=dis[cur]+w;
            if(val<dis[ch])
            {
                dis[ch]=val;
                qu.push({-dis[ch],ch});
            }
        }
    }
    for(ll i=1;i<=n;i++)//
    {
        if(dis[i]==INT_MAX)   cout<<"INF ";
        else cout<<dis[i]<<' ';
    }
}

int main()
{

    cin>>n>>e;
    for(ll i=0;i<e;i++)
    {
        ll x,y,c;
        cin>>x>>y>>c;
        v[x].push_back({y,c});
        v[y].push_back({x,c});
    }
    djikstra(1);
    
}