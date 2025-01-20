#include<bits/stdc++.h>
using namespace std;


struct Job{
	char a;
	int dl , profit ;
	
};

bool cmp(Job a, Job b)
{
	return a.profit > b.profit;
}


int main()
{
   int n;
   cin >>  n;
   
   
   Job job[n+5];
   
   for(int i = 0 ; i < n; i++)
   {
   	cin >> job[i].a >> job[i].dl >> job[i].profit;
   }
   
   sort(job , job + n , cmp);
   
   vector<char>ans;
   
   
   int pr = 0 ;
   
   vector<bool>slot(n,0);
   
   for(int i = 0 ; i < n ; i++ )
   {
   	   for(int j = min(n,job[i].dl) - 1; j >= 0 ; j--)
   	   {
   	   	if(!slot[j])
   	   	{
   	   		slot[j] = 1;
   	   		pr+=job[i].profit;
   	   		ans.push_back(job[i].a);
   	   		break;
		}
		}
   }
   
   
   cout << pr << endl;
   
   for(int i = 0 ; i < ans.size(); i++)
   {
   	cout << ans[i] << " ";
   }
   cout << endl;   
	
		
}
