#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

struct Knap{
	int weight , value;
};

bool cmp(Knap a, Knap b)
{
	double aa = (double) a.value / (double) a.weight;
	double bb = (double) b.value / (double) b.weight;
	
	return aa > bb;
	
}

int main()
{
	ll n,cap;
	//n = number of items
	//cap = capacity of the knapsack
	cin >> n >> cap;
	
	Knap k[n+5];
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> k[i].value >> k[i].weight;
	}
	
	sort(k , k + n, cmp);
	
	
	double ans = 0 ;
	
	for(int i = 0 ; i < n; i++){
		if(cap >= k[i].weight)
		{
		    ans+=k[i].value;
			cap-=k[i].weight;	
			
		////	cout << ans << endl;
		}
		else{
			double portion = (double)cap/(double)k[i].weight;
			//cout << portion << endl;
			ans+=portion *(double) k[i].value;
			
		}
		
	}
	
	cout << ans << endl;
}
