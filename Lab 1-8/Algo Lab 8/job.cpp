#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pu pop_back
#define N 1000
#define mod 1000000000
using namespace std;

struct job{
    char id;
    ll dl;
    ll pr;
};

bool com(job a, job b)
{
    return a.pr>b.pr;
}

int main()
{
    ll n;   cin>>n;
    job jb[n+3];
    ll result[n+3];
    bool slot[n+3] ={false};
    
    for(ll i=0;i<n;i++)
    {
        cin>>jb[i].id>>jb[i].dl>>jb[i].pr;
    }
    sort(jb,jb+n,com);
    for(ll i=0;i<n;i++)
    {
        for(ll j=min(n,jb[i].dl)-1;j>=0;j--)
        {
            if(!slot[j])
            {
                result[j]=i;
                slot[j]=true;
                break;
            }
        }

    }
    for(ll i=0;i<n;i++)
    {
        if(slot[i])
        {
            cout<<jb[result[i]].id<<' ';
        }
    }
}